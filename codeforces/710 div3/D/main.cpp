#include <bits/stdc++.h>
using namespace std;
int a[200005];
map<int,int> cnt;
int main() {
    int test;
    cin>>test;
    while(test--){
        cnt.clear();
        int n;
        cin>>n;
        int mx = 0;
        for(int i=1;i<=n;i++){
            cin>>a[i];
            cnt[a[i]]++;
            mx = max(mx,cnt[a[i]]);
        }
        if(mx<=n/2){
            cout<<(n&1)<<'\n';
            continue;
        }
        else{
            cout<<max((n&1),mx - (n-mx))<<'\n';
            continue;
        }
    }
}
