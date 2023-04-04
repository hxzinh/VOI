#include <bits/stdc++.h>
#define ll long long
#define oo 99999999999
#define FastIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;
const int NM=1e6+10;
ll n,a[NM];
bool cx[NM];

void readfile()
{
    freopen("NUMBER.INP","r",stdin);
    freopen("NUMBER.OUT","w",stdout);
    cin >> n;
    memset(cx,true,sizeof(cx));
}
void xuli()
{
    ll dem=0;
    cx[1]=false;
    for(int i=2;i<=10000;i++)
    {
        if(cx[i]==true)
        {
            for(int j=i*i;j<=100000;j+=i) cx[j]=false;
        }
    }
    for(int i=2;i<=10000;i++)
    {
        if(cx[i])
            for(int j=i*i;j<=100000;j=j*i) cx[j]=true;
    }
    for(int i=1;i<=n;i++)
    {
        if(cx[i])
            if(i>10000) dem++;
            else dem+=2;
    }
    cout << dem;
}
int main()
{
    FastIO
    readfile();
    xuli();
    return 0;
}
