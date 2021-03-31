#include <bits/stdc++.h>
using namespace std;

#define  NMAX 1005
#define  pb push_back
unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
vector <int> Coin;
bool flag;
int n;
void ask3FirstAndRemove(){
    // ask for 3 first coins, remove one if there exists an answer is 0 ( there are 2 coins 20 )

    for(int i=1;i<=3;i++){
        for(int j=i+1;j<=3;j++){
            cout<<"Q 1 1 "<<i<<" "<<j<<'\n';
            fflush(stdin);
            int response;
            cin>>response;
            if(response == 0){
                flag = 1;
                for(int k=1;k<=n;k++){
                    if(k!=i) Coin.pb(k);
                }
                return;
            }
        }
    }

    if(!flag){ // coin 10 and coin 30 are in the first 3 coins
        for(int i=1;i<=3;i++){
            for(int j=i+1;j<=3;j++){
                for(int k=1;k<=3;k++){
                    if(k!=i&&k!=j){
                        cout<<"Q 2 1 "<<i<<" "<<j<<" "<<k<<'\n';
                        fflush(stdin);
                        int response;
                        cin>>response;
                        if(response==0){
                            cout<<"Q 1 1"<<" "<<i<<" "<<j<<'\n';
                            fflush(stdin);
                            int answer;
                            cin>>answer;
                            if(answer == -1){
                                cout<<"A "<<i<<" "<<k;
                                exit(0);
                            }
                            else{
                                cout<<"A "<<j<<" "<<k;
                                exit(0);
                            }
                        }
                    }
                }
            }
        }
    }
}

vector <int> LeftSet;
vector <int> RightSet;
int pos10,pos30;
void Solve10(vector <int> v){
    int siz = v.size()/3;
    if(!siz){
        if(v.size() == 1) pos10 = v.back();
        else{
            cout<<"Q 1 1 "<<v[0]<<" "<<v[1]<<'\n';
            fflush(stdin);
            int response;
            cin>>response;
            if(response < 0) {
                pos10 = v[0];
            }
            else {
                pos10 = v[1];
            }
        }
        return;
    }
    vector <int> firstSet, secondSet, thirdSet;
    for(int i=0;i<siz;i++) firstSet.pb(v[i]);
    for(int i=siz;i<2*siz;i++) secondSet.pb(v[i]);
    for(int i=2*siz;i<v.size();i++) thirdSet.pb(v[i]);
    cout<<"Q "<<siz<<" "<<siz<<" ";
    for(int v : firstSet) cout<<v<<" ";
    for(int v: secondSet) cout<<v<<" ";
    cout<<'\n';
    fflush(stdin);
    int response;
    cin>>response;
    if(response == 0 ){
        Solve10(thirdSet);
    }
    else{
        if(response == - 1){ // firstSet contains coin 10
            Solve10(firstSet);
        }
        else Solve10(secondSet);
    }
}

void Solve30(vector <int> v){
    int siz = v.size()/3;
    if(!siz){
        if(v.size() == 1) pos30 = v.back();
        else{
            cout<<"Q 1 1 "<<v[0]<<" "<<v[1]<<'\n';
            fflush(stdin);
            int response;
            cin>>response;
            if(response < 0) pos30 = v[1];
            else pos30 = v[0];
        }
        return;
    }
    vector <int> firstSet, secondSet, thirdSet;
    for(int i=0;i<siz;i++) firstSet.pb(v[i]);
    for(int i=siz;i<2*siz;i++) secondSet.pb(v[i]);
    for(int i=2*siz;i<v.size();i++) thirdSet.pb(v[i]);
    cout<<"Q "<<siz<<" "<<siz<<" ";
    for(int v : firstSet) cout<<v<<" ";
    for(int v: secondSet) cout<<v<<" ";
    cout<<'\n';
    fflush(stdin);
    int response;
    cin>>response;
    if(response == 0 ){
        Solve30(thirdSet);
    }
    else{
        if(response == - 1){ // second contains coin 30
            Solve30(secondSet);
        }
        else Solve30(firstSet);
    }
}


int main() {
    cin >> n;

    if(n&1) ask3FirstAndRemove();
    else{
        for(int i=1;i<=n;i++) Coin.pb(i);
    }
    while(true){
        LeftSet.clear();
        RightSet.clear();
        shuffle(Coin.begin(), Coin.end(), default_random_engine(seed));
        for(int i=0;i<Coin.size()/2;i++) LeftSet.pb(Coin[i]);
        for(int i=Coin.size()/2;i<Coin.size();i++) RightSet.pb(Coin[i]);
/*        LeftSet.pb(1);
        LeftSet.pb(4);
        LeftSet.pb(5);
        RightSet.pb(6);
        RightSet.pb(2);
        RightSet.pb(3);*/
        cout<<"Q "<<LeftSet.size()<<" "<<RightSet.size()<<" ";
        for(int v : LeftSet) cout<<v<<" ";
        for(int v: RightSet) cout<<v<<" ";
        cout<<'\n';
        fflush(stdin);
        int response;
        cin>>response;
        if(response != 0){ // each set contains either 10 or 30
            if(response == -1){
                Solve10(LeftSet);
                Solve30(RightSet);
            }
            else{
                Solve10(RightSet);
                Solve30(LeftSet);
            }
            cout<<"A "<<pos10<<" "<<pos30;
            return 0;
        }
    }
}