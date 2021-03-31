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
#define NMAX 505
#define pb push_back
typedef long long ll;
typedef pair<ll,ll> pll;
typedef pair<int,int> pii;
int test;
int n,k,m;
pll a[NMAX];
vector <int> rem;
int cnt;
bool id[NMAX];
vector <int> G[NMAX];
vector <pll> adj[NMAX];
ll d[NMAX][NMAX];
priority_queue < pll , vector <pll> , greater <pll > > pq;
inline void dijkstra(int s){
    for(int i=0;i<NMAX;i++) d[s][i]=1e16;
    d[s][s]=0;
    pq.push({0,s});
    while(!pq.empty()){
        pll top=pq.top();pq.pop();
        ll val=top.first,u=top.second;
        if(d[s][u]!=val) continue;
        for(auto p:adj[u]){
            ll v=p.first,w=p.second;
            if(d[s][v]>d[s][u]+w){
                d[s][v]=d[s][u]+w;
                pq.push({d[s][v],v});
            }
        }
    }
}
int married[NMAX],visited[NMAX];
inline bool DFS(int u){
    if(visited[u]!=cnt) visited[u]=cnt;
    else return false;
    for(int v:G[u]){
        if(!married[v]||DFS(married[v])){
            married[v]=u;
            return true;
        }
    }
    return false;
}
int main(){
    freopen("INQUIR.inp","r",stdin);
   // freopen("INQUIR.out","w",stdout);
    read(test);
    while(test--){
        for(int i=1;i<=n;i++) adj[i].clear(),G[i].clear();
        memset(id,0,sizeof(id));
        rem.clear();
        read(n);read(k);read(m);
        for(int i=1;i<=k;i++){
            read(a[i].first);read(a[i].second);
            if(id[a[i].second]==0){
                id[a[i].second]=1;
                rem.pb(a[i].second);
            }
        }
        for(int i=1;i<=m;i++){
            int u,v,w;
            read(u);read(v);read(w);
            adj[u].pb({v,w});
            adj[v].pb({u,w});
        }
        for(int v:rem){
            dijkstra(v);
        }
        sort(a+1,a+k+1);
        for(int i=1;i<=k;i++){
            for(int j=i+1;j<=k;j++){
                if(d[a[i].second][a[j].second]<=a[j].first-a[i].first){
                    G[i].pb(j);
                }
            }
        }
        memset(married,0,sizeof(married));
        int res=0;
        for(int i=1;i<=k;i++){
            ++cnt;
            res+=DFS(i);
        }
//        for(int i=1;i<=k;i++){
//            cout<<i<<" "<<married[i]<<'\n';
//        }
        writeln(k-res);
    }
}
