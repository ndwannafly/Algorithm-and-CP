#include <bits/stdc++.h>
using namespace std;
#define NMAX 1<<10
#define pb push_back
int n;
vector <int> edge[NMAX+5];
vector<int> nxt[NMAX+5];
int F[NMAX+5];
int visit[NMAX+5];
int res;
queue <int> q;
bool getbit(int state, int i){
    return (state>>(i-1))&1;
}
int main(){
    freopen("C.inp","r",stdin);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n;
    for(int i=2;i<=n;i++){
        int u;
        cin>>u;
        edge[u].pb(i);
    }
    q.push(1);
    F[1]=1;
    visit[1]=1;
    int cnt=0;
    while(q.size()){
        ++cnt;
        if(cnt==20) return 0;
        int state=q.front();q.pop();
        cout<<state<<'\n';
        for(int i=1;i<=n;i++) cout<<getbit(state,i);
        cout<<'\n'<<'\n';
        for(int i=1;i<=n;i++){
            if(getbit(state,i)){
                bool check=0;
                for(int j:edge[i]){
                    if(!getbit(state,j)){ // turn on
                        int newstate=state+(1<<(j-1));
                        if(F[newstate]<F[state]+1){
                            F[newstate]=F[state]+1;
                            res=max(res,F[newstate]);
        cout<<"new: "<<newstate<<" "<<F[newstate]<<'\n';
        for(int i=1;i<=n;i++) cout<<getbit(newstate,i);
        cout<<'\n'<<'\n';
                            if(!visit[newstate]) q.push(newstate),visit[newstate]++;
                        }
                    }
                    else check=1;
                }
                if(!check&&state!=1){
                    int newstate=state-(1<<(i-1));
                    if(F[newstate]<F[state]+1){
                        F[newstate]=F[state]+1;
                        res=max(res,F[newstate]);
        cout<<"new: "<<newstate<<" "<<F[newstate]<<'\n';
        for(int i=1;i<=n;i++) cout<<getbit(newstate,i);
        cout<<'\n'<<'\n';
                        if(!visit[newstate]) q.push(newstate),visit[newstate]++;
                    }
                }
            }
        }
    }
    cout<<res;
}

