#include <bits/stdc++.h>
using namespace std;
int main(){
    srand(time(NULL));
    freopen("1726.inp","w",stdout);
    int n = 100000;
    cout<<n<<'\n';
    for(int i=1;i<=n;i++){
        cout<<rand()%1000000+1<<" "<<rand()%1000000+1<<'\n';

    }
}
