#include <bits/stdc++.h>
using namespace std;

typedef long double ld;
typedef long long ll;
#define  pb push_back

vector <ll> X;
vector <ll> Y;
int n;

int main() {
    auto compare = [](const ll  & x, const ll & y) -> bool{
        return abs(x) < abs(y);
    };

    int test;
    cin>>test;
    while(test--){
        cin>>n;
        X.clear();
        Y.clear();
        for(int i=1;i<=2*n;i++){
            ll x,y;
            cin>>x>>y;
            if(!x) Y.pb(y);
            if(!y) X.pb(x);
        }
        sort(X.begin(),X.end(), compare);
        sort(Y.begin(), Y.end(), compare);
        ld res = 0;
        for(int i=0;i<n;i++) {
            res = res + sqrt(X[i]*X[i] + Y[i]*Y[i]);
        }

        cout<<setprecision(15)<<fixed<<res<<'\n';
        /*for(ld x : X) cout<<x<<'\n';
        for(ld y : Y) cout<<y<<'\n';*/
    }
}
