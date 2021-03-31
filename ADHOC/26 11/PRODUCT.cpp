#include <bits/stdc++.h>
using namespace std;
template <typename T> inline void read(T &x){
    char c;
    bool nega=0;
    while((!isdigit(c=getchar()))&&(c!='-'));
    if(c=='-'){
        nega=1;
        c=getchar();
    }
    x=c-48;
    while(isdigit(c=getchar())) x=x*10+c-48;
    if(nega) x=-x;
}
template <typename T> inline void writep(T x){
    if(x>9) writep(x/10);
    putchar(x%10+48);
}
template <typename T> inline void write(T x){
    if(x<0){
        putchar('-');
        x=-x;
    }
    writep(x);
}
template <typename T> inline void writeln(T x){
    write(x);
    putchar('\n');
}
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
const ll mod=123456789;
#define pb push_back
#define NMAX 100005
ll a[NMAX];
int main(){
    freopen("PRODUCT.inp","r",stdin);
    freopen("PRODUCT.out","w",stdout);
    int test;
    read(test);
    while(test--){
        int n,k;
        read(n);read(k);
        for(int i=0;i<n;i++) read(a[i]);
        sort(a,a+n);
        ll product=1;
        if(a[n-1]==0&&(k&1)){
            writeln(0);
            continue;
        }
        if(a[n-1]<=0&&(k&1)){
            for(int i=n-1;i>=n-k;i--){
                product*=a[i]%mod;
                product%=mod;
            }
            if(product<0) product+=mod;
            writeln(product);
            continue;
        }
        int i=0,j=n-1;
        if(k&1){
            product*=a[j]%mod;
            product%=mod;
            j--;
            k--;
        }
        k>>=1;
        for(int itr=0;itr<k;itr++){
            ll left_p=a[i]*a[i+1];
            ll right_p=a[j]*a[j-1];
            if(left_p>right_p){
                product*=left_p%mod;
                product%=mod;
                i+=2;
            }
            else{
                product*=right_p%mod;
                product%=mod;
                j-=2;
            }
        }
        product%=mod;
        if(product<0) product+=mod;
        writeln(product);
    }
}
