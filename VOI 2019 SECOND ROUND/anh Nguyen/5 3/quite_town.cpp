#include <bits/stdc++.h>
using namespace std;
template <typename T> inline void read(T &x){
    char c;
    bool nega=0;
    while((!isdigit(c=getchar()))&&(c!='-'));
    if(c=='-'){
        nega=1;
        c=getchar();
    }
    x=c-48;
    while(isdigit(c=getchar())) x=x*10+c-48;
    if(nega) x=-x;
}
template <typename T> inline void writep(T x){
    if(x>9) writep(x/10);
    putchar(x%10+48);
}
template <typename T> inline void write(T x){
    if(x<0){
        putchar('-');
        x=-x;
    }
    writep(x);
}
template <typename T> inline void writeln(T x){
    write(x);
    putchar('\n');
}
#define pb push_back
#define mp make_pair
#define NMAX 1501
const int inf=1e9;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
struct data{
    int u,val;
};
struct cmp{
    inline bool operator ()(const data &x,const data &y){
        return x.val>y.val;
    }
};
int n,m,optimal;
int d[NMAX][NMAX],F[NMAX];
bool visit[NMAX],mark[NMAX];
vector <pii> adj[NMAX];
priority_queue <data, vector <data> , cmp > pq;
inline void dijkstra(int s){
    while(!pq.empty()) pq.pop();
    for(int i=1;i<=n;i++) d[s][i]=inf;
    d[s][s]=0;
    pq.push({s,0});
    while(!pq.empty()){
        data top=pq.top();pq.pop();
        if(d[s][top.u]!=top.val) continue;
        optimal=max(optimal,top.val);
        for(auto i:adj[top.u]){
            int v=i.first,w=i.second;
            if(d[s][v]>d[s][top.u]+w){
                d[s][v]=d[s][top.u]+w;
                pq.push({v,d[s][v]});
            }

        }
    }
}
void enter(){
    read(n);read(m);
    for(int i=1;i<=m;i++){
        int u,v,w;
        read(u);read(v);read(w);
        adj[u].pb(pii(v,w));
        adj[v].pb(pii(u,w));
    }

}
inline void DFS(int u,int root){
    if(visit[u]) return;
    visit[u]=true;
    F[u]=d[root][u];
    for(auto p:adj[u]){
        int v=p.first,w=p.second;
        if(d[root][v]==d[root][u]+w){
            DFS(v,root);
            F[u]=max(F[u],F[v]);
        }
    }
    if(F[u]==optimal) mark[u]=true;
}
void progress(){
    for(int i=1;i<=n;i++){
        dijkstra(i);
    }
//    for(int i=1;i<=n;i++){
//        for(int j=1;j<=n;j++){
//            cout<<i<<" "<<j<<" "<<d[i][j]<<'\n';
//        }
//    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++) visit[j]=false;
        DFS(i,i);
    }
    int cnt=0;
    for(int i=1;i<=n;i++) cnt+=(!mark[i]);
    writeln(cnt);
    for(int i=1;i<=n;i++) if(!mark[i]) writeln(i);
}
int main(){
    //freopen("quite_town.inp","r",stdin);
    //freopen("quite_town.out","w",stdout);
    enter();
    progress();
}
