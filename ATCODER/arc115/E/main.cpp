#include <bits/stdc++.h>
using namespace  std;
#define  NMAX 500005
typedef long long ll;
typedef pair<ll,ll> pll;
const ll base = 998244353;
int n;
ll a[NMAX];

ll dp[NMAX];
ll sum[NMAX];
ll L[NMAX];
stack<int> s;

int main() {
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }

    for(int i=1;i<=n;i++){
        while(!s.empty() && a[s.top()] >= a[i]) s.pop();
        if(!s.empty()) L[i] = s.top();
        s.push(i);
    }
    dp[1] = a[1] % base;
    sum[1] = a[1] % base;
    for(int i=2;i<=n;i++){
        if(i&1){
            if(L[i]) {
                ll d = i - L[i];
                ll tong = ((sum[i-1] - sum[L[i]])%base + base*base)%base; // i-1 chan
                tong = - tong;
                if(d&1) dp[i] = ( (a[i] * tong % base + (a[i]-1) * dp[L[i]] %base ) + base*base ) %base;
                else dp[i] = (a[i] * tong %base - (a[i]-1)*dp[L[i]]%base + base*base) %base;
            }
            else{
                dp[i] = ((a[i] * (-sum[i-1]) %base + a[i])% base + base*base )%base;
            }
            sum[i] = ((sum[i-1] + dp[i])%base + base*base)%base;
        }
        else{
            if(L[i]){
                ll d = i - L[i];
                ll tong = ((sum[i-1] - sum[L[i]])%base+base*base)%base; // i - 1 le
                if(d&1) dp[i] = ((a[i] * tong %base + (a[i]-1)*dp[L[i]] %base ) + base * base) %base;
                else dp[i] = ((a[i] * tong %base - (a[i]-1)*dp[L[i]] %base) + base*base)%base;
            }
            else{
                dp[i] = ((a[i] * sum[i-1] %base - a[i]) %base+ base * base) %base;
            }
            sum[i] = ((sum[i-1] - dp[i])%base + base*base)%base;
        }
    }
    cout<<dp[n]<<'\n';
}
