#include <bits/stdc++.h>
using namespace  std;
typedef long long ll;
ll n;
ll a[100005];
bool check(ll c){
    ll cur = -1;
    for(int i=1;i<n;i++){
        if(a[i] > a[i+1]){
            cur = a[i] + c - a[i+1];
            if(cur <= a[i] | cur <= a[i+1]) return false;
            if(cur <= c) return false;
        }
        else{
            ll dif = a[i+1] - a[i];
            if(dif != c) return false;
            if(cur !=-1 && dif >= cur) return false;
        }
    }
    if(cur == -1) return false;
    for(int i=2;i<=n;i++){
        if(a[i] != (a[i-1] + c)%cur) return false;
    }
    cout<<cur<<" "<<c<<'\n';
    return true;
}

bool arbitrary(){
    int dif = a[2] - a[1];
    for(int i=2;i<n;i++){
        if(a[i+1] - a[i] != dif) return false;
    }
    return true;
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int test;
    cin>>test;
    while(test--){
        cin>>n;
        for(int i=1;i<=n;i++) cin>>a[i];
        bool zr =arbitrary();
        if(zr){
            cout<<"0\n";
            continue;
        }
        bool flag = false;
        for(int i=1;i<n;i++){
            if(a[i+1]>a[i]){
                ll c = a[i+1] - a[i];
                if(check(c)) {
                    flag = true;
                    break;
                }
            }
        }
        if(flag) continue;
        cout<<"-1\n";
    }
}
