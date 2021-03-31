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
#define NMAX 1005

typedef pair<int,int> pii;
typedef long long ll;
typedef pair<ll,ll> pll;
const int inf=1e9;
struct data{
    int u,v,val;
};
vector <pii> adj[NMAX];
vector <data> edge;
int n,m;
int a[NMAX][NMAX],d[NMAX];
void enter(){
    read(n);read(m);
    if(m==1){
        puts("-1.000000");
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++) a[i][j]=a[j][i]=inf;
    }
    for(int i=1;i<=m;i++){
        int u,v,w;
        read(u);read(v);read(w);
        adj[u].pb({v,i-1});
        adj[v].pb({u,i-1});
        edge.pb({u,v,w});
        a[u][v]=a[v][u]=min(a[u][v],w);
    }
}
struct node{
    int u,val;
};
struct cmp{
    inline bool operator () (const node &x,const node &y){
        return x.val>y.val;
    }
};
inline int solve1(int s,int t,int id){

    priority_queue < node, vector <node> , cmp> pq;
    for(int i=1;i<=n;i++) d[i]=inf;
    d[s]=0;
    pq.push({s,0});
    while(!pq.empty()){
        node top=pq.top();pq.pop();
        int u=top.u,val=top.val;
        if(d[u]!=val) continue;
        //cout<<u<<" "<<val<<" "<<d[u]<<'\n';
        if(u==t) return val;
        for(auto p:adj[u]){
            int v=p.first,w=p.second;
            if(w!=id){
                if(d[v]>d[u]+a[u][v]){
                    d[v]=d[u]+a[u][v];
                //cout<<u<<" "<<v<<" "<<a[u][v]<<" "<<d[v]<<" "<<w<<'\n';
                    pq.push({v,d[v]});
                }
            }
        }
    }
}
inline void optimal(double &x,double y){
    if(x<y) x=y;
    return;
}
void progress(){
    double res=1.0;
    for(int i=0;i<edge.size();i++){
        int u=edge[i].u,v=edge[i].v,w=edge[i].val;
        int cur;
        if(a[u][v]!=w) continue;
        //if(m<=2000)
        cur=solve1(u,v,i);
        if(cur>=inf) continue;
   //     cout<<u<<" "<<v<<" "<<w<<" "<<cur<<'\n';
       // exit(0);
       //else cur=solve2(u,v,i);
        optimal(res,cur*1.0/w);
     //   cout<<"get: "<<res<<'\n';
    }
    cout<<fixed<<setprecision(6)<<res;
}
int main(){
    //ios_base::sync_with_stdio(0);
    //cin.tie(0);
   // cout.tie(0);
    //freopen("road.inp","r",stdin);
    enter();
    progress();
}


