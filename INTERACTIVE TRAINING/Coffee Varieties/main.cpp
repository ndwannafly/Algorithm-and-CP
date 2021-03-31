#include <bits/stdc++.h>
using namespace std;
unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();

char ask(int x){
    cout<<"? "<<x<<'\n';
    fflush(stdin);
    char response;
    cin>>response;
    return response;
}
int main() {
    int n,k;
    cin>>n>>k;
    int limit = min(15000, 3*n*n/(2*k));
    vector <int> v(n);
    for(int i = 0 ; i < n ; i++){
        v[i] = i+1;
    }
    //14 3 5 15 12 6 8 7 1 4 11 1 13 9 2 10
    // 1 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15
    while(true){
        cout<<"R\n";
        shuffle(v.begin(), v.end(), default_random_engine(seed));
        //cout<<"vector has:\n ";
        //for(int x : v) cout<<x<<" ";
        //cout<<'\n';
        vector <int> new_v;
        for(auto x : v){
            if(ask(x) == 'N'){
                new_v.emplace_back(x);
            }
            --limit;
            if(!limit) break;
        }
        if(!limit) break;
        v = new_v;
    }
    cout<<"! "<<v.size();
}
