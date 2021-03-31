#include <bits/stdc++.h>
using namespace std;
int n,k;
struct TrieNode{
    int dp;
    TrieNode* child[26];
    TrieNode(){
        dp = 1;
        memset(child, 0, sizeof(child));
    }
};

TrieNode *root = new TrieNode();
void add_TrieNode(string s){
    TrieNode *p = root;
    for(int c : s){
        c-='a';
        if(p->child[c] == nullptr){
            p->child[c] = new TrieNode();
        }
        p->dp = 0;
        p = p->child[c];
    }
}
void DFS(TrieNode *u){ // dp[u] = max ( v + 1 + dp[v])
    if(u->dp != 1) {
        vector <int> F;
        for (int i = 0; i < 26; i++) {
            if (u->child[i]) {
                //cout << char('a' + i) << '\n';
                DFS(u->child[i]);
                F.push_back(u->child[i]->dp);
            }
        }
        sort(F.begin(),F.end(),greater<int>());
        for(int i = 0; i < F.size() ; i++){
            u->dp = max( u->dp , F[i] + i + 1);
        }
    }
}

void query(TrieNode* u){
    if(u->dp == 1) return;
    vector < pair<int,int> > F;
    for(int i=0; i<26;i++){
        if(u->child[i]){
            F.push_back(make_pair(u->child[i]->dp,i));
        }
    }
    sort(F.begin(),F.end(), greater<pair<int,int>>());

    int now = 0;
    while(true){
        cout<<char('a' + F[now].second)<<'\n';
        fflush(stdin);
        int response;
        cin>>response;
        if(response){
            query(u->child[F[now].second]);
            break;
        }
        ++now;
    }
}
int main() {
    root->dp = 1;
    cin>>n>>k;
    for(int i=1;i<=n;i++){
        string s;
        cin>>s;
        add_TrieNode(s);
    }
    DFS(root);
    query(root);
}
