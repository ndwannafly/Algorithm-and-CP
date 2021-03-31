#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
vector<ll> sq;
map<ll,bool> isFree;
int main(){
    //freopen("D.inp","r",stdin);
    for(ll i=2;i*i<=1e9;i++){
        sq.push_back(i*i);
    }
    ll l,r;
    cin>>l>>r;
    for(ll i=l;i<=r;i++){
        for(ll x:sq){
            if(i%x==0){
                isFree[i]=1;
                break;
            }
        }
    }
    int cnt=0;
    for(ll a=l;a<=r;a++){
        if(isFree[a]) continue;
        for(ll b=a+1;b<=r;b++){
            if(isFree[b]) continue;
            if(__gcd(a,b)==1){
                ++cnt;
            }
        }
    }
    cout<<cnt;
}
