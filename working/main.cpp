#include <bits/stdc++.h>

using namespace std;

long n,res=0;
struct Bien
{
    long d,g,c;
};
Bien a[100005];
void doc()
{
    freopen("WORKING.INP","r",stdin);
    freopen("WORKING.OUT","w",stdout);
    cin>>n;
    for (long i=1;i<=n;i++){
        cin>>a[i].d>>a[i].c;
        a[i].g=a[i].c-a[i].d;
    }
}
bool cmp(const Bien &x,const Bien &y)
{
    return (x.d<y.d || (x.d==y.d && x.c>y.c));
}
void xuli()
{
    sort(a+1,a+n+1,cmp);
    for(long i=1; i<=n; i++)
    {
        cout<<a[i].d<<" " <<a[i].g<<" "<<a[i].c<<endl;
    }
    for (long i=1;i<=n;i++)
    {
        long s=a[i].g;
        long k=a[i].c;
        for (long j=i+1;j<=n;j++)
        {
            if(k<a[j].c)
            {
                if (a[j].d>=k)
                {
                    a[j].g=max(a[j].g,s+a[j].c-a[j].d);
                }
                else
                {
                    a[j].g=max(s-(k-a[j].d)+a[j].c-k,a[j].g);
                }
                res=max(res,a[j].g);
            }
        }
    }
    cout<<res<<endl;
}
int main()
{
    doc();
    xuli();
    return 0;
}
