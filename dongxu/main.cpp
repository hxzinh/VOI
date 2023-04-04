#include <bits/stdc++.h>

using namespace std;
const int NM=1e5+5;
int n,m,a[NM],b[NM],hieu[NM];

void readfile()
{
    int i;
    freopen("COINS.INP","r",stdin);
    freopen("COINS.OUT","w",stdout);
    cin >> n;
    cin >> m;
    for (i=0;i<n;i++)
    {
        cin >> a[i];
    }
    for (i=0;i<n;i++)
    {
        cin >> b[i];
        hieu[i]=b[i]-a[i];
    }
}
void sapxep(int e[NM],int k[NM],int a,int b)
{
    int i,j,tam,cx;
    i=a;
    j=b;
    tam=k[(a+b)/2];
    if (a>=b)
        return;
    while (i<j)
    {
        while (k[i]<tam)
            i++;
        while (k[j]>tam)
            j--;
        if (i<=j)
        {
            cx=k[i];
            k[i]=k[j];
            k[j]=cx;
            cx=e[i];
            e[i]=e[j];
            e[j]=cx;
            i++;
            j--;
        }
    }
    sapxep(e,k,a,j);
    sapxep(e,k,i,b);
}
void coin()
{
    int i;
    for (i=0;i<n;i++)
    {
        if (m>=hieu[i])
            m=m-hieu[i]+b[i];
        else
            break;
    }
    cout << m;
}
int main()
{
    readfile();
    sapxep(b,hieu,0,n-1);
    coin();
    return 0;
}
