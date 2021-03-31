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
ll n;
ll solve(ll n){
    if(n==1){
        writeln(2);
        exit(0);
    }
    ll cur1=1,cur2=2,res=0;
    while(cur1*cur1<=n){
        res=res+cur1*(cur1*cur1-(cur1-1)*(cur1-1));
        //cout<<"one: "<<res<<" "<<cur1<<'\n';
        cur1++;
    }
    while(cur2*cur2*cur2<=n){
        res=res+(cur2-1)*(cur2*cur2*cur2-(cur2-1)*(cur2-1)*(cur2-1));
        //cout<<"two: "<<res<<" "<<cur2<<'\n';
        cur2++;
    }
 //   cout<<res<<" "<<cur1<<" "<<cur2<<'\n';
    cur1--;cur2--;
    res=res+(cur1+1)*(n-(cur1*cur1));
    res=res+(cur2)*(n-cur2*cur2*cur2+1);
    return res;
}
int main(){
    freopen("sum.inp","r",stdin);
    freopen("sum.out","w",stdout);
    read(n);
    writeln(solve(n));
}
