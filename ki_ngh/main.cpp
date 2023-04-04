#include <bits/stdc++.h>
#define ll long long

using namespace std;
const int NM=1e6+5;
ll n,a[NM][3],s[NM][100];

void readfile()
{
    ll i,j;
    freopen("RELAX.INP","r",stdin);
    freopen("RELAX.OUT","w",stdout);
    cin >> n;
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=3;j++)
        {
            cin >> a[i][j];
        }
    }
}
void xuli()
{
    ll i,kqua;
    for(i=1;i<=3;i++) s[1][i]=a[1][i];
    for(i=1;i<=n;i++) s[i][0]=0;
    for(i=2;i<=n;i++)
    {
        s[i][1]=a[i][1]+max(s[i-1][2],s[i-1][3]);
        s[i][2]=a[i][2]+max(s[i-1][1],s[i-1][3]);
        s[i][3]=a[i][3]+max(s[i-1][1],s[i-1][2]);
    }
    kqua=max(s[n][1],s[n][2]);
    kqua=max(kqua,s[n][3]);
    cout << kqua;
}
int main()
{
    readfile();
    xuli();
    return 0;
}
