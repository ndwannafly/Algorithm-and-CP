#include <iostream>
#include <algorithm>
using namespace std;
#define NMAX 10005
typedef long long ll;
struct Point{
    ll x,y;
    ll id;
};
int n;
Point p[NMAX];
Point minP;
bool cmp(Point p, Point q){
    p.x-=minP.x;
    q.x-=minP.x;
    p.y-=minP.y;
    q.y-=minP.y;
    return p.x*q.y-p.y*q.x<0; // 2D cross product
}
int main(){
    //freopen("1207.inp","r",stdin);
    //freopen("1207.out","w",stdout);
    cin>>n;
    minP.x=1e9,minP.y=1e9;
    for(int i=1;i<=n;i++){
        cin>>p[i].x>>p[i].y;
        p[i].id=i;
        if(p[i].x<=minP.x){
            if(p[i].x<minP.x) minP=p[i];
            else if(p[i].y<minP.y) minP=p[i];
        }
        //cout<<p[i].x<<" "<<p[i].y<<" "<<p[i].id<<'\n';
    }
    swap(p[minP.id],p[n]);
    sort(p+1,p+n,cmp);
//    for(int i=1;i<=n;i++){
//        cout<<p[i].x<<" "<<p[i].y<<" "<<p[i].id<<'\n';
//    }
    cout<<minP.id<<" "<<p[n/2].id;
}
