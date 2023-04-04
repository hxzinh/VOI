#include <bits/stdc++.h>

using namespace std;
const int NM=1e7+5;
int n,a[NM];
bool cx[NM],so[NM];

void readfile()
{
    int i;
    freopen("DEMSO.INP","r",stdin);
    freopen("DEMSO.OUT","w",stdout);
    cin >> n;
    for (i=1;i<=n;i++)
    {
        cin >> a[i];
    }
    memset(cx,true,sizeof(cx));
    memset(so,true,sizeof(so));
}
void demso()
{
    int i,k,dem;
    dem=0;
    for (k=1;k<=n;k++)
    {
        for (i=1;i<=n;i++)
        {
            if (cx[i]==true)
            {
                if (a[i]==k)
                {
                    cx[i]=false;
                    so[k]=false;
                }
            }
        }
    }
    for (k=1;k<=n;k++)
    {
        if (so[k]==true)
        {
            dem++;
        }
    }
    cout << dem;
}
int main()
{
    readfile();
    demso();
    return 0;
}
