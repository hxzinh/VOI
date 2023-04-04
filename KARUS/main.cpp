#include <bits/stdc++.h>
#define ll long long
#define oo 99999999999
#define FastIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;
const int NM=1e4+10;
ll n,m,T[NM];
struct Data
{
    ll u,v,w;
};
Data a[NM];

void readfile()
{
    freopen("KAR.INP","r",stdin);
    freopen("KAR.OUT","w",stdout);
    cin >> n >> m;
    for(int i=1;i<=m;i++)
    {
        cin >> a[i].u >> a[i].v >> a[i].w;
    }
    memset(T,-1,sizeof(T));
}
bool cmp(Data A,Data B)
{
    return A.w<B.w;
}
ll root(ll x)
{
    if(T[x]==-1) return x;
    else return T[x]=root(T[x]);
}
void kar()
{
    ll dem=0,res=0;
    sort(a+1,a+m+1,cmp);
    for(int i=1;i<=m;i++)
    {
        if(dem==n-1) break;
        ll u=root(a[i].u), v=root(a[i].v);
        if(u!=v)
        {
            res+=a[i].w;
            dem++;
            T[max(u,v)]=min(u,v);
        }
    }
    cout << res;
}
int main()
{
    FastIO
    readfile();
    kar();
    return 0;
}
