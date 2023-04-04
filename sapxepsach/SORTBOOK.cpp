#include <bits/stdc++.h>

using namespace std;
const int NM=1e6+5;
int n,k,a[NM],b[NM][2];

void readfile()
{
    int i,j;
    freopen("SORTBOOK.INP","r",stdin);
    freopen("SORTBOOK.OUT","w",stdout);
    cin >> n;
    cin >> k;
    for (i=1;i<=k;i++)
    {
        for (j=1;j<=2;j++)
        {
            cin >> b[i][j];
        }
    }
    memset(a,0,sizeof(a));
}
void sortbook()
{
    int i,j,tam,t;
    for (i=1;i<=k;i++)
    {
        for (t=b[i][1];t<=b[i][2];t++)
        {
            a[t]++;
        }
    }
    for (i=1;i<n;i++)
    {
        for (j=i+1;j<=n;j++)
        {
            if (a[i]>a[j])
            {
                tam=a[i];
                a[i]=a[j];
                a[j]=tam;
            }
        }
    }
    cout << a[(n/2)+1];
}
int main()
{
    readfile();
    sortbook();
    return 0;
}
