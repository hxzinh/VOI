#include <bits/stdc++.h>
#define ll long long

using namespace std;
const int NM=1e6+5;
int n;
ll a[NM],s[NM],k[NM];

void readfile()
{
    freopen("HINHCN.INP","r",stdin);
    freopen("HINHCN.OUT","w",stdout);
    //ios_base::sync_with_stdio(0);
    //cin.tie(0);
    cin >> n;
    for(int i=1;i<=n;i++)
    {
        cin >> a[i];
        s[i]=s[i-1]+a[i];
    }
}
void xuli()
{
    ll kqua=-99999999;
    for(ll k=2;k<=n/2;k++)
    {
        kqua=max(kqua,s[2*k]);
        for(ll i=2*k+1;i<=n;i++)  kqua=max(kqua,s[i]-s[i-2*k]);
    }
    cout << kqua;
}
int main()
{
    readfile();
    xuli();
    return 0;
}
