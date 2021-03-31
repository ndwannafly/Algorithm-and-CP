#include <bits/stdc++.h>
using namespace std;
#define NMAX 1000005
#define pb push_back
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
const ll base=1e9+7;
int n;
char c[NMAX];
ll Hash[NMAX];
ll pw[NMAX];
// 2->4
// 1 2 3 4
// 1234
// 12
inline ll gethash(int l,int r){
    return Hash[r]-Hash[l-1]*pw[r-l+1];
}
inline bool solve(int len){
    ll cur=Hash[len];
    int i=len+len;
    for(;i<=n;i+=len){
        if(gethash(i-len+1,i)!=cur){
            return false;
        }
    }
    i-=len;
    if(i!=n){
        int least=n-i;
        if(Hash[least]!=gethash(i+1,n)) return false;
    }
    return true;
}
int main(){
    freopen("REPSTR.inp","r",stdin);
    freopen("REPSTR.out","w",stdout);
    char x;
    while((x=getchar())>='A'&&x<='Z'){
        c[++n]=x;
    }
    pw[0]=1;
    for(int i=1;i<NMAX;i++){
        Hash[i]=Hash[i-1]*base+c[i];
        pw[i]=pw[i-1]*base;
    }
    for(int i=1;i<=n;i++){
        if(solve(i)){
            for(int j=1;j<=i;j++){
                putchar(c[j]);
            }
            return 0;
        }
    }
}
