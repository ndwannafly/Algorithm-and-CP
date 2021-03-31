#include <bits/stdc++.h>
using namespace std;
string s,w[1005];
int p[1005],n,m;
int F[105][105],G[105][105][105][35];
int pos[105][30],res[105];
/// 1)  Chi phí max khi xóa hết đoạn [i -> j]
/// 2)  G[i,j,k,h] là chi phí max khi xóa đoạn [i->j]
    /// mà còn các kí tự từ 0 -> h của xâu con W(k)
    ///  => có thể suy biến thành s[j] = W(k)[h].
/// 3) Khi W(k).size() - 1 == h thì cập nhật:
    /// F[i,j] = max(F[i,j],G[i,j,k,h] + p[k]).
    /// G[i,j,k,h] + = p[k].
    /// Luôn cập nhật F[i,j] = max(F[i,j], G[i,j,k,h] + p[k]).
/// 4) pos[i,c] là vị trí max không vượt quá i có kí tự c.
/// 5) res[i] là chi phí max nhất khi xét đến vị trí i trong xâu s.

int main(){
    freopen("word.inp","r",stdin);
    cin>>s;
    m=s.size();s=" "+s;
    cin>>n;
    for(int i=1;i<=n;i++) cin>>w[i]>>p[i];
    memset(G,-0x3f,sizeof(G));
    memset(F,-0x3f,sizeof(F));
    for(int i=1;i<=m;i++){
        for(int j=0;j<=25;j++) pos[i][j]=pos[i-1][j];
        pos[i][s[i]-'a']=i;
    }
    for(int i=m;i>=1;i--){
        for(int j=i;j<=m;j++){
            for(int k=1;k<=n;k++){
                for(int h=0;h<w[k].size();h++){
                    if(s[j]==w[k][h]){
                        if(h==0&&i==j) G[i][j][k][h]=0;
                        else if(h>0){
                            int pp=j;
                            while(pp>=i){/// Tìm các vị trí pp = W(k)[h-1].
                                pp=pos[pp-1][w[k][h-1]-'a'];
                                if(pp+1>j-1) F[pp+1][j-1]=0;
                                G[i][j][k][h]=max(G[i][j][k][h],G[i][pp][k][h-1]+F[pp+1][j-1]);
                            }
                        }
                        if(h==w[k].size()-1){ // update G-> F
                            G[i][j][k][h]+=p[k];
                            F[i][j]=max(F[i][j],G[i][j][k][h]);
                        }
                    }
                }
            }
            for(int k=i;k<=j-1;k++){
                if(F[i][k]>0&&F[k+1][j]>0) F[i][j]=max(F[i][j],F[i][k]+F[k+1][j]);
            }
        }
    }
    for(int i=1;i<=m;i++){
        res[i]=res[i-1];
        for(int j=0;j<i;j++) res[i]=max(res[i],res[j]+F[j+1][i]);
    }
    cout<<res[m];
}




