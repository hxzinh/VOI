#include <bits/stdc++.h>
#define ll long long
#define oo 99999999999
#define FastIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;
const int NM=1e6+5;
ll n,m;

void sang(ll x,ll y)
{
    vector <bool> prime(y-x+1,true);
    for(ll i=2;i*i<=y;i++)
    {
        for(ll j=max(i*i,(x+i-1)/i*i);j<=y;j+=i)
        {
            prime[j-x]=false;
        }
    }
    if(1>=x) prime[1-x]=false;
    for(ll i=x;i<=y;i++)
    {
        if(prime[i-x]) cout << i << " ";
    }
    cout << '\n';
}
void readfile()
{
    freopen("SPRIMECOUNT.INP","r",stdin);
    freopen("SPRIMECOUNT.OUT","w",stdout);
    cin >> n;
    for(int i=1;i<=n;i++)
    {
        ll u,v;
        cin >> u >> v;
        sang(u,v);
    }
}
int main()
{
    FastIO
    readfile();
    return 0;
}
