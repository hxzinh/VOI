#include <bits/stdc++.h>
#define ll long long
#define oo 99999999999
#define FastIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;
const int NM=1e6+5;
ll n,m;
ll price[NM];

void progress(ll x,ll y,ll cost)
{

}
void readfile()
{
    freopen("MUASAM.INP","r",stdin);
    freopen("MUASAM.OUT","w",stdout);
    cin >> n >> m;
    for(int i=1;i<=n;i++)
    {
        cin >> price[i];
    }
    for(int i=1;i<=m;i++)
    {
        ll u,v,w;
        cin >> w >> u >> v;
    }
}
int main()
{
    FastIO
    cout << "Hello world!" << endl;
    return 0;
}
