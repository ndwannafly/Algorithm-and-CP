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
#define NMAX 10005
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
const ll base=1e9+7;
ll H[NMAX],pw[NMAX];
int n;
string s;
struct suffix_array{
    string str;
    int Rank[2];
    int id;
} arr[NMAX];
inline bool cmpsuff(suffix_array x, suffix_array y){
    if(x.Rank[0]==y.Rank[0]) return x.Rank[1]<y.Rank[1];
    return x.Rank[0]<y.Rank[0];
}
void make_hash(){
    pw[0]=1;
    for(int i=1;i<NMAX;i++) pw[i]=pw[i-1]*base;
    H[1]=s[1]-'A';
    for(int i=2;i<=n;i++){
        H[i]=H[i-1]*base+s[i]-'A';
    }
}
inline ll gethash(int l,int r){
    return H[r]-H[l-1]*pw[r-l+1];
}
inline int LCP(int x,int y){
    int l=n-x+1,r=n;
    int l=0,r=
    int res=0;
    while(l<=r){
        int m=(l+r)>>1;
        if(gethash(x,x+m-1)==gethash(y,y+m-1)){
            res=m;
        }

    }

}
int main(){
    freopen("substring.inp","r",stdin);
    cin>>s;
    n=s.size();
    s='0'+s;
    make_hash();
    for(int i=n;i>=1;i--){
        arr[n-i+1].str=s[i]+arr[n-i].str;
      //  cout<<n-i+1<<" "<<arr[n-i+1].str<<'\n';
    }
    for(int i=1;i<=n;i++){
        arr[i].id=i;
        arr[i].Rank[0]=(s[n-i+1]>='a'&&s[n-i+1]<='z')?(s[n-i+1]-'a'):(s[n-i+1]-'a'+100);
        arr[i].Rank[1]=(i>1)?(arr[i-1].Rank[0]):-1;
        cout<<i<<" "<<arr[i].str<<" "<<arr[i].Rank[0]<<" "<<arr[i].Rank[1]<<'\n';
    }
   // arr[n].Rank[1]=
    sort(arr+1,arr+n+1,cmpsuff);
    for(int i=1;i<=n;i++){
        cout<<i<<" "<<arr[i].str<<" "<<arr[i].id<<'\n';
    }
    ll res=arr[1].str.size();
    for(int i=2;i<=n;i++){
    res=res+(arr[i].str.size()-(arr[i-1].id<=arr[i].id)?LCP(arr[i-1].id,arr[i].id):LCP(arr[i].id,arr[i-1].id));
        cout<<arr[i].str.size()<<" "<<res<<'\n';
        exit(0);
    }
    writeln(res);
}
