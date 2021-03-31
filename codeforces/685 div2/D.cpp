#include <bits/stdc++.h>
using namespace std;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int test;
    cin>>test;
    while(test--){
        long long  d,k;
        cin>>d>>k;
        long long z;
        for(long long  i=0;i<=d;i+=k){
            if(i*i+i*i<=d*d){
                z=i;
            }
        }
        z= z*z + (z+k)*(z+k);
        d=d*d;
        if(z>d) cout<<"Utkarsh"<<'\n';
        else cout<<"Ashish"<<'\n';
    }
}
