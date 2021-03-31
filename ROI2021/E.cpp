#include <bits/stdc++.h>
using namespace std;
vector <vector<int>> res;
vector<int> v;
int n,k,cur,cnt;
void Try(int val){
    if(cnt==k){
        if(cur==n) res.push_back(v);
        return;
    }
    ++cnt;
    cur+=val-1;
    v.push_back(val-1);
    Try(val-1);
    --cnt;
    cur-=val-1;
    v.pop_back();
    ++cnt;
    cur+=val;
    v.push_back(val);
    Try(val);
    --cnt;
    cur-=val;
    v.pop_back();
    ++cnt;
    cur+=val+1;
    v.push_back(val+1);
    Try(val+1);
    --cnt;
    cur-=val+1;
    v.pop_back();
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>k;
    for(int i=-15;i<=15;i++){
        v.push_back(i);
        cnt++;
        cur+=i;
        Try(i);
        v.pop_back();
        cnt--;
        cur-=i;
    }
    for(auto i:res){
        for(int j=0;j<i.size();j++){
            if(i[j]>=0){
                if(j==0) cout<<i[j];
                else cout<<"+"<<i[j];
            }
            else cout<<i[j];
        }
        cout<<'\n';
    }
}
