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
typedef pair<ll,ll> pll;
typedef pair<int,int> pii;
#define NMAX 2005
#define pb push_back
ll n,m;
ll a[NMAX];
ll u,v,w;
ll C[NMAX][NMAX],F[NMAX][NMAX];
ll source,sink;
vector <pll> adj[NMAX];
pll d[NMAX];
bool inqueue[NMAX];
inline bool bfs(){
    queue <ll> q;
    memset(inqueue,0,sizeof(inqueue));
    for(int i=0;i<NMAX;i++){
        d[i]={1e16,-1};
    }
    q.push(source);
    inqueue[source]=0;
    d[source].first=0;
    while(!q.empty()){
        int u=q.front();q.pop();
        inqueue[u]=0;
        for(auto p:adj[u]){
            ll v=p.first,w=p.second;
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
    //freopen("BOXES.inp","r",stdin);
    int test;
    read(test);
    while(test--){
        read(n);
        memset(C,0,sizeof(C));
        memset(F,0,sizeof(F));
        for(int i=1;i<=n;i++){
            adj[i].clear();
            adj[i+n].clear();
            read(a[i]);
        }
        source=0;
        sink=2*n+1;
        adj[source].clear();
        adj[sink].clear();
        // 1 2 3 ... n n+1 n+2 n+3
        for(ll i=1;i<=n;i++){
            if(a[i]>1){
                for(ll j=1;j<=n;j++){
                    if(a[j]==0){
                        adj[i].pb({j+n,min(abs(i-j),n-abs(i-j))});
                        adj[j+n].pb({i,min(abs(i-j),n-abs(i-j))});
                        C[i][j+n]=1;
                    }
                }
            }
        }
        for(int i=1;i<=n;i++){
            if(a[i]>0){
                adj[source].pb({i,0});
                adj[i].pb({source,0});
                C[source][i]=a[i]-1;
           //     cout<<"edge: "<<source<<" "<<i<<" "<<a[i]-1<<'\n';
            }
        }
        for(int i=1;i<=n;i++){
            if(a[i]<=1){
                adj[i+n].pb({sink,0});
                adj[sink].pb({i+n,0});
                C[i+n][sink]=1;
            }
        }
        ll res=0;
        while(bfs()){
           // cout<<"DUC";
            ll add=1e16;
            for(int i=sink;i!=source;i=d[i].second){
                if(F[d[i].second][i]<0) add=min(add,-F[d[i].second][i]);
                else add=min(add,C[d[i].second][i]-F[d[i].second][i]);
            }
            for(int i=sink;i!=source;i=d[i].second){
                F[d[i].second][i]+=add;
                F[i][d[i].second]-=add;
            }
            res+=d[sink].first;
        //    cout<<"add: "<<d[sink].first<<'\n';
        }
        writeln(res);
    }
}
