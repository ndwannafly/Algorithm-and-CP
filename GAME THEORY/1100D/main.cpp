#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
pii rook[667];
int x_busy[1000],y_busy[1000];
bool busy[1000][1000];
int cnt[2][2];
int mx;
int king_x, king_y;
void ask2(int x,int y){
    cout<<x<<" "<<y<<'\n';
    fflush(stdout);
    king_x = x;
    king_y = y;
    int a,b,c;
    cin>>a>>b>>c;
    //a = 1, b =1, c=1;
    if(a == - 1 && b == -1 && c == -1) exit(0);
    if(a==0 && b==0 && c== 0){
        cout<<"invalid move";
        exit(0);
    }
    x_busy[rook[a].first]--;
    y_busy[rook[a].second]--;
    busy[rook[a].first][rook[a].second] = false;
    rook[a].first = b;
    rook[a].second = c;
    busy[b][c] = true;
    x_busy[b]++;
    y_busy[c]++;
}
bool in_range(int u){
    return u>=1 && u <= 999;
}
void check(int x,int y){
    for(int i=-1; i<=1; i++){
        if(!in_range(x+i)) continue;
        for(int j=-1; j<=1; j++){
            if(!in_range(y+j)) continue;
            if(x_busy[x+i] || y_busy[y+j]){
                if(!busy[x+i][y+j]) { // get checked
                    cout<<x+i<<" "<<y+j<<'\n';
                    fflush(stdout);
                    int a,b,c;
                    cin>>a>>b>>c;
                    exit(0); // sure that a,b,c = -1 -1 -1
                }
            }
        }
    }
}

int main() {
/*    fstream cin;
    cin.open("D:\\ALGO\\GAME THEORY\\1100D\\input.txt", ios::in);
    if(!cin) {
        cout << "NO SUCH FILE";
        return 0;
    }*/
    cin>>king_x>>king_y;
    for(int i=1; i<=666; i++){
        cin>>rook[i].first>>rook[i].second;
        busy[rook[i].first][rook[i].second] = true;
        x_busy[rook[i].first]++;
        y_busy[rook[i].second]++;
    }
    while(king_x != 500 || king_y != 500){
        check(king_x,king_y);
        if(king_x > 500) king_x--;
        else if(king_x < 500) king_x ++;
        if(king_y > 500) king_y--;
        else if(king_y < 500) king_y++;
        ask2(king_x,king_y);
    }
    for(int i = 1 ; i <= 666; i++){
        // 0 0 -> 0 1 ; 1 0
        // 1 1 -> 0 1 ; 1 0
        // 0 1 -> 0 0 ; 1 1
        // 1 0 -> 1 1 ; 0 0
        cnt[rook[i].first > 500][rook[i].second > 500]++;
        cnt[rook[i].first < 500][rook[i].second > 500]++;
        cnt[rook[i].first > 500][rook[i].second < 500]++;
    }
    int add_x,add_y;
    for(int i=0;i<=1;i++){
        for(int j=0;j<=1;j++){
            if(mx < cnt[i][j]){
                mx = cnt[i][j];
                add_x = i;
                add_y = j;
            }
        }
    }
    if(!add_x) add_x = -1;
    if(!add_y) add_y = -1;
    while(true){
        check(king_x,king_y);
        ask2(king_x + add_x, king_y + add_y);
    }
}