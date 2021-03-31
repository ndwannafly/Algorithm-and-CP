#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll a,b,k;
int main(){
    cin>>a>>b>>k;
    for(ll i=a;i<=b;i++){
        ll cur = i*(i-1)/2;
        for(int j=1;j<=min(k,i);j++){
            cout<<cur+j<<" ";
        }
        cout<<'\n';
    }
}
