#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main() {
    int test;
    cin>>test;
    while(test--){
        ll n,m,x;
        cin>>n>>m>>x;
        ll c = x / n + (x%n != 0); // cot
        ll h = x%n;
        if(!h) h = n;
        //cout<<h<<" "<<c<<'\n';
        cout<<m*(h-1)+c<<'\n';
    }
}
