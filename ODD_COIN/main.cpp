#include <bits/stdc++.h>
#define ll long long
#define oo 1e18
#define FastIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;
const int NM=1e3+5;
ll n;
///ll c[17]={0,1,3,5,10,30,50,100,300,500,1000,3000,5000,10000,30000,50000};
vector <ll> c;

ll dp(ll t,ll x)
{
    ll res=oo;
    if(x==0) return 0;
    if(t<0) return oo;
    ll k=c[t];
    res=min(res,x/c[t]+dp(t-1,x%c[t]));
    res=min(res,dp(t-1,x));
    return res;
}

void readfile()
{
    freopen("ODDCOIN.INP","r",stdin);
    freopen("ODDCOIN.OUT","w",stdout);
    cin >> n;
    for(int i=1;i<=n;i++)
    {
        ll u,v;
        c={1,3,5,10,30,50,100,300,500,1000,3000,5000,10000,30000,50000};
        cin >> u >> v;
        c.push_back(u);
        sort(c.begin(),c.end());
        cout << dp(15,v) << '\n';
       /// for(int j=0;j<16;j++) cout << c[j] << " ";
        ///cout << '\n';
        c.clear();
    }
}
int main()
{
    FastIO
    readfile();
    return 0;
}
