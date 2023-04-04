#include <bits/stdc++.h>
#define ll long long
#define oo 99999999999
#define FastIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;
const int NM=1e6+5;
ll n,m;
ll T[NM],s[NM],K[NM];
struct Data
{
    ll u,v,w,cs;
};
Data a[NM];
bool cx[NM];

void readfile()
{
    freopen("MPANTREE.INP","r",stdin);
    freopen("MPANTREE.OUT","w",stdout);
    cin >> n >> m;
    for(int i=1;i<=m;i++)
    {
        cin >> a[i].u >> a[i].v >> a[i].w;
    }
    memset(T,-1,sizeof(T));
    memset(K,-1,sizeof(K));
}
bool cmp(Data A,Data B)
{
    return A.w < B.w;
}
ll root(ll x)
{
    if(T[x]==-1) return x;
    else return T[x]=root(T[x]);
}
void xuli()
{
    ll dem=0,res=0;
    memset(cx,true,sizeof(cx));
    sort(a+1,a+m+1,cmp);
    for(int i=1;i<=m;i++)
    {
        if(dem==n-1) break;
        ll u=root(a[i].u);
        ll v=root(a[i].v);
        ll w=a[i].w;
        if(root(u)!=root(v))
        {
            dem++;
            res+=w;
            cx[i]=false;
            T[max(u,v)]=min(u,v);
        }
    }
    cout << res << '\n';
    for(int i=1;i<=m;i++)
    {
        if(!cx[i]) cout << a[i].u << " " << a[i].v << '\n';
    }
}
int main()
{
    FastIO
    readfile();
    xuli();
    return 0;
}
