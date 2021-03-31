#include <bits/stdc++.h>
using namespace std;
#define  NMAX 100005
int p[NMAX];
int n;
int L[NMAX], R[NMAX];
int cnt_L[NMAX],cnt_R[NMAX];
int main() {
    cin>>n;
    for(int i=1;i<=n;i++) cin>>p[i];

    for(int i=1;i<=n;i++){
        if(p[i] > p[i-1]) {
            L[i] = L[i - 1] + 1;
        }
        else L[i] = 1;
        cnt_L[L[i]]++;
    }


    for(int i=n;i>=1;i--){
        if(p[i] > p[i+1]) R[i] = R[i+1] + 1;
        else R[i] = 1;
        cnt_R[R[i]]++;
    }

    for(int i=1;i<=n;i++){
        cnt_L[i] += cnt_L[i-1];
        cnt_R[i] += cnt_R[i-1];
    }
    int ans = 0;
    for(int i=2; i<n;i++){
        if(p[i-1] > p[i] | p[i+1] > p[i]) continue;
        int r = cnt_R[n] - cnt_R[R[i]-1];
        if(r >= 2) continue;
        int l = cnt_L[n] - cnt_L[L[i]-1];
        if(l >= 2) continue;
        if(R[i] == L[i] && L[i]&1) ++ans;
    }
    cout<<ans;

}
