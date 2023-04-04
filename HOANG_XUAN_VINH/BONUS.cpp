#include <bits/stdc++.h>
#define ll long long

using namespace std;
const int NM=1e4+5;
ll n,m,q,u,v,x,y;
ll s[NM],k[NM],a[NM][NM];

void xuli()
{
    ll kqua=0;
    for(ll i=u;i<=x;i++)
    {
        for(ll j=v;j<=y;j++)
        {
            kqua+=a[i][j];
        }
    }
    cout << kqua << '\n';
}
void readfile()
{
    freopen("BONUS.INP","r",stdin);
    freopen("BONUS.OUT","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> m >> n >> q;
    for(ll i=1;i<=m;i++)
    {
        for(ll j=1;j<=n;j++)
        {
            cin >> a[i][j];
        }
    }
    for(ll i=1;i<=q;i++)
    {
        cin >> u >> v >> x >> y;
        xuli();
    }
}
int main()
{
    readfile();
    return 0;
}
