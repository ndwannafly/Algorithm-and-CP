#include <bits/stdc++.h>
using namespace std;
int main() {
    int test;
    cin>>test;
    while(test--){
        int n,k;
        cin>>n>>k;
        string s;
        cin>>s;
        int res = 2;
        int l = -1, r= -1;
        for(int i=0;i<n;i++){
            if(s[i] == '*'){
                l = i;
                break;
            }
        }
        for(int i = n-1; i >= 0 ;i--){
            if(s[i] =='*'){
                r=i;
                break;
            }
        }
        res = ((r!=l) ? 2 : 1);
        // cnt = 0;
        //cout<<l<<" "<<r<<'\n';
        while(l < n){
            //++cnt;
            //if(cnt ==7) return 0;
            int opt = -1;
            for(int j = l ; j<= min(l+k,n-1);j++){
                //cout<<j<<" "<<s[j]<<'\n';
                if(j==r){
                    opt = r;
                    break;
                }
                if(s[j] =='*') {
                    opt = j;
                }
            }
            //cout<<l<<" "<<opt<<'\n';
            if(l==opt) break;
            if(!opt){
                break;
            }
            if(opt >= r) break;
            l = opt;
            ++res;
        }
        cout<<res<<'\n';
    }
}
