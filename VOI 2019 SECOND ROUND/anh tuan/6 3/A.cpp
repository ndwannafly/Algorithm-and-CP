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
#define NMAX 1005

typedef long long ll;
typedef pair<ll,ll> pll;
typedef pair<int,int> pii;
int n,m;
int a[NMAX][NMAX];
bool mark[NMAX][NMAX];
vector <pair<int,pii>> rem;
vector <int> row[NMAX];
void enter(){
    read(n);read(m);
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++) read(a[i][j]),rem.pb({a[i][j],{i,j}});
    }
}
inline bool check(int val){
    for(int i=1;i<=n;i++) row[i].clear();
    for(int i=1;i<=m;i++){
        for(int j=1;j<=m;j++){
            mark[i][j]=false;
        }
    }
    for(auto v:rem){
        if(v.first<val) break;
      //  cout<<v.first<<" ";
        row[v.second.first].pb(v.second.second);
    }
    //cout<<'\n';
    for(int i=1;i<=n;i++){
      //  cout<<"GO: "<<i<<" "<<val<<'\n';
        for(auto u:row[i]){
            for(auto v:row[i]){
                if(u>=v) continue;
        //        cout<<u<<" "<<v<<'\n';
                if(mark[u][v]){return true;}
                else mark[u][v]=true;
            }
        }
    }
   // cout<<"FALSE"<<'\n';
    return false;
}
void progress(){
    sort(rem.begin(),rem.end());
    reverse(rem.begin(),rem.end());
    int l=0,r=rem[0].first;
    int res=0;
//    check(11);
  //  exit(0);
    while(l<=r){
        int m=(l+r)>>1;
        if(check(m)){
            res=m;
            l=m+1;
        }
        else r=m-1;
    }
    writeln(res);
}
int main(){
    //freopen("A.inp","r",stdin);
    enter();
    progress();
}
