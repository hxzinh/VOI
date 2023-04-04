#include <bits/stdc++.h>
#define ll long long

using namespace std;
const int NM=1e6+5;
ll n,k,a[NM],s[NM];

void readfile()
{
    ll i;
    freopen("FROG.INP","r",stdin);
    freopen("FROG.OUT","w",stdout);
    cin >> n >> k;
    for(i=1;i<=n;i++)
    {
        cin >> a[i];
        s[i]=1e10;
    }
}
void xuli()
{
    ll i,j,kqua=0,tam;
    s[1]=0;
    s[2]=abs(a[2]-a[1]);
    for(i=2;i<=k;i++)
    {
        s[i]=abs(a[i]-a[1]);
    }
    for(i=k+1;i<=n;i++)
    {
        for(j=i-k;j<=i-1;j++)
        {
            s[i]=min(s[i],s[j]+abs(a[j]-a[i]));
        }
    }
    cout << s[n];
}
int main()
{
    readfile();
    xuli();
    return 0;
}
