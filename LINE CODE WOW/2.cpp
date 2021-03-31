#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pll;
pll a[100005];
int n;
int main(){
    cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i].second>>a[i].first;
    sort(a+1,a+n+1);
    int now;
    while(cin>>now){
        int cur=-1;
        int l=1,r=n;
        while(l<=r){
            int m=(l+r)>>1;
            if(a[m].first>=now){
                cur=m;
                r=m-1;
            }
            else l=m+1;
        }
        if(a[cur].first==now){
            cout<<a[cur].second<<'\n';
            continue;
        }
        if(cur==1){
            cout<<a[1].second<<'\n';
            continue;
        }
        if(cur==-1){
            cout<<a[n].second<<'\n';
            continue;
        }
        if(a[cur].first-now!=now-a[cur-1].first){
            if(a[cur].first-now>now-a[cur-1].first) cout<<a[cur-1].second<<'\n';
            else cout<<a[cur].second<<'\n';
        }
        else{
            cout<<min(a[cur-1].second,a[cur].second)<<'\n';
        }
    }
}
