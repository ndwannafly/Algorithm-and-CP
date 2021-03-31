#include <bits/stdc++.h>
using namespace std;
vector<int> ord;
vector <int> depth;
string txt="",ntxt="";
bool isOpenCollapse(const string &p){
    int cnt=0;
    for(char c:p) cnt+=(c=='[');
    return cnt==3;
}
bool isCloseCollapse(const string &p){
    int cnt=0;
    for(char c:p) cnt+=(c==']');
    return cnt==3;
}
void prePrint(){
    if(!depth.size()) return ;
    cout<<"collapse";
    for(int i:depth) cout<<"_"<<i;
    cout<<":";
}
void fixPrint(string p){
    while(p.back()==' ') p.pop_back();
    bool wspace=1;
    for(char c:p){
        if(c!=' ') wspace=0;
        if(wspace) continue;
        cout<<c;
    }
    cout<<'\n';
}
void single_object(const string &p){
    string cur="";
    bool space_needed=1;
    bool isText=0;
    for(auto c:p){
        if(c=='['){
            space_needed=1;
            if(!isText) continue;
            prePrint();
            cout<<"text: ";
            fixPrint(cur);
            cur="";
            isText=0;
        }
        else{
            if(c==']'){
                if(cur.empty()) continue;
                prePrint();
                fixPrint(cur);
                cur="";
                isText=0;
            }
            else{
                cur=cur+c;
                if(c!=' ') isText=1;
                if(c==':'&&space_needed){
                    cur=cur+' ',space_needed=0;
                }
            }
        }
    }
    if(isText){
        prePrint();
        cout<<"text: ";
        fixPrint(cur);
    }
}
void updateOpen(){
    while(ord.size()<=depth.size()) ord.push_back(0);
    ord[depth.size()]++;
    depth.push_back(ord[depth.size()]);
    if(depth.size()){
        prePrint();
        cout<<" start"<<'\n';
    }
}
void updateClose(){
    prePrint();
    while(ord.size()<=depth.size()) ord.push_back(0);
    ord[depth.size()]=0;
    if(depth.size()){
        depth.pop_back();
        cout<<" end"<<'\n';
    }
}
void solve(){
    if(txt=="") return;
    bool wspace=1;
    ntxt="";
    for(char c:txt){
        if(c!=' ') wspace=0;
        if(wspace) continue;
        ntxt=ntxt+c;
    }
    txt="";
    single_object(ntxt);
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    //freopen("3.inp","r",stdin);
    //freopen("3.out","w",stdout);
    string s;
    while(getline(cin,s)){
        if(isOpenCollapse(s)){
            solve();
            updateOpen();
            continue;
        }
        if(isCloseCollapse(s)){
            solve();
            updateClose();
            continue;
        }
        txt=txt+s;
    }
    solve();
}
