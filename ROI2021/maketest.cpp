#include <bits/stdc++.h>
using namespace std;
int main(){
    srand(time(NULL));
    freopen("F.inp","w",stdout);
    cout<<5000<<'\n';
    cout<<200<<'\n';
    for(int i=1;i<=200;i++) cout<<rand()%5000+1<<" ";
    cout<<'\n';
    cout<<200<<'\n';
    for(int i=1;i<=200;i++) cout<<rand()%5000+1<<" ";
}
