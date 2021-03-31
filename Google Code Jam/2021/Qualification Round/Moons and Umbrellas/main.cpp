#include <bits/stdc++.h>
using namespace std;
int test;
string s;
int x,y;
int dp[1005][2];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>test;
    for(int t = 1 ; t <= test ; t++){
        for(int i = 0 ; i < 1005 ; i++){
            for(int j = 0; j < 2; j++) dp[i][j] = 1e9;
        }
        cin>>x>>y>>s;
        dp[1][0] = 0;
        dp[1][1] = 0;
        int n = s.size();
        for(int i = 2 ; i <= n ; i++){
            if(s[i-1] != '?' && s[i-2] != '?'){ // chu
                if(s[i-1] == s[i-2]){ // giong kieu
                    if(s[i-1] == 'C') dp[i][0] = dp[i-1][0];
                    else dp[i][1] = dp[i-1][1];
                }
                else{ // khac kieu
                    if(s[i-1] == 'C') dp[i][0] = dp[i-1][1] + y;
                    else dp[i][1] = dp[i-1][0] + x;
                }
            }
            else{
                if(s[i-1] == '?'){
                    if(s[i-2] == '?'){
                        dp[i][0] = min(dp[i-1][0], dp[i-1][1] + y);
                        dp[i][1] = min(dp[i-1][1], dp[i-1][0] + x);
                    }
                    else if(s[i-2] == 'C'){
                        dp[i][0] = dp[i-1][0];
                        dp[i][1] = dp[i-1][0] + x;
                    }
                    else if(s[i-2] == 'J'){
                        dp[i][1] = dp[i-1][1];
                        dp[i][0] = dp[i-1][1] + y;
                    }
                }
                else if(s[i-2] == '?'){
                    if(s[i-1] == '?'){
                        dp[i][0] = min(dp[i-1][0], dp[i-1][1] + y);
                        dp[i][1] = min(dp[i-1][1], dp[i-1][0] + x);
                    }
                    else if(s[i-1] == 'C'){
                        dp[i][0] = min(dp[i-1][0], dp[i-1][1] + y);
                    }
                    else if(s[i-1] == 'J'){
                        dp[i][1] = min(dp[i-1][1], dp[i-1][0] + x);
                    }
                }
            }
            //cout<<"dp: "<<i<<" "<<dp[i][0]<<" "<<dp[i][1]<<'\n';
        }
        cout<<"Case #"<<t<<": "<<min(dp[n][0], dp[n][1])<<'\n';
    }
}
