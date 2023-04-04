#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int NM=1e7+5;
ll n;
bool cx[NM];

void readfile()
{
    freopen("PRIMEDIV.INP","r",stdin);
    freopen("PRIMEDIV.OUT","w",stdout);
    cin >> n;
    memset(cx,true,sizeof(cx));
}
void xuli()
{
    ll i,j;
    bool t;
    t=true;
    for (i=2;i<=sqrt(n);i++)
    {
        if (n%i==0)
        {
            cout << i << " ";
            while (n%i==0) n=n/i;
        }
    }
    if (n>1) cout << n;
}
int main()
{
    readfile();
    xuli();
    return 0;
}
