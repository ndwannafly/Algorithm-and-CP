#include <bits/stdc++.h>
using namespace std;
int main(){
    //freopen("B.inp","r",stdin);
    int test;
    cin>>test;
    while(test--){
        int n,query;
        cin>>n>>query;
        string s;
        cin>>s;
        int first[2],last[2];
        memset(first,-1,sizeof(first));
        memset(last,-1,sizeof(last));
        for(int i=0;i<n;i++){
            char c=s[i]-'0';
            first[c]=(first[c]==-1?i:first[c]);
            last[c]=i;
        }
        //cout<<first[1]<<" "<<last[1]<<'\n';
        while(query--){
            int l,r;
            cin>>l>>r;
            l--;
            r--;
            // vi tri xuat hien dau tien cua s[l] trong s khac voi vi tri xuat hien dau tien cua chinh s[l] trong s
            //cout<<l<<" "<<r<<" "<<first[s[l]-'0']<<" "<<last[s[r]-'0']<<'\n';
            if(l!=first[s[l]-'0']){
                cout<<"YES"<<'\n';
                continue;
            }
            if(r!=last[s[r]-'0']){
                cout<<"YES"<<'\n';
                continue;
            }
            cout<<"NO"<<'\n';
        }
    }
}
