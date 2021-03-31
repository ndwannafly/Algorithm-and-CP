#include <bits/stdc++.h>
using namespace std;
#define NMAX 2005
#define pb push_back
typedef long long ll;
int n;
ll a[NMAX];
ll dp[NMAX][NMAX];
bool done[NMAX][NMAX];
inline ll F(int l,int r){
    if(l>=r) return 0;
    if(done[l][r]) return dp[l][r];
    done[l][r]=1;
    ll ans=0;
    if(a[l]<a[r]) ans=max(ans,F(l+1,r-1)+1);
    ans=max(ans,F(l+1,r));
    ans=max(ans,F(l,r-1));
    return dp[l][r]=ans;
}
int main(){
    freopen("SEQ2.inp","r",stdin);
    freopen("SEQ2.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i];
    cout<<F(1,n);
}
