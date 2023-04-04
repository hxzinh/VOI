#include <bits/stdc++.h>
#define ll long long
#define oo 99999999999
#define FastIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;
const int NM=1e3+10;
ll n;
ll a[NM][NM],s[NM][NM];

void readfile()
{
    freopen("CHIADAT.INP","r",stdin);
    freopen("CHIADAT.OUT","w",stdout);
    cin >> n;
    memset(s,0,sizeof(s));
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            cin >> a[i][j];
            s[i][j]=s[i-1][j]+s[i][j-1]-s[i-1][j-1]+a[i][j];
        }
    }
}
void xuli()
{
    ll res=oo;
    for(int i=1;i<n;i++)
    {
        for(int j=1;j<n;j++)
        {
            ll maxx=-oo,minn=oo;
            ll u=s[i][j];
            ll v=s[i][n]-s[i][j];
            ll x=s[n][j]-s[i][j];
            ll y=s[n][n]-u-v-x;
            maxx=max(maxx,max(u,max(v,max(x,y))));
            minn=min(minn,min(u,min(v,min(x,y))));
            res=min(res,maxx-minn);
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
