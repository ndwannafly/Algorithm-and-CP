#include <bits/stdc++.h>
using namespace std;
template <typename T> inline void read (T &x){
    bool nega=0;
    char c;
    while((!isdigit(c=getchar()))&&c!='-');
    if(c=='-'){
        nega=1;
        c=getchar();
    }
    x=c-48;
    while(isdigit(c=getchar())) x=x*10+c-48;
    if(nega) x=-x;
}
template <typename T> inline void writep(T x){
    if(x>9) writep(x/10);
    putchar(x%10+48);
}
template <typename T> inline void write(T x){
    if(x<0){
        putchar('-');
        x=-x;
    }
    writep(x);
}
template <typename T> inline void writeln(T x){
    write(x);
    putchar('\n');
}

typedef long long ll;
const ll base = 1e9+7;

vector <ll> a;
int cnt[10000001];
int prev_divisor[10000005];
int dp[200005][22];
int look_back[200005][22];
void sieve(){
    for(int i=2;i<=10000000;i++) {
        if (!prev_divisor[i]) {
            prev_divisor[i] = i;
            for (int j = i + i; j <= 10000000; j += i) {
                prev_divisor[j] = i;
            }
        }
    }
}

ll Analyze(ll x){
    ll code = 1;
    while(x!=1){
        ll degree = 0;
        ll u = prev_divisor[x];
        while(x % u == 0){
            ++degree;
            x /= u ;
        }
        degree %= 2;
        if(degree){
            code *= u;
        }
    }
    return code;
}
int main() {
    //srand(time(NULL));
    //freopen("test.inp","r",stdin);
    sieve();

    int test;
    read(test);
    while(test--){
        a.clear();
        int n,k;
        read(n);
        read(k);
        for(int i=0;i<=n;i++){
            for(int j=0;j<=k;j++) dp[i][j] = 1e9,look_back[i][j]=0;
        }
        for(int i=1;i<=n;i++){
            ll x;
            read(x);
            ll cur = Analyze(x);
            cnt[cur] = 0;
            a.emplace_back(cur);
        }
        for(int i = 0 ; i <= k ; i++){
            int got = 0;
            int l = n;

            for(int r = n-1 ; r >= 0 ; r--){
                while(l >= 1 && got + (cnt[a[l-1]] >0 ) <= i){
                    --l;
                    got += (cnt[a[l]] > 0);
                    ++cnt[a[l]];
                }
                look_back[r][i] = l;
                if(cnt[a[r]] > 1) --got;
                cnt[a[r]]--;
            }
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<=k;j++){
                for(int x = 0 ;x <= j ; x++){
                    int l = look_back[i][x];
                    if(l-1>=0) {
                        dp[i][j] = min(dp[i][j], dp[l - 1][j - x] + 1);
                    }
                    else dp[i][j] = 1;
                }
            }
        }

        int res = 1e9;
        for(int i=0;i<=k;i++) res = min(res, dp[n-1][i]);
        writeln(res);
    }
}
