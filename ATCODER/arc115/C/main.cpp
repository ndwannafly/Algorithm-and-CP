#include <bits/stdc++.h>
using namespace std;
int a[100005];
int main() {
    int n;
    cin>>n;
    for(int i=1;i<=n;i++) a[i] = 1;
    for(int i=1;i<=n;i++){
        for(int j = i + i ; j<=n; j+=i){
            if(a[j] == a[i]) a[j]++;
        }
    }
    for(int i=1;i<=n;i++) cout<<a[i]<<" ";
}
