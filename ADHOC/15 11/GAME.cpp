#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
#define NMAX 705
ll dp[NMAX][NMAX];
int n;
ll a[NMAX];
inline ll F(int l,int r){
    if(dp[l][r]!=-1) return dp[l][r];
    dp[l][r]=0;
    for(int i=l+1;i<r;i++){
        dp[l][r]=max(dp[l][r],F(l,i)+F(i,r)+a[i]*(a[l]+a[r]));
    }
    return dp[l][r];
}
int main(){
    freopen("GAME.inp","r",stdin);
    freopen("GAME.out","w",stdout);
    memset(dp,-1,sizeof(dp));
    cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i];
    cout<<F(1,n)<<'\n';
}
