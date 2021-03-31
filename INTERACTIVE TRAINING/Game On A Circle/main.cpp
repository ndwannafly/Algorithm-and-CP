#include <bits/stdc++.h>
using namespace std;
vector <int> v;
bool ask(int x){
    cout<<x<<'\n';
    fflush(stdin);
    int response;
    cin>>response;
    return response;
}
//
int main() {
    int test;
    cin>>test;
    while(test--){
        int black = 0;
        v.clear();
        bool enough = 0 ;
        for(int i = 0 ; i <= 9 ; i++){
            int x = i * 10 + i;
            if(ask(x)){
                ++black;
                v.push_back(x);
                enough == (black == 2);
                if(enough) break;
            }
        }
        if(black == 1){
            int x = v.back();
            x += 10;
            x %= 100;
            ask(x);
            continue;
        }
        else{
            for(int x=20;x<=99;x++){
                int i = x/10;
                int j = x%10;
                if(i == j ) continue;
                bool flag = 0;
                for (int y : v){
                    int p = y/10;
                    int q = y%10;
                    if(p == q) continue;
                    if(p == i || p == j || q == i || q == j) flag = 1;
                }
                if(!flag) {
                    ask(x);
                    break;
                }
            }
        }
    }
}
// 96 97 98 99 0 1 2 3 4 5
// 0 99
// 1 1 2 3 5 8 13
//______AB