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
const ll inf=1e16;

pll IT[4*NMAX+5];
ll sum[4*NMAX+5];

int n,query;
inline pll operator+ (const pll &x,const pll &y){
    return pll(max(x.first,y.first),min(x.second,y.second));
}
inline void change(int k,int l,int r,ll val){
    IT[k]=pll(val,val);
    sum[k]=1LL*(r-l+1)*val;
}
inline void Down(int k,int l,int r){
    if(IT[k].first!=IT[k].second) return; // equal segment
    int m=(l+r)>>1;
    change(k<<1,l,m,IT[k].first);
    change(k<<1|1,m+1,r,IT[k].first);
}
inline ll getmax(int k,int l,int r,int u,int v){
    if(l>v||r<u) return -1;
    if(l>=u&&r<=v){
        return IT[k].first;
    }
    Down(k,l,r);
    int m=(l+r)>>1;
    return max(getmax(k<<1,l,m,u,v),getmax(k<<1|1,m+1,r,u,v));
}
inline ll getsum(int k,int l,int r,int u,int v){
    if(l>v||r<u) return 0;
    if(l>=u&&r<=v){
        return sum[k];
    }
    Down(k,l,r);
    int m=(l+r)>>1;
    return getsum(k<<1,l,m,u,v)+getsum(k<<1|1,m+1,r,u,v);
}
inline void Modify(int k,int l,int r,int u,int v,ll top,ll mod){
    //out<<k<<" "<<l<<" "<<r<<" "<<u<<" "<<v<<" "<<top<<" "<<mod<<'\n';
    if(l>v||r<u||IT[k].first<top||IT[k].second>top) return;
    if(l>=u&&r<=v){
       // cout<<"GO: "<<k<<" "<<l<<" "<<r<<" "<<u<<" "<<v<<" "<<top<<" "<<mod<<'\n';
        if(IT[k].first==IT[k].second){
            //cout<<"G: "<<IT[k].first<<'\n';
            change(k,l,r,IT[k].first%mod);
            return ;
        }
    }
    Down(k,l,r);
    int m=(l+r)>>1;
    Modify(k<<1,l,m,u,v,top,mod);
    Modify(k<<1|1,m+1,r,u,v,top,mod);
    IT[k]=IT[k<<1]+IT[k<<1|1];
    sum[k]=sum[k<<1]+sum[k<<1|1];
}
inline void Update(int k,int l,int r,int u,int v,ll val){
    if(l>v||r<u) return ;
    if(l>=u&&r<=v){
        change(k,l,r,val);
        return;
    }
    Down(k,l,r);
    int m=(l+r)>>1;
    Update(k<<1,l,m,u,v,val);
    Update(k<<1|1,m+1,r,u,v,val);
    IT[k]=IT[k<<1]+IT[k<<1|1];
    sum[k]=sum[k<<1]+sum[k<<1|1];
}
void enter(){
    read(n);read(query);
}
void progress(){
    while(query--){
        int type,l,r;
        read(type);read(l);read(r);
        if(type==3){
            writeln(getsum(1,1,n,l,r));
        }
        if(type==1){
            ll mod;
            read(mod);
            while(1){
                ll top=getmax(1,1,n,l,r);
              //  cout<<top<<'\n';
                if(top<mod) break;
                Modify(1,1,n,l,r,top,mod);
            //exit(0);
            }
        }
        if(type==2){
            ll x;
            read(x);
            Update(1,1,n,l,r,x);
        }
    }
}
int main(){
    freopen("lonnho.inp","r",stdin);
    freopen("lonnho.out","w",stdout);
    enter();
    progress();
}
