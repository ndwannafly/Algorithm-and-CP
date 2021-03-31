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
#define NMAX 200005
#define pb push_back
#define mp make_pair

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
struct data{
    int L,R;
};
inline bool cmp(data x,data y){
    if(x.L==y.L) return x.R>y.R;
    return x.L<y.L;
}
struct segment_tree{
    int lazy,maxx;
} IT[8*NMAX];
int n,m;
data a[NMAX];
void enter(){
    read(n);read(m);
    for(int i=1;i<=n;i++){
        read(a[i].L);read(a[i].R);
    }
}
inline void build(int k,int l,int r){
    if(l>r) return;
    if(l==r){
        IT[k].maxx=-(m+1)+l;
        return;
    }
    int m=(l+r)>>1;
    build(2*k,l,m);
    build(2*k+1,m+1,r);
    IT[k].maxx=max(IT[2*k].maxx,IT[2*k+1].maxx);
}
void push_down(int k,int l,int r){
    if(IT[k].lazy>0){
        IT[2*k].maxx+=IT[k].lazy;
       // cout<<"ADD1: "<<2*k<<" "<<l<<" "<<r<<" "<<IT[2*k].minn<<'\n';
        IT[2*k+1].maxx+=IT[k].lazy;
        //cout<<"ADD2: "<<2*k+1<<" "<<l<<" "<<r<<" "<<IT[2*k+1].minn<<'\n';
        IT[2*k].lazy+=IT[k].lazy;
        IT[2*k+1].lazy+=IT[k].lazy;
        IT[k].lazy=0;
        return;
    }
}
inline void update(int k,int l,int r,int x,int y){
    if(l>r||x>y||l>y||r<x) return ;
    push_down(k,l,r);
    if(l>=x&&r<=y){
        IT[k].maxx++;
     //   cout<<"ADD: "<<" "<<k<<" "<<l<<" "<<r<<" "<<IT[k].minn<<'\n';
        IT[k].lazy++;
        return;
    }
    push_down(k,l,r);
    int m=(l+r)>>1;
    update(2*k,l,m,x,y);
    update(2*k+1,m+1,r,x,y);
    IT[k].maxx=max(IT[2*k].maxx,IT[2*k+1].maxx);
}
inline int getmax(int k,int l,int r,int x,int y){
   // cout<<k<<" "<<l<<" "<<r<<" "<<x<<" "<<y<<'\n';
    if(l>r||x>y||l>y||r<x) return 0;
    push_down(k,l,r);
    if(l>=x&&r<=y){
       // cout<<"GO: "<<k<<" "<<l<<" "<<r<<" "<<IT[k].maxx<<'\n';
        return IT[k].maxx;
    }
    push_down(k,l,r);
    int m=(l+r)>>1;
    return max(getmax(2*k,l,m,x,y),getmax(2*k+1,m+1,r,x,y));
}
void progress(){
    sort(a+1,a+n+1,cmp);
    int res=max(0,n-m);
    build(1,0,m+1);
    for(int i=1;i<=n;i++){
        update(1,0,m+1,1,a[i].R);
        res=max(res,getmax(1,0,m+1,a[i].L+1,a[i].R)-a[i].L);
     //   cout<<i<<" "<<a[i].L<<" "<<a[i].R<<" "<<res<<'\n';
    }
    writeln(res);
}
int main(){
    //freopen("D.inp","r",stdin);
    enter();
    progress();
}

