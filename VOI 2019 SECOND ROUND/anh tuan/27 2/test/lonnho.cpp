/*input
3 3
2 1 3 3
1 1 2 2
3 1 3
*/
#include <iostream>
#include <cstdio>
using namespace std;
#define For(i , a , b) for (int i = a , _b = b ; i <= _b ; ++i)
#define Ford(i , a  ,b) for (int i = a , _b = b : i >= _b ; --i)
#define Rep(i , n) for (int i = 0 , _n = n ; i < _n ; ++i)
#define sz(A) ((int)A.size())
#define LL(x) (x << 1)
#define RR(x) ((x << 1) | 1)

typedef pair<int , int> pt;

const int maxn = 100000 + 123;
int n, Q;

void ReadData() {
	cin >> n >> Q;
}

int l[maxn * 4], h[maxn * 4];
struct node {
	int mn, mx, lazyAss, lazyMod;
	long long tot;

	node() {
		mn = mx = 0;
		lazyAss = lazyMod = -1;
		tot = 0;
	}
	node (int _mn, int _mx, int _lazyAss, int _lazyMod, long long _tot) {
		mn = _mn, mx = _mx, lazyAss = _lazyAss, lazyMod = _lazyMod;
		tot = _tot;
	}
} it[maxn * 4];
node combine(const node L, const node R) {
	node res;
	res.mn = min(L.mn, R.mn);
	res.mx = max(L.mx, R.mx);
	res.tot = L.tot + R.tot;
	return res;
}
void buildTree(const int x, const int lo, const int hi) {
	l[x] = lo; h[x] = hi;
	if (lo != hi) {
		int mid = (lo + hi) >> 1;
		buildTree(LL(x), lo, mid);
		buildTree(RR(x), mid + 1, hi);
	}
}
void ass(const int x, const int val) {
	it[x] = node (val, val, val, -1, 1LL * val * (h[x] - l[x] + 1));
}
void doMod(const int x, const int val) {
	it[x] = node (
	            it[x].mn % val,
	            it[x].mx % val,
	            -1,
	            val,
	            1LL * (it[x].mn % val) * (h[x] - l[x] + 1)
	        );
}
void pushDown(const int x) {
	if (l[x] == h[x]) return;
	if (it[x].lazyMod != -1) {
		doMod(LL(x), it[x].lazyMod);
		doMod(RR(x), it[x].lazyMod);
		it[x].lazyMod = -1;
	}
	if (it[x].lazyAss != -1) {
		ass(LL(x), it[x].lazyAss);
		ass(RR(x), it[x].lazyAss);
		it[x].lazyAss = -1;
	}


}
void updateAssign(const int x, const int u, const int v, const int val) {
	if (l[x] > v || h[x] < u) return;
	if (u <= l[x] && h[x] <= v) {
		ass(x, val);
		return;
	}
	pushDown(x);
	updateAssign(LL(x), u, v, val);
	updateAssign(RR(x), u, v, val);
	it[x] = combine(it[LL(x)], it[RR(x)]);
}
void updateMod(const int x, const int u, const int v, const int val) {
	if (l[x] > v || h[x] < u || it[x].mx < val) return;
	if (u <= l[x] && h[x] <= v && it[x].mn == it[x].mx) {
		updateAssign(x, u, v, it[x].mn % val);
		return;
	}
	pushDown(x);
	updateMod(LL(x), u, v, val);
	updateMod(RR(x), u, v, val);
	it[x] = combine(it[LL(x)], it[RR(x)]);
}
long long getSum(const int x, const int u, const int v) {
	if (l[x] > v || h[x] < u) return 0;
	if (u <= l[x] && h[x] <= v) {
		return it[x].tot;
	}
	pushDown(x);
	return getSum(LL(x), u, v) + getSum(RR(x), u, v);
}

void Process() {
	buildTree(1, 1, n);

	while (Q--) {
		int typ, l, r; cin >> typ >> l >> r;

		if (typ == 1) {
			///mod query
			int val; cin >> val;
			updateMod(1, l, r, val);
		}

		if (typ == 2) {
			///assign query
			int val; cin >> val;
			updateAssign(1, l, r, val);
		}

		if (typ == 3) {
			cout << getSum(1, l, r) << "\n";
		}
	}
}

int main() {
    freopen("lonnho.inp" , "r", stdin);
    freopen("lonnho.out" , "w", stdout);

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	ReadData();
	Process();

	return 0;

}