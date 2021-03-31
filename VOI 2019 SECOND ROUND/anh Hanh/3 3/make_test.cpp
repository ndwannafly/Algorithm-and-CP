#include <bits/stdc++.h>
using namespace std;
int main(){
    freopen("B.inp","w",stdout);
    srand(time(NULL));
    cout<<'a';
    for(int i=1;i<=10000;i++) cout<<char((rand()%26)+'a');
    cout<<'a';
}
