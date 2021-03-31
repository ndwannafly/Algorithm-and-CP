#include <bits/stdc++.h>
using namespace std;
#define  NMAX 200005
typedef long long ll;
typedef pair<ll,ll> pii;
int n;
pii a[NMAX];

ll cal(pii l, pii r){
    int x = l.first - l.second;
    int y = r.first - r.second;
    if(x==y){
        if((l.first + l.second)&1) return 0;
        return abs(l.first - r.first);
    }
    if((l.first + l.second)%2==0){
        if((r.first + r.second)%2==0){
            return abs(x-y)/2;
        }
        else{
            return abs(y-x)/2;
        }
    }
    else{
        if((r.first + r.second)%2==0){
            return (abs(y-x) + 1 ) /2;
        }
        else{
            return abs(y-x)/2;
        }
    }
}
int main() {
    int test;
    cin>>test;
    while(test--){
        cin>>n;
        for(int i=1;i<=n;i++){
            cin>>a[i].first;
        }
        for(int i=1;i<=n;i++) {
            cin >> a[i].second;
        }
        sort(a+1,a+n+1);
        pii now = {1,1};
        ll res = 0;
        for(int i=1;i<=n;i++){
            res += cal(now,a[i]);
            now = a[i];
        }
        cout<<res<<'\n';
    }
}
