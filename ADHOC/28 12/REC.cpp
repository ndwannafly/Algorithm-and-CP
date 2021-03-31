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
#define NMAX 3005
#define pb push_back
int n;
ll a[NMAX],b[NMAX],c[NMAX],d[NMAX];
vector <ll> rem;
ll cntA[4*NMAX],cntB[4*NMAX],cntC[4*NMAX],cntD[4*NMAX];
ll FCD[4*NMAX],FBD[4*NMAX],FBC[4*NMAX];
int main(){
    freopen("REC.inp","r",stdin);
    freopen("REC.out","w",stdout);
    int test;
    read(test);
    while(test--){
        rem.clear();
        read(n);
        memset(cntA,0,sizeof(cntA));
        memset(cntB,0,sizeof(cntB));
        memset(cntC,0,sizeof(cntC));
        memset(cntD,0,sizeof(cntD));
        memset(FCD,0,sizeof(FCD));
        memset(FBD,0,sizeof(FBD));
        memset(FBC,0,sizeof(FBC));
        for(int i=1;i<=n;i++) read(a[i]),rem.pb(a[i]);
        for(int i=1;i<=n;i++) read(b[i]),rem.pb(b[i]);
        for(int i=1;i<=n;i++) read(c[i]),rem.pb(c[i]);
        for(int i=1;i<=n;i++) read(d[i]),rem.pb(d[i]);
        sort(rem.begin(),rem.end());
        for(int i=1;i<=n;i++){
            a[i]=lower_bound(rem.begin(),rem.end(),a[i])-rem.begin()+1;
            cntA[a[i]]++;
            b[i]=lower_bound(rem.begin(),rem.end(),b[i])-rem.begin()+1;
            cntB[b[i]]++;
            c[i]=lower_bound(rem.begin(),rem.end(),c[i])-rem.begin()+1;
            cntC[c[i]]++;
            d[i]=lower_bound(rem.begin(),rem.end(),d[i])-rem.begin()+1;
            cntD[d[i]]++;
        }
        sort(a+1,a+n+1);
        sort(b+1,b+n+1);
        sort(c+1,c+n+1);
        sort(d+1,d+n+1);
        ll sum=0;
        // CD
        for(int i=1;i<=n;i++){
            if(c[i]!=c[i-1]) sum=sum+cntC[c[i]]*cntD[c[i]];
        }
        for(int i=1;i<=n;i++){
            if(a[i]!=a[i-1]) FCD[a[i]]=sum-cntC[a[i]]*cntD[a[i]];
        }
        //BD
        sum=0;
        for(int i=1;i<=n;i++){
            if(b[i]!=b[i-1]) sum=sum+cntB[b[i]]*cntD[b[i]];
        }
        for(int i=1;i<=n;i++){
            if(a[i]!=a[i-1]) FBD[a[i]]=sum-cntB[a[i]]*cntD[a[i]];
        }
        // BC
        sum=0;
        for(int i=1;i<=n;i++){
            if(b[i]!=b[i-1]) sum=sum+cntB[b[i]]*cntC[b[i]];
        }
        for(int i=1;i<=n;i++){
            if(a[i]!=a[i-1]) FBC[a[i]]=sum-cntB[a[i]]*cntC[a[i]];
        }
        ll res=0;
        // cal for rec
        for(int i=1;i<=n;i++){
            if(a[i]!=a[i-1]){
                res=res+cntA[a[i]]*cntB[a[i]]*FCD[a[i]];
                res=res+cntA[a[i]]*cntC[a[i]]*FBD[a[i]];
                res=res+cntA[a[i]]*cntD[a[i]]*FBC[a[i]];
                res=res+cntA[a[i]]*cntB[a[i]]*cntC[a[i]]*cntD[a[i]];// cal for square
            }
        }
        writeln(res);
    }
}
