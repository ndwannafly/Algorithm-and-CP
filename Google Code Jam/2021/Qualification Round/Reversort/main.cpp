#include <bits/stdc++.h>
using namespace std;

int n;
int a[101];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int test;
    cin>>test;
    for(int t=1;t<=test;t++){
        cin>>n;
        for(int i=1;i<=n;i++){
            cin>>a[i];
        }
        int res = 0;
        for(int i=1;i<=n-1;i++){
            int mn = -1;
            int cur = 1e9;
            for(int j=i;j<=n;j++){
                if(a[j] < cur){
                    cur = a[j];
                    mn = j;
                }
            }
            int l = i;
            int r = mn;
            res += (r-l+1);
            reverse(a+l,a+r+1);
        }
        cout<<"Case #"<<t<<": "<<res<<'\n';
    }
}
