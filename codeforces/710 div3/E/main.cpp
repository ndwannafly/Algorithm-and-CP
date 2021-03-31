#include <bits/stdc++.h>
using namespace  std;

priority_queue<int> mn,mx;

int a[200005];
int pmx[200005],pmn[200005];
int main() {
    int test;
    cin>>test;
    while(test--){
        while(!mn.empty()) mn.pop();
        while(!mx.empty()) mx.pop();
        int n;
        cin>>n;
        for(int i=1;i<=n;i++){
            cin>>a[i];
        }
        for(int i=1;i<=n;i++){
            if(a[i] > a[i-1]){
                pmx[i] = a[i];
                pmn[i] = a[i];
                for(int j = a[i-1]+1; j<= a[i]-1; j++){
                    mx.push(j);
                    mn.push(-j);
                }
            }
            else{
                pmx[i] = mx.top();
                mx.pop();
                pmn[i] = -mn.top();
                mn.pop();
            }
        }
        for(int i=1;i<=n;i++) cout<<pmn[i]<<" ";
        cout<<'\n';
        for(int i=1;i<=n;i++) cout<<pmx[i]<<" ";
        cout<<'\n';
    }
}
