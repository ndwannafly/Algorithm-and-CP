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
int main(){
    freopen("TABLE.inp","r",stdin);
    read(n);read(m);read(base);
    for(int i=1;i<=m;i++){
        read(a[1][i]);
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            for(int k=1;k<=i-1;k++){
                for(int t=j-k;t<=j+k;t++){
                    a[i][j]+=a[i-k][t];
                    a[i][j]%=base;
                }
            }
        }
    }
    for(int i=1;i<=m;i++){
        cout<<a[n][i]<<" ";
    }
}
