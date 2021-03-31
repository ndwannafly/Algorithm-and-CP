#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <queue>
using namespace std;
typedef pair<int,int> pii;
int n;
pii a[10005];
priority_queue<pii> pq;
int main(){
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i].first;
        a[i].second=i;
        pq.push(a[i]);
    }
    while(pq.size()){
        pii u=pq.top();
        pq.pop();
        if(pq.size()){
            pii v=pq.top();pq.pop();
            cout<<u.second<<" "<<v.second<<" ";
            u.first--;
            v.first--;
            if(u.first) pq.push(u);
            if(v.first) pq.push(v);
        }
        else{
            cout<<u.second<<" ";
            if(u.first-1) pq.push(pii(u.first-1,u.second));
        }
    }
}
