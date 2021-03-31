#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
const ll base=1e9+7;
#define NMAX 755
#define pb push_back
int n;
string s[NMAX];
ll Hash[NMAX][50000];
ll pw[50000];
inline void get(int id,string t){
    Hash[id][0]=t[0]-'a';
    for(int i=1;i<t.size();i++){
        Hash[id][i]=(Hash[id][i-1]*base+t[i]-'a');
    }
}
inline ll gethash(int id,int l,int r){
    if(l==0) return Hash[id][r];
    return Hash[id][r]-Hash[id][l-1]*pw[r-l+1];
}
vector <int> adj[NMAX];
int married[2*NMAX],visited[2*NMAX],cnt;
inline bool DFS(int u){
    if(visited[u]!=cnt) visited[u]=cnt;
    else return false;
    for(int v:adj[u]){
        if(!married[v]||DFS(married[v])){
            married[v]=u;
           // cout<<v<<" "<<u<<'\n';
            return true;
        }
    }
    return false;
}
int main(){
    freopen("greetingcard.inp","r",stdin);
    freopen("greetingcard.out","w",stdout);
    pw[0]=1;
    for(int i=1;i<50000;i++){
        pw[i]=pw[i-1]*base;
    }
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>s[i];
        get(i,s[i]);
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(i==j) continue;
            ll now=Hash[i][s[i].size()-1];
            int l=0,r=s[i].size()-1;
            while(r<s[j].size()){
                if(gethash(j,l,r)==now){
                    adj[j].pb(i+NMAX);
                    break;
                }
                l++,r++;
            }
           // return 0;
        }
    }
    int ans=n,res=0;
    for(int i=1;i<=n;i++){
        if(!visited[i]){
            cnt++;
            res+=DFS(i);
        }
    }
    cout<<ans-res;
}
