#include <bits/stdc++.h>

using namespace std;
const long long NM=1e7+5;
unsigned int n;
long long a[NM];
bool cx[NM];

void readfile()
{
    int i;
    freopen("KMIN.INP","r",stdin);
    freopen("KMIN.OUT","w",stdout);
    cin >> n;
    for (i=1;i<=n;i++)
    {
        cin >> a[i];
    }
    memset(cx,true,sizeof(cx));
}
void kmin()
{
    int i,j;
    for (i=1;i<=n;i++)
    {
        for (j=1;j<=n;j++)
        {
            if (i==a[j])
            {
                cx[i]=false;
            }
        }
    }
    for (i=1;i<=n;i++)
    {
        if (cx[i]==true)
        {
            cout << i;
            break;
        }
    }
}
int main()
{
    readfile();
    kmin();
    return 0;
}
