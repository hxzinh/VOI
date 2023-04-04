#include <bits/stdc++.h>

using namespace std;
const int NM=1e5+5;
int n,m,a[NM],b[NM];

void readfile()
{
    freopen("SEARCH.INP","r",stdin);
    freopen("SEARCH.OUT","w",stdout);
    cin >> n;
    cin >> m;
    for (i=1;i<=n;i++)
    {
        cin >> a[i];
    }
    for (j=1;j<=m;j++)
    {
        cin >> b[j];
    }
}

void chat(int k)
{
    sd=1;
    sc=n;
    tb=(sd+sc)/2;
    if (k==a[tb])
    {
        dem++;
    }
    else
    {
        if (k>a[tb])
        {

        }
    }
}
void timkiem()
{
    for (i=1;i<=m;i++)
    {
        sd=1;
        sc=n;
        if (a[(sd+sc)/2]==b[i])
        {
            dem++;
        }

    }
}
int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
