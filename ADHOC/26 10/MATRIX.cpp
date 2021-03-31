#include <bits/stdc++.h>
using namespace std;
#define NMAX 505
#define pb push_back
typedef long long ll;
typedef pair<int,int> pii;
vector <int> row[NMAX],column[NMAX];
int m,n;
int pos;
int R[NMAX*NMAX],C[NMAX*NMAX];
int a[NMAX][NMAX];
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("MATRIX.inp","r",stdin);
    freopen("MATRIX.out","w",stdout);
    cin>>m>>n;
    for(int i=1;i<=m;i++){
        for(int j=1;j<=n;j++){
            int x;
            cin>>x;
            a[i][j]=x;
            if(x==m*n) pos=i;
            R[x]=i;
            C[x]=j;
            row[i].pb(x);
            column[j].pb(x);
        }
    }
    sort(row[pos].begin(),row[pos].end());
    reverse(row[pos].begin(),row[pos].end());
    for(int v:row[pos]) cout<<v<<" ";
    cout<<'\n';
    int now=C[m*n];
    sort(column[now].begin(),column[now].end());
    reverse(column[now].begin(),column[now].end());
    for(int i=1;i<column[now].size();i++){
        int v=column[now][i];
        cout<<v<<" ";
        int r=R[v];
        for(int j=2;j<=n;j++){
            cout<<a[r][C[row[pos][j-1]]]<<" ";
        }
        cout<<'\n';
    }
}
