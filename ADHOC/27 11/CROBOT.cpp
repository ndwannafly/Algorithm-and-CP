#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
#define NMAX 105
#define pb push_back
const ll inf=1e16;
int n,m,k;
vector <pll> adj[NMAX];
ll F[101][1000005];
inline ll solve(int u){
    for(int i=1;i<=n;i++){
        for(int j=0;j<=k;j++) F[i][j]=inf;
    }
    F[u][0]=0;
    for(int i=1;i<=k;i++){
        for(int j=1;j<=n;j++){
            for(auto v:adj[j]){
                F[v.first][i]=min(F[v.first][i],F[j][i-1]+v.second);
            }
        }
    }
    return F[u][k];
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("CROBOT.inp","r",stdin);
    freopen("CROBOT.out","w",stdout);
    cin>>n>>m>>k;
    for(int i=1;i<=m;i++){
        ll u,v,w;
        cin>>u>>v>>w;
        adj[u].pb({v,w});
    }
    if(k<=1000000){
        ll res=1e16;
        for(int i=1;i<=n;i++){
            res=min(res,solve(i));
        }
        if(res==1e16) cout<<-1;
        else cout<<res;
    }
    else{
        cout<<-1;
    }
}
