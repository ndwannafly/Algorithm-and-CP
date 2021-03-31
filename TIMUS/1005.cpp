#include <stdio.h>
#include <iostream>
using namespace std;
int n;
int a[21];
int x[21];
int res=1e9;
void Try(int u){
    if(u==n+1){
        int sum0=0,sum1=0;
        for(int i=1;i<=n;i++){
            if(x[i]==0) sum0+=a[i];
            else sum1+=a[i];
        }
        res=min(res,abs(sum1-sum0));
        return ;
    }
    for(int i=0;i<=1;i++){
        x[u]=i;
        Try(u+1);
    }
}
int main(){
    cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i];
    Try(1);
    cout<<res;
}
