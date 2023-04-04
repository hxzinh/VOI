#include <bits/stdc++.h>
#define ll long long

using namespace std;
const int NM=1e6+5;
struct tower
{
    ll a,b,c;
    ll h,dt,dai,rong;
};
tower k[NM];
ll n,kqua=-1,s[NM],tong[NM];

void readfile()
{
    ll i;
    freopen("TOWER.INP","r",stdin);
    freopen("TOWER.OUT","w",stdout);
    cin >> n;
    for(i=1;i<=n;i++)
    {
        cin >> k[i].a >> k[i].b;
        k[i].h=min(k[i].b,k[i].a);
        k[i].dai=max(k[i].a,k[i].b);
        cin >> k[i].c;
        k[i].dai=max(k[i].dai,k[i].c);
        k[i].h=min(k[i].h,k[i].c);
        k[i].rong=(k[i].a+k[i].b+k[i].c)-(k[i].dai+k[i].h);
        k[i].dt=(k[i].a*k[i].b*k[i].c)/k[i].h;
    }
}
bool tang(tower x,tower y)
{
    return x.dt<y.dt||(x.dt==y.dt&&x.h<y.h);
}
void xuli()
{
    ll i,dau,cuoi,j,t;
    sort(k+1,k+n+1,tang);
    for(i=1;i<=n;i++) tong[i]=0;
    for(i=1;i<=n;i++) s[i]=k[i].h;
    for(i=2;i<=n;i++)
    {
        for(j=i-1;j>=1;j--)
        {
            if(k[i].dai>=k[j].dai&&k[i].rong>=k[j].rong)
            {
                s[i]=max(s[i],k[i].h+s[j]);
            }
        }
        kqua=max(kqua,s[i]);
    }
    cout << kqua;
}
int main()
{
    readfile();
    xuli();
    return 0;
}
