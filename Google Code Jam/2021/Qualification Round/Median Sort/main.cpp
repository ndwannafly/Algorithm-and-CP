#include <bits/stdc++.h>
using namespace  std;

#define  eb emplace_back

int t, n, q;

int ask (int i, int j,int k){
    cout<<i<<" "<<j<<" "<<k<<'\n';
    fflush(stdout);
    int response;
    cin>>response;
    return response;
}

vector <int> a;
int main() {
    cin>>t>>n>>q;
    fflush(stdout);
    for(int test = 1 ; test <= t ; test++) {
        a.clear();
        int median = ask(1, 2, 3);
        if (median == 1) {
            a.eb(2);
            a.eb(1);
            a.eb(3);
        } else if (median == 2) {
            a.eb(1);
            a.eb(2);
            a.eb(3);
        } else {
            a.eb(1);
            a.eb(3);
            a.eb(2);
        }
        // 1 4 5 6 7 2 3
        // 1 2 3 4 5
        for (int i = 4; i <= n; i++) {
            int l = *a.begin(), r = *a.end();
            int response = ask(l, r, i);
            if (response == r) a.eb(i);
            else if(response == l){
                    vector <int> b;
                    b.eb(i);
                    for(int v : a) b.eb(v);
                    a = b;
            }
            else{ // l ---- m i --- r
                while(l < r) {
                    int m = (l + r) >> 1;
                    if(l!=m) response = ask(l, m, i);
                    else{
                        solve(l,r,i);
                        break;
                    }
                    if (response == i){
                        r = m - 1;
                    }
                    else{
                        l = m;
                    }
                }
            }
        }
    }
}
