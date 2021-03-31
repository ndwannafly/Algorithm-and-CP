#include <bits/stdc++.h>
using namespace std;
int a[100000];
int main(){
    freopen("NUMBER.out","r",stdin);
    int n=10000;
    for(int i=1;i<=2*n;i++) cin>>a[i];
    for(int i=1;i<=n;i++){
        if(a[i]!=a[i+n]) cout<<i<<'\n';
    }
}
