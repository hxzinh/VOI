#include <bits/stdc++.h>

using namespace std;
const int NM=1e5+5;
int a[NM],n;

void readfile()
{
    int i;
    freopen("SLN.INP","r",stdin);
    freopen("SLN.OUT","w",stdout);
    cin >> n;
    for (i=1;i<=n;i++)
    {
        cin >> a[i];
    }
}
void solonnhat()
{
    int i,a[NM];
    for (i=1;i<=n;i++)
    {
        a[0]=0;
        a[1]=1;
        a[2*i]=a[i];
        a[2*i+1]=a[i]+a[i+1];

    }
}
int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
