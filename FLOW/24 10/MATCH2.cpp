#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
#define NMAX 405
#define pb push_back
int n,m;
int u,v,w;
int C[NMAX][NMAX],F[NMAX][NMAX];
int source,sink;
vector <pii> adj[NMAX];
pii d[NMAX];
bool inqueue[NMAX];
inline bool bfs(){
    queue <int> q;
    memset(inqueue,0,sizeof(inqueue));
    for(int i=0;i<NMAX;i++){
        d[i]={1e9,-1};
    }
    q.push(source);
    inqueue[source]=0;
    d[source].first=0;
    while(!q.empty()){
        int u=q.front();q.pop();
        inqueue[u]=0;
        for(auto p:adj[u]){
            int v=p.first,w=p.second;
            if(C[u][v]>F[u][v]){
                if(d[v].first>d[u].first+(F[u][v]<0?-w:w)){
                    d[v].first=d[u].first+(F[u][v]<0?-w:w);
                    d[v].second=u;
                  //  cout<<u<<" "<<v<<" "<<w<<'\n';
                    if(!inqueue[v]){
                        inqueue[v]=1;
                        q.push(v);
                    }
                }
            }
        }
    }
    return d[sink].second!=-1;
}
int main(){
   // freopen("MATCH2.inp","r",stdin);
    cin>>n;
    while(cin>>u>>v>>w){
        C[u][v+n]++;
        adj[u].pb({v+n,w});
        adj[v+n].pb({u,w});
    }
    for(int i=1;i<=n;i++){
        adj[0].pb({i,0});
        adj[i].pb({0,0});
        C[0][i]=1;
        C[i][0]=1;
        adj[2*n+1].pb({i+n,0});
        adj[i+n].pb({2*n+1,0});
        C[i+n][2*n+1]=1;
        C[2*n+1][i+n]=1;
    }
    source=0;
    sink=2*n+1;
    int res=0;
    while(bfs()){
       // cout<<"DUC";
        int add=1e9;
        for(int i=sink;i!=source;i=d[i].second){
            if(F[d[i].second][i]<0) add=min(add,-F[d[i].second][i]);
            else add=min(add,C[d[i].second][i]-F[d[i].second][i]);
        }
        for(int i=sink;i!=source;i=d[i].second){
            F[d[i].second][i]+=add;
            F[i][d[i].second]-=add;
        }
        res+=d[sink].first;
      //  cout<<"add: "<<add<<'\n';
    }
    cout<<res<<'\n';
    for(int i=1;i<=n;i++){
        for(int j=n+1;j<=2*n;j++){
            if(C[i][j]!=0){
                if(F[i][j]==C[i][j]) cout<<i<<" "<<j-n<<'\n';
            }
        }
    }
}
