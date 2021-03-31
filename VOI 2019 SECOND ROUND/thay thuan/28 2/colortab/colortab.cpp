#include <bits/stdc++.h>

using namespace std;

#define FOR(i,j,k) for(i=j;i<=k;i++)
#define FORK(i,j,k) for(i=j;i<k;i++)
#define FORN(i,j,k) for(i=j;i>=k;i--)
#define pb push_back
#define mp make_pair
#define ll long long

typedef pair<int,int> ii;

template <typename T> inline void read(T &x)
{
	char c; bool nega=false;
	while ((!isdigit(c=getchar())) && (c!='-'));
	if (c=='-')
	{
		nega=true; c=getchar();
	}
	x=c-48;
	while (isdigit(c=getchar())) x=x*10+c-48;
	if (nega) x=-x;
}

template <typename T> inline void writep(T x)
{
	if (x>9) writep(x/10);
	putchar(x%10+48);
}

template <typename T> inline void write(T x)
{
	if (x<0)
	{
		putchar('-');
		x=-x;
	}
	writep(x);
}

template <typename T> inline void writeln(T x)
{
	write(x);
	putchar('\n');
}

//___________________________________________________

#define u first
#define v second
#define nmax 55

ii d[nmax][nmax];
queue<ii> q;
int a[nmax][nmax];
ii dm[2*nmax];
pair<ii, ii> c[6300000];
ii dd[nmax*nmax];
int xc[8]={-2, -1, 1, 2, 2, 1, -1, -2};
int yc[8]={1, 2, 2, 1, -1, -2, -2, -1};
bool cx[nmax][nmax];
int m, n, bd, k;

bool tman (int u, int v)
{
    return ((u>0) && (v>0) && (u<=m) && (v<=n));
}

void bfs (int u, int v, int val)
{
    while (!q.empty()) q.pop();
    int i, j, x, y, u1, v1;
    FOR(i, 1, m)
        FOR(j, 1, n) d[i][j]=mp(-1, -1);
    ii p; int dm=0;
    d[u][v]=mp(0, 0); q.push(mp(u, v));
    while (q.size())
    {
        x=q.front().u; y=q.front().v; q.pop();
        FOR(i, 0, 7)
        {
            u1=x+xc[i]; v1=y+yc[i];
            if ((tman(u1, v1)) && (d[u1][v1].u==-1))
            {
                if ((a[u1][v1]==val) && cx[u1][v1])
                {
                    d[u1][v1]=mp(x, y);
                    swap(a[u][v], a[u1][v1]); p.u=u1; p.v=v1;
                    while (p.u!=0)
                    {
                        dm++; dd[dm]=p; p=d[p.u][p.v];
                    }
                    FOR(i, 1, dm-1)
                    {
                        bd++; c[bd].u=dd[i]; c[bd].v=dd[i+1];
                    }
                    FORN(i, dm-2, 1)
                    {
                        bd++; c[bd].u=dd[i]; c[bd].v=dd[i+1];
                    }
                    return;
                }
                d[u1][v1]=mp(x, y); q.push(mp(u1, v1));
            }
        }
    }
}

void solve ()
{
    int i, j, x, t;
    FOR(i, 1, n)
    {
        x=dm[i].u;
        FOR(j, 1, x)
        {
            cx[j][i]=false; dm[i].u--;
            if (a[j][i]!=dm[i].v) bfs(j, i, dm[i].v);
        }
        t=k-i+1;
        FOR(j, x+1, m)
        {
            cx[j][i]=false; dm[t].u--;
            if (a[j][i]!=dm[t].v) bfs(j, i, dm[t].v);
        }
    }
}

void xli ()
{
    read(m); read(n); k=2*n;
    int i, j; bd=0;
    FOR(i, 1, k) dm[i]=mp(0, i);
    FOR(i, 1, m)
        FOR(j, 1, n)
        {
            read(a[i][j]); dm[a[i][j]].u++;
            cx[i][j]=true;
        }
    sort(dm+1, dm+k+1);
    bool lg=true; int tmp;
    FOR(i, 1, k/2)
    {
        tmp=dm[i].u+dm[k-i+1].u;
        if (tmp!=m)
        {
            lg=false; break;
        }
    }
    if (lg)
    {
        solve(); goto label;
    }
    int t, x;
    FOR(i, 1, n)
    {
        FOR(j, 1, k-2)
        {
            tmp=dm[j].u+dm[j+1].u;
            if (tmp<=m)
            {
                if (tmp+dm[k].u>m) t=j;
            }
            else break;
        }
        /* FOR(j, 1, k) cout<<dm[j].u<<" "; cout<<endl;
        cout<<t<<endl; */
        x=dm[t].u;
        FOR(j, 1, min(x, m))
        {
            cx[j][i]=false; dm[t].u--;
            if (a[j][i]!=dm[t].v) bfs(j, i, dm[t].v);
        }
        if (x<m)
        {
            tmp=x+dm[t+1].u;
            FOR(j, x+1, min(m, tmp))
            {
                cx[j][i]=false; dm[t+1].u--;
                if (a[j][i]!=dm[t+1].v) bfs(j, i, dm[t+1].v);
            }
        }
        x=tmp;
        if (x<m)
        {
            FOR(j, x+1, m)
            {
                cx[j][i]=false; dm[k].u--;
                if (a[j][i]!=dm[k].v) bfs(j, i, dm[k].v);
            }
        }
        sort(dm+1, dm+k+1);
    }
    label: ;
    writeln(bd);
    FOR(i, 1, bd)
    {
        write(c[i].u.u); putchar(' ');
        write(c[i].u.v); putchar(' ');
        write(c[i].v.u); putchar(' ');
        writeln(c[i].v.v);
    }
}

int main ()
{
    freopen("colortab.inp", "r", stdin);
    freopen("colortab.out", "w", stdout);
    int i, tv; read(tv);
    FOR(i, 1, tv) xli();
    return 0;
}
