#include <bits/stdc++.h>

using namespace std;
const int NM=1e5+5;
long long a[NM],b[NM];
int n,m,dem;

void readfile()
{
    int i;
    freopen("SEARCH.INP","r",stdin);
    freopen("SEARCH.OUT","w",stdout);
    cin >> n;
    cin >> m;
    for (i=0;i<n;i++)
    {
        cin >> a[i];
    }
    for (i=0;i<m;i++)
    {
        cin >> b[i];
    }
}
void sapxep(long long k[NM],int d,int c)
{
    int i,j,tam,cx;
    if (d>=c)
        return;
    i=d;
    j=c;
    tam=k[(d+c)/2];
    do
    {
        while (k[i]<tam)
            i++;
        while (k[j]>tam)
            j--;
        if (i<=j)
        {
            cx=a[i];
            a[i]=a[j];
            a[j]=cx;
            i++;
            j--;
        }
    }
    while (i<j);
    sapxep(k,d,j);
    sapxep(k,i,c);
}
void timkiem(int x)
{
    int sd,sc,tam;
    sd=0;
    sc=n-1;
    while (sd<=sc)
    {
        tam=(sd+sc)/2;
        if (x==a[tam])
        {
            dem++;
            break;
        }
        else
        {
            if (a[tam]>x)
            {
                sc=tam-1;
            }
            else
                sd=tam+1;
        }
    }
}
int main()
{
    int i;
    readfile();
    sapxep(a,0,n-1);
    dem=0;
    for (i=0;i<m;i++)
    {
        timkiem(b[i]);
    }
    cout << dem;
    return 0;
}
