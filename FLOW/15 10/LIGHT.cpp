#include <bits/stdc++.h>
using namespace std;
#define NMAX 205
#define pb push_back
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

ll m,n,k;
ll a[NMAX],b[NMAX];
ll C[NMAX][NMAX],F[NMAX][NMAX];
int trace[NMAX];
vector <int> adj[NMAX];
int source=0,sink=201;
// souce =0 sink 101
inline bool BFS(int source,int sink){
    queue <int> q;
    q.push(source);
    while(!q.empty()){
        int u=q.front();q.pop();
        for(int v:adj[u]){
            if(trace[v]==-1&&F[u][v]<C[u][v]){
                trace[v]=u;
             //   cout<<v<<" "<<u<<'\n';
                if(v==sink) return true;
                q.push(v);
            }
        }
    }
    return false;
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("LIGHT.inp","r",stdin);
    freopen("LIGHT.out","w",stdout);
    cin>>m>>n>>k;
    for(int i=1;i<=m;i++) cin>>a[i];
    for(int i=1;i<=n;i++) cin>>b[i];
    for(int i=1;i<=k;i++){
        int u,v;
        cin>>u>>v;
        adj[0].pb(u);
        adj[u].pb(0);
        adj[u].pb(v+100);
        adj[v+100].pb(u);
        adj[v+100].pb(201);
        adj[201].pb(v+100);
        C[u][v+100]=1e16;
        C[0][u]=a[u];
        C[v+100][201]=b[v];
    }
    ll res=0;
    while(1){
        memset(trace,-1,sizeof(trace));
        if(!BFS(source,sink)) break;
        ll add=1e10;
        for(int i=sink;i!=source;i=trace[i]) add=min(add,C[trace[i]][i]-F[trace[i]][i]);
        for(int i=sink;i!=source;i=trace[i]){
            F[trace[i]][i]+=add;
            F[i][trace[i]]-=add;
        }
        res+=add;
    }
    cout<<res;
}
