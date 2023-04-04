#include <bits/stdc++.h>
#define ll long long
#define oo 1e17
#define FastIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;
const int NM=300;
ll n,m;
ll a[NM][NM];
ll s[202][202][404];

void readfile()
{
    freopen("BROTHERS.INP","r",stdin);
    freopen("BROTHERS.OUT","w",stdout);
    cin >> n >> m;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            cin >> a[i][j];
        }
    }
    for(int i=1;i<=n;i++)
    for(int j=1;j<=m;j++)
        for(int u=1;u<=n+m;u++)
            s[i][j][u]=-oo;
}
ll tinhX(ll x,ll y,ll u)
{
    ///ll res=-oo;
    ll &res=s[x][y][u];
    ll v=x+y-u;
    if(x==n && u==n && y==m && v==m) return 0;
    if(x==u && y==v) return -oo;
    if(x>n || y>m || u>n || v>m) return -oo;
    if(s[x][y][u]!=-oo) return res;
    res=max(res,a[x][y]+a[u][v]+tinhX(x,y+1,u));
    res=max(res,a[x][y]+a[u][v]+tinhX(x+1,y,u+1));
    res=max(res,a[x][y]+a[u][v]+tinhX(x,y+1,u+1));
    res=max(res,a[x][y]+a[u][v]+tinhX(x+1,y,u));
    return res;
}
ll tinhY(ll x,ll y,ll u,ll v)
{
    ll res=-oo;
    if(x==n && u==n && y==m && v==m) return 0;
    if(x==u && y==v) return -oo;
    if(x>n || y>m || u>n || v>m) return -oo;
    res=max(res,a[x][y]+a[u][v]+tinhY(x,y+1,u,v+1));
    res=max(res,a[x][y]+a[u][v]+tinhY(x+1,y,u+1,v));
    res=max(res,a[x][y]+a[u][v]+tinhY(x,y+1,u+1,v));
    res=max(res,a[x][y]+a[u][v]+tinhY(x+1,y,u,v+1));
    return res;
}
void xuli()
{
    cout << tinhX(1,2,2);
}
int main()
{
    FastIO
    readfile();
    xuli();
    return 0;
}
