#include <bits/stdc++.h>
using namespace std;
#define NMAX 505
typedef long long ll;
typedef pair<int,int> pii;
int dx[]={0,-1,0,1};
int dy[]={1,0,-1,0};
const int inf=1e8;
int n,m;
pii a[NMAX][NMAX];
queue <pii> q;
int F2[NMAX][NMAX],F5[NMAX][NMAX];
bool visit[NMAX][NMAX];
pii get(ll x){
    int cnt2=0,cnt5=0;
    while(x%2==0||x%5==0){
        if(x<=0) break;
        if(x%2==0){
            x/=2;cnt2++;
        }
        if(x%5==0){
            x/=5;cnt5++;
        }
    }
    return pii(cnt2,cnt5);
}
void enter(){
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    for(int j=1;j<=m;j++){
        ll x;
        cin>>x;
        a[i][j]=get(x);
    }
}
bool ingrid(int x,int y){
    if(x>=1&&x<=n&&y>=1&&y<=m) return true;
    return false;
}
void bfs(){
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++) F2[i][j]=inf,F5[i][j]=inf;
    q.push(pii(1,1));
    visit[1][1]=true;
    F2[1][1]=a[1][1].first,F5[1][1]=a[1][1].second;
    while(!q.empty()){
        pii top=q.front();q.pop();
        int u=top.first,v=top.second;
        for(int i=0;i<4;i++){
            int x=u+dx[i],y=v+dy[i];
            if(ingrid(x,y)){
                if(F2[x][y]>F2[u][v]+a[x][y].second){
                    F2[x][y]=F2[u][v]+a[x][y].second;
                    q.push(pii(x,y));
                }
            }
        }
    }
    memset(visit,false,sizeof(visit));
    while(!q.empty()) q.pop();
    q.push(pii(1,1));
    while(!q.empty()){
        pii top=q.front();q.pop();
        int u=top.first,v=top.second;
        for(int i=0;i<4;i++){
            int x=u+dx[i],y=v+dy[i];
            if(ingrid(x,y)){
                if(F5[x][y]>F5[u][v]+a[x][y].second){
                    F5[x][y]=F5[u][v]+a[x][y].second;
                    q.push(pii(x,y));
                }
            }
        }
    }
}
int main(){
    freopen("SC.inp","r",stdin);
    freopen("SC.out","w",stdout);
    enter();
    bfs();
    cout<<min(F2[n][m],F5[n][m]);
}
