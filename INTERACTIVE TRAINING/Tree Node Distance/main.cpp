#include <bits/stdc++.h>
using namespace std;

int E(){
    cout<<"E"<<'\n';
    fflush(stdin);
    int response;
    cin>>response;
    return response;
}

int F(char A){
    cout<<"F "<< A << '\n';
    fflush(stdin);
    int response;
    cin>>response;
    return response;
}

void R(char A){
    cout<<"R "<< A << '\n';
    fflush(stdin);
}

int main() {
    bool flag = 0;
    int depth = 0;
    int x = 1;
    while (true) {
        for (int i = 0; i < x; i++) {
            if (E()) goto here;
            if (!flag) {
                depth += F('A');
            } else {
                depth -= F('B');
            }
        }
        flag = (!flag);
        x *= 2;
        continue;
        here:;
        R('A');
        R('B');
        int ans = 0;
        if (depth > 0) for (int i = 0; i < depth; i++) ans += F('A');
        else for (int i = 0; i < abs(depth); i++) ans += F('B');
        while (true) {
            if (E()) break;
            ans += F('A');
            ans += F('B');
        }
        cout << "A " << ans << '\n';
        fflush(stdin);
        break;
    }
}