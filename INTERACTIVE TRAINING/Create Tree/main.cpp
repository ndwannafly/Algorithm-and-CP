#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin>>n;
    auto ask = [](int u, int v){
        cout<<"Q "<<u<<" "<<v<<'\n';
        fflush(stdin);
        int response;
        cin>>response;
        return response;
    };

    for(int i = 2; i <= n ;i++){
        while(!ask(1,i)){
        }
    }
    cout<<"A";
}
