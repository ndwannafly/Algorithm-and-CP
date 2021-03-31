#include <bits/stdc++.h>
#define maxn 10001
using namespace std;
int n,m,low[maxn],tp,num[maxn],coun,dd[maxn],S,T,a[maxn],res,r[maxn];
stack<int> s;
vector<int> ke[maxn];
bool cx[maxn];
void    docdl(){
    int u,v,m;
    cin>>n>>m>>S>>T;
    for(int i=1;i<=m;i++){
        cin>>u>>v;
        ke[u].push_back(v);
        ke[v].push_back(u);
    }
}
void    dfs(int u,int p){
    coun++;
    num[u]=coun;
    low[u]=n+1;
    int nc=0;
    for(int i=0;i<ke[u].size();i++){
        int v=ke[u][i];
        if(v==p) continue;
        if(num[v]!=0)  low[u]=min(low[u],num[v]);
        else {
            bool kt1=false,kt2=false;
            nc++;
            s.push(u);
            dfs(v,u);
            low[u]=min(low[u],low[v]);
            if(low[v]>=num[u] || (u==p && nc>=2)){
                tp++;
                int dem=0;
                bool kt1=false,kt2=false;
                do{
                    v=s.top();
                    s.pop();
                    if(dd[v]!=tp) {
                        dd[v]=tp;
                        if(v==S) kt1=true;
                        if(v==T) kt2=true;
                        a[++dem]=v;
                    }
                }
                while(u!=v);
                if(kt1==true && kt2==true){
                    for(int i=1;i<=dem;i++) r[res+i]=a[i];
                    res+=dem;
                }
            }
        }
    }
    s.push(u);
}
void    xuli(){
    ke[S].push_back(T);
    ke[T].push_back(S);
    coun=0; tp=0; res=0;
    for(int i=1;i<=n;i++) if(num[i]==0) dfs(i,i);
    if(res<=2){cout<<0; return;}
    sort(r+1,r+res+1);
    cout<<res<<"\n";
    for(int i=1;i<=res;i++)  cout<<r[i]<<"\n";
}
int     main(){
    ios_base::sync_with_stdio(false);
    docdl();
    xuli();
}
