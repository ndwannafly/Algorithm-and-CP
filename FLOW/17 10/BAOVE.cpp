#include <bits/stdc++.h>
using namespace std;
#define NMAX 5005
#define pb push_back
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
int n;
ll C[NMAX][NMAX],F[NMAX][NMAX];
int trace[NMAX];
vector <pll> adj[NMAX],radj[NMAX];
vector <int> G[NMAX];
int source,sink=1;
// souce =0 sink 101
inline bool BFS(int source,int sink){
  //  cout<<"GO :"<<source<<" "<<sink<<'\n';
    queue <int> q;
    q.push(source);
    while(!q.empty()){
        int u=q.front();q.pop();
        for(int v:G[u]){
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
ll D[NMAX],R[NMAX];
priority_queue <pll, vector <pll> , greater <pll> > pq;
void rdijkstra(){
    for(int i=0;i<NMAX;i++) R[i]=1e16;
    R[1]=0;
    pq.push({R[1],1});
    while(!pq.empty()){
        pll top=pq.top();pq.pop();
        ll val=top.first,u=top.second;
        if(val!=R[u]) continue;
        for(auto p:radj[u]){
            ll v=p.first,w=p.second;
            if(R[v]>R[u]+w){
                R[v]=R[u]+w;
                pq.push({R[v],v});
            }
        }
    }
}
void dijkstra(){
    while(!pq.empty()) pq.pop();
    for(int i=0;i<NMAX;i++) D[i]=1e16;
    D[n]=0;
    pq.push({D[n],n});
    while(!pq.empty()){
        pll top=pq.top();pq.pop();
        ll val=top.first,u=top.second;
       // cout<<u<<" "<<val<<'\n';
        if(val!=D[u]) continue;
        for(auto p:adj[u]){
            ll v=p.first,w=p.second;
            if(D[v]>D[u]+w){
                D[v]=D[u]+w;
                pq.push({D[v],v});
            }
        }
    }
}
struct data{
    ll u,v,w;
};
vector <data> edge;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("BAOVE.inp","r",stdin);
    freopen("BAOVE.out","w",stdout);
    cin>>n;
    source=n;
    ll u,v,w;
    while(cin>>u>>v>>w){
      //  C[u][v]+=w;
        adj[u].pb({v,w});
        radj[v].pb({u,w});
        edge.pb({u,v,w});
        //cout<<u<<" "<<v<<" "<<w<<'\n';
    }
    rdijkstra();
    dijkstra();
    for(auto p:edge){
        ll u=p.u,v=p.v,w=p.w;
        if(D[u]>=1e16||R[v]>=1e16) continue;
        G[u].pb(v);
        G[v].pb(u);
        C[u][v]+=w;
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
