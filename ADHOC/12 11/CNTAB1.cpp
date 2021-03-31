#include <bits/stdc++.h>
using namespace std;
#define NMAX 55
#define pb push_back
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
int n;
int a[NMAX][NMAX],b[NMAX][NMAX],c[NMAX][NMAX];
int x[NMAX];
int cnt;
vector <int> adj[NMAX];
vector <int> res;
inline bool ok(int u){
    for(int i=1;i<=n;i++){
        if(c[i][u]!=b[i][u]) return true;
    }
    return false;
}
inline void change(int u){
    for(int i=1;i<=n;i++){
        c[i][u]=-c[i][u];
    }
}
inline bool check(){
    cnt=0;
    for(int i=1;i<=n;i++){
        if(x[i]){
            cnt++;
            for(int j=1;j<=n;j++) c[i][j]=-a[i][j];
        }
        else{
            for(int j=1;j<=n;j++) c[i][j]=a[i][j];
        }
    }
    res.clear();
    for(int i=1;i<=n;i++) if(ok(i)){
        change(i);
        cnt++;
        res.pb(i);
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(c[i][j]!=b[i][j]) return false;
        }
    }
    return true;
}
inline void Try(int u){
   // cout<<u<<'\n';
    if(u==n+1){
        if(check()){
            cout<<cnt<<'\n';
            for(int i=1;i<=n;i++){
                if(x[i]) cout<<1<<" "<<i<<'\n';
            }
            for(int v:res) cout<<2<<" "<<v<<'\n';
            exit(0);
        }
        return ;
    }
    for(int i=1;i>=0;i--){
        x[u]=i;
        Try(u+1);
    }
}
inline void sub3(){
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(a[i][j]!=b[i][j]) adj[i].pb(j);
        }
    }
    Try(1);
}
int main(){
    freopen("CNTAB1.inp","r",stdin);
    freopen("CNTAB1.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++) cin>>a[i][j];
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            cin>>b[i][j];
            if((a[i][j]+b[i][j])!=0&&a[i][j]*b[i][j]==0){
                cout<<-1;
                return 0;
            }
        }
    }
    sub3();

}
