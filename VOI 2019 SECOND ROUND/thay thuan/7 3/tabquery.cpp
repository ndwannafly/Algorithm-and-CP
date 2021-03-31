#include <bits/stdc++.h>
using namespace std;
#define y1 jbhkba
#define y0 jlnjln
#define x0 afasd
#define x1 jdsfsdf
struct fwTree2D{
    const int fwMAX = (int) 1e3+5;
    int node[1010][1010];
    void upd(int x,int y,int val){
        for(;x<=fwMAX;x+=x&-x){
            int yy = y;
            for(;yy<=fwMAX;yy+=yy&-yy){
                node[x][yy] += val;
            }
        }
    }
    int get(int x,int y){
        int res = 0;
        for(;x;x-=x&-x){
            int yy = y;
            for(;yy;yy-=yy&-yy){
                res += node[x][yy];
            }
        }
        return res;
    }
};
fwTree2D fw;
int q, epsilon;
int f(int x){
    return (x + epsilon) % ((int)1e9) + 1;
}
int main(){
    scanf("%d",&q);
    while(q--){
        int type;
        scanf("%d",&type);
        if (type == 1){
            int x, y, m;
            scanf("%d %d %d",&x,&y,&m);
            x = f(x);
            y = f(y);
            fw.upd(x, y, m);
        }
        else{
            int x0, y0, x1, y1;
            scanf("%d %d %d %d",&x0,&y0,&x1,&y1);
            x0 = f(x0);
            y0 = f(y0);
            x1 = f(x1);
            y1 = f(y1);
            if (x0 > x1 || y0 > y1){
                printf("0\n");
            }
            else{
                int res = fw.get(x1,y1) - fw.get(x1, y0-1) - fw.get(x0-1, y1) + fw.get(x0-1,  y0-1);
                printf("%d\n", res);
                epsilon += abs(res);
                while(epsilon >= (int) 1e9)  epsilon -= (int) 1e9;
            }
        }
    }
}
