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
#define pb push_back
#define NMAX 1005
typedef long long ll;
typedef pair<int,int> pii;
int n,m;
int F[NMAX][NMAX],G[NMAX][NMAX];
int a[NMAX][NMAX];
int dp[NMAX][NMAX];
inline int getF(int x,int y,int z,int t){
    return F[z][t]-F[x-1][t]-F[z][y-1]+F[x-1][y-1];
}
inline int getG(int x,int y,int z,int t){
    return G[z][t]-G[x-1][t]-G[z][y-1]+G[x-1][y-1];
}
int main(){
    freopen("NUMTAB.inp","r",stdin);
    freopen("NUMTAB.out","w",stdout);
    read(n);read(m);
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            read(a[i][j]);
            F[i][j]=F[i-1][j]+F[i][j-1]-F[i-1][j-1]+(a[i][j]!=0);
            G[i][j]=G[i-1][j]+G[i][j-1]-G[i-1][j-1]+(a[i][j]!=2);
        }
    }
    if(n<=100&&m<=100){
        for(int i=1;i<=n;i++){
            for(int j=i;j<=n;j++){
                dp[i][j]=max(dp[i][j],dp[i][j-1]);
                for(int p=1;p<=m;p++){
                    int now=i;
                    if(a[j][p]!=0){ // F
                        for(int q=p;q<=m;q++){
                            if(a[j][q]==0) break;
                            while(now<=j&&getF(now,p,j,q)!=((j-now+1)*(q-p+1))) ++now;
                            if(now<=j&&getF(now,p,j,q)==(j-now+1)*(q-p+1)) dp[i][j]=max(dp[i][j],getF(now,p,j,q));
                        }
                    }
                }
                for(int p=1;p<=m;p++){
                    int now=i;
                    if(a[j][p]!=2){ // F
                        for(int q=p;q<=m;q++){
                            if(a[j][q]==2) break;
                            while(now<=j&&getG(now,p,j,q)!=((j-now+1)*(q-p+1))) ++now;
                            if(now<=j&&getG(now,p,j,q)==(j-now+1)*(q-p+1)) dp[i][j]=max(dp[i][j],getG(now,p,j,q));
                        }
                    }
                }
               // cout<<i<<" "<<j<<" "<<dp[i][j]<<'\n';
            }
        }
        int test;
        read(test);
        while(test--){
            int X,Y;
            read(X);read(Y);
            writeln(dp[X][Y]);
        }
    }
    else{
        int test;
        read(test);
        while(test--){
            int X,Y;
            read(X);read(Y);
            writeln(1LL*(Y-X+1)*m);
        }
    }
}
