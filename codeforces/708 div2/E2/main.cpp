#include<bits/stdc++.h>
#define ll long long
#define ld long double
#define ull unsigned long long
#define i128 __int128
#define fi first
#define se second
#define mpa make_pair
#define eb emplace_back
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
using namespace std;
mt19937 gen(time(0));
mt19937_64 gen64(time(0));

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    vector<int> h(1e7 + 5);
    vector<int> e(1e7 + 5, 1);
    vector<int> minD(1e7 + 5, -1);
    minD[1] = 1;
    for (ll i = 2; i < 1e7 + 5; ++i) {
        if (e[i]) {
            minD[i] = i;
            for (ll j = i; j * i < 1e7 + 5; ++j) {
                e[i * j] = 0;
                if (minD[i * j] == -1) {
                    minD[i * j] = i;
                } else {
                    minD[i * j] = min(minD[i * j], (int)i);
                }

            }
        }
    }
    int T = 1;
    cin >> T;
    while (T-->0) {
        int n, k;
        cin >> n >> k;
        vector<int> a(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
            int ans = 1;
            map<int, int> cnt;
            while (minD[a[i]] != 1) {
                ++cnt[minD[a[i]]];
                a[i] /= minD[a[i]];
            }
            for (auto &elem : cnt) {
                if (elem.se % 2) {
                    ans *= elem.fi;
                }
            }
            a[i] = ans;
        }
        vector<vector<int>> sameSegment(k + 1, vector<int>(n));
        for (int i = 0; i <= k; ++i) {
            for (int j = 0; j < n; ++j) h[a[j]] = 0;
            int l = 0, cnt = 0;
            for (int j = 0; j < n; ++j) {
                ++h[a[j]];
                if (h[a[j]] > 1) {
                    ++cnt;
                }
                while (cnt > i) {
                    if (h[a[l]] > 1) {
                        --cnt;
                    }
                    --h[a[l]];
                    ++l;
                }
                sameSegment[i][j] = l;
            }
        }
        vector<vector<int>> dp(k + 1, vector<int>(n, 1e9));
        for (int i = 0; i <= k; ++i) {
            for (int j = 0; j < n; ++j) {
                for (int z = 0; z <= i; ++z) {
                    int ans = 1;
                    if (sameSegment[i - z][j] - 1 != -1) {
                        ans += dp[z][sameSegment[i - z][j] - 1];
                    }
                    dp[i][j] = min(dp[i][j], ans);
                }
            }
        }
        int res = 1e9;
        for (int j = 0; j <= k; ++j) {
            res = min(res, dp[j][n - 1]);
        }
        cout << res << '\n';
    }
}
/*
*/
