#include <bits/stdc++.h>

#define FOR(x, a, b) for (int x = a; x <= b; ++x)
#define FOD(x, a, b) for (int x = a; x >= b; --x)
#define REP(x, a, b) for (int x = a; x < b; ++x)
#define DEBUG(X) { cout << #X << " = " << X << endl; }
#define PR(A, n) { cout << #A << " = "; FOR(_, 1, n) cout << A[_] << " "; cout << endl; }
#define PR0(A, n)  { cout << #A << " = "; REP(_, 0, n) cout << A[_] << " "; cout << endl; }

using namespace std;

typedef long long LL;
typedef pair <int, int> II;

const int N = 1e3 + 10;
const int INF = 0x3f3f3f3f;

int n, m;
int dp[N][N], a[N][N], s[N][N];

bool Inside(int x, int y) {
    return 1 <= x && x <= n + 1 && 0 <= y && y <= m;
}

int DP(int i, int j) {
    if (i == n + 1 && j == m) return 0;
    int &ans = dp[i][j];
    if (ans != -1) return ans;
    ans = -INF;
    // R
    if (Inside(i, j + 1)) ans = max(ans, -DP(i, j + 1));
    // D
    bool first = ((i + j) % 2 == 1);
    int sum = (s[i][m] - s[i][j]) - s[i][j];
    if (Inside(i + 1, j)) ans = max(ans, -DP(i + 1, j) + (first ? sum : -sum));
    cout<<i<<" "<<j<<" "<<ans<<'\n';
    return ans;
}

int main() {
    freopen("forecast.inp","r",stdin);
    scanf("%d%d", &m, &n);
    cout<<m<<" "<<n<<'\n';
    FOR(i, 1, n)
        FOR(j, 1, m) scanf("%d", &a[i][j]);
    FOR(i, 1, n)
        FOR(j, 1, m) s[i][j] = s[i][j - 1] + a[i][j];
    memset(dp, -1, sizeof dp);
    cout << abs(DP(1, 0)) << endl;
    return 0;
}
