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
const ll base=1e9+7;
char a[NMAX],b[NMAX];
int n,m,k;
int sizn,sizm,res;
ll pw[NMAX];
ll HashA[NMAX],HashB[NMAX];
map <ll,ll> cnt;
inline ll gethashA(int l,int r){
    return HashA[r]-HashA[l-1]*pw[r-l+1];
}
inline ll gethashB(int l,int r){
    return HashB[r]-HashB[l-1]*pw[r-l+1];
}
inline void build_hash(){
    for(int i=1;i<=n;i++){
        HashA[i]=HashA[i-1]*base+a[i];
    }
    for(int i=1;i<=m;i++){
        HashB[i]=HashB[i-1]*base+b[i];
    }
}
inline ll F(int leng){
    cnt.clear();
    for(int i=1;i<=m-leng+1;i++){
        cnt[gethashB(i,i+leng-1)]++;
    }
    int had=0;
    for(int i=1;i<=n-leng+1;i++){
        int now=cnt[gethashA(i,i+leng-1)];
        if(had<now){
            had=now;
        }
    }
    return had;
}
vector <int> rem;
inline bool hashcmp(int x,int y){
    int l=0,r=res-1;
    int difpos=-1;
    while(l<=r){
        int mid=(l+r)>>1;
        if(gethashA(x,x+mid)==gethashA(y,y+mid)){
            difpos=mid;
            l=mid+1;
        }
        else{
            r=mid-1;
        }
    }
    if(difpos==res-1) return true;
    return a[x+difpos+1]<a[y+difpos+1];
}
inline void trace(){
    cnt.clear();
    for(int i=1;i<=m-res+1;i++){
        cnt[gethashB(i,i+res-1)]++;
    }
    int had=-1;
    for(int i=1;i<=n-res+1;i++){
        int now=cnt[gethashA(i,i+res-1)];
        if(had==-1||now>=k){
//            cout<<"GO: "<<'\n';
//            for(int j=i;j<=i+res-1;j++) cout<<a[j];
//            cout<<'\n';
            if(had==-1){
                had=i;
                continue;
            }
            else{
                if(hashcmp(i,had)){
                    had=i;
                }
            }
        }
    }
    for(int i=had;i<=had+res-1;i++) putchar(a[i]);
}
int main(){
    freopen("GATTACA.inp","r",stdin);
    freopen("GATTACA.out","w",stdout);
    pw[0]=1;
    for(int i=1;i<NMAX;i++){
        pw[i]=pw[i-1]*base;
    }
    read(n);read(m);read(k);
    for(int i=1;i<=n;i++){
        a[++sizn]=getchar();
    }
    getchar();
    for(int i=1;i<=m;i++){
        b[++sizm]=getchar();
    }
    getchar();
    build_hash();
    int l=1,r=n;
    while(l<=r){
        int mid=(l+r)>>1;
        if(F(mid)>=k){
            res=mid;
            l=mid+1;
        }
        else r=mid-1;
    }
    trace();

}
