#include <bits/stdc++.h>
using namespace std;
int main(){
    //freopen("A.inp","r",stdin);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int test;
    cin>>test;
    while(test--){
        int n;
        cin>>n;
        if(n<=3) cout<<n-1<<'\n';
        else cout<<(n%2==0?2:3)<<'\n';
    }
}
// 25 5 4 2 1
