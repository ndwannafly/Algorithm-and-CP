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
typedef long long ll;
struct data{
    ll u,v,w;
};
#define NMAX 100005
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
vector <ll> adj1[NMAX];
vector <data> adj2;
ll children[NMAX],n;
data id[NMAX];
ll weight[NMAX];
inline void DFS(ll x,ll parent){
    children[x]=1;
    for (int i=0; i<adj1[x].size();i++){
        ll y=adj1[x][i];
        if (y==parent) continue;
        DFS(y,x);
        children[x]+=children[y];
    }
}
ll res=0;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("network.inp","r",stdin);
    freopen("network.out","w",stdout);
    cin>>n;
    for(int i=1;i<n;i++){
        ll u,v,w;
        cin>>u>>v>>w;
        id[i]={u,v,w};
        weight[i]=w;
        adj2.push_back({u,v,w});
        adj1[u].push_back(v); adj1[v].push_back(u);
    }
    DFS(1,0);
    for(int i=0;i<adj2.size();i++){
        int u=adj2[i].u,v=adj2[i].v;
        res+=(ll)min(children[u],children[v])*(ll)(n-min(children[u],children[v]))*adj2[i].w;
    }
    int query;
    cin>>query;
    ll div=n*(n-1)*(n-2)/6;
    res=res*(n-2);
    while(query--){
        ll x,w;
        cin>>x>>w;
        ll u=id[x].u,v=id[x].v;
        res-=min(children[u],children[v])*(ll)(n-min(children[u],children[v]))*weight[x]*(n-2);
        res+=min(children[u],children[v])*(ll)(n-min(children[u],children[v]))*w*(n-2);
        weight[x]=w;
        cout<<setprecision(6)<<fixed<<(long double)(res)/div<<'\n';
    }
}
