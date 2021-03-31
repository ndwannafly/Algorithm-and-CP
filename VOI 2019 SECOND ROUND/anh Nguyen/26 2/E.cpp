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
struct data{
    int u,v,w;
};
inline bool operator < (const data &x,const data &y){
    return x.w<y.w;
}
typedef long long ll;
typedef pair<ll,ll> pll;
typedef pair<int,int> pii;
const int inf=1e8;
#define NMAX 2001
#define pb push_back
int dx[]={0,1,0,-1};
int dy[]={-1,0,1,0};
int h,w,p,query,cnt;
int house[NMAX][NMAX],root[200005],d[NMAX][NMAX],par[200005][20],maximum[200005][20],dep[200005];
char c[NMAX][NMAX];
queue <pii> q;
vector <data> edge;
vector <pii> adj[200005];
inline int findroot(int u){
    if(root[u]<0) return u;
    return root[u]=findroot(root[u]);
}
inline void Union(int u,int v){
    if(u==v) return;
    if(root[u]<root[v]){
        root[u]+=root[v];
        root[v]=u;
    }
    else{
        root[v]+=root[u];
        root[u]=v;
    }
}
void enter(){
    read(h);read(w);read(p);read(query);
    for(int i=1;i<=h;i++){
        for(int j=1;j<=w;j++){
            scanf(" %c",&c[i][j]);
            d[i][j]=inf;
        }
    }
    for(int i=1;i<=p;i++){
      //  cout<<i<<'\n';
      //  if(i==1000) exit(0);
        int u,v;
        read(u);read(v);
        d[u][v]=0;
        q.push({u,v});
        root[i]=-1;
        house[u][v]=i;
    }
}
inline bool ingrid(int x,int y){
    return (x>=1&&x<=h&&y>=1&&y<=w);
}
inline void DFS(int u,int pa){
    for(auto v:adj[u]){
        if(v.first!=pa){
            dep[v.first]=dep[u]+1;
            par[v.first][0]=u;
            maximum[v.first][0]=v.second;
            DFS(v.first,u);
        }
    }
}
void make_edge(){
    while(!q.empty()){
        pii top=q.front();q.pop();
        int u=top.first,v=top.second;
        //cout<<u<<" "<<v<<'\n';
        for(int i=0;i<4;i++){
            int x=u+dx[i],y=v+dy[i];
            if(ingrid(x,y)&&c[x][y]!='#'){
          //      cout<<"GO: "<<x<<" "<<y<<'\n';
                if(d[x][y]>d[u][v]+1){
                    d[x][y]=d[u][v]+1;
                    house[x][y]=house[u][v];
                    q.push({x,y});
                    continue;
                }
                if(d[x][y]==d[u][v]+1){
        //            cout<<house[x][y]<<" "<<house[u][v]<<" "<<d[u][v]*2+1<<'\n';
                    edge.pb({house[x][y],house[u][v],d[u][v]*2+1});
                    continue;
                }
                if(d[x][y]==d[u][v]){
      //              cout<<house[x][y]<<" "<<house[u][v]<<" "<<d[u][v]*2<<'\n';
                    edge.pb({house[x][y],house[u][v],d[u][v]*2});
                    continue;
                }
            }
        }
    }
    //exit(0);
    sort(edge.begin(),edge.end());
    for(int i=0;i<edge.size();i++){
        int u=edge[i].u,v=edge[i].v,w=edge[i].w;
        //cout<<u<<" "<<v<<" "<<w<<'\n';
        int pu=findroot(u),pv=findroot(v);
        if(pu!=pv){
            Union(pu,pv);
            cnt++;
            adj[u].pb({v,w});
            adj[v].pb({u,w});
            //cout<<"ADD: "<<u<<" "<<v<<" "<<w<<'\n';
            if(cnt==p-1) break;
        }
    }
    //exit(0);
}
void init_lca(){
    for(int j=1;(1<<j)<=p;j++){
        for(int i=1;i<=p;i++){
            if(par[i][j-1]!=0){
                par[i][j]=par[par[i][j-1]][j-1];
                maximum[i][j]=max(maximum[i][j-1],maximum[par[i][j-1]][j-1]);
            }
        }
    }
}
inline int get(int u,int v){
    if(dep[u]<dep[v]) swap(u,v);
    //cout<<u<<" "<<v<<'\n';
    int res=0;
    for(int i=19;i>=0;i--){
        if(dep[par[u][i]]>=dep[v]){
            res=max(res,maximum[u][i]);
            u=par[u][i];
        }
    }
    if(u==v) return res;
    for(int i=19;i>=0;i--){
        if(par[u][i]!=par[v][i]&&par[u][i]!=0){
            res=max(maximum[u][i],res);
            res=max(maximum[v][i],res);
            u=par[u][i];
            v=par[v][i];
        }
    }
    return max(res,max(maximum[v][0],maximum[u][0]));
}
void progress(){
    make_edge();
    for(int i=1;i<=p;i++){
        if(dep[i]==0){
            dep[i]=1;
            DFS(i,i);
        }
    }
    init_lca();
    while(query--){
        int u,v;
        read(u);read(v);
        if(findroot(u)!=findroot(v)){
            writeln(-1);
            continue;
        }
        else{
            writeln(get(u,v));
        }
    }
}
int main(){
//    ios_base::sync_with_stdio(0);
  //  cin.tie(0);
  //  freopen("E.inp","r",stdin);
  //  freopen("E.out","w",stdout);
    enter();
    progress();
}
