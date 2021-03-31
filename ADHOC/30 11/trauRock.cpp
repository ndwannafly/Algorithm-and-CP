#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,k;
#define NMAX 1000005
char c[1000005];
int S[NMAX][27];
ll res=0;
inline bool check(int l,int r){
    int had=0;
    for(int i=0;i<=26;i++){
        if(S[r][i]-S[l-1][i]>0){
            ++had;
        }
    }
    return had==k;
}
int main(){
    freopen("ROCK.inp","r",stdin);
   // freopen("ROCK.out","w",stdout);
    cin>>n>>k;
    getchar();
    for(int i=1;i<=n;i++){
        c[i]=getchar();
        S[i][c[i]-'a']++;
    }
    for(int i=1;i<=n;i++){
        for(int j=0;j<=26;j++){
            S[i][j]+=S[i-1][j];
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=i;j<=n;j++){
            if(check(i,j)) res++;
        }
    }
    cout<<res;
}
