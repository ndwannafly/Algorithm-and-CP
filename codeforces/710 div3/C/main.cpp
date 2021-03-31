#include <bits/stdc++.h>
using namespace  std;
int main() {
    int test;
    cin>>test;
    while(test--){
        string a,b;
        cin>>a>>b;
        if(a==b){
            cout<<0<<'\n';
            continue;
        }
        int res = -1;
        int n = a.size(), m = b.size();
        for(int len = 1 ; len <= min(n,m); len ++){
            for(int i=0; i+len-1 < n;i++){
                for(int j=0;j+len-1 <m;j++){
                    bool flag = true;
                    for(int k = 0;k<len;k++){
                        if(a[i+k] != b[j+k]) {
                            flag = false;
                            break;
                        }
                    }
                    if(flag){
                       res = len;
                    }
                }
            }
        }
        if(res == -1){
            cout<<n+m<<'\n';
        }
        else cout<<n + m - 2*res<<'\n';

    }
}
