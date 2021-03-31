#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
pii rng[4];
int r;
string D;
int tdiv;
int main(){
    rng[1].first=1901,rng[1].second=5000;
    rng[2].first=1601,rng[2].second=1900;
    rng[3].first=0,rng[3].second=1600;
    cin>>r;
    cin>>D;
    if(r>1900) tdiv=1;
    else if(r<=1600) tdiv=3;
    else tdiv=2;
    for(int i=0;i<D.size();i++){
        if(D[i]-'0'==tdiv){
            cout<<tdiv;
            return 0;
        }
    }
    for(int i=0;i<D.size();i++){
        int td=D[i]-'0';
        if(r>rng[td].second) cout<<D[i]<<"*\n";
        else cout<<D[i]<<'\n';
    }
}
