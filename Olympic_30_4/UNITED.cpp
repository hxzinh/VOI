#include <bits/stdc++.h>
#define ll long long
#define oo 99999999999
#define FastIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;
const int NM=1e5+10;
ll n;
ll a[NM],s[NM];
bool cx[NM];

void readfile()
{
    freopen("UNITED.INP","r",stdin);
    freopen("UNITED.OUT","w",stdout);
    cin >> n;
    for(int i=1;i<=n;i++)
    {
        cin >> a[i];
    }
    ///memset(cx,true,sizeof(cx));
    for(int i=1;i<=n;i++) s[i]=-oo;
}
ll dp(ll x,ll y)
{
    if(x<=0 || y>n) return 0;
    if(x>=y) return 0;
    if(a[x]==0) return dp(x-1,y);
    if(a[y]==0) return dp(y,y+1);
    if(a[x]!=a[y]) return 0;
    ll &res=s[x];
    if(s[x]!=-oo) return s[x];
    a[x]=0;
    a[y]++;
    res=max(res,1+dp(y,y+1));
    res=max(res,1+dp(x-1,y));
    res=max(res,1+dp(y+1,y+2));
    res=max(res,1+dp(x-2,y-2));
    a[y]--;
    a[x]=a[y];
    return res;
}
void xuli()
{
    ll ans=-oo;
    for(int i=1;i<n;i++)
    {
        ans=max(ans,dp(i,i+1));
    }
    cout << n-ans << '\n';
   /// for(int i=1;i<=n;i++)
}
int main()
{
    FastIO
    readfile();
    xuli();
    return 0;
}
