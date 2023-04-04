#include <bits/stdc++.h>

using namespace std;
const int NM=1e6+5;
int a[NM],x,n;
bool cx[NM];

void readfile()
{
    int i;
    freopen("GHEPCAP.INP","r",stdin);
    freopen("GHEPCAP.OUT","w",stdout);
    cin >> n;
    cin >> x;
    for (i=1;i<=n;i++)
    {
        cin >> a[i];
    }
    memset(cx,true,sizeof(cx));
}
void ghep()
{
    int i,j,dem;
    dem=0;
    for (i=1;i<n;i++)
    {
        if (cx[i]==true)
        {
            for (j=i+1;j<=n;j++)
            {
               if (a[i]+a[j]==x)
               {
                   dem=dem+1;
                   cx[j]=false;
               }
            }
        }
    }
    cout << dem;
}
int main()
{
    readfile();
    ghep();
    return 0;
}
