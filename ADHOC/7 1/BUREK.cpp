#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
#define NMAX 1000005
#define pb push_back
int n;
ll X[NMAX],Y[NMAX];
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("BUREK.inp","r",stdin);
    freopen("BUREK.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        ll a,b,c,d,e,f;
        cin>>a>>b>>c>>d>>e>>f;
        ll x=1e7,y=0;
        x=min(x,a);
        x=min(x,c);
        x=min(x,e);
        y=max(y,a);
        y=max(y,c);
        y=max(y,e);
        X[x+1]++,X[y]--;
        x=1e7,y=0;
        x=min(x,b);
        x=min(x,d);
        x=min(x,f);
        y=max(y,b);
        y=max(y,d);
        y=max(y,f);
        Y[x+1]++,Y[y]--;
    }
    for(int i=0;i<=1000000;i++){
        X[i]+=X[i-1];
        Y[i]+=Y[i-1];
    }
    int test;
    cin>>test;
    while(test--){
        char a,b;int x;
        cin>>a>>b>>x;
        if(a=='x'){
            cout<<X[x]<<'\n';
        }
        else cout<<Y[x]<<'\n';
    }
}
