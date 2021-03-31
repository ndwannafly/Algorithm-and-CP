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
#define NMAX 30005
ll n,k;
ll a[NMAX];
ll F[201][NMAX][4];
const ll inf=1e10;
void enter(){
    read(n);read(k);
    for(int i=1;i<=n;i++){
        read(a[i]);
    }
}
void progress(){
    for(int i=0;i<=k;i++){
        for(int j=0;j<=n;j++){
            for(int p=0;p<4;p++) F[i][j][p]=-inf;
        }
    }
    for(int i=1;i<=k;i++){
        for(int j=1;j<=n;j++){
            ll add=((i>1&&i<k)?2:1)*a[j];
            F[i][j][0]=max(F[i][j-1][0],max(F[i-1][j-1][1],F[i-1][j-1][3]))+add; // +
            if(i==1) F[i][j][0]=max(F[i][j][0],add);
            F[i][j][1]=max(F[i][j-1][1],max(F[i-1][j-1][0],F[i-1][j-1][2]))-add; // -
            if(i==1) F[i][j][1]=max(F[i][j][1],-add);
            F[i][j][2]=max(F[i-1][j-1][2],max(F[i][j-1][2],F[i-1][j-1][0])); // max prev +
            F[i][j][3]=max(F[i-1][j-1][3],max(F[i-1][j-1][1],F[i][j-1][3])); // max prev -
        }
    }
    ll ans=-inf;
    for(int i=k;i<=n;i++) ans=max(ans,max(F[k][i][0],F[k][i][1]));
    writeln(ans);
}
int main(){
   // freopen("E2.inp","r",stdin);
    enter();
    progress();
}
