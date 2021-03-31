#include <bits/stdc++.h>
using namespace std;
int F(int x){
    if(x<=0) return 2*x+115;
    if(x<=695) return 695;
    return 2*x+115;
}
int main() {
    int Z = -5518; // EA72
    int X = 5404; // 151C
    int Y = 0; // 0000
    // -5519 = Z
    // 5404 = X
    // 0 = Y
    cout<<F(Y+1)<<'\n';
    cout<<F(Z)<<'\n';
    cout<<F(X-1)<<'\n';
    cout<<F(Y+1)+F(Z)-F(X-1)+3;
    return 0;
    int test;
    cin>>test;
    while(test--){
        int n;
        cin>>n;
        string s1, s2, s3;
        cin>>s1>>s2>>s3;
        for(int i=1;i<=n;i++) cout<<0;
        for(int i=1;i<=n;i++) cout<<1;
        cout<<0;
        cout<<'\n';
    }
}