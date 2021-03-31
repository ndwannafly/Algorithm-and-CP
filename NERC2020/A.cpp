#include <bits/stdc++.h>
using namespace std;
#define NMAX 200005
int weight[NMAX],l[NMAX],r[NMAX],node[NMAX];
queue<int> q;
int main(){
    //freopen("A.inp","r",stdin);
    int a,b;
    cin>>a>>b;
    for(int i=1;i<=a+b;i++) weight[i]=1;
    node[1]=a+b;
    q.push(1);
    int cur=1;
    while(q.size()){
        int u=q.front();
        q.pop();
        int nodel=(node[u]-1)/2;
        int noder=node[u]/2;
        if(nodel&&cur<a+b){
            ++cur;
            l[u]=cur;
            node[cur]=nodel;
            q.push(cur);
        }
        if(noder&&cur<a+b){
            ++cur;
            r[u]=cur;
            node[cur]=noder;
            q.push(cur);
        }
    }
    if(b){ // exists 2 , build top down
        q.push(1);
        node[1]=b;
        while(q.size()){
            int u=q.front();q.pop();
            ++weight[u];
            int nodel=node[u]/2;
            int noder=(node[u]-1)/2;
            if(nodel){
                if(!l[u]){
                    cout<<-1;
                    return 0;
                }
                q.push(l[u]);
                node[l[u]]=nodel;
            }
            if(noder){
                if(!r[u]){
                    cout<<-1;
                    return 0;
                }
                q.push(r[u]);
                node[r[u]]=noder;
            }
        }
    }
    for(int i=1;i<=a+b;i++){
        cout<<weight[i]<<" "<<l[i]<<" "<<r[i]<<'\n';
    }
}
