#include <bits/stdc++.h>
#define ll long long

using namespace std;
const int NM=1e7+5;
ll n,m,a[NM],s[NM],t[NM];

void readfile()
{
    freopen("TANK.INP","r",stdin);
    freopen("TANK.OUT","w",stdout);
    cin >> m >> n;
    s[0]=0;
    for (ll i=1;i<=n;i++)
    {
        cin >> a[i];
        s[i]=s[i-1]+a[i];
    }
}
bool kiemtra(ll x)
{
    ll i;
    for (i=x;i<=n;i++)
    {
        t[i]=s[i]-s[i-x];
        if (t[i]<m) return false;
    }
    return true;
}
void xuli()
{
    ll d,c,tam,g;
    d=1;
    c=n;
    while (d<=c)
    {
        ///g=(d+c)/2;
        if ((d+c)%2==0)
            g=(d+c)/2;
        else g=(d+c+1)/2;
        if (kiemtra(g)==true)
        {
            tam=g;
            c=g-1;
        }
        else d=g+1;
    }
    cout << tam;
}
int main()
{
    readfile();
    xuli();
    return 0;
}
