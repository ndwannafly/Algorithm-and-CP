#include <bits/stdc++.h>
using namespace std;
/*
 * guess S12 , S23 , S13 to get a2, a1 a3
 * Then continuously guess S14 S15 ... S1N to get corresponding a4 a5 ... an
 */
int n;
int x,y,z,t;
vector <int> res;
int s12, s23,s31;
int main() {
    cin>>n;
    cout<<"? "<<1<<" "<<2<<'\n';
    fflush(stdin);
    cin>>s12;
    cout<<"? "<<2<<" "<<3<<'\n';
    fflush(stdin);
    cin>>s23;
    cout<<"? "<<3<<" "<<1<<'\n';
    fflush(stdin);
    cin>>s31;
    int a2 = ( s12 + s23 - s31 )/2;
    int a1 = s12 - a2;
    int a3 = s31- a1;
    res.push_back(a1);
    res.push_back(a2);
    res.push_back(a3);
    for(int i=4;i<=n;i++){
        cout<<"? "<<1<<" "<<i<<'\n';
        fflush(stdin);
        int sum;
        cin>>sum;
        res.push_back(sum-a1);
    }
    cout<<"! ";
    for(int u : res){
        cout<<u<<" ";
    }
}
