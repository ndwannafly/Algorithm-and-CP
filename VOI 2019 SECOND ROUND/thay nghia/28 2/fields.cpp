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

#define pb push_back
#define mp make_pair
#define NMAX 701

int dx[]={0,1,0,-1};
int dy[]={-1,0,1,0};

struct data{
    int x,y,id;
};
int n,m;
int a[NMAX][NMAX];
int add[NMAX][NMAX];
queue <data> q;
bool mark[NMAX][NMAX];
vector <pii> visit;
void enter(){
    read(n);read(m);
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            cin>>a[i][j];
        }
    }
}
inline bool ingrid(int u,int v){
    return (u>=1&&u<=n&&v>=1&&v<=m);
}
inline void boom(int i,int j){
    q.push({i,j,a[i][j]});
    mark[i][j]=true;
    visit.pb(pii(i,j));
    while(!q.empty()){
        data top=q.front();q.pop();
        int x=top.x,y=top.y,id=top.id-1;
        for(int i=0;i<4;i++){
            int u=x+dx[i],v=y+dy[i];
            if(id!=0&&ingrid(u,v)&&!mark[u][v]){
                add[u][v]+=id;
                mark[u][v]=true;
                visit.pb(pii(u,v));
                q.push({u,v,id});
            }
        }
    }
//    for(int i=1;i<=n;i++){
//        for(int j=1;j<=m;j++){
//            cout<<a[i][j]+add[i][j]<<" ";
//        }
//        cout<<'\n';
//    }
//    cout<<'\n';
    for(int i=0;i<visit.size();i++){
        mark[visit[i].first][visit[i].second]=false;
    }
    visit.clear();
}

void progress(){
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(a[i][j]!=0) boom(i,j);
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            write(a[i][j]+add[i][j]);putchar(' ');
        }
        putchar('\n');
    }
}

int main(){
    freopen("fields.inp","r",stdin);
    freopen("fields.out","w",stdout);
    enter();
    progress();
}
