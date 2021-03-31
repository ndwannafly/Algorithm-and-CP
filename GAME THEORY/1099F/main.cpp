#include <bits/stdc++.h>
using namespace std;

#define NMAX 100005
#define MAX 1000005
#define pb push_back
typedef long long ll;
typedef pair<long,long> pll;

ll n,T;
ll x[NMAX],t[NMAX];
vector <pll> adj[NMAX];
ll F[NMAX];

class FenWickTree{
    ll Time[1000005];
    ll Cookies[1000005];

public:
    void init(){
        memset(Time,0,sizeof(Time));
        memset(Cookies,0,sizeof(Cookies));
    }
    void update(ll u, ll val){
        for(ll i = u ; i < MAX ; i += i & -i){
            Time[i] += u * val;
            Cookies[i] += val;
        }
    }

    ll getTime(ll u){
        ll res = 0;
        for(ll i = u ; i ; i-= i & -i){
            res+= Time[i];
        }
        return res;
    }

    ll getCookies(ll u){
        ll res = 0;
        for(ll i = u; i ; i -= i & -i){
            res += Cookies[i];
        }
        return res;
    }
} BIT;

ll cal_cookies(ll val){
    ll best_choice = 0;
    ll sum = 0;
    ll l = 1 , r = MAX;
    while(l <= r){
        ll m = (l+r)>>1; // time eat cookies
        ll cur = BIT.getTime(m); // time to eat cookies from 1 -> m
        if(cur < val){
            best_choice = m; // res = 2
            sum = cur;
            l = m + 1;
        }
        else{
            r = m  - 1;
        }
    }
    ll res = BIT.getCookies(best_choice); // number of cookies if we eat from 1 -> best_choice
    if(best_choice < MAX){
        res += min(BIT.getCookies(best_choice + 1) - BIT.getCookies(best_choice), (val - sum)/(best_choice+1));
    }
    return res;
}

void preDFS(ll u, ll remain){
    if(remain <= 0 ) return;
    BIT.update(t[u],x[u]);
    F[u] = cal_cookies(remain);
    for(auto e:adj[u]){
        ll v = e.first, w = e.second;
        if(remain - 2*w > 0) {
            preDFS(v, remain - 2 * w);
            BIT.update(t[v], -x[v]);
        }
    }
}

void DFS(int u){
    priority_queue<ll> pq;
    for(auto e : adj[u]){
        ll v = e.first, w = e.second;
        DFS(v);
        pq.push(F[v]);
    }
    if(u == 1){
        F[u] = max(F[u], pq.top());
        return ;
    }
    if(pq.size() < 2) return;
    pq.pop();
    F[u] = max(F[u], pq.top());
}
int main() {
    //freopen("D:\\ALGO\\GAME THEORY\\1099F\\test.txt","r",stdin);
    cin>>n>>T;
    //cout<<n<<" "<<T<<'\n';
    for(int i=1;i<=n;i++) cin>>x[i];
    for(int i=1;i<=n;i++) cin>>t[i];
    for(int i=2;i<=n;i++){
        ll p,l;
        cin>>p>>l;
        adj[p].pb({i,l});
    }
    BIT.init();
    preDFS(1,T);
    DFS(1);
    cout<<F[1];
}
