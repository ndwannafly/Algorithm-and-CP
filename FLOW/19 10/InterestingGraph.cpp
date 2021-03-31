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
#define NMAX 505
#define pb push_back
int n,m;
vector <int> G[NMAX];
int visited[NMAX];
int married[NMAX];
bool E[NMAX][NMAX];
int id;
int center;
inline bool DFS(int u){
    if(visited[u]!=id) visited[u]=id;
    else return false;
    for(int v:G[u]){
        if(v!=center){
            if(!married[v]||DFS(married[v])){
                married[v]=u;
                return true;
            }
        }
    }
    return false;
}
inline ll solve(){
    memset(married,0,sizeof(married));
    memset(visited,0,sizeof(visited));
    ll add=0,Remove=0,matching=0;
    for(int i=1;i<=n;i++){
        if(!visited[i]&&i!=center){
            id++;
            matching+=DFS(i);
        }
    }
  //  cout<<matching<<'\n';
    for(int i=1;i<=n;i++){
        if(!E[center][i]) add++;
        if(i!=center){
            if(!E[i][center]) add++;
            for(int j=1;j<=n;j++){
                if(j!=center){
                    if(E[i][j]&&married[j]!=i){
                        Remove++;
                    }
                }
            }
        }
    }
    //cout<<add<<" "<<Remove<<" "<<matching<<'\n';
    return add+Remove+n-1-matching;
}
int main(){
    freopen("InterestingGraph.inp","r",stdin);
    freopen("InterestingGraph.out","w",stdout);
    read(n);read(m);
    for(int i=1;i<=m;i++){
        int u,v;
        read(u);read(v);
        E[u][v]=1;
        G[u].pb(v);
    }
    ll ans=1e16;
    for(int i=1;i<=n;i++){
        center=i;
        ans=min(ans,solve());
    }
    writeln(ans);
}
