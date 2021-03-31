#include <iostream>
using namespace std;
int n;
int a[60005];
int sum[60005];
int mx[60005];
int mn[60005];
int res;
int main(){
    //freopen("1296.inp","r",stdin);
    cin>>n;
    for(int i=1;i<=n;i++){
        mx[i]=-1e9;
        mn[i]=1e9;
    }
    for(int i=1;i<=n;i++){
        cin>>a[i];
        sum[i]=sum[i-1]+a[i];
        mn[i]=min(mn[i-1],sum[i]);
        res=max(res,sum[i]-mn[i]);
    }
    cout<<res;
}
