#include <bits/stdc++.h>
using namespace std;
int n;
int ask(int u){
    cout<<u<<'\n';
    n-=u;
    if(n==0) exit(0);
    fflush(stdin);
    int response;
    cin>>response;
    assert(response <= u);
    n-=response;
    if(n==0) exit(0);
    return response;
}
int main() {
    cin>>n;
    int res = 1;
    while(res <= n){
        res *= 2;
    }
    res/=2;
    ask(n-res);
    int limit = 499;
    while(limit--){
        int v = - 1;
        for(int i = 28 ; i >= 0 ; i--){
            if(n&(1<<i)){
                v = i;
            }
        }
        ask(1<<v);
    }
}
