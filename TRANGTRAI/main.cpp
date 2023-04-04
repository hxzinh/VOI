#include <bits/stdc++.h>
#define ll long long
#define FastIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define oo 1e18

using namespace std;
const int NM=1e4+5;
ll n,p,k,q;
ll a[NM],s[10005][5005];

void readfile()
{
    freopen("TRANGTRAI.INP","r",stdin);
    freopen("TRANGTRAI.OUT","w",stdout);
    cin >> n >> k >> q >> p;
    for(int i=1;i<=n;i++)
    {
        cin >> a[i];
    }
    for(int i=1;i<=n;i++)
        for(int j=1;j<=q;j++) s[i][j]=-oo;
}
ll dp(ll x,ll y)
{
    if(y<=0 || x>n) return 0;
    ll &res=s[x][y];
    if(res!=-oo) return s[x][y];
    for(int i=1;i<=min(y,p);i++)
    {
        res=max(res,a[x]*i+dp(x+k,y-i));
    }
    res=max(res,dp(x+1,y));
    return res;
}
void xuli()
{
    ll ans=-oo;
    for(int i=1;i<=n;i++) ans=max(ans,dp(i,q));
    cout << ans;
}
int main()
{
    FastIO
    readfile();
    xuli();
    return 0;
}
