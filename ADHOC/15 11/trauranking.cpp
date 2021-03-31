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
#define NMAX (1<<20)+1
typedef long long ll;
class{
private:
    int val[NMAX];
public:
    inline void init(int x){
        memset(val,0,sizeof(val));
        for(int i=1;i<=x;i++) val[i]=1;
        for(int i=1;i+(i&-i)<NMAX;i++){
            val[i+(i&-i)]+=val[i];
        }
    }
    inline void update(int x,int add){
        for(;x<NMAX;x+=(x&-x)) val[x]+=add;
    }
    inline int Lower_bound(int x){
        int lim=NMAX-1;
        for(int i=19;i>=0;i--){
            if(val[lim-(1<<i)]>=x) lim-=(1<<i);
            else x-=val[lim-(1<<i)];
        }
        return lim;
    }
}BIT;
int n;
int R[1000005];
int main(){
    freopen("ranking.inp","r",stdin);
    freopen("ranking.out","w",stdout);
    read(n);
    BIT.init(n);
    for(int i=1;i<=n;i++){
        int x;
        read(x);
        int k=BIT.Lower_bound(x+1);
        R[k]=i;
        BIT.update(k,-1);
    }
    for(int i=1;i<=n;i++){
        writeln(R[i]);
    }
}
