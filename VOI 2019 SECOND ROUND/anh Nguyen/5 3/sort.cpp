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
#define NMAX 200005
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
int n;
int a[NMAX];
priority_queue < int, vector <int> , greater<int> > pq[NMAX];
vector <int> rem;
queue <int> q;
inline void change(int &x,int &y){
    if(pq[x].size()<pq[y].size()) swap(x,y);
    while(!pq[y].empty()){
        pq[x].push(pq[y].top());
        pq[y].pop();
    }
}
int main(){
    //freopen("sort.inp","r",stdin);    read(n);
    for(int i=1;i<=n;i++) read(a[i]),rem.pb(a[i]);
    sort(rem.begin(),rem.end());
    for(int i=1;i<=n;i++){
        a[i]=lower_bound(rem.begin(),rem.end(),a[i])-rem.begin()+1;
        pq[i].push(a[i]);
        q.push(i);
    }
    ll res=0;
    for(int i=1;i<=n;i++){
        int fr=q.front();q.pop();
        while(1){
            if(!pq[fr].empty()&&pq[fr].top()==i){
                res+=pq[fr].size()-1;
                pq[fr].pop();
                if(!pq[fr].empty()) q.push(fr);
                break;
            }
            change(fr,q.front());
            q.pop();
        }
    }
    writeln(res);
}
