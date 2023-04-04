#include <bits/stdc++.h>
#define ll long long

using namespace std;
const int NM=1e6+5;
ll n,a[NM],s[NM],dem=0;
ll kqua=0;

void readfile()
{
    freopen("EPROTEST.INP","r",stdin);
    freopen("EPROTEST.OUT","w",stdout);
    cin >> n;
    s[0]=0;
    for(ll i=1;i<=n;i++)
    {
        cin >> a[i];
        s[i]=s[i-1]+a[i];
        if(a[i]<0){
            dem++;
        }
    }
}
void check(ll x,ll y)
{
    ll i,j;
    if(x>=y-1) return;
    for(i=x;i<=y;i++)
    {
        if(s[i]>=0&&s[y]-s[i]>=0)
        {
            kqua++;
            check(1,i);
        }
    }
}
void xuli()
{
    ll i;
    if(s[n]<0){
        cout << 0;
        return;
    }
    for(i=1;i<=n;i++)
    {
        if(s[i]>=0&&s[n]-s[i]>=0)
        {
            kqua++;
            check(1,i);
        }
    }
    cout << kqua;
}
int main()
{
    readfile();
    xuli();
    return 0;
}
