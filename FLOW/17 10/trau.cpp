#include <bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) for (int i=a; i<=b; i++)
#define FORD(i,a,b) for (int i=a; i<b; i++)
const int N=755;
const int base=1e9+7;
int n,kq,dx[N];
int h[N][N],pw[10000005];
queue <int> q;
string st[N];
vector<int>res;
int gethash(int i, int j, int x)
{
    return h[x][j]-h[x][i-1]*pw[j-i+1];
}
void HASH()
{
    int maxsz=0;
    FOR(i,1,n)
    {
        int p=st[i].size();
        maxsz=max(maxsz,p);
    }
    pw[0]=1;
    FOR(i,1,maxsz) pw[i]=pw[i-1]*base;
    FOR(i,1,n) FORD(j,0,st[i].size())
        h[i][j+1]=h[i][j]*base+st[i][j]-48;
}
void xuli()
{
    res.clear();
    FOR(i,1,n) if (dx[i]==1) res.push_back(i);
    int kt=0;
    FORD(i,0,res.size()) FORD(j,i+1,res.size())
    {
        int u=res[i],v=res[j];
        if (st[u].size()<st[v].size()) swap(u,v);
        int sz=st[v].size();
        int p=gethash(1,sz,v);
        FOR(x,sz,st[u].size())
            if (gethash(x-sz+1,x,u)==p)
            {
                kt=1;
                goto line;
            }
    }
    line:;
    if (kt==0) kq=max(kq,(int) res.size());
}
void Try(int i)
{
    dx[i]=1;
    if (i<n) Try(i+1);
    else xuli();

    dx[i]=0;
    if (i<n) Try(i+1);
    else xuli();
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    freopen("greetingcard.inp","r",stdin);
//    freopen("greetingcard.out","w",stdout);
    cin >> n;
    FOR(i,1,n) cin >> st[i];
    HASH();
    Try(1);
    cout << kq;
}
