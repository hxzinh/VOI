#include <bits/stdc++.h>
#define ll long long
#define oo 99999999999
#define FastIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;
const int NM=1e5+10;
ll n;
ll a[NM],s[NM][3];
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
    if(x<=0 || y>n || x>=n || x>=y) return 0;
    if(a[x]==-1) return dp(x-1,y);
    if(a[y]==-1) return dp(x,y+1);
    ll &res=s[y];
    if(s[y]!=-oo) return s[y];
    if(a[x]!=a[y]) return max({dp(x+1,y+1),dp(x-1,y-1)});
    a[x]=-1;
    a[y]++;
    res=max(res,1+dp(y,y+1));
    res=max(res,1+dp(x-1,y));
    res=max(res,1+dp(y+1,y+2));
    a[y]--;
    a[x]=a[y];
    res=max(res,dp(y+1,y+2));
    res=max(res,dp(x-2,y-2));
    res=max(res,dp(y,y+1));
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
}
int main()
{
    FastIO
    readfile();
    xuli();
    return 0;
}
