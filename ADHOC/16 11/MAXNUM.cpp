#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
#define NMAX 100005
ll n,m;
ll a[NMAX];
ll L[NMAX],R[NMAX];
stack <int> s;
int main(){
    freopen("MAXNUM.inp","r",stdin);
    freopen("MAXNUM.out","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>a[i];
    for(int i=1;i<=n;i++){
        // 5 2 3 4 3 2 5
        while(!s.empty()&&a[s.top()]<a[i]) s.pop();
        if(s.size()) L[i]=s.top();
        else L[i]=0;
        s.push(i);
    }
    while(!s.empty()) s.pop();
    for(int i=n;i>=1;i--){
        while(!s.empty()&&a[s.top()]<=a[i]) s.pop();
        if(s.size()) R[i]=s.top();
        else R[i]=n+1;
        s.push(i);
    }
    ll res=0;
    for(int i=1;i<=n;i++){
        if(a[i]==m){
            res=res+(ll)((R[i]-i)*(i-L[i]));
         //   cout<<i<<" "<<L[i]<<" "<<R[i]<<'\n';
        }
    }
    cout<<res;
}
