#include <bits/stdc++.h>
using namespace  std;

template <typename T> inline void read (T &x){
    bool nega=0;
    char c;
    while((!isdigit(c=getchar()))&&c!='-');
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

int Divisor[20000001];
ll res;
void solve(ll c,ll d,ll x){
    for(int i=1; i<= sqrt(x);i++){
        if(x % i == 0){
            ll gcd = i;
            ll ckd = x / gcd;
            if((ckd + d)%c ==0) {
                ll k = (ckd + d) / c; // c*k - d =  x/ gcd   ;  lcm = gcd * k
                res += (1ll<<Divisor[k]);
            }

            if(gcd != ckd){ // ckd = gcd ; gcd = ckd;
                if ((gcd +d)%c == 0) {
                    ll k = (gcd + d) / c;
                    res += (1ll<<Divisor[k]);
                }
            }
        }
    }
    writeln(res);
    //exit(0);
}
void PreProcessing(){
    for(int i=2;i<=20000000;i++){
        if(!Divisor[i]){
            Divisor[i] = 1;
            for(int j = i+i; j<=20000000;j+=i){
                Divisor[j]++;
            }
        }
    }
}
int main(){
    PreProcessing();
    int test;
    read(test);
    while(test--){
        res = 0;
        ll c,d,x;
        read(c);read(d);read(x);
        solve(c,d,x);
        //return 0;
    }

}