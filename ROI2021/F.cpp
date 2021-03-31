
//1 2 1 2 1
//2 1 2 1 2
// F[1][1][1] = F[0][0][1]
//F[i][j][1/2] = F[i-1][j][1/2];
//F[i][j][1/2] = F[i-1][j-1][1] & f[i-1][j-1][2]

//F1[i][1/2] i
//F2[i][1/2]; i-1
#include <bits/stdc++.h>
using namespace std;
int F[4005][4005][3];
int G[4005][4005][3];
int k,n,m;
int a[5005],b[5005];
int main(){
    //freopen("F.inp","r",stdin);
    //F[x][0][1/2]=1;
    cin>>k>>n;
    for(int i=0;i<=n;i++){
        F[i][0][1]=1;
        F[i][0][2]=1;
    }
    int cnt=0;
    for(int i=1;i<=n;i++) cin>>a[i];
    for(int i=1;i<=n;i++)
    for(int i=1;i<=n;i++){
        for(int j=1;j<=i;j++){
            F[i][j][1]=F[i-1][j][1];
            F[i][j][2]=F[i-1][j][2];
            if(a[i]==1) F[i][j][1]=F[i-1][j-1][1]&F[i-1][j-1][2];
            if(a[i]==2) F[i][j][2]=F[i-1][j-1][1]&F[i-1][j-1][2];
            //cout<<i<<" "<<j<<" "<<F[i][j][1]<<" "<<F[i][j][2]<<'\n';
        }
        //cout<<'\n';
    }

    ////cout<<"ngat\n";

    cin>>m;
    for(int i=0;i<=m;i++){
        G[i][0][1]=1;
        G[i][0][2]=1;
    }
    for(int i=1;i<=m;i++) cin>>b[i];
    for(int i=1;i<=m;i++){
        for(int j=1;j<=i;j++){
            G[i][j][1]=G[i-1][j][1];
            G[i][j][2]=G[i-1][j][2];
            if(b[i]==1) G[i][j][1]=G[i-1][j-1][1]&G[i-1][j-1][2];
            if(b[i]==2) G[i][j][2]=G[i-1][j-1][1]&G[i-1][j-1][2];
            //cout<<i<<" "<<j<<" "<<G[i][j][1]<<" "<<G[i][j][2]<<'\n';
        }
        //cout<<'\n';
    }

    int res,lastdig=0;
    for(int i=1;i<=max(n,m)+1;i++){
        if(lastdig) break;
        for(int j=1;j<=2;j++){
            if(!(F[n][i][j]|G[m][i][j])){
                res=i;
                lastdig=j;
                break;
            }
        }
    }
    cout<<res<<'\n';
    for(int i=1;i<=res;i++) cout<<lastdig<<" ";
}
