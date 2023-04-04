#include <bits/stdc++.h>
#define ll long long
#define oo 99999999999
#define FastIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;
const int NM=1e3+10;
ll n,m;
ll a[NM][NM],s[100][100][100];

void readfile()
{
    freopen("INVEST.INP","r",stdin);
    freopen("INVEST.OUT","w",stdout);
    cin >> m >> n;
    for(int i=1;i<=m;i++)
    {
        for(int j=1;j<=n;j++)
        {
            cin >> a[j][i];

        }
    }
    for(int i=0;i<=n;i++)
    for(int j=0;j<=m;j++)
        for(int z=0;z<=m;z++)
        s[i][j][z]=-oo;
}
ll dp(ll x,ll y,ll t)
{
    ///if(t<=0) return 0;
    if(x>n || y>m || t<y) return 0;
    ll &res=s[x][y][t];
    if(res!=-oo) return s[x][y][t];
    ll tam=a[x][y];
    res=max(res,a[x][y]+dp(x+1,1,t-y));
    res=max(res,dp(x,y+1,t));
    res=max(res,dp(x+1,1,t));
    return res;
}
void xuli()
{
    cout << dp(1,1,m);
}
int main()
{
    FastIO
    readfile();
    xuli();
    return 0;
}
