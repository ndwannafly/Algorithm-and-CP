#include <bits/stdc++.h>
using namespace  std;
#define  NMAX 100005

typedef long long ll;
typedef pair<int,pair<int,int>> pii;
int a[NMAX];
vector <int> v[NMAX];
int res[NMAX];
int p[NMAX];
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int test;
    cin>>test;
    while(test--){
        int n,m;
        cin>>n>>m;
        int k = (m+1)/2;
        for(int i=1;i<=m;i++){
            p[i] = 0;
            res[i] = 0;
        }
        for(int i=1;i<=n;i++){
            v[i].clear();
            a[i] = 0;
        }
        for(int i=1;i<=m;i++){
            cin>>p[i];
            for(int j=1;j<=p[i];j++){
                int x;
                cin>>x;
                a[x]++;
                v[x].emplace_back(i);
            }
        }
        for(int i=1;i<=n;i++){
            if(a[i] <= k){
                for(int x : v[i]){
                    if(!res[x]) {
                        res[x] = i;
                        //cout<<"get: "<<x<<" "<<i<<'\n';
                    }
                }
            }
        }
        priority_queue<pii> pq;
        for(int i=1;i<=n;i++){
            if(a[i] > k){
                for(int x : v[i]){
                    pq.push({-p[x],{x,i}});
                }
                a[i] = k;
            }
        }
        while(!pq.empty()){
            //cout<<pq.top().first<<" "<<pq.top().second.first<<" "<<pq.top().second.second<<'\n';
            int date = pq.top().second.first;
            int id = pq.top().second.second;
            if(a[id] > 0 && !res[date]){
                res[date] = id;
                a[id] --;
                //cout<<"add: "<<date<<" "<<id<<'\n';
            }
            pq.pop();
        }
        bool flag = false;
        for(int i=1;i<=m;i++){
            if(!res[i]){
                flag = true;
                break;
            }
        }
        //cout<<'\n';
        if(flag){
            cout<<"NO\n";
            continue;
        }
        cout<<"YES\n";
        for(int i=1;i<=m;i++) cout<<res[i]<<" ";
        cout<<'\n';
    }
}