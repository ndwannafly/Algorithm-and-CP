#include <bits/stdc++.h>
using namespace std;
#define  NMAX 100005
int a[NMAX];
map<int,bool> m;
int main() {
    int test;
    cin>>test;
    while(test--){
        int n,k;
        cin>>n>>k;
        m.clear();

        int mex = 0;
        for(int i=1;i<=n;i++){
            cin>>a[i];
            m[a[i]]=true;
        }
        if(!k) {
            cout << n << '\n';
            continue;
        }
        sort(a+1,a+n+1);
        if(a[1] != 0) mex = 0;
        else{
            a[n+1] = 1000000005;
            for(int i=1;i<=n+1;i++){
                if(a[i]-a[i-1]>1){
                    mex = a[i-1]+1;
                    break;
                }
            }
        }
        if(mex == a[n]+1){
            cout<<n+k<<'\n';
        }
        else{
            int x = (a[n] + mex) + ((a[n]+mex)&1);
            x/=2;
            if(m[x]) cout<<n<<'\n';
            else cout<<n+1<<'\n';
        }
    }
}
