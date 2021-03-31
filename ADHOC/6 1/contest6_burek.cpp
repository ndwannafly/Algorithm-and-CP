#include <iostream>
#include <string>

using namespace std;
typedef long long ll;

int n,m;
char xy,dummy;
int coor;
int flag=0;
int equala=0;
int burek=0;
int x[100000];
int y[100000];
        
int main(){
    cin >> n;
    for(int i=0;i<3*n;i+=3){
        cin >> x[i]; cin >> y[i];
        cin >> x[i+1]; cin >> y[i+1];
        cin >> x[i+2]; cin >> y[i+2];
    }
    
    cin >> m;
    for(int i=0;i<m;i++){
        burek=0;
        cin >> xy;
        cin >> dummy;
        cin >> coor;
        if(xy=='x'){
            for(int i=0;i<3*n;i+=3){
                flag=0;
                equala=0;
                for(int k=0;k<3;k++){
                    if(x[i+k]>coor)
                        flag++;
                    else if(x[i+k]<coor)
                        flag--;
                    else
                        equala++;
                  }
                if(!((equala!=0&&flag!=0)||flag==3||flag==-3)){
                    burek++;
                }
            }
        }
        else for(int i=0;i<3*n;i+=3){
                flag=0;
                equala=0;
                for(int k=0;k<3;k++)
                    if(y[i+k]>coor)
                        flag++;
                    else if(y[i+k]<coor)
                        flag--;
                    else
                        equala++;
                if(!((equala!=0&&flag!=0)||flag==3||flag==-3))
                    burek++;
            }
        cout << burek << endl;
    }
    return 0;
}
