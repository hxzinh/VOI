#include <bits/stdc++.h>

using namespace std;
const int NM=1e5+5;
int n,s[NM];

void readfile()
{
    freopen("BEAUTY.INP","r",stdin);
    freopen("BEAUTY.OUT","w",stdout);
    cin >> n;
}
void beauty()
{
    int dem,k,tam,s,i;
    dem=0;
    k=0;
    while (dem<n)
    {
        k++;
        tam=k;
        i=0;
        s=0;
        if (tam<10)
        {
            dem++;
            continue;
        }
        else
        {
            while (tam!=0)
            {
                if (tam<10)
                {
                    s=s+tam;
                }
                else
                {
                    s=s+(tam%10);
                }
                i++;
                tam=tam/10;
            }
        }
        if (s%i==0)
        {
            dem++;
        }
    }
    cout << k;
}
int main()
{
    readfile();
    beauty();
    return 0;
}
