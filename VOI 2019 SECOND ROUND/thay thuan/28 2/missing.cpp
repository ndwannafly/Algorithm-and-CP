/*input
7 6
2 3 4 5 6 7
*/
#ifdef EVAL
#include "missinglib.h"
#endif
#include <bits/stdc++.h>
using namespace std;
#define sp ' '
#define endl '\n'
#define fi first
#define se second
#define mp make_pair
#define N 100005
#define bit(x,y) ((x>>y)&1LL)

#ifndef EVAL
namespace Grader {
	int n, m;
	int a[N];
	vector<int> total;
	int numQ = 0;
}
int get_n() {
	cin >> Grader::n;
	return Grader::n;
}
int get_m() {
	cin >> Grader::m;
	for (int i = 1; i <= Grader::m; i++) cin >> Grader::a[i], Grader::total.push_back(Grader::a[i]);
	return Grader::m;
}
int ask(int i, int j) {
	Grader::numQ++;
	return bit(Grader::a[i], j);
}
void guess(vector<int> inp) {
	cout << "Grader :";
	cout << Grader::numQ << endl;
	for (auto it : inp) Grader::total.push_back(it);
	sort(Grader::total.begin(), Grader::total.end());
	if (Grader::total.size() != Grader::n) {
		cout << "Duplicate elements found!" << endl;
		exit(0);
	}
	Grader::total.resize(distance(Grader::total.begin(), unique(Grader::total.begin(), Grader::total.end())));
	if (Grader::total.size() != Grader::n) {
		cout << "Not enough elements found!" << endl;
		exit(0);
	}
	cout << "OK!" << endl;
	exit(0);
}
#endif

#define what_is(x) cerr << #x << " is " << x << endl;
#define error(args...) { string _s = #args; replace(_s.begin(), _s.end(), ',', ' '); stringstream _ss(_s); istream_iterator<string> _it(_ss); err(_it, args); }
void err(istream_iterator<string> it) {}
template<typename T, typename... Args>
void err(istream_iterator<string> it, T a, Args... args) {
	cerr << *it << " = " << a << endl;
	err(++it, args...);
}
template <class T1, class T2>
ostream &operator<<(ostream &os, const pair<T1, T2> &a) {
	return os << '(' << a.first << ", " << a.second << ')';
}
template <class T>
ostream &operator<<(ostream &os, const vector<T> &a) {
	os << '[';
	for (unsigned int i = 0; i < a.size(); i++)
		os << a[i] << (i < a.size() - 1 ? ", " : "");
	os << ']';
	return os;
}
template <class T>
ostream &operator<<(ostream &os, const set<T> &a) {
	os << '{';
	for (typename set<T>::iterator it = a.begin(); it != a.end(); it++) {
		typename set<T>::iterator jt = it;
		os << *it << (++jt != a.end() ? ", " : "");
	}
	os << '}';
	return os;
}
template <class T1, class T2>
ostream &operator<<(ostream &os, map<T1, T2> &a) {
	os << "{\n";
	for (typename map<T1, T2>::iterator it = a.begin(); it != a.end(); it++) {
		typename map<T1, T2>::iterator jt = it;
		os << "  " << it->first << ": " << it->second << (++jt != a.end() ? ",\n" : "\n");
	}
	os << '}';
	return os;
}


int n, m;
bool mark[100005];
void solve(int l, int r, int p) {
	while (p <= m) {
		if (r - l + 1 <= m - p + 1) {
			break;
		}
		int curnum = 0;
		int j = 0;
		while ((1 << j) <= n) {
			// cache question
			int rec = ask(p, j);
			while (rec != bit(l, j)) {
				mark[l] = true;
				// cout << "mark" << sp << l << endl;
				l++;
			}
			// if (j == 0 && p == 2) {
			// 	cout << l << endl;
			// }
			curnum += (rec << j);
			int tmp = curnum + (1 << (j + 1));

			while (tmp <= l) {
				tmp += (1 << (j + 1));
			}
			// cout << l << sp << tmp << endl;
			if (r - tmp + 1 < m - p + 1) {
				// cout << p << sp << tmp << sp << curnum << endl;
				tmp -= (1 << (j + 1));
				tmp = max(tmp, p);
				for (int i = l; i < tmp; i++) {
					// cout << "mark" << sp << i << endl;
					mark[i] = true;
				}
				if (p == m) {
					for (int i = tmp + 1; i <= n; i++) {
						// cout << "mark" << sp << i << endl;
						mark[i] = true;
					}
				}
				p++; l = tmp + 1;
#ifndef EVAL
				cout << "Missing " << sp << tmp << endl;
#endif
				break;
			}
			j++;
		}
	}
	vector<int> ret;
	for (int i = 1; i <= n; i++) if (mark[i]) ret.push_back(i);
	guess(ret);
	// cout << ret << endl;
}

signed main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	n = get_n(); m = get_m();
	solve(1, n, 1);
}