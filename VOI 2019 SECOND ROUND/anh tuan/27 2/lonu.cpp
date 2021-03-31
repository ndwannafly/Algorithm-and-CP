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
#define pb push_back
#define mp make_pair
#define NMAX 200001

typedef long long ll;
typedef pair<ll,ll> pll;
typedef pair<int,int> pii;

int n;
int a[NMAX],F[NMAX];

void enter(){
    read(n);
    for(int i=1;i<=n;i++) read(a[i]);
}

void sub1(){
    for(int i=1;i<=n;i++){
        for(int j=i+1;j<=n;j++){
           // cout<<a[i]<<" "<<a[j]<<" "<<(a[i]&a[j])<<'\n';
            if((a[i]&a[j])==0){
                F[a[i]|a[j]]++;
            }
        }
    }
    int optimal=0,res=0;
    for(int i=0;i<=200000;i++){
        if(optimal<=F[i]){
            optimal=F[i];
            res=i;
        }
    }
    writeln(res);
    exit(0);
}

void sub2(){

}
void progress(){
    if(n<=5000) sub1();
    else sub2();
}
int main(){
    freopen("lonu.inp","r",stdin);
    enter();
    progress();
}
