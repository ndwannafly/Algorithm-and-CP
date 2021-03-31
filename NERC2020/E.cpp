#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll exgcd(ll a,ll b,ll &x,ll &y){
    if(!b){
        x=1,y=0;
        return a;
    }
    ll xx,yy;
    ll g=exgcd(b,a%b,xx,yy);
    x=yy;
    y=xx-a/b*yy;
    return g;
}
int main(){
    //freopen("E.inp","r",stdin);
    int test;
    cin>>test;
    while(test--){
        ll b,d;
        cin>>b>>d;// 9,6
        ll z=b*b;//81
        ll x,y;
        ll g=exgcd(d,b,x,y);
        cout<<(b-1)/(d/g)<<'\n';
    }

}
