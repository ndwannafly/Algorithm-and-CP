#include <bits/stdc++.h>
using namespace std;
#define NMAX 105
#define pb push_back
typedef long long ll;
typedef pair<ll,ll> pll;
int n,m,k,source,sink;
vector <pll> adj[NMAX];
ll C[NMAX][NMAX],F[NMAX][NMAX];
pll d[NMAX];
bool inqueue[NMAX];
inline bool ford_bellman(){
   // cout<<"GO: "<<'\n';
    for(int i=0;i<NMAX;i++) d[i]={1e16,0};
    queue <int> q;
    memset(inqueue,0,sizeof(inqueue));
    q.push(s);
    inqueue[s]=1;
    d[s].first=0;
    while(!q.empty()){
        int u=q.front();q.pop();
        inqueue[u]=0;
        for(auto pp:adj[u]){
            ll v=pp.first,w=pp.second;
            if(C[u][v]>F[u][v]){
                ll neww=d[u].first+(F[u][v]>=0?w:-w);
              //  cout<<u<<" "<<v<<" "<<w<<" "<<neww<<" "<<d[v].first<<'\n';
                if(d[v].first>neww){
                    d[v].first=neww;
                    d[v].second=u;
                    if(!inqueue[v]){
                        inqueue[v]=1;
                        q.push(v);
                    }
                }
            }
        }
    }
    if(d[t].second!=0) return true;
    return false;
}
vector <pll> edge;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    //freopen("mincost.inp","r",stdin);
    cin>>n>>m>>k>>s>>t;
    if(s==t){
        cout<<0<<'\n';
        cout<<0<<" "<<0<<" "<<0<<'\n';
        return 0;
    }
    //cout<<"DUC";
    for(int i=1;i<=m;i++){
        ll u,v,c,d;
        cin>>u>>v>>c>>d;
        edge.pb({u,v});
        edge.pb({v,u});
        adj[u].pb({v,c});
        adj[v].pb({u,c});
        C[u][v]+=d;
        C[v][u]+=d;
    }
    ++n;
    C[n][s]=k;
    adj[n].pb({s,0});
    s=n;
    ll flow=0;
    ll res=0;
    bool flag=0;
    while(ford_bellman()){
        ll add=1e16;
        for(int i=t;i!=s;i=d[i].second){
            if(F[d[i].second][i]>=0) add=min(add,C[d[i].second][i]-F[d[i].second][i]);
            else add=min(add,-F[d[i].second][i]);
        }
        for(int i=t;i!=s;i=d[i].second){
            F[d[i].second][i]+=add;
            F[i][d[i].second]-=add;
        }
        flow+=add;
        res+=add*d[t].first;
       // cout<<flow<<" "<<add<<'\n';
    }
    if(flow<k){
        cout<<-1;
        return 0;
    }
    cout<<res<<'\n';
    for(auto P:edge){
     //   cout<<P.first<<" "<<P.second<<" "<<F[P.first][P.second]<<'\n';
        if(F[P.first][P.second]>0){
            cout<<P.first<<" "<<P.second<<" "<<F[P.first][P.second]<<'\n';
        }
    }
    cout<<0<<" "<<0<<" "<<0<<'\n';
}
