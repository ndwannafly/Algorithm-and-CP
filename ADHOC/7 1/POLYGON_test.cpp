//#include <iostream>
#include <bits/stdc++.h>
#include <vector>
#include <set>
#include <map>
#include <cstring>
#include <string>
#include <cmath>
#include <cassert>
#include <ctime>
#include <algorithm>
#include <sstream>
#include <list>
#include <queue>
#include <deque>
#include <stack>
#include <cstdlib>
#include <cstdio>
#include <iterator>
#include <functional>
#include <bitset>
#define mp make_pair
#define pb push_back
#define M_PI 3.14159265359
#ifdef LOCAL
#define eprintf(...) fprintf(stderr,__VA_ARGS__)
#else
#define eprintf(...)
#endif

#define TIMESTAMP(x) eprintf("["#x"] Time : %.3lf s.\n", clock()*1.0/CLOCKS_PER_SEC)
#define TIMESTAMPf(x,...) eprintf("[" x "] Time : %.3lf s.\n", __VA_ARGS__, clock()*1.0/CLOCKS_PER_SEC)

#if ( _WIN32 || __WIN32__ )
    #define LLD "%I64d"
#else
    #define LLD "%lld"
#endif

using namespace std;

#define TASKNAME "polygon"

#ifdef LOCAL
static struct __timestamper {
	~__timestamper(){
        TIMESTAMP(end);
	}
} __TIMESTAMPER;
#endif

typedef long long ll;
typedef long double ld;

const ld eps = 1e-9;

int sgn(ld x) { return x < -eps ? -1 : x > eps; }
struct point {
  ld x, y;
  point() : x(0), y(0) {}
  point(ld x, ld y) : x(x), y(y) {}
  point operator+(const point &p2) const { return point(x + p2.x, y + p2.y); }
  point operator-(const point &p2) const { return point(x - p2.x, y - p2.y); }
  point operator*(const ld b) const { return point(x * b, y * b); }
  int operator*(const point &p2) const { return x * p2.y - y * p2.x; }
  ld dist2() const { return x * x + y * y; }
  ld dist() const { return sqrt(dist2()); }
  ld atan2() const {return std::atan2(y, x); }
  void load(){
  	int _x,_y;
  	scanf("%d %d",&_x,&_y);
  	x = _x;
  	y = _y;
  }
  point rotate(double ang){
  	ld _x = x * cos(ang) - y * sin(ang);
  	ld _y = x * sin(ang) + y * cos(ang);
  	return point(_x, _y);
  }
};
struct line {
  ld a, b, c;
  line() : a(0), b(0), c(1) {}
  line(const point &p1, const point &p2) {
    a = p1.y - p2.y;
    b = p2.x - p1.x;
    c = -a * p1.x - b * p1.y;
    ld nc = sqrt(norm2());
    a /= nc;
    b /= nc;
    c /= nc;
  }
  line(ld a, ld b, ld c) : a(a), b(b), c(c) {}
  ld distz(const point &p) const { return a * p.x + b * p.y + c; }
  ld norm2() const { return a * a + b * b; }
  int side(const point &p) const { return sgn(a * p.x + b * p.y + c); }
};


int cross(const point &center, ld r,
                 const line &l, point& resp1, point& resp2) {
  ld di = l.distz(center);
  ld d2 = l.norm2();
  assert(fabs(d2) > eps);
  point mid = center + point(l.a, l.b) * (-di / d2);

  ld s = r * r - di * di / d2;
  if (s < -eps) return 0;
  if (fabs(di * di - r * r * d2) < eps){
    resp1 = mid;
    return 1;
  }

  point off = point(-l.b, l.a) * sqrt(s / d2);
  assert(fabs(off.dist2() - s) < eps*max(1.0, (double)fabs(s)));
  vector<point> res;
  resp1 = mid + off;
  resp2 = mid - off;
  return 2;
}

inline bool is_in(ld l, ld r, ld x) {
  if (l > r) swap(l, r);
  return l <= x + eps && x - eps <= r;
}

inline bool contains(const point &a, const point &b, const point &p) {
  if (sgn((p - a) * (p - b)) != 0) return false;
  return is_in(a.x, b.x, p.x) &&
         is_in(a.y, b.y, p.y);
}


vector<point> cross(const point& center, ld r, const point& p1, const point& p2){
	point resp1, resp2;
	int cnt = cross(center, r, line(p1, p2), resp1, resp2);
	vector<point> res;
	cout<<"cnt: "<<cnt<<'\n';
	cout<<resp2.x<<" "<<resp2.y<<'\n';
	exit(0);
	if (cnt >= 1 && contains(p1, p2, resp1))
		res.pb(resp1);
	if (cnt >= 2 && contains(p1, p2, resp2))
		res.pb(resp2);
	return res;
}

const int MAXN = 2000;

point pt[MAXN];
int n;

/*point getCenter(){
	ld s = 0;
	point center;
	for (int i = 0; i < n; i++){
		ld ds = pt[i] * pt[(i+1) % n];
		center = center + (pt[i] + pt[(i+1) % n]) * ds;
//		eprintf("%lf\n", (double)ds);
		s += ds;
	}
//	eprintf("%lf\n", (double)s);
	center = center * (1.0/(3*s));
	return center;
}*/



int main(){
  freopen("polygon.inp","r",stdin);
  freopen("polygon.out","w",stdout);

  scanf("%d",&n);
  for (int i = 0; i < n; i++)
  	pt[i].load();

/*  point center = getCenter();
  double ang = -M_PI/2 - (center - pt[0]).atan2();*/

  point base = pt[0];

  for (int i = 0; i < n; i++){
	pt[i] = (pt[i] - base);//.rotate(ang);
    //cout<<pt[i].x<<" "<<pt[i].y<<'\n';
  }
  //  return 0;

  int m;
  scanf("%d",&m);
  for (int i = 0; i < m; i++){
  	point nail;
  	nail.load();
  	nail = nail - base;
    cout<<"nail: "<<nail.x<<" "<<nail.y<<'\n';
  	double dst = nail.dist();
    double min_ang = -2*M_PI;
    double max_ang = 2*M_PI;
    double nailatan2 = nail.atan2();
    cout<<dst<<" "<<nailatan2<<'\n';
  	for (int j = 0; j < n; j++){
  		vector<point> bad = cross(pt[0], dst, pt[j], pt[(j+1) % n]);
  		//cout<<bad.size();
  		return 0;
  		for (int k = 0; k < (int)bad.size(); k++){
  			double ang = nailatan2 - bad[k].atan2();
  			cout<<k<<" "<<ang<<'\n';
            while (ang > eps) ang -= 2*M_PI;
            while (ang < -2*M_PI - eps) ang += 2*M_PI;
            min_ang = max(min_ang, ang);
            ang += 2*M_PI;
            max_ang = min(max_ang, ang);
  		}
  	}
  	cout<<min_ang<<" "<<max_ang<<'\n';
    assert(min_ang < eps);
    assert(max_ang > -eps);
    printf("%.12lf %.12lf\n", -min_ang / M_PI * 180, max_ang / M_PI * 180);
  }
  return 0;
}
