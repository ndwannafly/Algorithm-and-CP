#include <bits/stdc++.h>
using namespace  std;
int main() {
    int test;
    cin>>test;
    while(test--){
        int n,k;
        cin>>n>>k;
        string s;
        cin>>s;
        unsigned int l = 0 , r = s.size()-1;
        int cnt = 0;
        while(l<r && s[l] == s[r]){
            ++cnt;
            ++l;
            --r;
        }
        if(cnt < k){
            cout<<"NO\n";
            continue;
        }
        if(cnt == k && n == 2*k){
            cout<<"NO\n";
            continue;
        }
        cout<<"YES\n";
    }
}
