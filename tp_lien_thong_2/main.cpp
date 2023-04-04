#include <bits/stdc++.h>
#define ll long long

using namespace std;
const int NM=1e3;
ll n;
ll a[NM][NM],T[NM];
bool cx[NM];

void readfile()
{
    ll i,j;
    freopen("LIENTHONG.INP","r",stdin);
    freopen("LIENTHONG.OUT","w",stdout);
    cin >> n;
    for(i=1;i<=n;i++)
        for(j=1;j<=n;j++)
            cin >> a[i][j];
    memset(cx,true,sizeof(cx));
}
void DFS(ll u)
{
    ll v;
    cx[u]=false;
    cout << u<< " ";
    for(v=1;v<=n;v++)
    {
        if(cx[v]==true && a[u][v]!=0)
        {
            T[v]=u;
            DFS(v);
        }
    }
}
void xuli()
{
    ll dem=0,i;
    for(i=1;i<=n;i++)
    {
        if(cx[i]==true)
        {
            dem++;
            cout << "Thanh phan thu " << dem << ": ";
            DFS(i);
            cout << '\n';
        }
    }
    cout << dem << '\n';

}
int main()
{
    readfile();
    xuli();
    return 0;
}
