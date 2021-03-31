#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define NMAX 100005
ll a[NMAX],b[NMAX];
int n;
ll sum[NMAX];
const ll base=1e5;
int main(){
    freopen("NUMPOLY.inp","r",stdin);
    freopen("NUMPOLY.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    for(int i=1;i<=n;i++){
        a[i]%=base;
        sum[i]=sum[i-1]+a[i];
        sum[i]%=base;
    }
    ll res=0;
    for(int i=1;i<=n;i++){
        res+=a[i]*(sum[n]-sum[i])%base;
        res%=base;
    }
    b[1]=a[n];
    b[2]=a[1];
    b[n]=a[2];
    int l=3,r=n-1;
    int nowL=n-1;
    int nowN=3;
    bool type=1;// greater
    while(l<=r){
        if(type){
            if(b[l-1]<=b[r+1]){
                if(b[l]==0){
                    b[l]=a[nowL];
                    nowL--;
                }
                if(b[r]==0){
                    b[r]=a[nowL];
                    nowL--;
                }
            }
            else{
                if(b[r]==0){
                    b[r]=a[nowL];
                    nowL--;
                }
                if(b[l]==0){
                    b[l]=a[nowL];
                    nowL--;
                }
            }
        }
        else{
            if(b[l-1]<=b[r+1]){
                if(b[r]==0){
                    b[r]=a[nowN];
                    nowN++;
                }
                if(b[l]==0){
                    b[l]=a[nowN];
                    nowN++;
                }
            }
            else{
                if(b[l]==0){
                    b[l]=a[nowN];
                    nowN++;
                }
                if(b[r]==0){
                    b[r]=a[nowN];
                    nowN++;
                }
            }
        }
        type=!type;
        l++,r--;
    }
    for(int i=1;i<=n;i++){
        int idtrc=i+1;
        if(idtrc>n) idtrc=1;
        ll sub=(b[i]*b[idtrc])%100000;
        res-=sub;
        res%=100000;
        if(res<0)res+=100000;
    }
    cout<<setw(5)<<setfill('0')<<res;
}
