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
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
#define NMAX 50005
#define pb push_back
const ll inf=1e16;
int type;
ll Nx,Mx,Ny,My;
vector <pll> Gx[NMAX],Gy[NMAX],Gd[NMAX];
ll F[NMAX],G[NMAX];
priority_queue < pll, vector <pll> , greater <pll> > pq;
inline void dijkstraA(){
    while(!pq.empty()) pq.pop();
    for(int i=0;i<NMAX;i++) F[i]=inf;
    F[1]=0;
    pq.push({0,1});
    while(!pq.empty()){
        pll top=pq.top();pq.pop();
        ll val=top.first,u=top.second;
        if(F[u]!=val) continue;
        for(auto P:Gx[u]){
            ll v=P.first,w=P.second;
            if(F[v]>F[u]+w){
                F[v]=F[u]+w;
                pq.push({F[v],v});
            }
        }
    }
}
inline void dijkstraB(){
    while(!pq.empty()) pq.pop();
    for(int i=0;i<NMAX;i++) G[i]=inf;
    G[1]=0;
    pq.push({0,1});
    while(!pq.empty()){
        pll top=pq.top();pq.pop();
        ll val=top.first,u=top.second;
        if(G[u]!=val) continue;
        for(auto P:Gy[u]){
            ll v=P.first,w=P.second;
            if(G[v]>G[u]+w){
                G[v]=G[u]+w;
                pq.push({G[v],v});
            }
        }
    }
}
struct data{
    ll u,v,w;
    inline bool operator < (const data &other){
        return w<other.w;
    }
};
vector <data> edge;
class{
private:
    int p[1000000];
public:
    inline void init(){
        memset(p,-1,sizeof(p));
    }
    inline int findroot(int u){
        if(p[u]<0) return u;
        return p[u]=findroot(p[u]);
    }
    inline void Union(int u,int v){
        if(p[u]<p[v]){
            p[u]+=p[v];
            p[v]=u;
        }
        else{
            p[v]+=p[u];
            p[u]=v;
        }
    }
}DSU;
inline ll C(int x,int y){
    return (x-1)*Ny+y;
}
int main(){
    freopen("ABD.inp","r",stdin);
    freopen("ABD.out","w",stdout);
    read(type);
    read(Nx);read(Mx);
    for(int i=1;i<=Mx;i++){
        ll u,v,w;
        read(u);read(v);read(w);
        Gx[u].pb({v,w});
        Gx[v].pb({u,w});
    }
    read(Ny);read(My);
    for(int i=1;i<=My;i++){
        ll u,v,w;
        read(u);read(v);read(w);
        Gy[u].pb({v,w});
        Gy[v].pb({u,w});
    }
    if(type==1){
        dijkstraA();
        dijkstraB();
        writeln(F[Nx]+G[Ny]);
    }
    else{
        DSU.init();
        // dinh (i,j) = dinh (i+j*Ny)
        for(int i=1;i<=Nx;i++){
            for(int j=1;j<=Ny;j++){
                for(auto P:Gy[j]){ // (i,j) -> (i,v)
                    edge.pb({C(i,j),C(i,P.first),P.second});
                }
                for(auto P:Gx[i]){ // (i,j) -> (v,j)
                    edge.pb({C(i,j),C(P.first,j),P.second});
                }
            }
        }
        sort(edge.begin(),edge.end());
        int cities=Nx*Ny,cnt=0;
        ll res=0;
        for(int i=0;i<edge.size();i++){
            ll u=edge[i].u,v=edge[i].v,w=edge[i].w;
            int pu=DSU.findroot(u),pv=DSU.findroot(v);
            if(pu!=pv){
                DSU.Union(pu,pv);
                res+=w;
                cnt++;
                if(cnt==cities-1){
                    writeln(res);
                    return 0;
                }
            }
        }
    }
}
