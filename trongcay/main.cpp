#include <bits/stdc++.h>

using namespace std;
const long long NM=1e8+5;
long long n,k,a,b,c[NM],sln;

void readfile()
{
    long long i;
    freopen("TREE.INP","r",stdin);
    freopen("TREE.OUT","w",stdout);
    cin >> n;
    cin >> k;
    sln=0;
    memset(c,0,sizeof(c));
    for (i=1;i<=n;i++)
    {
        cin >> a;
        cin >> b;
        c[b]=a;
        if (b>sln)
            sln=b;
    }
}
void trungvi()
{
    long long i,s,maxs;
    s=0;
    for (i=1;i<=(2*k)+1;i++)
    {
        s=s+c[i];
    }
    maxs=s;
    for (i=2;i<=sln-(2*k);i++)
    {
        s=s-c[i-1]+c[(2*k)+i];
        if (s>maxs)
        {
            maxs=s;
        }
    }
    cout << maxs;
}
int main()
{
    readfile();
    trungvi();
    return 0;
}
