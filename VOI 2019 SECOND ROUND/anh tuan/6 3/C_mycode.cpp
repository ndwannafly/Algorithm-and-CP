#include <bits/stdc++.h>
using namespace std;
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

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

#define NMAX 10005
#define pb push_back
#define mp make_pair

int n;
int num[12*NMAX],low[12*NMAX],tplt[12*NMAX];
bool visit[12*NMAX];
vector <int> adj[12*NMAX];
stack <int> s;
vector <pii> rem;
void init(){
    memset(num,0,sizeof(num));
    memset(low,0,sizeof(low));
    memset(tplt,0,sizeof(tplt));
    memset(visit,0,sizeof(visit));
    while(!s.empty()) s.pop();
    for(int i=0;i<12*NMAX;i++) adj[i].clear();
}
inline void build(){
    for(int i=2*n-1;i>0;i--){
        adj[(2*(2*n+(i<<1))].pb(2*(2*n+i));
		adj[(2*(2*n+i)+1].pb(2*(2*n+(i<<1))+1);
		adj[(2*(2*n+(i<<1)+1)].pb(2*(2*n+i));
		adj[(2*(2*n+i)+1].pb(2*(2*n+(i<<1)+1)+1);
    }
}
void enter(){
    read(n);
    for(int i=0;i<n;i++){
        int x;
        read(x);rem.pb({x,i*2});
        read(x);rem.pb({x,i*2+1});
    }
    sort(rem.begin(),rem.end());
}
void progress(){
    int l=0,r=1e9+1;
    int ans=0;
    while(l<=r){
        int m=(l+r)>>1;
        bool flag=1;
        if(m>0){
            init();
            for(int i=0;i<n;i++){
                adj[4*n].pb(4*n+3);
                adj[4*n+3].pb(4*n);
                adj[4*n+1].pb(4*n+2);
                adj[4*n+2].pb(4*n+1);
            }
            for(int i=0;i<rem.size();i++){
                for(int j=0;j<2;j++){
                    adj[(4*n+i)*2+j].pb(rem[i].second*2+j);
                    adj[rem[i].second*2+j].pb((4*n+i)*2+j);
                }
            }
            build();
            for(int i=0;i<rem.size();i++){
                int pos=rem[i].first;
                int r=lower_bound(rem.begin(),rem.end(),pii(pos+mid,-1))-rem.begin();
                add(i,i+1,r);
                int l=lower_bound(rem.begin(),rem.end(),pii(pos-mid+1,-1))-rem.begin();
                add(i,l,i);
            }
        }
    }
}
int main(){
    enter();
    progress();
}
