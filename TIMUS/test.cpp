#include <bits/stdc++.h>
using namespace std;
set<string> s;
int main(){
    freopen("1067.inp","r",stdin);
    int n;
    cin>>n;
    while(n--){
        string t;
        cin>>t;
        t=t+'\\';
        string tmp="";
        for(char c:t){
            if(c=='\\'){
                s.insert(tmp);
                tmp="";
            }
            else tmp=tmp+c;
        }
    }
    for(auto c:s) cout<<c<<'\n';
}
