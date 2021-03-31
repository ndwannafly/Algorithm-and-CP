// E - LEQ and NEQ
#include <bits/stdc++.h>

using namespace std;

#define	MOD	998244353

int main(int argc, char *argv[])
{
	cin.tie(0)->sync_with_stdio(0);
	int n;
	cin >> n;
	vector<long long> a(n);
	for (auto &x : a) cin >> x;

	vector<long long> dp(n + 1);
	dp[0] = 1;
	vector<pair<int, long long>> st;
	long long cur = 0;
	for (int i = 1; i <= n; i++) {
		long long to_add = 0;
		for (; !st.empty() && a[st.back().first] >= a[i - 1]; st.pop_back()) {
			cur = (cur - st.back().second * a[st.back().first] % MOD + MOD) % MOD;
			to_add = (to_add + st.back().second) % MOD;
		}
		long long t = ((i - 1) & 1) ? (MOD - dp[i - 1]) % MOD : dp[i - 1];
		to_add = (to_add + t) % MOD;
		cur = (cur + to_add * a[i - 1] % MOD) % MOD;
		st.push_back({i - 1, to_add});
		dp[i] = i % 2 ? cur : (MOD - cur) % MOD;
	}

	cout << dp[n] << endl;

	return 0;
}
