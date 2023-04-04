#include <bits/stdc++.h>
#define ll int
#define oo 9999999
#define FastIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;
const int NM=1e4+5;
ll n,k,p,q;
ll a[NM],F[NM][NM];

void readfile()
{
    freopen("TRANGTRAI.INP","r",stdin);
    freopen("TRANGTRAI.OUT","w",stdout);
    cin >> n >> k >> q >> p;
    for(int i=1;i<=n;i++)
    {
        cin >> a[i];
    }
    memset(F,-1,sizeof(F));
}
ll dp(ll x,ll last)
{
    if(x<=0 || last<=0 || x>n) return 0;
    ll &res=F[x][last];
    if(res!=-1) return F[x][last];
    res=max(res,dp(x-1,last));
    res=max(res,dp(x-k,last-1)+a[x]);
    return res;
}
ll trace(ll x,ll last)
{
    if(x<=0 &&last<=0) return oo;
    if(dp(x,last)==dp(x-k,last-1)+a[x]) return min(a[x],trace(x-k,last-1));
    return trace(x-1,last);
}
void xuli()
{
    if(q%p==0) cout << dp(n,q/p)*p;
    else cout << dp(n,q/p+1)*p-trace(n,q/p+1)*(p - q%p);
}
int main()
{
    FastIO
    readfile();
    xuli();
    return 0;
}
