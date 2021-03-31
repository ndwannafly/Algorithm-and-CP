#include <bits/stdc++.h>
using namespace std;
#define NMAX 1001
#define pb push_back
typedef long long ll;
typedef pair<ll,ll> pll;
int n,m,s,t;
ll F[NMAX][NMAX],C[NMAX][NMAX];
vector <int> adj[NMAX];
int d[NMAX],id;
int mark[NMAX];
inline bool BFS(){
    memset(d,0,sizeof(d));
    queue <int> q;
    q.push(s);
    d[s]=1;
    while(!q.empty()){
        int u=q.front();q.pop();
        if(u==t) return true;
        for(int v:adj[u]){
            if(!d[v]&&F[u][v]<C[u][v]){
                d[v]=d[u]+1;
                q.push(v);
            }
        }
    }
    return false;
}
inline ll visit(ll u,ll cost){
    if(u==t) return cost;
    if(mark[u]!=id) mark[u]=id;
    else return 0;
    for(int v:adj[u]){
        if(mark[v]==id) continue;
        if(d[v]!=d[u]+1) continue;
        if(F[u][v]>=C[u][v]) continue;
        ll x=visit(v,min(cost,C[u][v]-F[u][v]));
        if(x){
            F[u][v]+=x;
            F[v][u]-=x;
            return x;
        }
    }
    return 0;
}
int main(){
    freopen("NKFLOW.inp","r",stdin);
    cin>>n>>m>>s>>t;
    for(int i=1;i<=m;i++){
        ll u,v,w;
        cin>>u>>v>>w;
        adj[u].pb(v);
        adj[v].pb(u);
        C[u][v]+=w;
    }
    while(BFS()){
        id++;
        ll x=visit(s,1e12);
        ans+=x;
    }
    cout<<ans;
}
