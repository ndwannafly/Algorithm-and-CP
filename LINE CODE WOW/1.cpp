#include <bits/stdc++.h>
using namespace std;
struct data{
    string keyword;
    string content;
}s[100005];
int n;
string inp;
string key;
bool cmp(const data &p, const data &q){
    int siz=min(p.keyword.size(),q.keyword.size());
    for(int i=0;i<siz;i++){
        if(p.keyword[i]!=q.keyword[i]) return p.keyword[i]<q.keyword[i];
    }
    return p.keyword.size()<q.keyword.size();
}
int main(){
    //freopen("1.inp","r",stdin);
    //freopen("1.out","w",stdout);
    getline(cin, inp);
    stringstream ss(inp);
    ss>>n;
    for(int i=1;i<=n;i++){
        string t;
        getline(cin,t);
        bool isContent=0;
        for(char c:t){
            if(c==':') isContent=1;
            if(!isContent) s[i].keyword+=c;
            else s[i].content+=c;
        }
    }
    sort(s+1,s+n+1,cmp);
    getline(cin,key);
    int now=1,cnt=0;
    bool ok=0;
    while(now<=n&&cnt<5){
        if(s[now].keyword==key) ok=1;
        if(ok){
            cout<<s[now].keyword<<s[now].content<<'\n';
            ++cnt;
        }
        ++now;
    }
    if(!ok) cout<<"no data";
}
