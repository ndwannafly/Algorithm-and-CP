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
#define NMAX 100005
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
struct data{
    int st,len,id;
    inline bool operator < (const data &other){
        if(st==other.st) return len<other.len;
        return st<other.st;
    }
};
int n,k;
int p,q;
vector <data> line;
ll best[NMAX];
ll ind[NMAX];
int main(){
    freopen("TREES.inp","r",stdin);
    freopen("TREES.out","w",stdout);
    read(n);read(k);
    if(n==1){
        if(k==0){
            cout<<-1;
            return 0;
        }
        cout<<1;
        return 0;
    }
    p=1,q=n;
    for(int i=1;i<=k;i++){
        int u,v;
        read(u);read(v);
        if(v<p) continue;
        if(u>q) continue;
        u=max(u,p);
        v=min(v,q);
        line.pb({u,v-u,i});
    }
    sort(line.begin(),line.end());
    int start=p;
    int ans=0;
    vector <int> need;
    best[0]=line[0].st+line[0].len;
    ind[0]=line[0].id;
    for(int i=1;i<line.size();i++){
        if(line[i].st+line[i].len>=best[i-1]){
            ind[i]=line[i].id;
            best[i]=line[i].st+line[i].len;
        }
        else{
            best[i]=best[i-1];
            ind[i]=ind[i-1];
        }
    }
    while(start<=q){
        int l=0,r=line.size()-1,res=-1;
        while(l<=r){
            int m=(l+r)>>1;
            if(line[m].st<=start){
                res=m;
                l=m+1;
            }
            else r=m-1;
        }
        ans++;
        if(res==-1||best[res]<start){
            cout<<-1;
            return 0;
        }
        if(best[res]==start){
            cout<<-1;
            return 0;
        }
        start=best[res];
        need.pb(ind[res]);
        if(start==q){
            break;
        }
    }
    cout<<ans<<'\n';
    //for(int v:need) cout<<v<<" ";
}
