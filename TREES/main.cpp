#include <bits/stdc++.h>
#define ll long long
#define oo 99999999999
#define FastIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;
const int NM=1e5+10;
ll n;
///-------------------------------------------///
struct Data
{
    ll vt,w;
};
Data a[NM];

void readfile()
{
    freopen("TREES.INP","r",stdin);
    freopen("TREES.OUT","w",stdout);
    cin >> n;
    for(int i=1;i<=n;i++)
    {
        cin >> a[i].w;
        a[i].vt=i;
    }
}
bool cmp(Data x,Data y)
{
    return x.w<y.w;
}
void xuli()
{
    ll res=-oo,maxx=-oo;
    for(ll i=n;i>=1;i--)
    {
        if(a[i].w<=maxx) continue;
        else maxx=a[i].w;
        for(ll j=1;j<=i;j++)
        {
            if(a[i].w>a[j].w)
            {
                res=max(res,i-j);
                break;
            }
        }
    }
    if(res==-oo) cout << "-1";
    else cout << res;
}
int main()
{
    FastIO
    readfile();
    xuli();
    return 0;
}
