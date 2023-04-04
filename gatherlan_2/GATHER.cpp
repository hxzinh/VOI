#include <bits/stdc++.h>

using namespace std;
const int NM=1e5+5;
int n,t,a[NM];

void readfile()
{
    int i,j,tam;
    freopen("GATHER.INP","r",stdin);
    freopen("GATHER.OUT","w",stdout);
    cin >> n;
    for (i=1;i<=n;i++)
    {
        cin >> a[i];
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
}
void gather()
{
    int t,i,s;
    s=0;
    t=0;
    if (n%2==0)
    {
        t=n/2;
    }
    else
    {
        t=n/2+1;
    }
    for (i=1;i<=n;i++)
    {
        s=s+abs(a[t]-a[i]);
    }
    cout << s;
}
int main()
{
    readfile();
    gather();
    return 0;
}
