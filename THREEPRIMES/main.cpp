#include <bits/stdc++.h>
#define ll long long
#define oo 99999999999
#define FastIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;
const int NM=1e7+10;
ll k;
bool cx[NM];

void readfile()
{
    freopen("THREEPRIMES.INP","r",stdin);
    freopen("THREEPRIMES.OUT","w",stdout);
    cin >> k;
    memset(cx,true,sizeof(cx));
}
void xuli()
{
    ll dem=0;
    cx[1]=false;
    for(int i=2;i<=1e4;i++)
    {
        if(cx[i])
            for(int j=i*i;j<=1e7;j+=i) cx[j]=false;
    }
    for(int i=2;i<=1e8;i++)
    {
        if(cx[i] && cx[2*i-1]) dem++;
        if(dem==k) {cout << i << " " << i << " " << 2*i-1; break;}
        if(cx[i] && cx[2*i+1]) dem++;
        if(dem==k) {cout << i << " " << i << " " << 2*i+1; break;}
    }
}
int main()
{
    FastIO
    readfile();
    xuli();
    return 0;
}
