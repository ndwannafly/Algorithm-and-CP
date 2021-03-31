#include <bits/stdc++.h>
int p[]={2,1};
using namespace std;
int main(){
    do{
        for(int i=0;i<=1;i++) cout<<p[i]<<" ";
        cout<<'\n';
    }while(next_permutation(p,p+2));
}
