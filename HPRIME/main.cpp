#include <bits/stdc++.h>
#define ll long long
#define oo 99999999999
#define FastIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;
const int NM=1e6+10;
ll n,h;
bool cx[NM];

void readfile()
{
    freopen("HPRIME.INP","r",stdin);
    freopen("HPRIME.OUT","w",stdout);
    cin >> n >> h;
    memset(cx,true,sizeof(cx));
}
bool check(ll x)
{
    ll res=0;
    while(x!=0)
    {
        res+=x%10;
        x=x/10;
    }
    if(res==h) return true;
    else return false;
}
void xuli()
{
    cx[1]=false;
    for(int i=2;i<=4e4;i++)
    {
        if(cx[i])
            for(int j=i*i;j<=1e6;j+=i) cx[j]=false;
    }
    for(int i=1;i<=n;i++)
    {
        if(check(i) && cx[i]) cout << i << '\n';
    }
}
int main()
{
    FastIO
    readfile();
    xuli();
    return 0;
}
