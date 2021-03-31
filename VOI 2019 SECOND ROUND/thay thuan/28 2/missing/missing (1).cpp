#include <bits/stdc++.h>
#include "missinglib.h"
const int N = 1005;
using namespace std;

typedef vector <int> vi;

int n, m;

//namespace XXX{
//    vi ans;
//    int n, m, num[N], cnt;
//    void init(){
//        n = rand()%1000 + 1, m = n-1;
//        for (int i = 1; i <= n; i++) num[i] = i;
//        random_shuffle(num+1, num+1+n);
//        sort(num+1, num+1+m);
//        for (int i = m+1; i <= n; i++) ans.push_back(num[i]);
//        sort(ans.begin(), ans.end());
//        cout << n << " " << m << "\n";
//        for (int i = 1; i <= m; i++) cout << num[i] << " "; cout << "\n";
//        return;
//    }
//
//    int ask(int i, int j){
//        cnt++;
//        if (i > m || i < 1) exit(1);
//        return (num[i] >> j)&1;
//    }
//
//    void guess(vi a){
//        for (int i = 0; i < a.size(); i++) cout << a[i] << " "; cout << "\n";
//        for (int i = 0; i < ans.size(); i++) cout << ans[i] << " "; cout << "\n";
//        if (a == ans) cout << "Correct\n";
//        else cout << "Wrong answer\n";
//        cout << cnt << "\n";
//        exit(0);
//    }
//    int get_n() {return n;}
//    int get_m() {return m;}
//}

vi solve(int Min, int Max, int M, int mask, vi ck){
    vi ans[2], res, nxt[2];
    if (Max - Min + 1 == M) return ans[0];
    if (M == 0){
        for (int i = Min; i <= Max; i++) ans[0].push_back(i^mask);
        return ans[0];
    }

    nxt[0].assign(m, 0); nxt[1].assign(m, 0);
    int bit = 0; for (int i = 10; i >= 0; i--) if (Max&(1 << i)) {bit = i; break;}
    int cnt[] = {(1 << bit) - Min, Max - (1 << bit) + 1};

    if (m == n-1){
        int x = ask((mask^(1 << bit))-1, bit);
        if (x == 0) {
            ans[0] = solve(0, Max ^ (1 << bit), (Max ^ (1 << bit)), mask^(1 << bit), nxt[1]);
        }
        else{
            ans[0] = solve(Min, (1 << bit)-1, (1 << bit)-1 - Min, mask, nxt[0]);
        }
        return ans[0];
    }

    for (int i = 0; i < ck.size(); i++){
        if (ck[i]){
            int x = ask(i+1, bit);
            cnt[x]--; M--; nxt[x][i] = true;
            if (cnt[x] == 0) {
                i++; for (; i < ck.size(); i++) if (ck[i]) nxt[x^1][i] = true, cnt[x^1]--, M--;
            }
        }
    }

    ans[0] = solve(Min, (1 << bit)-1, (1 << bit) - Min - cnt[0], mask, nxt[0]);
    ans[1] = solve(0, Max ^ (1 << bit), Max - (1 << bit) + 1 - cnt[1], mask^(1 << bit), nxt[1]);

    for (int i = 0; i < ans[1].size(); i++) ans[0].push_back(ans[1][i]);
    return ans[0];
}

int main(){
//    srand(time(NULL));
//    init();
    n = get_n(); m = get_m();
    vi a(m, 1);
    guess(solve(1, n, m, 0, a));
}
