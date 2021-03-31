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
#define NMAX 1001
int n;
string s[NMAX];
map<string,bool> mymap;

void enter(){
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>s[i];
        mymap[s[i]]=true;
    }
}

void sub1(){

}

void progress(){
    if(n<=10) sub1();
}

int main(){
    enter();
    progress();
}
