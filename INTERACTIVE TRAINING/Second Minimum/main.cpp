#include <bits/stdc++.h>
using namespace  std;
vector <int> grtr[10005];
// 1 2 3 ... n/2   |   n/2 +1  . ..  n
int query(int x,int y){
    cout<<"Q "<<x<<" "<<y<<'\n';
    fflush(stdin);
    int response;
    cin>>response;
    return response;
}

int Try(int l,int r){ // find the minimum
    if(l==r) return l;
    int m = (l+r)>>1;
    int minL = Try(l,m), minR = Try(m+1, r);
    if(query(minL,minR) == minL){
        grtr[minL].push_back(minR);
        return minL;
    }
    else{
        grtr[minR].push_back(minL);
        return minR;
    }
}
int main() {
    int n;
    cin>>n;
    int smallest = Try(1,n);
    int res = grtr[smallest].back();
    grtr[smallest].pop_back();
    for(auto v : grtr[smallest]){
        if(query(res,v) == v){
            res = v;
        }
    }
    cout<<"A "<<res;
}
// 4 5 3 1 2