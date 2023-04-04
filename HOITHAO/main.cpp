#include <bits/stdc++.h>
#define ll long long
#define FastIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define oo 1e18

using namespace std;
const int NM=1e5+10;
ll n,m;
ll a[NM],b[NM],s[NM];

void readfile()
{
    freopen("OLYMPIC.INP","r",stdin);
    freopen("OLYMPIC.OUT","w",stdout);
    cin >> n;
    for(int i=1;i<=n;i++)
    {
        cin >> a[i];
        s[i]=s[i-1]+a[i];
    }
    cin >> m;
    for(int i=1;i<=m;i++)
    {
        cin >> b[i];
    }
}
ll check(ll x)
{
    ll d=1,c=n,g,res=-1;
    while(d<=c)
    {
        g=(d+c)/2;
        if(s[g]>=x)
        {
            res=g;
            c=g-1;
        }
        else d=g+1;
    }
    return res;
}
void xuli()
{
    for(int i=1;i<=m;i++) cout << check(b[i]) << " ";
}
int main()
{
    FastIO
    readfile();
    xuli();
    return 0;
}
