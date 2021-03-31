#include <iostream>
#include <cstdio>
#include <bitset>

using namespace std;
#define For(i , a , b) for (int i = a , _b = b ; i <= _b ; ++i)
#define Ford(i , a  ,b) for (int i = a , _b = b : i >= _b ; --i)
#define Rep(i , n) for (int i = 0 , _n = n ; i < _n ; ++i)
#define sz(A) ((int)A.size())
#define LL(x) (x << 1)
#define RR(x) ((x << 1) | 1)

typedef pair<int , int> pt;

const int maxn = (1 << 21) + 1;
int n, m;
int edge[24];
int maxN;

void readData() {
    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        int u, v; cin >> u >> v; 
        if (u != v) {
            edge[u] |= (1 << v);
            edge[v] |= (1 << u);
        }
    }
}

int independant[maxn];
void backtrack(const int pos, const int mask) {
    if (pos == n) {
        independant[mask] = 1;
        return;
    }
    backtrack(pos + 1, mask);
    if ((edge[pos] & mask) == 0) backtrack(pos + 1, mask | (1 << pos));
}

bool onbit(const int state, const int pos) {
    return (state >> pos) & 1;
}
void up(int x[maxn]) {
    for (int i = 0; i < n; i++) {
        for (int mask = 0; mask < (1 << n); ++mask) {
            if (onbit(mask, i)) x[mask] += x[mask ^ (1 << i)];
        }
    }
}
void down(int x[maxn]) {
    for (int i = 0; i < n; i++) {
        for (int mask = 0; mask < (1 << n); ++mask) {
            if (onbit(mask, i)) x[mask] -= x[mask ^ (1 << i)];
        }
    }
}

int x[maxn], y[maxn];
bool deb = false;
bitset<maxn> mul (bitset <maxn> X, bitset<maxn> Y) {
    bitset<maxn> res; 
    for (int i = 0; i < (1 << n); i++) x[i] = X[i];
    
    up(x);
    for (int i = 0; i < (1 << n); i++) y[i] = Y[i];
    up(y);
    for (int i = 0; i < (1 << n); ++i) x[i] *= y[i];
    down(x);
    
    if (deb ) return res;
    for (int i = 0; i < maxn; i++) res.set(i, x[i] != 0);
    return res;
}
bitset<maxn> trans(int x[]) {
    bitset<maxn> res;
    for (int i = 0; i < maxn; i++) res.set(i, x[i] != 0);
    return res;
}
bitset<maxn> dp[26];

void Process() {
    backtrack(0, 0);
    dp[1] = trans(independant);
    dp[2] = mul(dp[1], dp[1]);
    dp[4] = mul(dp[2], dp[2]);
    dp[8] = mul(dp[4], dp[4]);
    dp[16] = mul(dp[8], dp[8]);

    bitset<maxn> cur;
    cur.reset(); cur.set(0, 1);
    int res = 0;
    for (int i = 16; i >= 1; i >>= 1) {
        bitset<maxn> nxt = mul(cur, dp[i]);
        if (!nxt.test((1 << n) - 1)) {
            cur = nxt;
            res += i;
        }
    }
    cout << res + 1 << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    freopen("loncon.inp" , "r" , stdin);
    freopen("loncon.out" , "w", stdout);
    readData();
    Process();

    return 0;

}