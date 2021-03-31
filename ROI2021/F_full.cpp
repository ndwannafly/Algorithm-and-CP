//1 2 1 2 1
//2 1 2 1 2
// F[1][1][1] = F[0][0][1]
//F[i][j][1/2] = F[i-1][j][1/2];
//F[i][j][1/2] = F[i-1][j-1][1] & f[i-1][j-1][2]

//F1[j][1] = F2[j-1][1]&F[2][j-1][2]...F2[j-1][k];
//F1[j][2] = F2[j-1][1]&F[2][j-1][2];
//F2[j][1/2]=F1[j][1/2];
#include <bits/stdc++.h>
using namespace std;
int F1[5005][5005];
int F2[5005][5005];
int G1[5005][5005];
int G2[5005][5005];
int k,n,m;
int a[5005],b[5005];
int newstate;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("F.inp","r",stdin);
    //freopen("F.out","w",stdout);
    cin>>k>>n;
    for(int i=0;i<=k;i++){
        F2[0][i]=1;
    }
    for(int i=1;i<=n;i++) cin>>a[i];
    for(int i=1;i<=n;i++){
        for(int j=1;j<=i;j++){
            int state=1; // = and F2[j-1][1...k]
            for(int p=1;p<=k;p++){
                state&=F2[j-1][p];
            }
            for(int p=1;p<=k;p++){
                F1[j][p]=F2[j][p];
                if(a[i]==p) F1[j][p]=state;
            }
        }
        for(int j=1;j<=i;j++){
            for(int p=1;p<=k;p++) F2[j][p]=F1[j][p];
        }
    }

    cin>>m;
    for(int i=0;i<=k;i++){
        G2[0][i]=1;
    }
    for(int i=1;i<=m;i++) cin>>b[i];
    for(int i=1;i<=m;i++){
        for(int j=1;j<=i;j++){
            int state=1; // = and G2[i-1][j-1][1...k]
            for(int p=1;p<=k;p++) state&=G2[j-1][p];
            for(int p=1;p<=k;p++){
                G1[j][p]=G2[j][p];
                if(b[i]==p) G1[j][p]=state;
            }
        }
        for(int j=1;j<=i;j++){
            for(int p=1;p<=k;p++) G2[j][p]=G1[j][p];
        }
    }

    int res,lastdig=0;
    for(int i=1;i<=max(n,m)+1;i++){
        if(lastdig) break;
        for(int j=1;j<=k;j++){
            if(!(F1[i][j]|G1[i][j])){
                res=i;
                lastdig=j;
                break;
            }
        }
    }
    cout<<res<<'\n';
    for(int i=1;i<=res;i++) cout<<lastdig<<" ";
}

