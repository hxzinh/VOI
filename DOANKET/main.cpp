#include <bits/stdc++.h>
#define ll long long
#define oo 99999999999
#define FastIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;
const int NM=1e6+5;
ll n,a[NM],s[NM];
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
    memset(cx,true,sizeof(cx));
}
ll dp(ll x,ll y)
{
    if(x<=0 || y>n || x>n || y<=0) return 0;
    if(!cx[x]) return dp(x-1,y);
    if(a[x]!=a[y]) return 0;
    ll res=-oo;
    a[y]++;
    cx[x]=false;
    res=max(res,1+dp(y,y+1));
    res=max(res,1+dp(y+1,y+2));
    res=max(res,1+dp(x-3,y-2));
    res=max(res,1+dp(x-1,y));
    a[y]--;
    return res;
}
void xuli()
{
    ll ans=-oo;
    for(int i=1;i<=n;i++) s[i]=oo;
    for(int i=1;i<=n;i++)
    {
        ans=max(ans,dp(i,i+1));
        ans=max(ans,dp(i-1,i));
    }
    cout << ans;
}
int main()
{
    FastIO
    readfile();
    xuli();
    return 0;
}
