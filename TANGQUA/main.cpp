#include <bits/stdc++.h>
#define ll long long
#define oo 99999999999
#define FastIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;
const int NM=2*2e3+50;
ll n,d;
ll a[NM],s[NM][NM];

void readfile()
{
    freopen("TANGQUA.INP","r",stdin);
    freopen("TANGQUA.OUT","w",stdout);
    cin >> n >> d;
    for(int i=1;i<=2*n;i++)
    {
        cin >> a[i];
    }
    for(int i=0;i<=2*n;i++)
        for(int j=0;j<=2*n;j++) s[i][j]=-oo;
}
ll dp(ll l,ll r)
{
    if(l==r || l>r) return 0;
    ll &res=s[l][r];
    if(res!=-oo) return s[l][r];
    if(abs(a[l]-a[r])<=d) res=max(res,1+dp(l+1,r-1));
    res=max(res,dp(l,r-1));
    res=max(res,dp(l+1,r));
    return res;
}
int main()
{
    FastIO
    readfile();
    cout << dp(1,2*n);
    return 0;
}
