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
typedef long double ld;

const ld PI=2.0*acos(0.0);
#define INF 1000000000
#define pb push_back
struct points{
	ll x,y;
	points(){
	    x=y=0;
    }
	points(ll _x, ll _y) : x(_x), y(_y) {};
	bool operator == (const points &other) {
		return (x==other.x)&&(y==other.y);
	}
	inline bool operator < (const points &other){
        if(x==other.x) return y<other.y;
        return x<other.x;
	}
};
ll n;
vector<points> vpoint, convex;
inline ll cross3(points &o,points &a,points &b){
	return (a.x-o.x)*(b.y-o.y)-(a.y-o.y)*(b.x-o.x);
}
void convex_hull(){
	ll t,n=(ll)vpoint.size(),k=0;
	convex.resize(2*n);
	sort(vpoint.begin(),vpoint.end());
	for(int i=0;i<n;i++){
		while(k>=2&&cross3(convex[k-2],convex[k-1],vpoint[i])<=0) k--;
		convex[k++]=vpoint[i];
	}
	for(int i=n-1,t=k+1;i>=0;i--){
		while(k>=t&&cross3(convex[k-2],convex[k-1],vpoint[i])<=0) k--;
		convex[k++]=vpoint[i];
	}
	if(convex[0]==convex[k-1]) k--;
	convex.resize(k);
}
points to_vec (points &a,points &b) {
	return points(b.x-a.x,b.y-a.y);
}
ll cross2 (const points &a, const points &b) {
	return a.x*b.y-a.y*b.x;
}
ld area(int a, int b, int c, vector <points> &convex){
    a%=(int)convex.size();
    b%=(int)convex.size();
    c%=(int)convex.size();
    ld ret =convex[a].x*convex[b].y -convex[b].x*convex[a].y;
    ret+=convex[b].x*convex[c].y - convex[c].x*convex[b].y;
    ret+=convex[c].x*convex[a].y - convex[a].x*convex[c].y;
    return abs(ret)/2;
}
ld max_tri(){
    int n=(int)(convex.size());
   // cout<<n;
  //  exit(0);
    int i=0,j=1,k=2;
    ld res=0;
   // cout<<n<<'\n';
//   for(int i=0;i<n;i++){
//        for(int j=0;j<n;j++){
//            for(int k=0;k<n;k++){
//                res=max(res,area(i,j,k,convex));
//            }
//        }
//   }
//   return res;
    for(;i<=n;i++){
        while(true){
            while(true){
                res=max(res,area(i,j,k,convex));
                if(area(i,j,k,convex)>area(i,j,k+1,convex)){
                    break;
                }
                k++;
            }
            res=max(res,area(i,j,k,convex));
            if(area(i,j,k,convex)>area(i,j+1,k,convex)) break;
            j++;
        }
        j=max(j,i+2);
        k=max(k,j+1);
    }
	return (ld)(res);
}

int main(){
    freopen("TRILAND.inp","r",stdin);
    freopen("TRILAND.out","w",stdout);
	cin>>n;
	for(int i=0;i<n;i++){
        ll x,y;
        cin>>x>>y;
        vpoint.pb({x,y});
	}
	convex_hull();
	cout<<setprecision(1)<<fixed<<max_tri()<<'\n';
}
