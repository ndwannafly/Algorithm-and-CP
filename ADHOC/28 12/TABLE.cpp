#include <bits/stdc++.h>
using namespace std;
template <typename T> inline void read (T &x){
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
        x=-x;
        putchar('-');
    }
    writep(x);
}
template <typename T>inline void writeln(T x){
    write(x);
    putchar('\n');
}
#define NMAX 2005
#define pb push_back
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
ll a[NMAX][NMAX];
ll base,n,m;
ll xDiagon[5*NMAX],yDiagon[5*NMAX];
const int add=2000;
int main(){
    freopen("TABLE.inp","r",stdin);
    freopen("TABLE.out","w",stdout);
    read(n);read(m);read(base);
    for(int i=1;i<=m;i++){
        read(a[1][i]);
        a[1][i]%=base;
        xDiagon[(1-i)+add]+=a[1][i];
        yDiagon[1+i+add]+=a[1][i];
        xDiagon[(1-i)+add]%=base;
        yDiagon[1+i+add]%=base;
    }
    for(int i=1;i<=m;i++){
        a[2][i]+=a[1][i-1]+a[1][i]+a[1][i+1];
        xDiagon[(2-i)+add]+=a[2][i];
        xDiagon[(2-i)+add]%=base;
        yDiagon[(2+i)+add]+=a[2][i];
        yDiagon[(2+i)+add]%base;
    }
    for(int i=3;i<=n;i++){
        for(int j=1;j<=m;j++){
            a[i][j]=2*a[i-1][j]+xDiagon[(i-j)+add]+yDiagon[(i+j)+add];
            a[i][j]%=base;
            xDiagon[(i-j)+add]+=a[i][j];
            xDiagon[(i-j)+add]%base;
            yDiagon[(i+j)+add]+=a[i][j];
            yDiagon[(i+j)+add]%=base;
        }
    }
    for(int i=1;i<=m;i++){
        write(a[n][i]);putchar(' ');
    }
}
