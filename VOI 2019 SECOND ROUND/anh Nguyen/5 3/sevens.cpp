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
int a[14],b[14],n,L,R,numA,numB;
bool mark[14];
void solve(){

    read(n);
    while(n--){
        memset(a,0,sizeof(a));
        memset(b,0,sizeof(b));
        memset(mark,0,sizeof(mark));
        for(int i=1;i<=6;i++){
            int x;
            read(x);
            a[x]++;
            mark[x]=true;
        }
        for(int i=1;i<=13;i++){
            if(i==7) continue;
            if(!mark[i]) b[i]++;
        }
        L=6,R=8,numA=numB=6;
        int turn=0;
        while(1){
            bool flag=1;
            if(!turn){
                if(a[L]&&a[R]){
                    if(a[1]) a[L]--,L--;
                    else a[R]--,R++;
                    flag=0;
                }
                else{
                    if(a[L]&&!a[R]) a[L]--,L--,flag=0;
                    if(a[R]&&!a[L]) a[R]--,R++,flag=0;
                }
                if(!flag) numA--;
                if(numA==0) break;
            }
            else{
                if(b[L]&&b[R]){
                    if(b[1]) b[L]--,L--;
                    else b[R]--,R++;
                    flag=0;
                }
                else{
                    if(b[L]&&!b[R]) b[L]--,L--,flag=0;
                    if(b[R]&&!b[L]) b[R]--,R++,flag=0;
                }
                if(!flag) numB--;
                if(numB==0) break;
            }
            turn^=1;
        }
        //exit(0);
        if(turn==0) puts("yes");
        else puts("no");
        //exit(0);
    }
}
int main(){
   // freopen("sevens.inp","r",stdin);
    solve();
}
