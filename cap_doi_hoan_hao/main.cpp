#include <bits/stdc++.h>
#define ll long long

using namespace std;
const int NM=1e6+5;
ll n,a[NM],s[NM];

void readfile()
{
    freopen("PERFECT.INP","r",stdin);
    freopen("PERFECT.OUT","w",stdout);
    cin >> n;
    for(ll i=1;i<=n;i++)
    {
        cin >> a[i];
    }
}
void xuli()
{
    ll i,kqua=1e9;
    sort(a+1,a+n+1);
    for(i=2;i<=n;i++)
    {
        s[i]=a[i]-a[i-1];
        kqua=min(kqua,s[i]);
    }
    cout << kqua;
}
int main()
{
    readfile();
    xuli();
    return 0;
}
