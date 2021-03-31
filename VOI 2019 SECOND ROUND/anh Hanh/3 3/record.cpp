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
#define pb push_back
#define mp make_pair
#define NMAX 105
typedef long long ll;
typedef pair<ll,ll> pll;
typedef pair<int,int> pii;
struct data{
    int start,finish;
};
vector <data> episode;
vector <int> adj[2*NMAX];
data live[NMAX],repeat[NMAX];
int num[2*NMAX],low[2*NMAX],mark[2*NMAX],n;

inline void OrClause(int x,int y){ // x|y
    adj[x^1]
}
inline void load(){
    for(int i=0;i<2*n;i++) num[i]=0,low[i]=0,mark[i]=0;
}
void build_graph(int l,int r){
    for(int i=l;i<=r;i++){
        for(int j=i+1;j<=r;j++){

        }
    }
}
void progress(){
    int test;
    read(test);
    while(test--){
        read(n);
        episode.clear();
        load();
        for(int i=1;i<=n;i++){
            int a,b,c,d;
            read(a);read(b);read(c);read(d);
            episode.pb({a,b});episode.pb({c,d});
        }
        int resL=1,resR=1,r=1;
        for(int l=1;l<=n;l++){
            while(l<=r&&r<=n){
                build_graph(l,r);
                if(check(l,r)){
                    if(resR-resL+1<r-l+1){
                        resL=l;
                        resR=r;
                    }
                    r++;
                }
                else break;
            }
        }
        writeln(res);
    }
}
int main(){
    progress();

}
