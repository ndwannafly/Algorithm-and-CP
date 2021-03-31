#include <bits/stdc++.h>
using namespace std;
#define FOR(i, j, k) for(int i=(j); i<=(k); i++)
#define FFOR(i, j, k) for(int i=(j); i<(k); i++)
#define DFOR(i, j, k) for(int i=(j); i>=(k); i--)
#define bug(x) cerr<<#x<<" = "<<(x)<<'\n'
#define pb push_back
#define mp make_pair
#define setbit(s, i) (s|=(1LL<<(i)))
#define bit(s, i) (((s)>>(i))&1LL)
#define mask(i) ((1LL<<(i)))
#define builtin_popcount __builtin_popcountll
typedef long long ll;
typedef long double ld;
template <typename T> inline void read(T &x){
    char c;
    bool nega=0;
    while((!isdigit(c=getchar()))&&(c!='-'));
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
#define taskname "DECODE"
int n;
string w[2001];
struct node{
    char c;
    int p;
    int g[128];
} trie[2001];
int sz;
int _end[2001];
int add(string s){
    int i=0;
    for(char c: s){
        if(trie[i].g[c]==0){
            trie[i].g[c]=++sz;
            trie[sz].c=c;
            trie[sz].p=i;
        }
        i=trie[i].g[c];
    }
    return i;
}
const int inf=1e9;
int f[2001][2001];
pair <int, int> _next[2001][2001];
bool done[2001][2001];
int F(int u, int v){
    if(done[u][v]) return f[u][v];
    done[u][v]=1;
    f[u][v]=inf;
    int res=inf;
    if((trie[u].p)&&(trie[v].p)){
        if(trie[trie[u].p].c!=trie[trie[v].p].c) return f[u][v]=inf;
        res=min(f[u][v], F(trie[u].p, trie[v].p)+1);
        _next[u][v]=mp(trie[u].p, trie[v].p);
    }
    else if((trie[u].p==0)&&(trie[v].p==0)){
        res=1;
        _next[u][v]=mp(0, 0);
    }
    else if(trie[u].p==0){
        FOR(x, 1, n) if(trie[_end[x]].c==trie[trie[v].p].c) if(res>F(_end[x], trie[v].p)+1){
            res=F(_end[x], trie[v].p)+1;
            _next[u][v]=mp(_end[x], trie[v].p);
        }
    }
    else{
        FOR(x, 1, n) if(trie[_end[x]].c==trie[trie[u].p].c) if(res>F(trie[u].p, _end[x])+1){
            res=F(trie[u].p, _end[x])+1;
            _next[u][v]=mp(trie[u].p, _end[x]);
        }
    }
    return f[u][v]=res;
}
string ans[2];
#define next anext
pair <int, int> next;
void find(){
    int u=next.first;
    int v=next.second;
    ans[0]+=trie[u].c;
    ans[1]+=trie[v].c;
    if(F(u, v)==1){
        reverse(ans[0].begin(), ans[0].end());
        reverse(ans[1].begin(), ans[1].end());
        cout<<ans[0]<<'\n'<<ans[1];
        exit(0);
    }
    if(trie[u].p==0) ans[0]+='+';
    if(trie[v].p==0) ans[1]+='+';
    next=mp(_next[u][v].first, _next[u][v].second);
}
int main(){
    #ifdef Kanikou
        if(fopen(taskname".inp", "r"))
            freopen(taskname".inp", "r", stdin);
    #endif // Kanikou
//    ios_base::sync_with_stdio(false);
//    cin.tie(NULL);
    cin>>n;
    FOR(i, 1, n){
        cin>>w[i];
        _end[i]=add(w[i]);
    }
    pair <int, int> best;
    bool no_solution=1;
    FOR(i, 1, n) FOR(j, i+1, n) if(trie[_end[i]].c==trie[_end[j]].c) if(no_solution||(F(_end[i], _end[j])>F(best.first, best.second))){
        no_solution=0;
        best=mp(_end[i], _end[j]);
    }
    if(no_solution||(F(best.first, best.second)==inf)){
        puts("-1");
        return 0;
    }
    next=mp(best.first, best.second);
    while(true) find();
    cout<<ans[0]<<'\n'<<ans[1];
}