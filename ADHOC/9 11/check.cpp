#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
string s="2068965517241379310344827586206896551724137931034482758";
int main(){
    ll now=0;
    ll base=1e9+7;
    for(int i=0;i<s.size();i++){
        now=(now*10+s[i]-'0')%base;
    }
    cout<<now;
}
