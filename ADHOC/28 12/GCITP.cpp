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
#define NMAX 5005
int n;
ll a[NMAX],b[NMAX];
int where[NMAX];
ll pw[NMAX];
class{
public:
    ll hash_val;
    bool had[NMAX];
    inline void clear(){
        hash_val=0;
        memset(had,0,sizeof(had));
    }
    inline void insert(int u){
        if(!had[u]){
            had[u]=1;
        }
        else return ;
        hash_val+=pw[u];
    }
}Set;
inline void solve(ll a[],ll L,ll R,map<ll,ll> &Map){
    Set.clear();
    Set.insert(a[L]);
    for(int i=L+1;i<=R;i++){
        Set.insert(a[i]);
        Map[Set.hash_val]++;
    }
}
int main(){
    freopen("GCITP.inp","r",stdin);
    freopen("GCITP.out","w",stdout);
    read(n);
    for(int i=1;i<=n;i++){
        read(a[i]);
    }
    for(int i=1;i<=n;i++){
        read(b[i]);
    }
    if(n>300){
        for(int i=1;i<=n;i++){
            where[b[i]]=i;
        }
        ll res=0;
        for(int i=1;i<=n;i++){
            int L=n,R=1;
            for(int j=i;j<=n;j++){
                L=min(L,where[a[j]]);
                R=max(R,where[a[j]]);
                if(R-L==j-i) res++;
            }
        }
        write(res-n);
        return 0;
    }
    else
    {
        vector <int> List(a+1,a+n+1);
        List.insert(List.end(),b+1,b+n+1);
        sort(List.begin(),List.end());
        for(int i=1;i<=n;i++) a[i]=lower_bound(List.begin(),List.end(),a[i])-List.begin()+1;
        for(int i=1;i<=n;i++) b[i]=lower_bound(List.begin(),List.end(),b[i])-List.begin()+1;
        pw[0]=2309;
        pw[1]=2309;
        for(int i=2;i<NMAX;i++){
            pw[i]=pw[i-1]*2309;
        }
        map <ll,ll> CntA,CntB;
        for(int i=1;i<=n;i++) solve(a,i,n,CntA);
        for(int i=1;i<=n;i++) solve(b,i,n,CntB);
        auto it=CntA.begin(),jt=CntB.begin();
        ll res=0;
        while(it!=CntA.end()&&jt!=CntB.end()){
            if(it->first==jt->first){
                res+=it->second*jt->second;
                it++,jt++;
            }
            else{
                if(it->first<jt->first) it++;
                else jt++;
            }
        }
        writeln(res);
    }
}
