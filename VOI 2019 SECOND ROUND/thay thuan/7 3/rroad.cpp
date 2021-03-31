#include <bits/stdc++.h>

using namespace std;

const int N = 1005;
const int INF = 1e9;

typedef pair<int, int> ii;

struct Edge {
	int u, v, w; 

	Edge (int u, int v, int w) : u(u), v(v), w(w) {}
};

int n, m;
int dis[N];
int a[N][N];
bool vis[N];
vector<Edge> edges;
vector<ii> G[N];

int cal1(int s, int t, int id) {
	for (int i = 1; i <= n; ++i) dis[i] = INF;
	priority_queue< ii, vector<ii>, greater<ii> > pq;
	pq.push(ii(dis[s] = 0, s));
	while (pq.size()) {
		ii u = pq.top(); pq.pop();
		if (u.first != dis[u.second]) continue;
		if (u.second == t) return u.first; 
		for (auto i : G[u.second]) {
			if (i.first == id) continue;
			ii v = ii(u.first + edges[i.first].w, i.second);
			if (dis[v.second] > v.first) {
				dis[v.second] = v.first, pq.push(v);
			}
		}
	} 
}

struct Vector {
	int sz, a[N];

	void init() { sz = 0; }

	void add(int x) { a[sz++] = x; }

	void del(int x) {
		for (int i = x + 1; i < sz; ++i) a[i - 1] = a[i]; sz--;
	}

};

int cal2(int s, int t, int id) {
	for (int i = 1; i <= n; ++i) dis[i] = INF, vis[i] = 0;
	Vector vec; vec.init();
	vec.add(s), dis[s] = 0, vis[s] = 1;
	while (vec.sz) {
		int p = 0;
		for (int i = 1; i < vec.sz; ++i) {
			if (dis[vec.a[i]] < dis[vec.a[p]]) p = i;
		}
		int u = vec.a[p];
		if (u == t) return dis[u];
		vec.del(p);
		for (auto v : G[u]) {
			if (v.first == id) continue;
			if (dis[v.second] > dis[u] + edges[v.first].w) {
				dis[v.second] = dis[u] + edges[v.first].w;
				if (!vis[v.second]) {
					vec.add(v.second), vis[v.second] = 1;
				}
			}
		}
	} 
}

int main() {
	ios::sync_with_stdio(false);
	cin >> n >> m;
	if (m == 1) {
		cout << "-1.000000"; return 0;
	}	
	for (int i = 1; i <= n; ++i) for (int j = 1; j <= n; ++j) a[i][j] = INF;
	for (int i = 0; i < m; ++i) {
		int u, v, w; cin >> u >> v >> w;
		edges.push_back(Edge(u, v, w));
		G[u].push_back(ii(i, v));
		G[v].push_back(ii(i, u));
		a[u][v] = a[v][u] = min(a[u][v], w);
	}
	double res = 1.0;
	for (int i = 0; i < m; ++i) {
		int tmp;
		int u = edges[i].u, v = edges[i].v, w = edges[i].w;
		if (a[u][v] != w) continue;
		if (m <= 2000) tmp = cal1(u, v, i);
		else tmp = cal2(u, v, i);
		if (tmp == INF) continue;
		// cout << "# " << u << ' ' << v << ' ' << tmp << '\n';
		res = max(res, 1.0 * tmp / w);
	}
	cout << fixed << setprecision(6) << res;
}