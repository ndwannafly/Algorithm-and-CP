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
ll x,k;
#define pb push_back
inline ll NumbersKbitsGreaterThanX(ll x,int k){
    x++;
    while(__builtin_popcountll(x)>k){
        x|=x-1;
        x++;
    }
    for(int i=k-__builtin_popcountll(x);i!=0;--i){
        x|= x+1;
    }
    return x;
}
ll L,R;
string str(int x){
    stringstream s;
    s<<x;
    string st;
    s>>st;
    return st;
}
inline ll solve(){
    for(int i=63;i>=0;i--){
        if(__builtin_popcountll(L)==i){
            return L;
        }
        ll x=NumbersKbitsGreaterThanX(L,i);
        if(x<=R){
            return x;
        }
    }
}
void make(int test){
    ofstream f1 ((str(test)+".inp").c_str());
    ofstream f2 ((str(test)+".out").c_str());
    int TT;
    TT=10000;
    f1<<TT<<'\n';
    while(TT--){
        L=1LL*rand()*rand()*rand();
        R=1LL*rand()*rand()*rand();
        if(L>R) swap(L,R);
        f1<<L<<" "<<R<<'\n';
        f2<<solve()<<'\n';
    }
}
int main(){
    srand(time(NULL));
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int itest;
    for(itest=76;itest<=100;itest++){
        make(itest);
    }
}
