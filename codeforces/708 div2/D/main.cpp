#include <bits/stdc++.h>
using namespace std;

#define  NMAX 5005
typedef long long ll;
ll dp[NMAX];
int n;
int tag[NMAX];
ll s[NMAX];
int main() {

    int test;
    cin>>test;
    while(test--){
        memset(dp,0,sizeof(dp));
        cin>>n;
        for(int i=1;i<=n;i++){
            cin>>tag[i];
        }
        for(int i=1;i<=n;i++){
            cin>>s[i];
        }
        ll res = 0;
        for(int i=2;i<=n;i++){
            for(int j=i-1;j>=1;j--){
                if(tag[i] == tag[j]) continue;
                ll tmp = dp[i];
                dp[i] = max(dp[i] , dp[j] + abs(s[i]-s[j]));
                dp[j] = max(dp[j] , tmp + abs(s[i]-s[j]));
                res = max(res,dp[i]);
                res = max(res,dp[j]);
                //cout<<"i: "<<i<<" "<<dp[i]<<'\n';
                //cout<<"j: "<<j<<" "<<dp[j]<<'\n';
            }
        }
        cout<<res<<'\n';
    }
}
