#include <bits/stdc++.h>
#define ll long long

using namespace std;
const int NM=1e6+5;
ll n,q,a[NM],k[NM],m[NM];

void readfile()
{
    ll i;
    freopen("MINPOS.INP","r",stdin);
    freopen("MINPOS.OUT","w",stdout);
    cin >> n;
    for(i=1;i<=n;i++)
    {
        cin >> a[i];
    }
    cin >> q;
    for(i=1;i<=q;i++)
    {
        cin >> k[i];
    }
}
ll truyvan(ll x)
{
    ll d=1,c=n,kqua=-1;
    while(d<=c)
    {
        ll g=(d+c)/2;
        if(m[g]<=x)
        {
            kqua=g;
            c=g-1;
        }else d=g+1;
    }
    return kqua;
}
void xuli()
{
    ll i;
    m[0]=1e9;
    for(i=1;i<=n;i++)
    {
        m[i]=min(m[i-1],a[i]);
    }
    for(i=1;i<=q;i++)
    {
        cout << truyvan(k[i]) << '\n';
    }
}
int main()
{
    readfile();
    xuli();
    return 0;
}
