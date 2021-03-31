#include <bits/stdc++.h>
using namespace std;

#define NMAX 300005
typedef long long ll;
typedef pair<ll,ll> pll;

int n;
pll a[NMAX];
ll dp[NMAX];

map<ll,ll> pos;
int L[NMAX];
class SegmentTree{
private:
    ll node[4*NMAX];
public:
    void init(){
        for(int i=0;i<4*n;i++){
            node[i] = -1e16;
        }
    }

    void update(int k, int l,int r, int pos, ll val){
        if( l > r || l > pos || r < pos) return ;
        if(l == pos && r == pos){
            node[k] = max(node[k], val);
            return;
        }
        int m = (l+r)>>1;
        update(2*k,l,m,pos,val);
        update(2*k+1,m+1,r,pos,val);
        node[k] = max(node[2*k], node[2*k+1]);
    }

    ll get(int k, int l, int r, int x, int y){
        if(l > y || r < x || l > r || x > y) return -1e16;
        if(l >= x && r <= y) {
            //cout<<"get: "<<l<<" "<<r<<" "<<x<<" "<<y<<" "<<node[k]<<'\n';
            return node[k];
        }
        int m = (l+r)>>1;
        return max(get(2*k,l,m,x,y), get(2*k+1,m+1,r,x,y));
    }
}IT;

int main() {
    cin>>n;
    IT.init();
    for(int i=0; i <=n; i++) dp[i] = -1e16;
    for(int i=1;i<=n;i++){
        cin>>a[i].first;
    }
    //cout<<IT.get(1,1,n,1,2)<<'\n';
    for(int i=1;i<=n;i++){
        cin>>a[i].second;
        pos[a[i].first] = a[i].second;
    }

    stack <int> s;
    for(int i=1;i<=n;i++){
        while(!s.empty() && a[s.top()] >= a[i]) s.pop();
        if(!s.empty()) L[i] = s.top();
        s.push(i);
        int j = L[i];
        if(!L[i]) dp[i] = a[i].second;
        else dp[i] = IT.get(1,1,n,j,i-1) + a[i].second;
        cout<<"GET: "<<j<<" "<<i-1<<" "<<IT.get(1,1,n,j,i-1)<<'\n';
        cout<<i<<" "<<L[i]<<" "<<IT.get(1,1,n,j,i-1)<<" "<<a[i].second<<" "<<dp[i]<<'\n';
        IT.update(1,1,n,i,dp[i]);
        //if(i==2) return 0;
    }
}
/*
10
4 7 3 2 5 1 9 10 6 8
-4 40 -46 -8 -16 4 -10 41 12 3
 */