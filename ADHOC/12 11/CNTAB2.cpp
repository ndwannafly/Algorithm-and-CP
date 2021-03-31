#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
#define pb push_back
#define NMAX 105
vector <int> adj[NMAX];
int n;
int a[NMAX][NMAX],b[NMAX][NMAX],c[NMAX][NMAX];
int p[NMAX];
int q[NMAX];
bool mark[NMAX];
int hang[NMAX],cot[NMAX];
struct data{
    int x,y,z;
}cnt[NMAX];
inline bool check(int u,int v){
    return (cnt[u].x==cnt[v].x&&cnt[u].y==cnt[v].y&&cnt[u].z==cnt[v].z);
}
vector <data> res;
inline void trace(){
   // cout<<"DUC"<<'\n';
    for(int i=1;i<=n;i++){
        hang[i]=i;
        cot[i]=i;
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(hang[j]==p[i-1]&&hang[j]!=hang[i]){
                swap(hang[j],hang[i]);
                res.pb({1,i,j});
            }
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(cot[j]==q[i-1]&&cot[i]!=cot[j]){
                swap(cot[i],cot[j]);
                res.pb({2,i,j});
            }
        }
    }
    cout<<res.size()<<'\n';
    for(auto duc:res){
        cout<<duc.x<<" "<<duc.y<<" "<<duc.z<<'\n';
    }
}
int main(){
    freopen("CNTAB2.inp","r",stdin);
    freopen("CNTAB2.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            cin>>a[i][j];
            if(a[i][j]==-1) cnt[i].x++;
            else if(a[i][j]==0) cnt[i].y++;
            else if(a[i][j]==1) cnt[i].z++;
            c[i][j]=a[i][j];
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            cin>>b[i][j];
        }
    }
    for(int i=0;i<n;i++){
        p[i]=i+1;
        q[i]=i+1;
    }
    do{
        bool flag=0;
        for(int i=1;i<=n;i++){
            if(!check(i,p[i-1])){
                flag=1;
                break;
            }
        }
        if(flag) continue;
        do{
            bool ok=0;
            // hang i la hang p[i],cot j la cot q[j]
            for(int i=1;i<=n;i++){
                if(ok) break;
                for(int j=1;j<=n;j++){
                    if(b[i][j]!=a[p[i-1]][q[j-1]]){
                        ok=1;
                        break;
                    }
                }
            }
            if(ok) continue;
            else{
                trace();
                exit(0);
            }
        }while(next_permutation(q,q+n));
    }while(next_permutation(p,p+n));
}
