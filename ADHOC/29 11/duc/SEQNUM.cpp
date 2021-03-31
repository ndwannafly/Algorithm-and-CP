#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll a[56];
int main(){
    freopen("SEQNUM.inp","r",stdin);
    freopen("SEQNUM.out","w",stdout);
    a[1]=1;
    a[2]=1;
    for(int i=3;i<=55;i++){
        a[i]=a[i-1]+a[i-3]+1;
    }
    int test;
    cin>>test;
    while(test--){
        int n;
        cin>>n;
        cout<<a[n]<<'\n';
    }
}
