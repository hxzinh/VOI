#include <bits/stdc++.h>
#define ll long long
#define oo 99999999999
#define FastIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;
ll n,k,t=240;

void readfile()
{
    ll dem=0;
    freopen("NEWYEAR.INP","r",stdin);
    freopen("NEWYEAR.OUT","w",stdout);
    cin >> n >> k;
    t=t-k;
    for(int i=1;i<=n;i++)
    {
        if(t<5*i) break;
        dem++;
        t=t-5*i;
    }
    cout << dem;
}
int main()
{
    FastIO
    readfile();
    return 0;
}
