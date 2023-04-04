#include <bits/stdc++.h>
#define ll unsigned long long
#define oo 1e18
#define FastIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;
const int NM=1e3+10;
ll n,k;
ll s[NM][NM],a[NM][NM],h[NM][NM];

void readfile()
{
    freopen("CATBANH.INP","r",stdin);
    freopen("CATBANH.OUT","w",stdout);
    cin >> n >> k;
    for(int i=1;i<=n;i++) s[i][0]=s[0][i]=0;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            cin >> a[i][j];
        }
    }
    for(int i=1;i<=n;i++) h[i][0]=h[0][i]=0;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
            h[i][j]=h[i][j-1]+a[i][j];
}
ll tinh(ll x,ll y)
{
    ll tam=0;
    for(int i=0;i<=k;i++)
    {
        tam+=h[x-i][y+k-i]-h[x-i][y-1];
    }
    return tam;
}
void xuli()
{
    ll res=-oo;
    for(int i=k+1;i<=n;i++)
    {
        for(int j=1;j<=n-k;j++)
        {
            res=max(res,tinh(i,j));
        }
    }
    cout << res;
}
int main()
{
    FastIO
    readfile();
    xuli();
    return 0;
}
