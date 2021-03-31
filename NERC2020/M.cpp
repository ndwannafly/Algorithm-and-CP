#include <bits/stdc++.h>
using namespace std;
#define pb push_back
int n;
vector <int> v[100005];
vector<int> edge[100005];
int res=0;
int F[100005];
int DFS(int u){
    if(F[u]!=0) return F[u];
    int cur=1;
    for(int v:edge[u]){
        cur=max(cur,DFS(v)+1);
    }
    F[u]=cur;
    return F[u];
}

int main(){
    //freopen("M.inp","r",stdin);
    cin>>n;
    for(int i=1;i<=n;i++){
        int k;
        cin>>k;
        for(int j=1;j<=k;j++){
            int x;
            cin>>x;
            v[x].pb(i);
        }
    }
    for(int i=1;i<=100000;i++){
        for(int j=1;j<v[i].size();j++){
            int x=v[i][j-1];
            int y=v[i][j];
            edge[x].pb(y);
        }
    }
    for(int i=1;i<=100000;i++){
        res=max(res,DFS(i));
    }
    cout<<res;
}

