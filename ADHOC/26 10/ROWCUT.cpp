#include <bits/stdc++.h>
using namespace std;
#define NMAX 3005
#define pb push_back
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
const ll base=1e9+7;
ll pw[NMAX];
int m,n;
char a[NMAX][NMAX];
ll Hash[NMAX][NMAX];
void build_hash(){
    for(int j=1;j<=n;j++){
        for(int i=1;i<=m;i++){
            Hash[j][i]=Hash[j][i-1]*base+a[i][j];
        }
    }
}
map<ll,bool> mymap;
inline bool check(int lim){
    mymap.clear();
    for(int i=1;i<=n;i++){
        if(mymap[Hash[i][lim]]) return false;
        mymap[Hash[i][lim]]=1;
    }
    return true;
}
int main(){
    freopen("ROWCUT.inp","r",stdin);
    freopen("ROWCUT.out","w",stdout);
    cin>>m>>n;
    getchar();
    for(int i=1;i<=m;i++){
        for(int j=1;j<=n;j++){
            a[i][j]=getchar();
        }
        getchar();
    }
    build_hash();
    int res=-1;
    for(int i=1;i<=m;i++){
        if(check(i)){
            res=m-i;
            break;
        }
    }
    cout<<res;
}
