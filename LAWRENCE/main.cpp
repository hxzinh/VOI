#include <bits/stdc++.h>
#define ll long long
#define oo 99999999999
#define FastIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;
const ll NM=1e3+10;
ll n,m;
ll a[NM],s[NM][NM],t[NM],ans=0,d[500][500],luu[NM];
bool cx[NM];

void readfile()
{
    freopen("LAWRENCE.INP","r",stdin);
    freopen("LAWRENCE.OUT","w",stdout);
    cin >> n >> m;
    t[0]=0;
    for(int i=1;i<=n;i++)
    {
        cin >> a[i];
        t[i]=t[i-1]+a[i];
    }
 /**   for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            if(j>=i) s[i][j]=a[i]*(t[j]-t[i]);
            else s[i][j]=a[i]*(t[n]-t[i]);
            if(s[i][j]<0) s[i][j]=0;
        }
        ans+=s[i][n];
    } **/
    for(int i=n;i>=1;i--)
    {
        for(int j=i-1;j>=1;j--)
        {
            s[j][i]=s[j+1][i]+a[j]*(t[i]-t[j]);
        }
    }
    memset(luu,0,sizeof(luu));
    for(int i=n;i>=1;i--)
        luu[i]=luu[i+1]+a[i]*(t[n]-t[i]);
    for(int i=0;i<=n;i++)
        for(int j=0;j<=n;j++) d[i][j]=s[i][n];
    memset(cx,true,sizeof(cx));
    ///cout << ans;
}
ll dp(ll x,ll t)
{
    if(n-x<=t) return 0;
    ll &res=d[x][t];
    if(res!=s[x][n]) return res;
    if(t==0)
    {
        res=s[x][n];
        return res;
    }
    for(int i=x;i<n;i++)
    {
        res=min(res,s[x][i]+dp(i+1,t-1));
    }
    return res;
}
void xuli()
{
    ll ans=dp(1,m);
    if(ans!=oo) cout << dp(1,m) << '\n';
    else cout << "0";
}
int main()
{
    FastIO
    readfile();
    xuli();
    return 0;
}
