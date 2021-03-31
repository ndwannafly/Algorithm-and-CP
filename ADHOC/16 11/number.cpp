#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int test;
string s;
ll res=0;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("NUMBER.inp","r",stdin);
    freopen("NUMBER.out","w",stdout);
    cin>>test;
    while(test--){
        ll res=0;
        cin>>s;
        if(s.size()==1){
            cout<<s[0]-'1'<<'\n';
            continue;
        }
        bool flag=0;
        bool pw10=0;
        for(int i=1;i<s.size();i++) if(s[i]!='0') pw10=1;
        if(!pw10){
            if(s[0]=='1') pw10=1;
        }
        if(!pw10){
            res++;
            s[0]--;
            for(int i=1;i<s.size();i++) s[i]='9';
        }
        int num=0;
        for(int i=0;i<s.size()-1;i++){
            if(s[i]=='1') flag=1;
            if(s[i]=='0') num++;
        }
        res-=num;
        res=res+s.back()-'0';
        for(int i=s.size()-2;i>=0;i--){
            res=res+s[i]-'0'+1;
        }
       // cout<<res<<'\n';
       // return 0;
        int n=s.size()-1;
        while(n>1){
            res=res+10*(n-1)+9;
         //   cout<<n<<" "<<res<<'\n';
            n--;
        }
        res+=8;
        if(flag) res--;
        cout<<res<<'\n';
        //return 0;
    }
}
