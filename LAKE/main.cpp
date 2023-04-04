#include <bits/stdc++.h>
#define ll long long

using namespace std;
const int NM=1e3+10;
ll cld[]={0,-1,0,1};
ll clc[]={-1,0,1,0};
ll n,m,k,dem=0,kqua=-99999999,l=0,f=1;
ll a[NM][NM];
struct Data
{
    ll u,v;
};
Data luu[NM];

void readfile()
{
    freopen("LAKE.INP","r",stdin);
    freopen("LAKE.OUT","w",stdout);
    cin >> m >> n >> k;
    for(int i=1;i<=m;i++)
    {
        for(int j=1;j<=n;j++)
        {
            a[i][j]=0;
        }
    }
    for(int i=1;i<=k;i++)
    {
        ll u,v;
        cin >> u >> v;
        a[u][v]=1;
    }
}
void push(ll x,ll y)
{
    l++;
    luu[l].u=x;
    luu[l].v=y;
}
bool isEmpty()
{
    if(f<=l) return true;
    else return false;
}
void BFS(ll x,ll y)
{
    for(int i=0;i<=3;i++)
    {
        ll u,v;
        u=x+cld[i];
        v=y+clc[i];
        if(a[u][v]==1)
        {
            push(u,v);
            ///cx[u][v]=false;
        }
    }
    a[x][y]=0;
    while(f<=l)
    {
        ll u,v;
        dem++;
        a[luu[f].u][luu[f].v]=0;
        for(int i=0;i<=3;i++)
        {
            ll u,v;
            u=luu[f].u+cld[i];
            v=luu[f].v+clc[i];
            if(a[u][v]==1)
            {
                push(u,v);
            }
        }
        f++;
    }
}
void xuli()
{
    for(int i=1;i<=m;i++)
    {
        for(int j=1;j<=n;j++)
        {
            if(a[i][j]==1)
            {
                dem=1;
                BFS(i,j);
            }
            kqua=max(kqua,dem);
        }
    }
    for(int i=1;i<=m;i++)
    {
        for(int j=1;j<=n;j++)
        {
            cout << a[i][j] << " ";
        }
        cout << '\n';
    }
    cout << kqua;
}
int main()
{
    readfile();
    xuli();
    return 0;
}
