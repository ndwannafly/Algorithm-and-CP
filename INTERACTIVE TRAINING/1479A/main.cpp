#include <bits/stdc++.h>
using namespace std;
int n;
#define  inf 100005
int main() {
    // +oo 10 9 8 7 6 5 4 3 2 1 +oo
    int a1,a2, an, anl;

    cin>>n;


    int l = 1, r = n;
    while(l<=r){
        int m = (l+r)>>1;
        cout<<"? "<<m<<'\n';
        fflush(stdin);
        int aml,amr,am;
        cin>>am;
        if(m-1 !=0 ) {
            cout << "? " << m - 1 << '\n';
            fflush(stdin);
            cin >> aml;
        }
        else aml = inf;
        if (m != n) {
            cout << "? " << m + 1 << '\n';
            fflush(stdin);
            cin >> amr;
        }
        else amr = inf;

        if(am < aml && am < amr){
            cout<<"! "<<m;
            return 0;
        }

        if(aml > am && am > amr){
            l = m+1;
        }
        else r = m-1;
    }
}
