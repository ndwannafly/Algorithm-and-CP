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
#define NMAX 100005
#define pb push_back
int n;
int a[NMAX];
int b[NMAX];
int c[NMAX];
int tmp;
int F[NMAX],G[NMAX];
int type[NMAX];
int len;
int cnt[NMAX];
int pos[NMAX];
string str(int x){
    stringstream s;
    s<<x;
    string st;
    s>>st;
    return st;
}
void make(int test){
    ofstream f1 ((str(test)+".inp").c_str());
    ofstream f2 ((str(test)+".out").c_str());
    int n=100000;
    memset(F,0,sizeof(F));
    memset(G,0,sizeof(G));
    memset(a,0,sizeof(a));
    memset(type,0,sizeof(type));
    memset(b,0,sizeof(b));
    memset(c,0,sizeof(c));
    memset(cnt,0,sizeof(cnt));
    memset(pos,0,sizeof(pos));
    f1<<n<<'\n';
    for(int i=1;i<=n;i++){
        a[i]=rand()+1;
        f1<<a[i]<<" ";
    }
        b[1]=a[1];
    F[1]=1;
    tmp=1;
    for(int i=2;i<=n;i++){
        F[i]=lower_bound(b+1,b+tmp+1,a[i])-b;
        tmp=max(tmp,F[i]);
        b[F[i]]=a[i];
    }
    len=tmp;
    for(int i=1;i<=n;i++){
        c[i]=-a[n-i+1];
    }
    memset(b,0,sizeof(b));
    b[1]=c[1];
    G[n]=1;
    tmp=1;
    for(int i=2;i<=n;i++){
        G[n-i+1]=lower_bound(b+1,b+tmp+1,c[i])-b;
        tmp=max(tmp,G[n-i+1]);
        b[G[n-i+1]]=c[i];
    }
    for(int i=1;i<=n;i++){
        if(F[i]+G[i]-1==len) type[i]=2;
        else type[i]=1;
    }
    for(int i=1;i<=n;i++){
        if(type[i]==2) cnt[F[i]]++;
    }
    for(int i=1;i<=n;i++){
        if(cnt[F[i]]==1&&type[i]==2){
            type[i]=3;
        }
    }
    for(int i=1;i<=n;i++){
        f2<<(type[i]);
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
