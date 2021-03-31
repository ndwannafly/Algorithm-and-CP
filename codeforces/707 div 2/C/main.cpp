#include <bits/stdc++.h>
using namespace std;
#define  NMAX 200005
typedef pair<int,int> pii;
struct data{
    int val, u, v;
    bool operator < (const data &x){
        if(val == x.val){
            return (u == x.u) ? (v < x.v) : (u < x.u);
        }
        return val < x.val;
    }
};
int n;
pii a[NMAX];
vector<data> v;
pii mark[5000001];
void sub1(){
    for(int i=1;i<=n;i++){
        for(int j=i+1;j<=n;j++){
            int x = a[j].first - a[i].first;
            if(mark[x].first !=0){
                cout<<"YES\n";
                cout<<a[j].second<<" "<<mark[x].first<<" "<<a[i].second<<" "<<mark[x].second;
                exit(0);
            }
        }
        for(int j=i-1;j>=0;j--){
            int x= a[i].first - a[j].first;
            mark[x]={a[j].second,a[i].second};
        }
    }
    cout<<"NO\n";
    exit(0);
}
int main() {
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i].first;
        a[i].second = i;
    }
    sort(a+1,a+n+1);
    if(n<=5000){
        sub1();
    }
    for(int i=1;i<n;i++){
        v.push_back({a[i+1].first - a[i].first,a[i].second,a[i+1].second});
    }
    sort(v.begin(), v.end());
    for(int i = 0 ; i < v.size()-1 ; i++){
        int j = i+1;
        while(v[i].val == v[j].val){
            if(v[i].u != v[j].u && v[i].u != v[j].v && v[i].v != v[j].u && v[i].v != v[j].v){
                cout<<"YES\n";
                cout<<v[i].u<<" "<<v[j].v<<" "<<v[i].v<<" "<<v[j].u<<'\n';
                return 0;
            }
            ++j;
        }
        i=j-1;
    }
    cout<<"NO\n";
}
