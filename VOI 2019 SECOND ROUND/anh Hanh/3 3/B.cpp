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
typedef long long ll;
typedef pair<int,int> pii;
int n,cnt;
string s;
char ans[2601];
int dp[2601][2601],dem[27];
inline ll F(int i,int j){

    if(i>j) return 0;
    if(dp[i][j]!=0) return dp[i][j];
    if(i==j) dp[i][j]=1;
    else{
        if(s[i]==s[j]){
            dp[i][j]=F(i+1,j-1)+2;
        }
        else{
            dp[i][j]=max(F(i+1,j),F(i,j-1));
        }
    }
    return dp[i][j];
}
inline void Find(int i,int j){
    if(i>j) return;
   // cout<<i<<" "<<j<<" "<<dp[i][j]<<'\n';
    if(i==j) ans[++cnt]=s[i];
    else{
        if(s[i]==s[j]){
            ans[++cnt]=s[i];
            Find(i+1,j-1);
            ans[++cnt]=s[j];
        }
        else{
            if(dp[i+1][j]<dp[i][j-1]) Find(i,j-1);
            else Find(i+1,j);
        }
    }
}
int main(){
//    freopen("B.inp","r",stdin);
    cin>>s;
    n=s.size();
    s='*'+s;
    if(n<=2600){
        cnt=F(1,n);
        cnt=0;
        //writeln(cnt);
        //return 0;
        Find(1,n);
        if(cnt<=100){
            for(int i=1;i<=cnt;i++) putchar(ans[i]);
        }
        else{
            for(int i=1;i<=50;i++) putchar(ans[i]);
            for(int i=cnt-49;i<=cnt;i++) putchar(ans[i]);
        }
    }
    else{
        for(int i=1;i<=n;i++){
            dem[s[i]-'a']++;
        }
        for(int i=0;i<=26;i++){
         //   cout<<i<<" "<<dem[i]<<'\n';
            if(dem[i]>=100){
                for(int j=1;j<=100;j++) putchar(char(i+'a'));
                return 0;
            }
        }
    }
}
