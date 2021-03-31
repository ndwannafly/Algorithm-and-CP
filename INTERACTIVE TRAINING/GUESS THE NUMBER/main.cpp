#include <bits/stdc++.h>
using namespace std;
int a[1005];
#define pb push_back
int main() {
    int n;
    cin>>n;
    cout<<"Q 2 1 2\n";
    fflush(stdin);
    int a12;
    cin>>a12;
    cout<<"Q 2 1 3\n";
    fflush(stdin);
    int a13;
    cin>>a13;
    cout<<"Q 2 2 3\n";
    fflush(stdin);
    int a23;
    cin>>a23;
    a[2] = (a12 + a23 - a13)/2;
    a[1] = a12 - a[2];
    a[3] = a13 - a[1];
    for(int i=4;i<=n;i++){
        cout<<"Q 2 1\n"<<i;
        fflush(stdin);
        int a1i;
        cin>>a1i;
        a[i] = a1i-a[1];
    }
    cout<<"A ";
    for(int i=1;i<=n;i++){
        cout<<a[i]<<" ";
    }
}
