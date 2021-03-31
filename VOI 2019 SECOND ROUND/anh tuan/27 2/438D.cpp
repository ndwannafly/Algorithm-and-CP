#include <bits/stdc++.h>
#define FOR(i, a, b) for (int i = a; i<= b; ++i)
#define FORD(i, a, b) for (int i = a; i>=b; --i)
#define REP(i, a) for (int i = 0; i<a; ++i)
#define DEBUG(x) { cerr << #x << " = " << x << endl; }
#define Arr(A, l, r) { cerr << #A  << " = "; FOR(_, l, r) cerr << A[_] << ' '; cerr << endl; }
#define N 1001000
#define pp pair<int, int>
#define next __next
#define prev __prev
#define __builtin_popcount __builtin_popcountll
#define bit(S, i) (((S) >> i) & 1)
#define IO ios::sync_with_stdio(false); cin.tie(NULL);cout.tie(NULL);

using namespace std;

pp IT[N << 2];
long long Sum[N << 2];

pp operator+ (pp a, pp b) {
    return pp(max(a.first, b.first), min(a.second, b.second));
}

void Change(int k, int l, int r, int val) {
    IT[k] = pp(val, val);
    Sum[k] = 1ll * (r - l + 1) * val;
}
int a[N];
void Build(int k, int l, int r) {
    if (l == r) {
        Change(k, l, r, a[l]);
        return;
    }
    int m = (l + r) >> 1;
    Build(k << 1, l, m);
    Build(k << 1 | 1, m + 1, r);
    IT[k] = IT[k << 1] + IT[k << 1 | 1];
    Sum[k] = Sum[k << 1] + Sum[k << 1 | 1];
}
void Down(int k, int l, int r) {
    if (IT[k].first != IT[k].second) return;
    int m = (l + r) >> 1;
    Change(k << 1, l, m, IT[k].first);
    Change(k << 1 | 1, m + 1, r, IT[k].first);
}

void Up(int k, int l, int r, int u, int v, int val) {
    if (l > v || r < u) return;
    if (u <= l && r <= v) {
        Change(k, l, r, val);
        return;
    }
    Down(k, l, r);
    int m = (l + r) >> 1;
    Up(k << 1, l, m, u, v, val);
    Up(k << 1 | 1, m + 1, r, u, v, val);
    IT[k] = IT[k << 1] + IT[k << 1 | 1];
    Sum[k] = Sum[k << 1] + Sum[k << 1 | 1];
}

int Max(int k, int l, int r, int u, int v) {
    if (l > v || r < u) return -1;
    if (u <= l && r <= v) return IT[k].first;
    Down(k, l, r);
    int m = (l + r) >> 1;
    return max(Max(k << 1, l, m, u, v), Max(k << 1 | 1, m + 1, r, u, v));
}

void Research(int k, int l, int r, int u, int v, int val, int mod) {
    if (l > v || r < u || IT[k].first < val || IT[k].second > val) return;
    if (u <= l && r <= v) {
        if (IT[k].first == IT[k].second) {
            Change(k, l, r, IT[k].second % mod);
            return;
        }
    }
    Down(k, l, r);
    int m = (l + r) >> 1;
    Research(k << 1, l, m, u, v, val, mod);
    Research(k << 1 | 1, m + 1, r, u, v, val, mod);
    IT[k] = IT[k << 1] + IT[k << 1 | 1];
    Sum[k] = Sum[k << 1] + Sum[k << 1 | 1];
}

long long GetSum(int k, int l, int r, int u, int v) {
    if (l > v || r < u) return 0;
    if (u <= l && r <= v) return Sum[k];
    Down(k, l, r);
    int m = (l + r) >> 1;
    return GetSum(k << 1, l, m, u, v) + GetSum(k << 1 | 1, m + 1, r, u, v);
}
int main() {
    IO;
    freopen("lonnho.inp","r",stdin);
    int n, q;
    cin >> n >> q;
    FOR(i, 1, n) cin >> a[i];
    Build(1, 1, n);
    while (q--) {
        int type, l, r, x;
        cin >> type;
        if (type == 2) {
            cin >> l >> r >> x;
            while (true) {
                int t = Max(1, 1, n, l, r);
                if (t < x) break;
                Research(1, 1, n, l, r, t, x);
            }
        }
        if (type == 3) {
            cin >> l >> x;
            Up(1, 1, n, l, l, x);
        }
        if (type == 1) {
            cin >> l >> r;
            cout << GetSum(1, 1, n, l, r) << '\n';
        }
    }
}
