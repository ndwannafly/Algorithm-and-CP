#include <bits/stdc++.h>
using namespace std;
int a2, a3 ,a5 ,a7;
int main() {
    auto ask = [](int x){
        cout<<"Q "<<x<<'\n';
        fflush(stdin);
        int response;
        cin>>response;
        return response;
    };

    int res = 1;

    a2 = ask(2);
    while(a2--) res*=2;
    a3 = ask(3);
    while(a3--) res*=3;
    a5 = ask(5);
    while(a5--) res*=5;
    a7 = ask(7);
    while(a7--) res*=7;
    cout<<"A "<<res;
}
