#include <bits/stdc++.h>
using namespace std;
template <typename T> inline void read(T &x){
    char c;
    bool nega=0;
    while((!isdigit(c=getchar()))&&(c!='-'));
    if(c=='-'){
        nega=1;
        c=getchar();
    }
    x=c-48;
    while(isdigit(c=getchar())) x=x*10+c-48;
    if(nega) x=-x;
}
template <typename T> inline void writep(T x){
    if(x>9) writep(x/10);
    putchar(x%10+48);
}
template <typename T> inline void write(T x){
    if(x<0){
        putchar('-');
        x=-x;
    }
    writep(x);
}
template <typename T> inline void writeln(T x){
    write(x);
    putchar('\n');
}
#define pb push_back
#define mp make_pair
#define NMAX 1005

typedef pair<int,int> pii;
typedef long long ll;
typedef pair<ll,ll> pll;

struct data{
    int num,child[27];
};
string s;
data trie[NMAX*10];
int n,cnt=1;
string ans1="",ans2="";
bool mark[NMAX][NMAX];
inline void Add(string s){
    int start=1;
    for(int i=0;i<s.size();i++){
        int j=s[i];
        if(trie[start].child[j-'a']==0) trie[start].child[j-'a']=++cnt;
        start=trie[start].child[j-'a'];
    }
    trie[start].num++;
}

inline bool F(int u,int v){
    if(mark[u][v]) return false;
    mark[u][v]=true;
    if(trie[u].num>0&&trie[v].num>0&&u!=v){
        return true;
    }

    for(int i=0;i<=26;i++){
        int uu=trie[u].child[i];
        int vv=trie[v].child[i];
        if(uu!=0&&vv!=0&&F(uu,vv)){
            ans1+=char(i+'a');
            ans2+=char(i+'a');
            return true;
        }
    }
    if(trie[u].num>0){
        for(int i=0;i<=26;i++){
            int uu=trie[1].child[i];
            int vv=trie[v].child[i];
            if(uu!=0&&vv!=0&&F(uu,vv)){
                ans1+=char(i+'a');
                ans1+='+';
                ans2+=char(i+'a');
                return true;
            }
        }
    }
    if(trie[v].num>0){
        for(int i=0;i<=26;i++){
            int uu=trie[u].child[i];
            int vv=trie[1].child[i];
            if(uu!=0&&vv!=0&&F(uu,vv)){
                ans1+=char(i+'a');
                ans2+=char(i+'a');
                ans2+='+';
                return true;
            }
        }
    }
    return false;
}
void progress(){
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>s;
        Add(s);
    }
   // exit(0);
    if(!F(1,1)){
        writeln(-1);
    }
    else{
        reverse(ans1.begin(),ans1.end());
        reverse(ans2.begin(),ans2.end());
        cout<<ans1<<'\n'<<ans2;
    }
}
int main(){
    //freopen("decode.inp","r",stdin);
    progress();
}
