#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
    srand(time(NULL));
    freopen("ROCK.inp","w",stdout);
    int n=1000,k=10;
    cout<<n<<" "<<k<<'\n';
    for(int i=1;i<=n;i++){
        cout<<char(rand()%26+'a');
    }
}
