#include <bits/stdc++.h>
#define ll long long

using namespace std;
const int NM=1e3;
ll n,c;
ll a[NM][NM],dem[NM];
bool cx[NM];

void readfile()
{
    ll i,e,b,v;
    freopen("NUOCLANH.INP","r",stdin);
    freopen("NUOCLANH.OUT","w",stdout);
    cin >> n >> c;
    for(i=1;i<=c;i++)
    {
        cin >> e >> b >> v;
        a[e][b]=1;
        a[b][e]=1;
        a[e][v]=1;
        a[v][e]=1;
    }
    memset(cx,true,sizeof(cx));
    memset(dem,0,sizeof(dem));
    dem[1]=1;
}
void DFS(ll u)
{
    ll v,i;
    cx[u]=false;
    for(v=1;v<=n;v++)
    {
        if(cx[v]==true && a[u][v]==1)
        {
            dem[v]=dem[u]+1;
            DFS(v);
        }
    }
}
int main()
{
    ll i,j;
    readfile();
    DFS(1);
    for(ll i=1;i<=n;i++) cout << dem[i] << '\n';
    return 0;
}
