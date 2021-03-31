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
    return had>=k;
}
inline bool check2(int l,int r){
    int had=0;
    for(int i=0;i<=26;i++){
        if(S[r][i]-S[l-1][i]>0){
            ++had;
        }
    }
    return had>=k+1;
}
string str(int x){
    stringstream s;
    s<<x;
    string st;
    s>>st;
    return st;
}
inline ll solve(){
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
        int l=i,r=n;
        int fmin=0,fmax=0;
        while(l<=r){
            int m=(l+r)>>1;
            if(check(i,m)){
                fmin=m;
                r=m-1;
            }
            else l=m+1;
        }
        l=fmin,r=n;
        while(l<=r){
            int m=(l+r)>>1;
            if(check2(i,m)){
                fmax=m;
                r=m-1;
            }
            else l=m+1;
        }
        fmax--;
        if(fmin==0) continue;
        int had=0;
        for(int j=0;j<=26;j++){
            if(S[fmin][j]-S[i-1][j]>0) had++;
        }
        if(had!=k) continue;
        if(fmax==-1) fmax=n;
        res+=(fmax-fmin+1);
    }
    return res;
}
void make(int test){
    ofstream f1 ((str(test)+".inp").c_str());
    ofstream f2 ((str(test)+".out").c_str());
    memset(c,0,sizeof(c));
    memset(S,0,sizeof(S));
    res=0;
    n=1000000;
    k=rand()%25+1;
    f1<<n<<" "<<k<<'\n';
    for(int i=1;i<=n;i++){
        c[i]=char(rand()%26+'a');
        f1<<c[i];
    }
    f1<<'\n';
    f2<<solve();
}
int main(){
    srand(time(NULL));
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int itest;
    for(itest=51;itest<=60;itest++){
        make(itest);
    }
}
