#include <bits/stdc++.h>
using namespace std;
int cnt=36;
bool ok[501*501];
int main(){
    ios_base::sync_with_stdio(0);
    cout.tie(0);
    freopen("MATRIX.inp","w",stdout);
    srand(time(NULL));
    int m=150,n=150;
    cout<<m<<" "<<n<<'\n';
    for(int i=1;i<=m;i++){
        for(int j=1;j<=n;j++){
            int x;
            while(ok[x=(rand()%(m*n)+1)]);
            ok[x]=1;
            cout<<x<<" ";
        }
        cout<<'\n';
    }
}
