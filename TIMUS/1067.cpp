#include <iostream>
#include <algorithm>
#include <set>
#include <vector>
#include <stdio.h>
#include <map>
using namespace std;
#define NMAX 40005
int n;
string trace[NMAX];
string S[NMAX];
vector <int> newstr[NMAX];
set<string> setstr;
map<string,int> ord;
struct TrieNode{
    TrieNode* child[750];
    TrieNode(){
        for(int i=0;i<750;i++){
            child[i]=nullptr;
        }
    }
};
TrieNode* root = new TrieNode();
void TrieInsert(const vector<int> &v){
    TrieNode* p = root;
    for(int x:v){
        if(p->child[x]==nullptr) p->child[x]= new TrieNode();
        p=p->child[x];
    }
}
int now=0;
void printTrie(TrieNode* p){
    for(int x=0;x<750;x++){
        if(p->child[x]!=nullptr){
            for(int j=0;j<now;j++) cout<<" ";
            cout<<trace[x]<<'\n';
            ++now;
            printTrie(p->child[x]);
            --now;
        }
    }
}
int main(){
    //freopen("1067.inp","r",stdin);
    //freopen("1067.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>S[i];
        S[i]=S[i]+'\\';
        string tmp="";
        for(char c:S[i]){
            if(c=='\\'){
                setstr.insert(tmp);
                tmp="";
            }
            else tmp=tmp+c;
        }
    }
    int cnt=0;
    for(auto c:setstr) ord[c]=++cnt,trace[cnt]=c;
    for(int i=1;i<=n;i++){
        string tmp="";
        for(char c:S[i]){
            if(c=='\\'){
                newstr[i].push_back(ord[tmp]);
                tmp="";
            }
            else tmp=tmp+c;
        }
        TrieInsert(newstr[i]);
    }
    printTrie(root);
}
