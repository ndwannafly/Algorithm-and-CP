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

#define NMAX 500005

ll lcm, g, x, y;
ll n,m,k;
ll A[NMAX];
ll B[NMAX];
ll aI[2*NMAX], bI[2*NMAX];
vector <ll> v;

inline ll exgcd(ll a,ll b,ll &x,ll &y){
    if(!b){
        x=1,y=0;
        return a;
    }
    ll xx,yy;
    ll g=exgcd(b,a%b,xx,yy);
    x=yy;
    y=xx-a/b*yy;
    return g;
}
inline bool check(ll turn){
    ll res = 0;
    for(ll meet : v){
        if(turn < meet) continue;
        ll add = (turn - meet) / lcm + 1;
        res += add;
    }
    return (turn - res) >= k;
}
void brute_force(){
    int i = 1, j = 1;
    ll cnt = 0;
    ll remain = k;
    while(true){
        ++cnt;
        if ( A[((i - 1)%n) + 1] != B[((j - 1) %m ) + 1]){
            --remain;
            if(remain==0){
                cout<<cnt;
                exit(0);
            }
        }
        ++i;
        ++j;
        if(cnt == 1e6) return;
    }
}
int main() {
    //freopen("test.inp","r",stdin);
    read(n);
    read(m);
    read(k);

    for(int i = 1 ; i <= n ; i++){
        read(A[i]);
        aI[A[i]]= i;
    }

    for(int i = 1; i <= m ; i++){
        read(B[i]);
        bI[B[i]] = i;
    }
/*    if(k <= 1e6){
        brute_force();
    }*/
    g = exgcd(n,-m,x,y);
    lcm = abs(n * m / g);
    for(int u = 1 ; u <= n; u++) {
        ll i = A[u];
        if (!bI[i] | !aI[i]) continue;
        ll c = bI[i] - aI[i];
        if (c % g != 0) continue;
        ll aa = x * (c / g), bb = y * (c / g);
        ll ka = aa / (m / g); // k la he so them bot de dc aa , bb la so tu nhien
        if (aa % (m / g) && aa < 0) {
            if ((m / g) < 0) ka++;
            else ka--;
        }
        ll kb = bb / ((n / g));
        if (bb % (n / g) && bb < 0) {
            if ((n / g) < 0) kb++;
            else kb--;
        }
        ll kk = min(ka, kb);
        aa -= (m / g) * kk;
        ll meet = aI[i] + aa * n;
        if(meet > 0) v.push_back(meet);
    }

    ll l = 1 , r = 1e18;
    ll ans = -1;
    while(l<=r){
        ll m = (l+r)>>1ll;
        if(check(m)){
            ans = m;
            r = m - 1;
        }
        else l = m+1;
    }
    write(ans);
}