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
#define NMAX 26

int n,m;
int color[NMAX],dep[NMAX];
bool visited[NMAX];
vector <int> adj[NMAX],trace[NMAX];

void enter(){
    read(n);read(m);
 //   writeln(n);writeln(m);
    for(int i=0;i<=n;i++){
        color[i]=0,dep[i]=0,visited[i]=0;
        adj[i].clear();
        trace[i].clear();
    }
    for(int i=1;i<=m;i++){
        int u,v;
        read(u);read(v);
        adj[u].pb(v);
        adj[v].pb(u);
    }
}

inline void DFS(int u,int pre,int depth){
    if(depth>1){
        trace[pre].pb(u);
    }
    dep[u]=depth;
    for(int v: adj[u]){
        if(!dep[v]) DFS(v,u,depth+1);
    }
}
inline bool check(int u){
    for(int v:adj[u]){
        if(dep[v]<dep[u]){ // v->u
            if(color[v]==color[u]) return false;
        }
    }
    return true;
}
//int cnt;
inline bool go(int u){

    if(!check(u)) return false;
//    cout<<"GO: "<<u<<'\n';
    for(int v:trace[u]){
        bool flag=0;
        for(int c=1;c<=3;c++){
            if(c!=color[u]){
                color[v]=c;
                if(go(v)){
                    flag=1;
                    break;
                }
            }
        }
        if(!flag) return false;
    }
    return true;
}
inline void mark(int u){
    if(!visited[u]) visited[u]=true;
    for(int v:adj[u]) if(!visited[v]) visited[v]=true,mark(v);
}
void progress(){
    for(int i=1;i<=n;i++){
        if(!visited[i]){
         //   cout<<"Start: "<<i<<'\n';
            DFS(i,0,1);
    //        cout<<"OUT";
            color[i]=1;

            bool flag=go(i);
     //       cout<<"DONE";
            if(!flag){
                cout<<"Khong"<<'\n';
                return;
            }
            mark(i);
        }
    }
    cout<<"Co"<<'\n';
}

int main(){
    freopen("lonto.inp","r",stdin);
    int test;
    cin>>test;
    while(test--){
        enter();
        progress();
    }
}
