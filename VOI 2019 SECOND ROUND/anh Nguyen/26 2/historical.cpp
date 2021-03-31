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
#define NMAX 100001

typedef long long ll;
typedef pair<ll,ll> pll;

const int Block_size=335;

struct data{
    int l,r,id;
};
inline bool cmp(const data &x,const data &y){
    if(x.l/Block_size!=y.l/Block_size) return x.l<y.l;
    return x.r<y.r;
}
int n,Q;

ll a[NMAX];
ll cnt[NMAX],ans[NMAX];

vector <ll> rem;
vector <data> query[Block_size+5];
void enter(){
    read(n);read(Q);
    for(int i=1;i<=n;i++) read(a[i]),rem.pb(a[i]);
    sort(rem.begin(),rem.end());
    for(int i=1;i<=n;i++){
        a[i]=lower_bound(rem.begin(),rem.end(),a[i])-rem.begin();
    }
    for(int i=1;i<=Q;i++){
        int l,r;
        read(l);read(r);
        query[l/Block_size].pb({l,r,i});
    }
}
void progress(){
    for(int i=0;i<=Block_size;i++){
        if(!query[i].size()) continue;
        sort(query[i].begin(),query[i].end(),cmp);
        int MinL=1e5+1,MaxL=-1;
        for(auto j:query[i]){
            MinL=min(MinL,j.l);
            MaxL=max(MaxL,j.l);
        }
        int now=MaxL+1;
        ll have=0;
        for(auto j:query[i]){
            while(now<=j.r){ // n times for max
                cnt[a[now]]++;
                have=max(have,cnt[a[now]]*rem[a[now]]);
                now++;
            }
            for(int p=j.l;p<=min(j.r,MaxL);p++) cnt[a[p]]++;
            ans[j.id]=have;
            for(int p=j.l;p<=min(j.r,MaxL);p++) ans[j.id]=max(ans[j.id],cnt[a[p]]*rem[a[p]]);
            for(int p=j.l;p<=min(j.r,MaxL);p++) cnt[a[p]]--; // Max = sqrt n ,( = block_size) for max with each query => Q*sqrtn
        }
        memset(cnt,0,sizeof(cnt)); // not exceed sqrt n times, => N*sqrt(n)
    }
    for(int i=1;i<=Q;i++) writeln(ans[i]);
}
int main(){
  //  freopen("C.inp","r",stdin);
    enter();
    progress();
}
