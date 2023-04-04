#include <bits/stdc++.h>
#define ll long long

using namespace std;
const int NM=1e6+5;
struct doan
{
    ll d,c,tong;
    bool cx;
};
doan a[NM];
ll dau,cuoi,n;

void readfile()
{
    ll i;
    freopen("WORKING.INP","r",stdin);
    freopen("WORKING.OUT","w",stdout);
    cin >> n;
    for(i=1;i<=n;i++)
    {
        cin >> a[i].d >> a[i].c;
        a[i].cx=true;
    }
}
void xuli()
{
    ll i;
    dau=a[1].d;
    cuoi=a[1].c;
    for(i=2;i<=n;i++)
    {
        if()
    }
}
int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
