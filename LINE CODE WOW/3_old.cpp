#include <bits/stdc++.h>
using namespace std;
vector<int> ord;
vector <int> depth;
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
void single_object(const string &p){
    string cur="";
    bool space_needed=0;
    for(auto c:p){
        if(c=='['){
            if(cur.empty()) continue;
            prePrint();
            cout<<"text: "<<cur<<'\n';
            cur="";
            space_needed=1;
        }
        else{
            if(c==']'){
                if(cur.empty()) continue;
                prePrint();
                cout<<cur<<'\n';
                cur="";
            }
            else{
                cur=cur+c;
                if(c==':'&&space_needed){
                    cur=cur+' ',space_needed=0;
                }
            }
        }
    }
    if(!cur.empty()){
        prePrint();
        cout<<"text: "<<cur<<'\n';
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
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("3.inp","r",stdin);
    freopen("3.out","w",stdout);
    string s;
    while(getline(cin,s)){
        if(isOpenCollapse(s)) updateOpen();
        else if(isCloseCollapse(s)) updateClose();
        else{
            string txt="";
            txt=s;
            int check=0;
            while(getline(cin,s)){
                if(isCloseCollapse(s)){
                    check=1;
                    break;
                }
                if(isOpenCollapse(s)){
                    check=2;
                    break;
                }
                txt=txt+s;
            }
            bool wspace=1;
            string ntxt="";
            for(char c:txt){
                if(c!=' ') wspace=0;
                if(wspace) continue;
                ntxt=ntxt+c;
            }
            single_object(ntxt);
            if(check==1) updateClose();
            if(check==2) updateOpen();
        }
    }
}

