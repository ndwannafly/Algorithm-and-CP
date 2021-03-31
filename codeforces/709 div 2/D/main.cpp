#include <bits/stdc++.h>
using namespace std;

#define NMAX 100005

int n;
int nxt[NMAX];
vector <int> playlist;
vector <int> res;
bool choose[NMAX];
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int test;
    cin>>test;
    while(test--){
        cin>>n;
        vector <int> a(n);
        playlist.clear();
        res.clear();
        for(int &i : a) cin>>i;

        for(int i = 0 ; i < n; i++){
            choose[i] = false;
            nxt[i] = (i+1)%n;
            playlist.push_back(i);
        }
        bool did = false;
        while(!did){
            did = true;
            vector<int> nextErase;
            for(int v : playlist){
                //cout<<"go: "<<v<<'\n';
                if(choose[v]) continue;
                int u =nxt[v];
                if(__gcd(a[v],a[u]) == 1){
                    choose[u] = true;
                    res.push_back(u);
                    nextErase.push_back(v);
                    nxt[v] = nxt[u];
                    did = false;
                }
            }
            playlist = nextErase;
        }
        cout<<res.size()<<' ';
        for(int v : res) cout<<v+1<<" ";
        cout<<'\n';
    }
}
