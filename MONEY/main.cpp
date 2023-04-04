#include <bits/stdc++.h>
#define ll int
#define oo 9999999

using namespace std;
const int NM=1e4+5;
ll n,m,k,st,f;
ll a[NM][NM],s[NM],d[NM];
struct khung
{
    ll cost,d;
};
khung c[NM];
bool cx[NM];

void readfile()
{
    ll i,u,v,w;
    freopen("MONEY.INP","r",stdin);
    freopen("MONEY.OUT","w",stdout);
    cin >> n >> m >> k;
    cin >> st >> f;
    for(i=1;i<=k;i++)
    {
        cin >> u >> v;
        c[i].cost=v;
        c[i].d=u;
    }
    for(i=1;i<=m;i++)
    {
        cin >> u >> v >> w;
        a[u][v]=w;
        a[v][u]=w;
    }
}
void khoitao()
{
    ll i;
    memset(cx,true,sizeof(cx));
    for(i=1;i<=n;i++) s[i]=oo-1;
}
void distra1()
{
    ll i,minn,u;
    khoitao();
    s[st]=0;
    while(true)
    {
        minn=oo;
        u=0;
        for(i=1;i<=n;i++)
        {
            if(cx[i]==true && s[i]<minn)
            {
                minn=s[i];
                u=i;
            }
        }
        if(u==0) break;
        cx[u]=false;
        for(i=1;i<=n;i++)
        {
            if(a[u][i]!=0)
            {
                s[i]=min(s[i],s[u]+a[u][i]);
            }
        }
    }
}
void distra2()
{
    ll i,minn,u;
    memset(cx,true,sizeof(cx));
    for(i=1;i<=n;i++) d[i]=oo-1;
    d[f]=0;
    while(true)
    {
        minn=oo;
        u=0;
        for(i=1;i<=n;i++)
        {
            if(cx[i]==true && d[i]<minn)
            {
                minn=d[i];
                u=i;
            }
        }
        if(u==0) break;
        cx[u]=false;
        for(i=1;i<=n;i++)
        {
            if(a[u][i]!=0)
            {
                d[i]=min(d[i],d[u]+a[u][i]);
            }
        }
    }
}
void xuli()
{
    ll i,kqua=oo,tam,u;
    distra1();
    distra2();
    for(i=1;i<=k;i++)
    {
        tam=s[c[i].d]+c[i].cost+d[c[i].d];
        if(tam<kqua)
        {
            kqua=tam;
            u=c[i].d;
        }
    }
    cout << kqua << " " << u;
}
int main()
{
    readfile();
    xuli();
    return 0;
}
