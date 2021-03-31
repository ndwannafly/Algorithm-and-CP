#include <bits/stdc++.h>
using namespace std;
char c[]={'.','#'};
int main(){
    srand(time(NULL));
    freopen("LABYRINTH.inp","w",stdout);
    int n,m;
    n=1500;
    m=n;
   // swap(n,m);
    cout<<m<<" "<<n<<'\n';
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
                cout<<'.';
        }
        cout<<'\n';
    }
}
