#include <bits/stdc++.h>
#define ll long long
#define oo 99999999999
#define FastIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;
const int NM=1e3+10;
ll n;
struct Data
{
    ll x,y;
};
Data d[NM],t[NM];

void readfile()
{
    freopen("PIN.INP","r",stdin);
    freopen("PIN.OUT","w",stdout);
    cin >> n;
    for(int i=1;i<=n;i++)
    {
        cin >> d[i].x >> d[i].y >> t[i].x >> t[i].y;
    }
}
void xuli()
{
    ll dem=0;
    for(int i=1;i<n;i++)
    {
        for(int j=i+1;j<=n;j++)
        {
            if(d[i].x<t[j].x && d[j].x<t[i].x && d[i].y<t[j].y && d[j].y<t[i].y) dem++;
        }
    }
    cout << dem;
}
int main()
{
    FastIO
    readfile();
    xuli();
    return 0;
}
