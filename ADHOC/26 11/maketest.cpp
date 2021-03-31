#include <bits/stdc++.h>
using namespace std;
int main(){
    freopen("TRILAND.inp","w",stdout);
    srand(time(NULL));
    int n=100;
    cout<<n<<'\n';
    for(int i=1;i<=n;i++){
        cout<<rand()%100<<" "<<rand()%100<<'\n';
    }
}
