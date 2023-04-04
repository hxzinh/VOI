#include <bits/stdc++.h>

using namespace std;
const int NM=1e5+5;
int a[NM];
float n;

void readfile()
{
    int i;
    freopen("DAYSO.INP","r",stdin);
    freopen("DAYSO.OUT","w",stdout);
    cin >> n;
    for (i=1;i<=n;i++)
    {
        cin >> a[i];
    }
}
void dayso()
{
    int tam,b[NM],k,i,j,c[NM],dem;
    dem=0;
    while (n!=0)
    {
        tam=(1+n)/2;
        k=a[tam];
        dem++;
        b[dem]=k;
        for (i=tam+1,j=1;i<=n;i++,j++)
        {
            c[j]=a[i];
        }
        n=n-tam;
        for (i=1;i<=n;i++)
        {
            a[i]=c[i];
        }
    }
    for (i=1;i<=dem;i++)
    {
        cout << b[i] << "\t";
    }
}
int main()
{
    readfile();
    dayso();
    return 0;
}
