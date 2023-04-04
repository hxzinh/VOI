#include <bits/stdc++.h>
#define ll long long
#define oo 1e18
#define FastIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;
const int NM=1e6+10;
ll n,a[NM],s[NM][2],t[NM];
bool cx[NM],ok[NM];

void readfile()
{
    freopen("PHITIEU.INP","r",stdin);
    freopen("PHITIEU.OUT","w",stdout);
    cin >> n;
    for(int i=1;i<=n;i++)
    {
        cin >> a[i];
        s[i][0]=-oo;
        s[i][1]=-oo;
    }
    memset(cx,true,sizeof(cx));
    memset(ok,true,sizeof(ok));
    memset(t,-1,sizeof(t));
}
ll dp(ll x,ll y)
{
    if(x<=0 || x>n) return 0;
    if(!cx[x-1] && !cx[x+1]) return 0;
    if(!cx[x-1] && !cx[x-2]) return 0;
    if(!cx[x+1] && !cx[x+2]) return 0;
    ///ll res=-oo;
    ll &res=s[x][y];
    if(res!=-oo) return s[x][y];
    cx[x]=false;
    ///ok[x]=false;
    if(y==0) res=max(res,a[x]+dp(x+1,1));
    res=max(res,a[x]+dp(x+2,0));
    cx[x]=true;
    ll tam=res;
    res=max(res,dp(x+1,0));
    if(res==tam)
    {
        ok[x+1]=false;
    }
    else ok[x]=false;
    return res;
}
int main()
{
    ll dem=0;
    FastIO
    readfile();
    ll res=dp(1,0);
    for(int i=1;i<=n;i++)
        if(!ok[i]) dem++;
    cout << dem << " " << res << '\n';
    for(int i=n;i>=1;i--) if(!ok[i]) cout << i << '\n';
    return 0;
}
