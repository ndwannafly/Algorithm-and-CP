#include <bits/stdc++.h>
using namespace std;
#define NMAX 105
#define pb push_back
int a[2*NMAX+5][2*NMAX+5];
int trace[NMAX];
int F[NMAX][NMAX];
int n;
queue <int> q;
inline bool bfs(int source,int sink){
    while(!q.empty()) q.pop();
    q.push(source);
    while(!q.empty()){
        int u=q.front();q.pop();
        for(int i=0;i<2*n+2;i++){
            if(F[u][i]>0&&trace[i]==-1){
                trace[i]=u;
                if(i==sink) return true;
                q.push(i);
            }
        }
    }
    return false;
}
inline int max_flow(int source,int sink){
    int mflow=0;
    while(1){
        for(int i=0;i<2*n+2;i++) trace[i]=-1;
        if(!bfs(source,sink)) break;
        int add=1e9;
        for(int i=sink;i!=source;i=trace[i]) add=min(add,F[trace[i]][i]);
        mflow+=add;
        for(int i=sink;i!=source;i=trace[i]){
            F[trace[i]][i]-=add;
            F[i][trace[i]]+=add;
        }
    }
    return mflow;
}
int main(){
    freopen("GRIDGAME.inp","r",stdin);
    cin>>n;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++) cin>>a[i][j];
    }
    int l=1,r=1e9,res=1;
    while(l<=r){
        int m=(l+r)>>1;
    //    m=21;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(a[i][j]>=m){
                    F[i][j+n]=1;
                }
            }
        }
        for(int i=0;i<n;i++){
            F[2*n][i]=1;
            F[i+n][2*n+1]=1;
        }
        if(max_flow(2*n,2*n+1)==n){
            res=m;
            l=m+1;
        }
        else r=m-1;
    }
    cout<<res;
}
