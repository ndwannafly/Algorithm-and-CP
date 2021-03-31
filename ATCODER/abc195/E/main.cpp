#include <bits/stdc++.h>
using namespace  std;
#define NMAX 200005
int n;
string s, x;
set <int> dp[NMAX];

int main() {
    cin>>n;
    cin>>s>>x;
    dp[n].insert(0);
    for(int i = n-1 ; i >= 0; i--){
        if(x[i]=='T'){
            for(int j=0;j<7;j++){
                int p = (10*j)%7;
                int q = ((10*j)+(s[i]-'0'))%7;
                if(dp[i+1].count(p)) {
                    dp[i].insert(j);
                    //cout<<i<<": insert "<<j<<'\n';
                }
                if(dp[i+1].count(q)) {
                    dp[i].insert(j);
                    //cout<<i<<": insert "<<j<<'\n';
                }
            }
        }
        else{
            for(int j=0;j<7;j++){
                int p = (10*j)%7;
                int q = ((10*j)+(s[i]-'0'))%7;
                if(dp[i+1].count(p) && dp[i+1].count(q)) {
                    dp[i].insert(j);
                    //cout<<i<<": insert "<<j<<'\n';
                }
            }
        }
    }
    if(dp[0].count(0)) cout<<"Takahashi";
    else cout<<"Aoki";
}
