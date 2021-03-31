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
typedef pair<ll,ll> pll;
#define NMAX 1005
int n;
ll a[NMAX];
ll S[NMAX];
ll dp[NMAX][NMAX][2];
inline ll get(int l,int r){
    return S[r]-S[l-1];
}
inline ll F(int l,int r,bool type){
    if(l>r) return 0;
    if(dp[l][r][type]!=-1) return dp[l][r][type];
    ll ans=-1e16;
    if(!type){
        if(l==r) return dp[l][r][type]=a[l];
        for(int i=l;i<=r;i++){
            ans=max(ans,get(l,i)+F(i+1,r,!type));
             ans=max(ans,get(i,r)+F(l,i-1,!type));
        }
        return dp[l][r][type]=ans;
    }
    else{
        if(l==r) return dp[l][r][type]=0;
        for(int i=l;i<=r;i++){
            ans=max(ans,get(l,i)+((i+1<=r)?(get(i+1,r)-F(i+1,r,!type)):0));
            ans=max(ans,get(i,r)+((i-1>=l)?(get(l,i-1)-F(l,i-1,!type)):0));
        }
        return dp[l][r][type]=get(l,r)-ans;
    }
}
int main(){
    freopen("GAMES.inp","r",stdin);
    freopen("GAMES.out","w",stdout);
    int test=3;
    while(test--){
        memset(dp,-1,sizeof(dp));
        read(n);
        for(int i=1;i<=n;i++){
            read(a[i]);
            S[i]=S[i-1]+a[i];
        }
        writeln(F(1,n,0));
    }

}
