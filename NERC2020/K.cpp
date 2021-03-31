#include <bits/stdc++.h>
using namespace std;
int n;

int main(){
    //freopen("K.inp","r",stdin);
    cin>>n;
    int res=0;
    int hold=1e9;
    int cnt=0;
    while(n--){
        ++cnt;
        int p;
        string s;
        cin>>p;
        cin>>s;
        int two=0,zr=0,one=0;
        for(auto i:s){
            if(i=='0') zr++;
            if(i=='1') one++;
            if(i=='2') two++;
        }
        //cout<<zr<<" "<<one<<" "<<two<<'\n';
        if(zr>=1&&one>=1&&two>=2){
            if(p<hold) hold=p,res=cnt;
        }
    }
    cout<<res;
}
