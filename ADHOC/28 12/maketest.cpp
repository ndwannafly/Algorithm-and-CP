#include <bits/stdc++.h>
using namespace std;
int main(){
    srand(time(NULL));
    freopen("GCITP.inp","w",stdout);
    // permutation-test
    int n=50;
    cout<<n<<'\n';
    vector <int> rem;
    for(int i=1;i<=n;i++){
        rem.push_back(i);
    }
    while(!rem.empty()){
        int x=rand()%rem.size();
        cout<<rem[x]<<" ";
        swap(rem[x],rem.back());
        rem.pop_back();
    }
    cout<<'\n';
    for(int i=1;i<=n;i++){
        rem.push_back(i);
    }
    while(!rem.empty()){
        int x=rand()%rem.size();
        cout<<rem[x]<<" ";
        swap(rem[x],rem.back());
        rem.pop_back();
    }
    //
//    int n=300;
//    cout<<n<<'\n';
//    for(int i=1;i<=n;i++){
//        cout<<rand()%50+1<<' ';
//    }
//    cout<<'\n';
//    for(int i=1;i<=n;i++){
//        cout<<rand()%50+1<<' ';
//    }
}
