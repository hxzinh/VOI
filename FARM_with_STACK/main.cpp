#include <bits/stdc++.h>
#define ll long long

using namespace std;
const int NM=1e3+10;
ll cld[]={-1,0,1,0};
ll clc[]={0,-1,0,1};
ll n,m;
char a[NM][NM];
bool cx[NM][NM];

void readfile()
{
    freopen("FARM.INP","r",stdin);
    freopen("FARM.OUT","w",stdout);
    cin >> n >> m;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            cin >> a[i][j];
            cx[i][j]=true;
        }
    }
}
void DFS(ll x,ll y)
{
    stack <int> st[NM];
    st.push({x,y});
    cx[x][y]=false;
    while(!st.empty())
    {
        for(int i=0;i<=3;i++)
        {
            ll u,v;
            u=x+cld[i];
            v=y+clc[i];
        }
    }

}
void xuli()
{

}
int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
