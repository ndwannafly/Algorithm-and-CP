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
#define NMAX 1005
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
const ll inf=1e10;
ll n,m,sum;
ll dp[NMAX][NMAX];
ll col[NMAX][NMAX],row[NMAX][NMAX],a[NMAX][NMAX];
void enter(){
    read(m);read(n);
    for(int i=0;i<NMAX;i++) for(int j=0;j<NMAX;j++) dp[i][j]=-inf;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++) read(a[i][j]),sum+=a[i][j];
    }
 //   exit(0);
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++)
            row[i][j]+=(row[i][j-1]+a[i][j]);
    }
    for(int i=1;i<=m;i++){
        for(int j=1;j<=n;j++) col[i][j]+=(col[i][j-1]+a[j][i]);
    }
}
inline bool ingrid(int x,int y){
    return (x>=0&&x<=n&&y>=0&&y<=m);
}
inline ll F(int x,int y){
    if(x==n&&y==m){
        dp[x][y]=0;
        return 0;
    }
    if(dp[x][y]!=-inf) return dp[x][y];
    if(ingrid(x,y+1)) dp[x][y]=max(dp[x][y],-F(x,y+1));
    ll add=row[x+1][m]-2*row[x+1][y];
    if(ingrid(x+1,y)) dp[x][y]=max(dp[x][y],-F(x+1,y)+(((x+y)%2==0)?add:-add));
    return dp[x][y];
}
void progress(){
    writeln(abs(F(0,0)));
}
int main(){
    enter();
    progress();
}
