#include <bits/stdc++.h>
using namespace std;

struct data
{
    int num,Child[30];
};

data tree[10000];
int n,top=1;
bool Free[1005][1005];
string s,rs1="",rs2="";

void Add(string s)
{
    int tmp=1;
    for(int i=0;i<s.size();i++)
    {
        if(tree[tmp].Child[s[i]-'a']==0)
            tree[tmp].Child[s[i]-'a']=++top;
        tmp=tree[tmp].Child[s[i]-'a'];
    }
    tree[tmp].num++;
}

bool f(int u,int v)
{
    if(Free[u][v]==true)
        return false;
    Free[u][v]=true;
    if(tree[u].num>0&&tree[v].num>0&&u!=v)
        return true;
    for(int i=0;i<=26;i++)
    {
        int uu=tree[u].Child[i];
        int vv=tree[v].Child[i];
        if(uu!=0&&vv!=0&&f(uu,vv)==true)
        {
            rs1+=char(i+'a');
            rs2+=char(i+'a');
            return true;
        }
    }
    if(tree[u].num>0)
        for(int i=0;i<=26;i++)
        {
            int uu=tree[1].Child[i];
            int vv=tree[v].Child[i];
            if(uu!=0&&vv!=0&&f(uu,vv)==true)
            {
                rs1+=char(i+'a');
                rs1+='+';
                rs2+=char(i+'a');
                return true;
            }
        }
    if(tree[v].num>0)
        for(int i=0;i<=26;i++)
        {
            int uu=tree[u].Child[i];
            int vv=tree[1].Child[i];
            if(uu!=0&&vv!=0&&f(uu,vv)==true)
            {
                rs1+=char(i+'a');
                rs2+=char(i+'a');
                rs2+='+';
                return true;
            }
        }
    return false;
}

int main()
{
    ios_base::sync_with_stdio(false);
    //freopen("DECODE.INP","r",stdin);
    cin>>n;
    while(n--)
    {
        cin>>s;
        Add(s);
    }
    if(f(1,1)==false)
        cout<<-1;
    else
    {
        reverse(rs1.begin(),rs1.end());
        reverse(rs2.begin(),rs2.end());
        cout<<rs1<<"\n"<<rs2;
    }
}
