#include <bits/stdc++.h>
using namespace std;
#define pb push_back
int n,m;
bool a[22][22];
int x[22];
bool cl[22];
int res;
vector <int> ans1,ans2;
inline void solve(){
    int cur=n;
    for(int i=1;i<=n;i++){
        cur-=x[i];
    }
    if(cur<=res) return ;
    memset(cl,0,sizeof(cl));
    int num=0;
    for(int i=1;i<=m;i++){
        int had=0;
        for(int j=1;j<=n;j++){
            if(x[j]) continue;
            if(a[j][i]==1){
                had++;
                if(had==2){
                    cl[i]=1;
                    ++num;
                    break;
                }
            }
        }
    }
    for(int i=1;i<=n;i++){
        if(x[i]) continue;
        int had=0;
        for(int j=1;j<=m;j++){
            if(cl[j]) continue;
            had+=a[i][j];
            if(had>=2&&a[i][j]==1){
                num++;
                cl[j]=1;
            }
        }
    }
    for(int i=1;i<=n;i++){
        if(x[i]) continue;
        int had=0;
        for(int j=1;j<=m;j++){
            if(cl[j]) continue;
            had+=a[i][j];
        }
        if(had!=1) return ;
    }
    for(int i=1;i<=m;i++){
        if(cl[i]) continue;
        int had=0;
        for(int j=1;j<=n;j++){
            if(x[j]) continue;
            had+=a[j][i];
        }
        if(had==0){
            cl[i]=1;
            continue;
        }
        if(had!=1) return ;
    }
    int now=-1;
    for(int i=1;i<=n;i++){
        if(x[i]) continue;
        for(int j=1;j<=m;j++){
            if(cl[j]) continue;
            if(a[i][j]==1){
                if(j<now) return ;
                now=j;
            }
        }
    }
    if(res<cur){
        res=cur;
        ans1.clear();
        ans2.clear();
        for(int i=1;i<=n;i++) if(x[i]) ans1.pb(i);
        for(int i=1;i<=m;i++) if(cl[i]) ans2.pb(i);
    }
}
inline void Try(int u){
    if(u==n+1){
        solve();
        return ;
    }
    for(int i=0;i<=1;i++){
        x[u]=i;
        Try(u+1);
    }
}
int main(){
    freopen("MATRIX.inp","r",stdin);
    freopen("MATRIX.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            cin>>a[i][j];
        }
    }
    Try(1);
    cout<<res<<'\n';
    for(int v:ans1) cout<<v<<" ";
    cout<<'\n';
    for(int v:ans2) cout<<v<<" ";
    cout<<'\n';
}
