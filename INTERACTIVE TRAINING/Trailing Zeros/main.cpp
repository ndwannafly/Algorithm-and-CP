#include <bits/stdc++.h>
using namespace std;
int zr;
int last;
int main() {
    auto ask = [](int u){
        cout<<"Q "<<u<<'\n';
        fflush(stdin);
        int response;
        cin>>response;
        return response;
    };

    int l = 0, r = 1000000;
    while(l<=r){
        int m = (l+r)>>1;
        if(ask(m)){
            zr = m;
            l = m + 1;
        }
        else r = m - 1;
    }


    auto get = [](int x){
        int pw = 5;
        int ans = 0;
        while(pw <= 100000){
            ans += x/pw;
            pw*=5;
        }
        return ans;
    };

    l = 0, r = 100000;
    int res=5;
    while(l<=r){
        int m = (l+r)>>1;
        if(get(m) >=  zr){
            res = m;
            r = m-1;
        }
        else l = m+1;
    }

    cout<<"A "<<res;

}
