
#include <bits/stdc++.h>
using namespace std;
int n,k;
string a,b;
vector <int> x;
int have[30],need[30];
int main(){
    //freopen("C.inp","r",stdin);
    ios_base::sync_with_stdio(0);
    int test;
    cin>>test;
    while(test--){
        cin>>n>>k;
        cin>>a>>b;
        memset(have,0,sizeof(have));
        memset(need,0,sizeof(need));
        for(int i=0;i<n;i++){
            have[a[i]-'a']++;
            need[b[i]-'a']++;
        }
        bool stp=0;
        for(int i=0;i<26;i++){
            if(have[i]<need[i]) stp=1;
            if((have[i]-need[i])%k!=0) stp=1;
            have[i]-=need[i];
            have[i+1]+=have[i];
        }
        if(stp) cout<<"No"<<'\n';
        else cout<<"Yes"<<'\n';
    }
}
