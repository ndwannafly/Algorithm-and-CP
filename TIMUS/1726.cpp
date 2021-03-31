#include <iostream>
#include <algorithm>
using namespace std;
#define NMAX 100005
typedef long long ll;
typedef pair<ll,ll> pll;
pll a[NMAX];
ll cnt[NMAX*10],sum[NMAX];
ll scsum[NMAX*10];
ll n;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    //freopen("1726.inp","r",stdin);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i].first>>a[i].second;
        cnt[a[i].second]++;
    }
    sort(a+1,a+n+1);
    for(int i=1;i<=n;i++){
        sum[i]=sum[i-1]+a[i].first;
    }
    for(int i=1;i<=1e6;i++){
        scsum[i]=scsum[i-1]+cnt[i]*i;
    }
    for(int i=1;i<=1e6;i++){
        cnt[i]+=cnt[i-1];
    }
    ll res=0;
    for(int i=1;i<=n;i++){
        ll cur=0;
        cur+=(a[i].first*(i-1))-sum[i-1];
        cur+=(-a[i].first*(n-i))+sum[n]-sum[i];
        cur+=a[i].second*cnt[a[i].second]-scsum[a[i].second]+scsum[1000000]-scsum[a[i].second]-a[i].second*(n-cnt[a[i].second]);
        res+=cur;
    }
    res/=(n*(n-1));
    cout<<res;
}
