#include <bits/stdc++.h>
#define ll long long

using namespace std;
const int NM=1e6+5;
ll t,n,c,a[NM];

void qs(ll l,ll r)
{
    ll i,j,tam;
    if (l>=r) return;
    i=l;
    j=r;
    tam=a[(l+r)/2];
    while (i<j)
    {
        while (a[i]<tam) i++;
        while (a[j]>tam) j--;
        if (i<=j)
        {
            swap(a[i],a[j]);
            i++;
            j--;
        }
    }
    qs(l,j);
    qs(i,r);
}
bool kiemtra(ll x)
{
    ll vt,dem=1,i;
    vt=a[1];
    for (i=2;i<=n;i++)
    {
        if (a[i]-vt>=x)
        {
            dem++;
            vt=a[i];
        }
    }
    if (dem>=c)
    {
        return true;
    }
    else return false;
}
void readfile()
{
    ll i,minn,maxx,dau,cuoi,g,kqua,j;
    freopen("COW.INP","r",stdin);
    freopen("COW.OUT","w",stdout);
    cin >> t;
    for (i=1;i<=t;i++)
    {
        cin >> n;
        cin >> c;
        minn=1e8;
        maxx=-1e8;
        kqua=-1e8;
        for (j=1;j<=n;j++)
        {
            cin >> a[j];
            minn=min(minn,a[j]);
            maxx=max(maxx,a[j]);
        }
        qs(1,n);
        dau=1;
        cuoi=maxx-minn;
        while (dau<=cuoi)
        {
            g=(dau+cuoi)/2;
            if (kiemtra(g)==true)
            {
                kqua=max(kqua,g);
                dau=g+1;
            }
            else cuoi=g-1;
        }
        cout << kqua << endl;
    }
}
int main()
{
    readfile();
    return 0;
}
