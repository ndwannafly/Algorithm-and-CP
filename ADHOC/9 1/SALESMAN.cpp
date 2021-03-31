#include <bits/stdc++.h>
using namespace std;
template <typename T> inline void read(T &x){
    bool nega=0;
    char c;
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
        x=-x;
        putchar('-');
    }
    writep(x);
}
template <typename T> inline void writeln(T x){
    write(x);
    putchar('\n');
}
typedef long long ll;
#define NMAX 1505
ll a[NMAX][NMAX];
ll res=1e16,now;
int n;
int main(){
    freopen("SALESMAN.inp","r",stdin);
    freopen("SALESMAN.out","w",stdout);
    read(n);
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            read(a[i][j]);
        }
    }
    for(int i=1;i<=n;i++){
        now=i;
        ll cur=0;
        for(int j=1;j<=n;j++){
            if(i!=j){
                cur+=a[now][j];
                now=j;
            }
        }
        res=min(res,cur);
    }
    for(int i=1;i<=n;i++){
        now=i;
        ll cur=0;
        for(int j=n;j>=1;j--){
            if(i!=j){
                cur+=a[now][j];
                now=j;
            }
        }
        res=min(res,cur);
    }
    write(res);
}
