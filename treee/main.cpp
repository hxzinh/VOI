#include <bits/stdc++.h>

using namespace std;
const long long NM=1e7+5;
long long n,k,a[NM],b[NM],s[NM],t[NM];
bool cx[NM];

void readfile()
{
    long long i;
    freopen("TREE.INP","r",stdin);
    freopen("TREE.OUT","w",stdout);
    cin >> n;
    cin >> k;
    memset(t,0,sizeof(t));
    for (i=1;i<=n;i++)
    {
        cin >> a[i];
        cin >> b[i];
        t[b[i]]=a[i];
    }
    memset(cx,true,sizeof(cx));
}
void sapxep(long long d,long long c)
{
    if (d<=c) return;
    long long tam,i,j;
    tam=b[(d+c)/2];
    i=d;
    j=c;
    while (i<j)
    {
        while (b[i]<tam) i++;
        while (b[j]>tam) j--;
        if (i<=j)
        {
            swap(a[i],a[j]);
            swap(b[i],b[j]);
            i++;
            j--;
        }
    }
    sapxep(d,j);
    sapxep(i,c);
}
void xuli()
{
    long long sd,sc,dem,maxx,tam,i;
    dem=0;
    sd=1;
    sc=1+(k*2);
    while (sc<=b[n])
    {
        dem++;
        tam=(sd+sc)/2;
        for (i=sd;i<=sc;i++)
        {
            s[dem]=s[dem]+t[i];
        }
        sd++;
        sc++;
    }
    maxx=s[1];
    for (i=2;i<=dem;i++)
    {
        if (s[i]>maxx)
        {
            maxx=s[i];
        }
    }
    cout << maxx;
}
int main()
{

    readfile();
    sapxep(1,n);
    for (int i=1;i<=n;i++)
    {
        cout << a[i];
        cout << " " << b[i];
        cout << endl;
    }
    ///xuli();
    return 0;
}
