#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    srand(time(NULL));
    freopen("NUMTAB.inp","w",stdout);
    cout<<1000<<" "<<1000<<'\n';
    for(int i=1;i<=1000;i++){
        for(int j=1;j<=1000;j++){
            cout<<0<<" ";
        }
        cout<<'\n';
    }
    int test=100;
    cout<<test<<'\n';
    while(test--){
        int L=rand()%100+1,R=rand()%100+1;
        if(L>R) swap(L,R);
        cout<<L<<" "<<R<<'\n';
    }
}
