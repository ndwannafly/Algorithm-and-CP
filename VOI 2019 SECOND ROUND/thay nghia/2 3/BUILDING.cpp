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
#define NMAX 17
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
int n,b[NMAX];
ll t[NMAX],siz[NMAX],f[NMAX][(1<<NMAX)];
ll res=1e16;
bool visit[NMAX][(1<<NMAX)];
vector <int> adj[NMAX];
inline bool getbit(int state,int i){
    return (state>>i)&1;
}
inline int onbit(int state,int i){
    if(!getbit(state,i)) return state+(1<<i);
    return state;
}
inline int offbit(int state,int i){
    if(getbit(state,i)) return state-(1<<i);
    return state;
}
void enter(){
    read(n);
    for(int i=1;i<=n;i++){
        read(t[i]);
    }
    for(int i=2;i<=n;i++){
        int x;
        read(x);
        adj[i].pb(x);
        adj[x].pb(i);
    }
}
inline void solve(){
    ll ans=0;
    for(int i=1;i<=n;i++){
    //    cout<<b[i]<<" ";
        if(b[i]){
            siz[i]=0;
            ans+=t[i];
            for(int v:adj[i]){
                siz[v]--;
            }
        }
    }
    for(int i=1;i<=n;i++){
        if(siz[i]!=0){
            for(int j=1;j<=n;j++) siz[j]=adj[j].size();
            return;
        }
    }
    for(int j=1;j<=n;j++) siz[j]=adj[j].size();
    res=min(res,ans);
}
inline void Try(int u){
    if(u==n+1){
        solve();
        return ;
    }
    for(int i=0;i<=1;i++){
       b[u]=i;
       Try(u+1);
    }
}
void progress(){
    //ll res=1e16;
    for(int i=1;i<=n;i++) siz[i]=adj[i].size();
    Try(1);
    writeln(res);
}
int main(){
    freopen("Building.inp","r",stdin);
    enter();
    progress();
}
