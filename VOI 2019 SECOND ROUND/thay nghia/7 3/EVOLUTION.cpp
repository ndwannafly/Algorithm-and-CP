#include <bits/stdc++.h>
using namespace std;
#define NMAX 100005
#define pb push_back
typedef pair<int,int> pii;
typedef long long ll;
typedef pair<ll,ll> pll;

inline pair<pll,pll> make_data(int a,int t,int c,int g){
    pair<pll,pll> res;
    res.first.first=a;
    res.first.second=t;
    res.second.first=c;
    res.second.second=g;
    return res;
}
ll n,l,cnta,cntc,cntt,cntg,res;
map <pair<pll,pll>,int> mymap;
map <pair<pll,pll>,bool> ok;
string s;
void enter(){
    cin>>n>>l;
    cin>>s;
    s='*'+s;
}
void progress(){
    for(int i=1;i<=l;i++){
        if(s[i]=='A') cnta++;
        if(s[i]=='C') cntc++;
        if(s[i]=='T') cntt++;
        if(s[i]=='G') cntg++;
    }
    mymap[make_data(cnta,cntt,cntc,cntg)]++;
    if(!ok[make_data(cnta,cntt,cntc,cntg)]){
        ok[make_data(cnta,cntt,cntc,cntg)]=true;
        res++;
    }
    for(int i=l+1;i<=n;i++){
        if(s[i]=='A') cnta++;
        if(s[i]=='C') cntc++;
        if(s[i]=='T') cntt++;
        if(s[i]=='G') cntg++;
        if(s[i-l]=='A') cnta--;
        if(s[i-l]=='C') cntc--;
        if(s[i-l]=='T') cntt--;
        if(s[i-l]=='G') cntg--;
        mymap[make_data(cnta,cntt,cntc,cntg)]++;
        if(!ok[make_data(cnta,cntt,cntc,cntg)]){
            ok[make_data(cnta,cntt,cntc,cntg)]=true;
            res++;
        }
    }
    cout<<res;
}
int main(){
    freopen("EVOLUTION.inp","r",stdin);
    freopen("EVOLUTION.out","w",stdout);
    enter();
    progress();
}
