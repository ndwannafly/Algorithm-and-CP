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
#define NMAX 220000

typedef long long ll;
typedef pair<ll,ll> pll;
typedef pair<int,int> pii;
const ll inf=1e16;
struct data{
     ll u,val;
};
struct cmp{
    inline bool operator () (const data &x,const data &y){
        return x.val>y.val;
    }
};
ll n,m,s,res;
vector <data> adj[NMAX];
vector <ll> ke[NMAX],re[NMAX],go[NMAX];
priority_queue < data, vector <data> , cmp > pq;
queue <ll> q;
ll d[NMAX],depth[NMAX],deg[NMAX],par[NMAX][23];
void enter(){
    read(n);read(m);read(s);
    for(int i=1;i<=n;i++){
        for(int j=0;j<=22;j++) par[i][j]=-1;
    }
    for(int i=1;i<=m;i++){
        ll u,v,w;
        read(u);read(v);read(w);
        adj[u].pb({v,w});
        adj[v].pb({u,w});
    }
}
void dijkstra(int s){
    for(int i=1;i<=n;i++) d[i]=inf;
    d[s]=0;
    pq.push({s,0});
    while(!pq.empty()){
        data top=pq.top();pq.pop();
        ll u=top.u,val=top.val;
        if(d[u]!=val) continue;
        for(auto p:adj[u]){
            ll v=p.u,w=p.val;
            if(d[v]>d[u]+w){
                d[v]=d[u]+w;
                pq.push({v,d[v]});
            }
        }
    }
}
inline ll getlca(ll u,ll v){
    if(depth[u]<depth[v]) swap(u,v);
    for(int i=22;i>=0;i--){
        if(par[u][i]!=-1&&depth[par[u][i]]>=depth[v]) u=par[u][i];
    }
    if(u==v) return u;
    for(int i=22;i>=0;i--){
        if(par[u][i]!=-1&&par[u][i]!=par[v][i]){
            u=par[u][i];
            v=par[v][i];
        }
    }
    return par[u][0];
}
inline void build_tree(){
    q.push(s);
    depth[s]=1;
    while(!q.empty()){
        ll fr=q.front();q.pop();
        for(ll v:ke[fr]){
            deg[v]--;
            if(!deg[v]) q.push(v);
        }
        if(fr==s) continue;
        ll pa=re[fr][0];
        for(int i=1;i<re[fr].size();i++){
            pa=getlca(pa,re[fr][i]);
        }
        par[fr][0]=pa;
        go[pa].pb(fr);
        //cout<<pa<<" "<<fr<<'\n';
        depth[fr]=depth[pa]+1;
        for(int i=0;i<21;i++){
            if(par[fr][i]!=-1) par[fr][i+1]=par[par[fr][i]][i];
        }
    }
}
ll numchild[NMAX];
inline void DFS(int u){
    numchild[u]=1;
    for(int v:go[u]){
        DFS(v);
        numchild[u]+=numchild[v];
    }
    if(u!=s) res=max(res,numchild[u]);
}
void progress(){
    dijkstra(s);
    for(int u=1;u<=n;u++){
        for(auto p:adj[u]){
            ll v=p.u,w=p.val;
            if(d[v]!=inf&&d[u]!=inf&&d[v]==d[u]+w){
                ke[u].pb(v);
                re[v].pb(u);
                deg[v]++;
            }
        }
    }
    build_tree();
    DFS(s);
    writeln(res);
}
int main(){
//    freopen("B.inp","r",stdin);
    enter();
    progress();
}
