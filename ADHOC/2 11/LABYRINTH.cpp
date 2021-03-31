#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
#define NMAX 1505
#define pb push_back
int dx1[]={0,-1,0,1};// phai tren trai xuong
int dy1[]={1,0,-1,0};
int dx2[]={1,0,-1,0}; //xuong trai tren phai
int dy2[]={0,-1,0,1};
int dx3[]={0,1,0,-1};// trai xuong phai tren
int dy3[]={-1,0,1,0};
char a[NMAX][NMAX];
int w,h;
int lowpath[NMAX][NMAX];
int highpath[NMAX][NMAX];
int S[NMAX][NMAX];
vector <pii> rem;
inline bool ingrid(int x,int y){
    return (x>=1&&x<=h&&y>=1&&y<=w);
}
bool flag;
inline void DFSlow(int x,int y){
    if(flag) return ;
   // cout<<x<<" "<<y<<'\n';
    if(x==1&&y==1){
        flag=1;
        return ;
    }
    for(int i=0;i<4;i++){
        int u=x+dx2[i],v=y+dy2[i];
        if(ingrid(u,v)&&a[u][v]!='#'&&lowpath[u][v]==0){
            lowpath[u][v]=1;
            DFSlow(u,v);
            if(flag) return ;
            lowpath[u][v]=2;
        }
    }
}
bool duc;
inline void DFShigh(int x,int y){
    if(flag) return ;
    if(x==1&&y==1){
        flag=1;
        return ;
    }
    if(highpath[x-1][y]==1){
        for(int i=0;i<4;i++){
            int u=x+dx3[i],v=y+dy3[i];
            if(ingrid(u,v)&&a[u][v]!='#'&&highpath[u][v]==0){
                highpath[u][v]=1;
                DFShigh(u,v);
                if(flag) return ;
                highpath[u][v]=2;
            }
        }
    }
    else{
        for(int i=0;i<4;i++){
            int u=x+dx1[i],v=y+dy1[i];
            if(ingrid(u,v)&&a[u][v]!='#'&&highpath[u][v]==0){
                highpath[u][v]=1;
                DFShigh(u,v);
                if(flag) return ;
                highpath[u][v]=2;
            }
        }
    }
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
int ans1,ans2;
inline bool check(int len){
    for(auto p:rem){
        int x=p.first,y=p.second;
        int u=x-len+1,v=y-len+1;
        if(ingrid(u,v)&&highpath[u][v]==1&&get(u,v,x,y)==0){
           // cout<<u<<" "<<v<<" "<<x<<" "<<y<<'\n';
            ans1=u,ans2=v;
            return true;
        }
        if(!ingrid(x-len+1,y+len-1)||highpath[x-len+1][y+len-1]!=1) continue;
        x=x-len+1;
        u=x+len-1,v=y+len-1;
        if(get(x,y,u,v)==0){
          //  cout<<x<<" "<<y<<" "<<u<<" "<<v<<'\n';
            ans1=x,ans2=y;
            return true;
        }
    }
    return false;
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("LABYRINTH.inp","r",stdin);
    freopen("LABYRINTH.out","w",stdout);
    cin>>w>>h;
    for(int i=1;i<=h;i++){
        for(int j=1;j<=w;j++){
            cin>>a[i][j];
            S[i][j]=S[i-1][j]+S[i][j-1]-S[i-1][j-1]+(a[i][j]=='#');
        }
    }
    lowpath[h][w]=1;
    DFSlow(h,w);
    for(int i=1;i<=h;i++){
        for(int j=1;j<=w;j++){
            if(lowpath[i][j]==1){
                rem.pb({i,j});
            }
        }
    }
    flag=0;
    DFShigh(h,w);
    for(int i=1;i<=min(w,h);i++){
        if(check(i)){
            cout<<i<<" "<<ans2<<" "<<ans1<<'\n';
            return 0;
        }
    }
    cout<<"Impossible";
}
