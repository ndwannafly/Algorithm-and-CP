#include <bits/stdc++.h>
using namespace std;
int main(){
    int n,m;
    cin>>n>>m;
    int girl_boy = min(n,m);
    int desk = girl_boy*2;
    desk+=(n-girl_boy)%2==1;
    desk+=(m-girl_boy)%2==1;
    cout<<desk;
}
