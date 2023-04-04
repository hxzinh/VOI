#include <bits/stdc++.h>
#define ll long long

using namespace std;
const int NM=1e6+5;
ll n,a[NM],s[NM],t;
bool cx;

void readfile()
{
    freopen("TONGS.INP","r",stdin);
    freopen("TONGS.OUT","w",stdout);
    cin >> n;
    for(ll i=1;i<=n;i++)
    {
        cin >> a[i];
    }
    cin >> t;
}
void timdoan()
{
    ll i,s=0,kqua,vt=0;
    for(i=1;i<=n;i++)
    {
        s+=a[i];
        while(s>t)
        {
            s=s-a[vt+1];
            vt++;
        }
        if(s==t)
        {
            kqua=max(i-vt,kqua);
            cx=true;
        }
    }
    if(cx==true) cout << kqua;
    else cout << "-1";
}
int main()
{
    readfile();
    timdoan();
    return 0;
}
