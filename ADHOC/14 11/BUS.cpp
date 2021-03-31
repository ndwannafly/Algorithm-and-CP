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
#define NMAX 200005
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
int n,m;
vector <int> adj[NMAX];
struct data{
    ll t,x,id;
};
ll t[NMAX],k[NMAX];
ll d[NMAX];
data x[NMAX];
ll F[NMAX];
ll cnt;
inline bool check(int i,int j){
    int u=x[i].x,v=x[j].x;
    if(x[i].t+d[j]-d[i]>=x[j].t) return true;
    return false;
}
int main(){
    freopen("BUS.inp","r",stdin);
    freopen("BUS.out","w",stdout);
    read(n);read(m);
    ll res=0;
    for(int i=1;i<=n;i++){
        read(t[i]);read(k[i]);
        res+=t[i];
        d[i]=d[i-1]+t[i];
        for(int j=1;j<=k[i];j++){
            read(x[++cnt].t);
            x[cnt].x=i;
            x[cnt].id=j;
        }
    }
    for(int i=1;i<=cnt;i++){
        F[i]=x[i].id;
        for(int j=i-1;j>=1;j--){
            if(x[i].x!=x[j].x){
                if(check(i,j)) F[i]=max(F[i],F[j]+x[i].id);
            }
        }
        //cout<<i<<" "<<F[i]<<'\n';
    }
    cout<<res+1;
}
