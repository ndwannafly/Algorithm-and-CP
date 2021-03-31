#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,m,p,q;
int main(){
    freopen("josephus.inp","r",stdin);
    freopen("josephus.out","w",stdout);
    cin>>n>>m>>p>>q;
    ll now=n*m;
    ll nn=n+1,mm=m-1;
    while(now>n){
        now=now+(now-nn)/mm-n;
    }
    ll res=(now+p)%n-1;
    cout<<res<<" ";
    cout<<(p+(q-res)+n)%n;
}
