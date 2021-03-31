#include <bits/stdc++.h>
using namespace std;

int main(){
    freopen("GAME.inp","w",stdout);
    srand(time(NULL));
    cout<<10<<'\n';
    for(int i=1;i<=10;i++){
        cout<<rand()%20+1<<" ";
    }
}
