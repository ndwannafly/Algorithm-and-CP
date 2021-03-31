
#include <cstring>
#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <fstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <climits>
#include <cstdlib>
#include <ctime>
#include <memory.h>
#include <cassert>

#define FOR(i, a, b) for(int i = (a); i < (b); ++i)
#define REP(i, a, b) for(int i = (a); i <=(b); ++i)
#define FORD(i, a, b) for(int i = (a); i > (b); --i)
#define REPD(i, a, b) for(int i = (a); i >=(b); --i)
#define TR(it, a) for(__typeof(a.begin()) it = a.begin(); it != a.end(); ++it)
#define RESET(a, v) memset(a, (v), sizeof(a))
#define SZ(a) (int(a.size()))
#define ALL(a) a.begin(), a.end()
#define PB push_back
#define MP make_pair
#define LL long long
#define LD long double
#define II pair<int, int>
#define X first
#define Y second
#define VI vector<int>
#define VII vector<II>
#define endl '\n'

const int N = 222;
const int INF = INT_MAX;

using namespace std;

int d[N]; int T[N];
bool inQ[N];
int cap[N][N], cost[N][N], flow[N][N];
int n, m, source, sink;
int minCost, maxFlow;

bool findPath() {
  REP(i, 1, n) {
  queue<int> Q;
    d[i] = INF;
    T[i] = 0;
    inQ[i] = 0;
  }
  Q.push(source); inQ[source] = 1; d[source] = 0LL;
  while (!Q.empty()) {
    int u = Q.front(); Q.pop(); inQ[u] = 0;
    REP(v, 1, n)
    if (flow[u][v] < cap[u][v]) {
      int uv = (flow[u][v] < 0 ? -1 : 1) * cost[u][v];
      if (d[v] > d[u] + uv) {
        d[v] = d[u] + uv;
        T[v] = u;
        if (!inQ[v]) {
          inQ[v] = 1;
          Q.push(v);
        }
      }
    }
  }
  return T[sink] != 0;
}

void incFlow() {
  int delta = INF;
  for (int v = sink; v != source; v = T[v])
    delta = min(delta, flow[T[v]][v] >= 0 ? (cap[T[v]][v] - flow[T[v]][v]) : -flow[T[v]][v]);
  for (int v = sink; v != source; v = T[v])
    flow[T[v]][v] += delta, flow[v][T[v]] -= delta;
  maxFlow += delta;
  minCost += d[sink] * delta;
}

int main() {
   // freopen("mincost.inp","r",stdin);
  ios::sync_with_stdio(0); cin.tie(0);
  #ifdef _LAD_
    freopen("9.in", "r", stdin);
  #endif // _LAD_
  cin >> n >> m >> maxFlow >> source >> sink;
  int u, v;
  FOR(i, 0, m) {
    cin >> u >> v;
    cin >> cost[u][v] >> cap[u][v];
    cost[v][u] = cost[u][v];
    cap[v][u] = cap[u][v];
  }
  ++n;
  cost[n][source] = 0;
  cap[n][source] = maxFlow;
  int S = maxFlow;
  source = n;
  maxFlow = 0;
  while (findPath()) incFlow();
  if (maxFlow < S) cout << -1 << endl;
  else {
    cout << minCost << endl;
    FOR(u, 1, n) FOR(v, 1, n)
    if (flow[u][v] > 0)
      cout << u << ' ' << v << ' ' << flow[u][v] << endl;
    cout << "0 0 0\n";
  }
  return 0;
}
