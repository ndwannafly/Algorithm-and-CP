#include <iostream>
#include <cstdio>
using namespace std;
#define For(i , a , b) for (int i = a , _b = b ; i <= _b ; ++i)
#define Ford(i , a  ,b) for (int i = a , _b = b : i >= _b ; --i)
#define Rep(i , n) for (int i = 0 , _n = n ; i < _n ; ++i)
#define sz(A) ((int)A.size())
#define LL(x) (x << 1)
#define int long long
#define RR(x) ((x << 1) | 1)

typedef pair<int , int> pt;
const int maxn = 200000 + 123;
const int lg = 19;
int n, a[maxn];

void ReadData() {
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];
}

bool onbit(const int state, const int pos) {
    return (state >> pos) & 1;
}

void up(int x[]) {
    for (int i = 0; i <= lg; i++) {
        for (int mask = 0; mask < maxn; mask++) {
            if (onbit(mask, i)) x[mask] += x[mask ^ (1 << i)]; 
        }
    }
}
void down(int x[]) {
    for (int i = 0; i <= lg; i++) {
        for (int mask = 0; mask < maxn; mask++) {
            if (onbit(mask, i)) x[mask] -= x[mask ^ (1 << i)]; 
        }
    }
}


int fa[lg + 1][maxn];
int res[maxn];
int fb[lg + 1][maxn];

void Process() {
    for (int i = 1; i <= n; i++) {
        fa[__builtin_popcount(a[i])][a[i]]++;
    }
    for (int i = 0; i <= lg; i++) up(fa[i]);
    for (int x = 0; x < maxn; x++) {
        for (int i = 0; i <= lg; i++) {
            long long tot = 0;
            for (int j = 0; j <= i; j++) {
                tot += fa[j][x] * fa[i - j][x];
            }
            fb[i][x] = tot;
        }
    }
    for (int i = 0; i <= lg; i++) down(fb[i]);
    int best = 0;
    for (int s = 0; s < maxn; ++s) {
        if (fb[__builtin_popcount(s)][s] > best) best = s;
    }

    cout << best << endl;
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    freopen("lonu.inp" , "r", stdin);
    freopen("lonu.out" , "w" , stdout);
    ReadData();
    Process();

    return 0;

}