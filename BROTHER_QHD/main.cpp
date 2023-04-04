#include <bits/stdc++.h>
#define ll int
#define oo 99999999999
#define FastIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;
ll n,m;
ll clx[]={-1,1,0,0};
ll cly[]={0,0,-1,1};
ll a[202][202],s[404][202][202];

void readfile()
{
    freopen("BROTHER.INP","r",stdin);
    freopen("BROTHER.OUT","w",stdout);
    cin >> n >> m;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            cin >> a[i][j];
        }
    }
    for(int i=0;i<=n+m;i++)
        for(int j=0;j<=n;j++)
        for(int z=0;z<=m;z++)
            s[i][j][z]=-1e6;
}
void xuli()
{
    s[2][1][1]=0;
    for(ll k=3;k<n+m;k++)
    {
        for(ll i=max(1,k-m);i<=min(n,k-1);i++)
        {
            for(ll j=i+1;j<=min(n,k-1);j++)
            {
                s[k][i][j]=a[i][k-i]+a[j][k-j]+max(s[k-1][i-1][j-1],max(s[k-1][i-1][j],max(s[k-1][i][j-1],s[k-1][i][j])));
            }
        }
    }
    cout << s[m+n-1][n-1][n];
}
int main()
{
    FastIO
    readfile();
    xuli();
    return 0;
}
