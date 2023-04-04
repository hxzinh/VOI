#include <bits/stdc++.h>
#define ll long long
#define oo 1e18
#define FastIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;
const int NM=1e3+10;
ll n,k;
ll a[NM],b[NM],s[NM][NM][7];

void readfile()
{
    freopen("KSEGAME.INP","r",stdin);
    freopen("KSEGAME.OUT","w",stdout);
    cin >> n >> k;
    for(int i=1;i<=n;i++) cin >> a[i];
    for(int i=1;i<=n;i++) cin >> b[i];
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
            for(int c=1;c<=n;c++) s[i][j][c]=-oo;
}
ll dp(ll x,ll y,ll z)
{
    if(x<=0 || y>n || z<=0) return 0;
    ll &res=s[x][y][z];
    if(res!=-oo) return s[x][y][z];
    res=max(res,a[x]*b[y]+dp(x+1,y+1,z-1));
    res=max(res,dp(x+1,y,z));
    res=max(res,dp(x,y+1,z));
    return res;
}
int main()
{
    FastIO
    readfile();
    ll tam=0;
    cout << tam,dp(1,1,k);
    return 0;
}
