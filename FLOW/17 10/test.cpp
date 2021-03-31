#include <bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) for (int i=a; i<=b; i++)
int n;
char c[]={'a','b'};
int main()
{
    freopen("greetingcard.inp","w",stdout);
    cin >> n;
    cout << n << endl;
    srand(time(NULL));
    FOR(i,1,n)
    {
//        if (i==1) FOR(j,1,100000) cout << 'b';
//        else cout << 'a';
//        cout << endl;
        int x=rand()%20+1;
        FOR(j,1,x) cout << c[rand()%2];
        cout << endl;
    }
}
