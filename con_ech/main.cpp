#include <bits/stdc++.h>
#define ll long long

using namespace std;
const int NM=1e6+5;
ll n,a[NM],s[NM],kqua=0;

void readfile()
{
    ll i;
    freopen("FROG.INP","r",stdin);
    freopen("FROG.OUT","w",stdout);
    cin >> n;
    for(i=1;i<=n;i++)
    {
        cin >> a[i];
    }
}
void xuli()
{
    ll i;
    s[1]=0;
    s[2]=abs(a[2]-a[1]);
    for(i=3;i<=n;i++)
    {
        s[i]=min(s[i-1]+abs(a[i]-a[i-1]),s[i-2]+abs(a[i]-a[i-2]));
    }
    cout << s[n];
}
int main()
{
    readfile();
    xuli();
    return 0;
}
