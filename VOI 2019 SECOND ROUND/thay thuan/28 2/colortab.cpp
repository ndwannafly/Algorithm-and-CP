#include <bits/stdc++.h>
using namespace std;
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
int cx[]={-1, -1, -2, -2, 1, 1, 2, 2};
int cy[]={-2, 2, -1, 1, -2, 2, -1, 1};
int t, m, n;
int c[51][51];
int b[51][51];
int done[51][51];
int f[101];
int a[101];
bool cmp(int u, int v){
    return f[u]<f[v];
}
vector <pair <pair <int, int>, pair <int, int> > > ans;
deque <pair <int, int> > q;
pair <int, int> trace[51][51];
pair <int, int> bfs(int u, int v, int d){
    q.clear();
    q.pb(mp(u, v));
    pair <int, int> p, x;
    t++;
    done[u][v]=t;
    while(!q.empty()){
        p=q.front();
        q.pop_front();
        FFOR(j, 0, 8){
            x=mp(p.first+cx[j], p.second+cy[j]);
            if(x.first>m||x.first<1) continue;
            if(x.second>n||x.second<1) continue;
            if(done[x.first][x.second]!=t){
                done[x.first][x.second]=t;
                trace[x.first][x.second]=p;
                q.pb(x);
                if(c[x.first][x.second]==d&&c[x.first][x.second]!=b[x.first][x.second]) return x;
            }
        }
    }
}
vector <pair <int, int> > path;
inline void doswap(int u, int v, int x, int y){
    path.clear();
    pair <int, int> p=mp(x, y);
    pair <int, int> s=mp(u, v);
    while(p!=s){
        path.pb(p);
        p=trace[p.first][p.second];
    }
    path.pb(s);
    FFOR(i, 1, path.size()){
        ans.pb(mp(path[i], path[i-1]));
        swap(c[path[i].first][path[i].second], c[path[i-1].first][path[i-1].second]);
    }
    DFOR(i, path.size()-2, 1){
        ans.pb(mp(path[i], path[i-1]));
        swap(c[path[i].first][path[i].second], c[path[i-1].first][path[i-1].second]);
    }
}
void solve(){
    ans.clear();
    read(m);
    read(n);
    FOR(i, 1, 2*n) f[i]=0;
    FOR(i, 1, 2*n) a[i]=i;
    FOR(i, 1, m) FOR(j, 1, n){
        read(c[i][j]);
        f[c[i][j]]++;
    }
    sort(a+1, a+n*2+1, cmp);
    bool good=1;
    FOR(i, 1, n) if(f[a[i]]+f[a[2*n-i+1]]!=m){
        good=0;
        break;
    }
    if(good){
        FOR(i, 1, n){
            FOR(j, 1, f[a[i]]) b[j][i]=a[i];
            FOR(j, f[a[i]]+1, m) b[j][i]=a[2*n-i+1];
        }
    }
    else{
        bool df=0;
        int k=1;
        FOR(j, 1, n){
            sort(a+k, a+n*2+1, cmp);
            while(f[a[k]]==0) k++;
            int i=k;
            if(i>=2*n-1) df=1;
            if(df){
                FOR(i, 1, m){
                    while(f[a[k]]==0) k++;
                    b[i][j]=a[k];
                    f[a[k]]--;
                }
            }
            else{
                while(f[a[i]]+f[a[i+1]]+f[a[2*n]]<m) i++;
                int x=0;
                int nc=f[a[i]];
                FOR(k, 1, nc){
                    if(x<m){
                        b[++x][j]=a[i];
                        f[a[i]]--;
                    }
                    else break;
                }
                nc=f[a[i+1]];
                FOR(k, 1, nc){
                    if(x<m){
                        b[++x][j]=a[i+1];
                        f[a[i+1]]--;
                    }
                    else break;
                }
                while(x<m){
                    b[++x][j]=a[n*2];
                    f[a[n*2]]--;
                }
            }
        }
    }
    pair <int, int> p;
    FOR(i, 1, m) FOR(j, 1, n){
        if(c[i][j]==b[i][j]) continue;
        p=bfs(i, j, b[i][j]);
        doswap(i, j, p.first, p.second);
    }
    writeln(ans.size());
    for(pair <pair <int, int>, pair <int, int> > p: ans){
        write(p.first.first);
        putchar(' ');
        write(p.first.second);
        putchar(' ');
        write(p.second.first);
        putchar(' ');
        writeln(p.second.second);
    }
}
int main(){
    int t;
    read(t);
    while(t--) solve();
}
