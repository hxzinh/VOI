#include <bits/stdc++.h>
#define ll long long

using namespace std;
const int NM=1e6+5;
ll n,c,x[NM],tong;
ll i,j,kt[NM],p[NM],kq=0;

struct mang
{
    ll p,t;
};
mang a[NM];
void readfile()
{
    freopen("CAKE.INP","r",stdin);
    freopen("CAKE.OUT","w",stdout);
    cin >>n>>c;
    for (int i=1;i<=n;i++)
    {
        cin >>x[i]>>a[i].t;
        a[i].p=i;
    }
    x[n+1]=1e14;
}
bool xet(mang a,mang b)
{
    return (a.t<b.t);
}
void xuli()
{
    sort (a+1,a+1+n,xet);
    for (i=1;i<=n;i++)
    {
        tong=x[i];
        if (tong<=c&&x[i+1]>x[i])
        {
        for (j=1;j<=i;j++)
        {
            if (a[j].p<=i)
            {
                if (tong+a[j].t<=c)
                {
                    tong+=a[j].t;
                    kt[i]++;
                }
                else break;
            }
        }
        }
        kq=max(kq,kt[i]);
    }
    cout<<kq;
}
int main()
{
    readfile();
    xuli();
    return 0;
}

