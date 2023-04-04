#include <bits/stdc++.h>
#define ll long long

using namespace std;
const int NM=1e6+5;
ll n,t,a[NM],s[NM],k[NM],dem=0;
bool cx[NM];

void readfile()
{
    ll i;
    freopen("CAKE.INP","r",stdin);
    freopen("CAKE.OUT","w",stdout);
    cin >> n >> t;
    for(i=1;i<=n;i++)
    {
        cin >> a[i]>> k[i];
    }
    memset(cx,true,sizeof(cx));
}
void kiemtra(ll x)
{
    if(a[x]==a[x+1]&&t>=k[x+1])
    {
        dem++;
        t=t-k[x+1];
        cx[x+1]=false;
    } else return;
    kiemtra(x+1);
}
void kt(ll p)
{
    if(a[p]==a[p-1]&&t>=k[p-1])
    {
        dem++;
        t=t-k[p-1];
        cx[p-1]=false;
    }
    else return;
    kt(p-1);
}
void xuli()
{
    ll i,vt,tam,minn=1e9,d,c,j;
    vt=0;

    for(i=1;i<=n;i++)
    {
        if(cx[i]==true)
        {
            tam=k[i]+abs(a[i]-vt);
            if(tam<minn)
            {
                c=i;
                d=a[i];
                minn=tam;
            }
        }
    }
    while(t>=minn)
    {
        dem++;
        if(dem==n) break;
        t=t-minn;
        vt=d;
        cx[c]=false;
        kiemtra(c );
        kt(c);
        minn=1e9;
        for(i=1;i<=n;i++)
        {
            if(cx[i]==true)
            {
                tam=k[i]+abs(a[i]-vt);
                if(tam<minn)
                {
                    c=i;
                    d=a[i];
                    minn=tam;
                }
            }
        }
    }
    cout << dem;
}
int main()
{
    readfile();
    xuli();
    return 0;
}
