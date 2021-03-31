#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
#define NMAX 200
#define pb push_back
int dx1[]={0,-1,0,1};
int dy1[]={1,0,-1,0};
char a[NMAX][NMAX];
int S[NMAX][NMAX];
int w,h;
bool mark[NMAX][NMAX];
inline bool ingrid(int x,int y){
    return (x>=1&&x<=h&&y>=1&&y<=w);
}
inline int get(int u,int v,int x,int y){
    if(!ingrid(u,v)) return 1;
    if(!ingrid(x,y)) return 1;
    if(x==h&&y==w) return 1;
    if(u==h&&v==w) return 1;
    if(x==1&&y==1) return 1;
    if(u==1&&v==1) return 1;
    return S[x][y]-S[x][v-1]-S[u-1][y]+S[u-1][v-1];
}
queue <pii> q;
bool inqueue[NMAX][NMAX];
inline bool BFS(){
    while(!q.empty()) q.pop();
    memset(inqueue,0,sizeof(inqueue));
    q.push({1,1});
    inqueue[1][1]=1;
    //cout<<a[11][27]<<" "<<mark[11][27]<<'\n';
    //return 0;
    while(!q.empty()){
        int u=q.front().first,v=q.front().second;
      //  cout<<u<<" "<<v<<'\n';
        q.pop();
        if(u==h&&v==w) return true;
        for(int i=0;i<4;i++){
            int x=u+dx1[i],y=v+dy1[i];
            if(ingrid(x,y)&&a[x][y]!='#'&&!mark[x][y]&&!inqueue[x][y]){
                q.push({x,y});
                inqueue[x][y]=1;
            }
        }
    }
    return false;
}
inline bool check(int len){
    for(int u=1;u<=h;u++){
        for(int v=1;v<=w;v++){
            int x=u+len-1,y=v+len-1;
            memset(mark,0,sizeof(mark));
            if(get(u,v,x,y)==0){
                    for(int i=u;i<=x;i++){
                        for(int j=v;j<=y;j++){
                            mark[i][j]=1;
                        }
                    }
                    if(!BFS()){
                        cout<<u<<" "<<v<<" "<<x<<" "<<y<<'\n';
                        return true;
                    }
            }
        }
    }
    return false;
}
int main(){
    freopen("LABYRINTH.inp","r",stdin);
    //freopen("TEST.out","w",stdout);
    cin>>w>>h;
    getchar();
    for(int i=1;i<=h;i++){
        for(int j=1;j<=w;j++){
            cin>>a[i][j];
       //     a[i][j]=getchar();
            S[i][j]=S[i-1][j]+S[i][j-1]-S[i-1][j-1]+(a[i][j]=='#');
            //cout<<a[i][j];
        }
        //getchar();
      //  cout<<'\n';
    }
    mark[2][38]=1;
    if(!BFS()){
        cout<<"DUC";
        return 0;
    }
    for(int i=1;i<=min(w,h);i++){
       // cout<<i<<" ";
        if(check(i)){
            cout<<i;
            return 0;
        }
    }
}
