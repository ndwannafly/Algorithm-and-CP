#include<bits/stdc++.h>
using namespace std; 
const int N = 2e5 + 10;
vector <int> V;
int n;
int a[N];
typedef priority_queue<int, vector<int >, greater<int > > PQ;
PQ pp[N];
queue<int > Q;
 
void mergex(int &x, int &y){
    if(pp[x].size() < pp[y].size()) swap(x, y);
    while(pp[y].size()){
        pp[x].push(pp[y].top());
        pp[y].pop();
    }
}
int main(){
    freopen("sort.inp","r",stdin);
    read(n);
    for(int i = 1; i <= n; i++) {
        cin>>a[i];
        V.push_back(a[i]);
    }
    sort(V.begin(), V.end());
    for (int i = 1; i <= n; i++){
        a[i] = lower_bound(V.begin(), V.end(), a[i]) - V.begin() + 1;
        pp[i].push(a[i]);
        Q.push(i);
    }
 
    long long ans = 0;
    for (int i = 1; i <= n; i++){
        int init = Q.front();
        Q.pop();
        while (1){
            if (pp[init].size() && pp[init].top() == i) {
                ans += pp[init].size() - 1;
                pp[init].pop();
                if (pp[init].size()) Q.push(init);
                break;
            }
            mergex(init, Q.front());
            Q.pop();
        }
        cout<<pq.top()<<'\n';
    }
    cout << ans << '\n';
}
