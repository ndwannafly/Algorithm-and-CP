#include <bits/stdc++.h>
using namespace std;

int test;
int n,C;
int a[105];
int b[105];
int res[105];

int main() {
    cin>>test;
    for(int t = 1 ; t <= test; t++){
        cout<<"Case #"<<t<<": ";
        memset(b,0,sizeof(b));
        memset(res,0,sizeof(res));
        memset(a,0,sizeof(a));
        cin>>n>>C;
        int now = 1;
        int sum = 0;
        for(int i = 1 ; i <= n ; i++){
            b[i] = i;
        }
        bool flag = false;
        while(now < n){
            bool did = false;
            for(int i = n - now + 1 ; i >= 1; i--){
                if(sum + i + n - now - 1 <= C){
                    a[now] = i;
                    sum += i;
                    //cout<<now<<" "<<i<<'\n';
                    did = true;
                    break;
                }
            }
            if(!did) flag = true;
            ++now;
        }
        a[n] = 1;
        if(sum != C || flag){
            cout<<"IMPOSSIBLE\n";
            continue;
        }
        for(int i = 1 ; i <=n; i++){
           /* for(int j = 1; j <= n ; j++){
                cout<<b[j]<<" ";
            }
            cout<<'\n';
            cout<<"ai: "<<a[i]<<'\n';*/
            int pos = b[i+a[i]-1];
            //cout<<"pos: "<<pos<<'\n';
            res[pos] = i;
            reverse(b + i, b + i + a[i]);
        }
        for(int i = 1; i<=n;i++){
            cout<<res[i]<<" ";
        }
        cout<<'\n';
    }
}
