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
#define NMAX 300001
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

map <int,int> mymap[NMAX];
int n,m,k;
int color[NMAX],res;
vector <int> adj[NMAX];
void enter(){
    read(n);read(m);read(k);
    for(int i=1;i<=n;i++) read(color[i]);
    adj[1].pb(2);
    adj[2].pb(1);
    mymap[1][color[2]]++;
    mymap[2][color[1]]++;
    for(int i=3;i<=n;i++){
        int x;read(x);
        adj[i].pb(x);
        adj[x].pb(i);
        mymap[x][color[i]]++;
        mymap[i][color[x]]++;
        if(color[x]==color[i]) res++;
    }
}
void progress(){
    for(int i=1;i<=m;i++){
        int light,col;
        read(light);read(col);
     //   cout<<mymap[light][color[light]]<<" "<<mymap[light][col]<<'\n';
        res-=mymap[light][color[light]];
        res+=mymap[light][col];
        for(int v:adj[light]){
            mymap[v][color[light]]--;
            mymap[v][col]++;
        }
        color[light]=col;
        writeln(res);
    }

}
int main(){
    freopen("DECORATION.inp","r",stdin);
    enter();
    progress();
}
