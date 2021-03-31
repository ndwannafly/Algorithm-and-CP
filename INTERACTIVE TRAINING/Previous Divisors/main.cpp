#include <bits/stdc++.h>
using namespace std;
vector <int> v;
#define  pb push_back
int main() {
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
        int res = 0;
        int x;
        cin>>x;
        for(int y : v){
            if( (y != 0 && x%y == 0)|| !x) ++res;
        }
        cout<<res<<'\n';
        v.pb(x);
    }
}
