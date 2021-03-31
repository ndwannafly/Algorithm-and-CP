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
template <typename T> inline void display(T x){
    if(x>9) display(x/10);
    putchar(x%10+48);
}
template <typename T> inline void write(T x){
    if(x<0){
        putchar('-');
        x=-x;
    }
    display(x);
}
template <typename T> inline void writeln(T x){
    write(x);
    putchar('\n');
}
#define NMAX 300001
typedef long long ll;
int n;
ll a[NMAX];
ll b[NMAX],dem;
map <ll,bool> cnt;
void sub1(){
    ll res=0;
    for(int i=1;i<=n;i++){
        if(a[i]!=a[i-1]) b[++dem]=a[i];
    }
    for(int i=1;i<=dem;i++){
        for(int j=1;j<i;j++){
            ll x=b[i]-b[j];
            if(x==b[i]) continue;
            if(x==b[j]) continue;
            bool t=cnt[x];
            if(t){
                res++;
            }
        }
        cnt[b[i]]=1;
    }
    writeln(res);
}
void sub2(){
    ll res=n-2;
    for(int i=2;i<=n;i++){
        res=res+(n-i);
        if(i<=n-i) res--;
    }
    writeln(res);
}
int main(){
    freopen("QD.inp","r",stdin);
    freopen("QD.out","w",stdout);
    read(n);
    for(int i=1;i<=n;i++){
        read(a[i]);
    }
    sort(a+1,a+n+1);
    if(n<=3000){
        sub1();
    }
    else
        sub2();
}
