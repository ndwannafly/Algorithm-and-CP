#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pll;
typedef pair<pll,ll> data;
map<data,bool> done;
int main(){
    freopen("NUMTRIAN.inp","w",stdout);
    int n=300000;
    cout<<n<<'\n';
    for(int i=1;i<=n;i++){
        while(1){
            ll a=rand()-rand(),b=rand()-rand(),c=rand()-rand();
            if(!done[{{a,b},c}]){
                cout<<a<<" "<<b<<" "<<c<<'\n';
                done[{{a,b},c}]=1;
                break;
            }
        }
    }
}
