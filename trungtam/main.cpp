#include <bits/stdc++.h>
#define ll long long

using namespace std;
const int NM=1e6+5;
long long n,m,d[NM],w[NM],p[NM],s[NM];

void readfile()
{
    long long i;
    freopen("CENTER.INP","r",stdin);
    freopen("CENTER.OUT","w",stdout);
    cin >> n >> m;
    for (i=1;i<=n;i++)
    {
        cin >> d[i];
    }
    for (i=1;i<=n;i++)
    {
        cin >> w[i];
    }
    for (i=1;i<=m;i++)
    {
        cin >> p[i];
    }
}
void xuli()
{
    long long i,j;
    for (i=1;i<=m;i++)
    {
        for (j=1;j<=n;j++)
        {
            s[i]=s[i]+w[j]*abs(d[j]-p[i]);
        }
        cout << s[i] << '\n';
    }
}
int main()
{
    readfile();
    xuli();
    return 0;
}
