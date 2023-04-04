#include <bits/stdc++.h>
#define ll long long

using namespace std;
const int NM=1e6+5;
ll n;
ll a[NM],t[NM],s[NM];

void readfile()
{
    ll i;
    freopen("BETONG.INP","r",stdin);
    freopen("BETONG.OUT","w",stdout);
    cin >> n;
    for(i=1;i<=n;i++)
    {
        cin >> a[i];
        t[i]=a[i];
        s[i]=a[i];
    }
}
void xuli()
{
    ll i,j,dem,kqua=-99999999;
    bool ok;
    sort(t+1,t+1+n);
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=n;j++)
        {
            if(s[j]-t[i]<=0) a[j]=0;
            else s[j]=s[j]-t[i];
        }
        ok=false;
        dem=0;
        for(j=1;j<=n;j++)
        {
            if(ok==false && a[j]>0)
            {
                ok=true;
                dem++;
                continue;
            }
            if(a[j]<=0) ok=false;
        }
        kqua=max(kqua,dem);
    }
    cout << kqua;
}
int main()
{
    readfile();
    xuli();
    return 0;
}
