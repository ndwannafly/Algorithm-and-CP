#include <bits/stdc++.h>
using namespace std;
int n;
int c[505][505];
int a[505];
int b[505];
int main() {
    cin>>n;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++) cin>>c[i][j];
    }
    for(int i=1;i<=n;i++){
        a[i] = 0;
        bool flag = false;
        for(int j=1;j<=n;j++){
            b[j] = c[i][j];
        }
        for(int j=1;j<=n;j++){
            a[j] = c[j][1] - b[1];

            if(a[j] < 0){
                flag = true;
                break;
            }
            if(i==j){
                if(a[j] != 0){
                    flag = true;
                    break;
                }
            }
        }
        if(flag) continue;
        for(int j=1;j<=n;j++){
            for(int k=1;k<=n;k++){
                if(a[j] + b[k] != c[j][k]){
                    flag = true;
                    break;
                }
            }
            if(flag) break;
        }
        if(flag) continue;
        cout<<"Yes\n";
        for(int j=1;j<=n;j++) cout<<a[j]<<" ";
        cout<<'\n';
        for(int j=1;j<=n;j++) cout<<b[j]<<" ";
        cout<<'\n';
        return 0;
    }
    cout<<"No\n";
}
