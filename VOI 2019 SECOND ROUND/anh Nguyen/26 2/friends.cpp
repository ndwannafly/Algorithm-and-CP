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
typedef pair<ll,ll> pll;
#define NMAX 100005
#define pb push_back
struct data{
    int v,id;
    data(int v,int id){
        this->v=v;
        this->id=id;
    }
};

ll n,m;
int p[NMAX];
int siz[NMAX];
bool mark_edge[3*NMAX],visited[NMAX];
vector <data> edge[NMAX];
inline int findroot(int u){
    if(p[u]==u) return u;
    return p[u]=findroot(p[u]);
}
inline void Union(int u,int v){
    //cout<<"U: "<<u<<" "<<v<<'\n';
    u=findroot(u);v=findroot(v);
    if(u==v) return ;
    siz[u]+=siz[v];
    siz[v]=0;
    p[v]=u;
}
void enter(){
    read(n);read(m);
    for(int i=1;i<=m;i++){
        int u,v;
        read(u);read(v);
        edge[u].pb(data(v,i));
    }
    for(int i=1;i<=n;i++){
        siz[i]=1;
        p[i]=i;
    }
}
inline void DFS(int u){
    if(visited[u]) return;
    visited[u]=true;
    for(int i=0;i<edge[u].size();i++){
        int v=edge[u][i].v;
        Union(u,v);
        mark_edge[edge[u][i].id]=true;
        DFS(v);
    }
}
void progress(){
    for(int i=1;i<=n;i++){
//        cout<<i<<" "<<edge[i].size()<<'\n';
        if(edge[i].size()>=2){
            for(int j=0;j<edge[i].size()-1;j++){
              //  cout<<edge[i][j].v<<" "<<edge[i][j+1].v<<'\n';
                Union(edge[i][j].v,edge[i][j+1].v);
            }
        }
    }
    //exit(0);
    for(int i=1;i<=n;i++){
        if(edge[i].size()>=2){
            for(int j=0;j<edge[i].size();j++){
                int v=edge[i][j].v;
                DFS(v);
            }
        }
    }
    ll ans=0;
    for(int i=1;i<=m;i++){
        if(!mark_edge[i]) ans++;
    }
    for(int i=1;i<=n;i++){
        ans+=(ll)(siz[i])*(siz[i]-1);
    }
    writeln(ans);
}
int main(){
   // freopen("friends.inp","r",stdin);
    enter();
    progress();
}
