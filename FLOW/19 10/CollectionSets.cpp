#include <bits/stdc++.h>
using namespace std;
template <typename T> inline void read(T &x){
    bool nega=0;
    char c;
    while((!isdigit(c=getchar()))&&(c!='-'));
    if(c=='-'){
        nega=1;
        c=getchar();
    }
    x=c-48;
    while(isdigit(c=getchar())) x=x*10+c-48;
    if(nega) x=-x;
}
template <typename T> inline void display(T x){
    if(x>9) display(x/10);
    putchar(x%10+48);
}
template <typename T> inline void write(T x){
    if(x<0){
        putchar('-');
        x=-x;
    }
    display(x);
}
template <typename T> inline void writeln(T x){
    write(x);
    putchar('\n');
}
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
#define NMAX 605
#define pb push_back
vector <int> adj[NMAX];
ll C[NMAX][NMAX],F[NMAX][NMAX],trace[NMAX];
int n;
int source=0,sink;
inline bool BFS(){
    queue <int> q;
    q.push(source);
  //  cout<<source<<'\n';
    while(!q.empty()){
        int u=q.front();q.pop();
    //    cout<<u<<" ";
        for(int v:adj[u]){
            if(trace[v]==-1&&F[u][v]<C[u][v]){
                trace[v]=u;
                if(v==sink) return true;
                q.push(v);
            }
        }
    }
    return false;
}
int main(){
    freopen("collectionsets.inp","r",stdin);
    freopen("collectionsets.out","w",stdout);
    read(n);
    sink=2*n+1;
    for(int i=1;i<=n;i++){
        ll num;
        read(num);
        while(num--){
            ll x;
            read(x);
            adj[i].pb(x+n);
            adj[x+n].pb(i);
            C[i][x+n]+=1e16;
        }
    }
    ll res=0;
    for(int i=1;i<=n;i++){
        ll x;
        read(x);
        adj[source].pb(i);
        adj[i].pb(source);
        C[source][i]+=1e9-x;
        res-=1e9-x;
        adj[sink].pb(i+n);
        adj[i+n].pb(sink);
        C[i+n][sink]+=1e9;
    }
    while(1){
        memset(trace,-1,sizeof(trace));
        if(!BFS()) break;
        ll add=1e18;
        for(int i=sink;i!=source;i=trace[i]){
            add=min(add,C[trace[i]][i]-F[trace[i]][i]);
        }
        for(int i=sink;i!=source;i=trace[i]){
            F[trace[i]][i]+=add;
            F[i][trace[i]]-=add;
        }
        res+=add;
    }
    writeln(res);

}
