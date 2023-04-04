#include <bits/stdc++.h>
#define ll long long

using namespace std;
const int NM=1e6+5;
ll n,m,a[NM],b[NM];
ll mxa=-1e9,mxb=-1e9,mna=1e9,mnb=1e9;

void readfile()
{
    ll i;
    freopen("WALL.INP","r",stdin);
    freopen("WALL.OUT","w",stdout);
    cin >> n;
    for(i=1;i<=n;i++)
    {
        cin >> a[i];
        if(a[i]>mxa) mxa=a[i];
        if(a[i]<mna) mna=a[i];
    }
    cin >> m;
    for(i=1;i<=m;i++)
    {
        cin >> b[i];
        if(b[i]>mxb) mxb=b[i];
        if(b[i]<mnb) mnb=b[i];
    }
}
bool check(ll x)
{
   ll i,j,dem=1;
   bool cx[NM];
   memset(cx,false,sizeof(cx));
   for(i=1;i<=n;i++)
   {
       if(a[i]<x)
       {
           while(dem<=m)
           {
               if(a[i]+b[dem]>=x)
               {
                   dem++;
                   cx[i]=true;
                   break;
               }
               else dem++;
           }
       }
       else cx[i]=true;
       if(dem>m) break;
   }
   for(i=1;i<=n;i++)
   {
       if(cx[i]==false&&a[i]<x) return false;
   }
   return true;
}
void xuli()
{
    ll d,c,g,kqua;
    d=min(mna,mnb);
    c=mxa+mxb;
    while(d<=c)
    {
        g=(d+c)/2;
        if(check(g)==true)
        {
            d=g+1;
            kqua=g;
        }
        else c=g-1;
    }
    cout << kqua;
}
int main()
{
    readfile();
    xuli();
    return 0;
}
