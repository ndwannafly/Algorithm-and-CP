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
typedef pair<ll,ll> pll;
#define NMAX 100005
#define pb push_back
struct data{
    int l,r,id;
};
int n,m;
int test;
int type[NMAX],cnt[NMAX];
vector <data> stepL;
vector <data> stepR;
set<int> s;
inline bool cmpL(const data &x,const data &y){
    if(x.l==y.l) return x.r<y.r;
    return x.l<y.l;
}
inline bool cmpR(const data &x,const data &y){
    if(x.r==y.r)x.l<y.l;
    return x.r<y.r;
}
void enter(){
    stepL.clear();
    stepR.clear();
    memset(type,0,sizeof(type));
    memset(cnt,0,sizeof(cnt));
    s.clear();
    read(n);read(m);
    for(int i=1;i<=m;i++){
        int X,L,K;
        read(X);read(L);read(K);
        stepL.pb(data({max(0,X-K),min(n,X+K),i}));
        stepR.pb(data({max(0,X-K),min(n,X+K),i}));
        type[i]=L;
    }
}
void progress(){
    sort(stepL.begin(),stepL.end(),cmpL);
    sort(stepR.begin(),stepR.end(),cmpR);
//    for(int i=0;i<stepL.size();i++){
//        cout<<stepL[i].id<<" "<<stepL[i].l<<" "<<stepL[i].r<<" "<<type[stepL[i].id]<<'\n';
//    }
//    cout<<'\n';
//    for(int i=0;i<stepR.size();i++){
//         cout<<stepR[i].id<<" "<<stepR[i].l<<" "<<stepR[i].r<<" "<<type[stepR[i].id]<<'\n';
//    }
//    cout<<'\n';
    int res=0;
    int it1=0,it2=0;
    for(int i=1;i<=n;i++){
        //cout<<"times: "<<i<<'\n';
        while(it1<m&&stepL[it1].l<=i){
            cnt[type[stepL[it1].id]]++;
            s.insert(stepL[it1].id);
   //         cout<<"insert: "<<stepL[it1].id<<" "<<cnt[type[stepL[it1].id]]<<'\n';
            it1++;
        }
        while(it2<m&&stepR[it2].r<i){
            cnt[type[stepR[it2].id]]--;
            s.erase(stepR[it2].id);
       //     cout<<"Erase: "<<stepR[it2].id<<" "<<cnt[type[stepR[it2].id]]<<'\n';
            it2++;
        }
        if(s.empty()) res++;
        else{
            int k=*s.rbegin();
         //   cout<<k<<" "<<" "<<type[k]<<" "<<cnt[type[k]]<<'\n';
            if(cnt[type[k]]>1) res++;
        }
    }
    writeln(res);
}

int main(){
 //   freopen("A.inp","r",stdin);
 //   freopen("A.out","w",stdout);
    read(test);
    while(test--){
        enter();
        progress();
    }
}

