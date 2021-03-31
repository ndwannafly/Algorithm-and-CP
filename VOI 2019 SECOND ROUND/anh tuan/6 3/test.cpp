#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

#define FOR(i, a, b) for (int i = (a), i##_END_ = (b); i <= i##_END_; i++)
#define DNF(i, a, b) for (int i = (a), i##_END_ = (b); i >= i##_END_; i--)

template <typename Tp> void in(Tp &x) {
	char ch = getchar(), f = 1; x = 0;
	while (ch != '-' && (ch < '0' || ch > '9')) ch = getchar();
	if (ch == '-') ch = getchar(), f = -1;
	while (ch >= '0' && ch <= '9') x = x * 10 + ch - '0', ch = getchar();
	x *= f;
}

template <typename Tp> void out(Tp x) {
	if (x > 9) out(x / 10);
	putchar(x % 10 + '0');
	return;
}

template <typename Tp> Tp Max(const Tp &x, const Tp &y) {return x > y ? x : y;}
template <typename Tp> Tp Min(const Tp &x, const Tp &y) {return x < y ? x : y;}
template <typename Tp> bool chkmax(Tp &x, Tp y) {return x >= y ? 0 : (x=y, 1);}
template <typename Tp> bool chkmin(Tp &x, Tp y) {return x <= y ? 0 : (x=y, 1);}

const int MAXN = 200010;

struct Obj {
	int L, R;
} num[MAXN];

int n, m;
int maxx[MAXN << 2], tag[MAXN << 2];

bool cmp(const Obj &x, const Obj &y) {return x.L < y.L;}

void build(int now, int l, int r)
{
	if (l == r) {
		maxx[now] = -(m - (l - 1) + 1);
		return;
	}
	int mid = (l + r) >> 1;
	build(now << 1, l, mid); build(now << 1 | 1, mid + 1, r);
	maxx[now] = Max(maxx[now << 1], maxx[now << 1 | 1]);
}

void pushdown(int now)
{
	if (!tag[now]) return;
	maxx[now << 1] += tag[now]; tag[now << 1] += tag[now];
	maxx[now << 1 | 1] += tag[now]; tag[now << 1 | 1] += tag[now];
	tag[now] = 0;
}

void modify(int now, int l, int r, int x, int y, int z)
{
	if (x <= l && r <= y) {
		maxx[now] += z; tag[now] += z; return;
	}
	pushdown(now);
	int mid = (l + r) >> 1;
	if (x <= mid) modify(now << 1, l, mid, x, y, z);
	if (mid < y) modify(now << 1 | 1, mid + 1, r, x, y, z);
	maxx[now] = Max(maxx[now << 1], maxx[now << 1 | 1]);
}

int query(int now, int l, int r, int x, int y)
{
	if (x <= l && r <= y) return maxx[now];
	pushdown(now);
	int mid = (l + r) >> 1;
	if (y <= mid) return query(now << 1, l, mid, x, y);
	if (mid < x) return query(now << 1 | 1, mid + 1, r, x, y);
	return Max(query(now << 1, l, mid, x, y), query(now << 1 | 1, mid + 1, r, x, y));
}

int main()
{
    freopen("D.inp","r",stdin);
	in(n); in(m);
	FOR(i, 1, n) in(num[i].L), in(num[i].R);

	std::sort(num + 1, num + n + 1, cmp);

	build(1, 1, m + 2);

	int he = Max(0, n - m);

	FOR(i, 1, n) {
	    cout<<i<<" "<<num[i].L<<" "<<num[i].R<<'\n';
		modify(1, 1, m + 2, 1, num[i].R + 1, 1);
		chkmax(he, query(1, 1, m + 2, num[i].L + 2, num[i].R + 1) - num[i].L);
		cout<<query(1, 1, m + 2, num[i].L + 2, num[i].R + 1)<<" "<<num[i].L<<'\n';
	}

	printf("%d\n", he);

	return 0;
}
