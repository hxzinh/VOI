#include <bits/stdc++.h>
#define ll long long
#define oo 99999999999
#define FastIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;
const int NM=1e6+10;
ll n,m,C,q;
ll p[NM],s[NM],L[NM];

void update(ll x,ll l,ll r,ll i,ll v)
{
    if(i<l || i>r) return;
    if(l==r)
    {
        L[x]=v;
        return;
    }
    ll g=(l+r)/2;
    update(x*2,l,g,i,v);
    update(x*2+1,g+1,r,i,v);
    L[x]=max(L[x*2],L[x*2+1]);
}
ll findmax(ll x,ll l,ll r,ll u,ll v)
{
    if(v<l || u>r) return 0;
    if(u<=l && v>=r) return L[x];
    ll g=(l+r)/2;
    return max(findmax(x*2,l,g,u,v),findmax(x*2+1,g+1,r,u,v));
}
void readfile()
{
    freopen("STONE.INP","r",stdin);
    freopen("STONE.OUT","w",stdout);
    cin >> n >> m >> C;
    memset(s,0,sizeof(s));
    memset(p,0,sizeof(p));
    for(int i=1;i<=m;i++)
    {
        ll u,v,k;
        cin >> u >> v >> k;
        s[u]=s[u]+k;
        s[v+1]=s[v+1]-k;
    }
    for(int i=1;i<=n;i++) p[i]=p[i-1]+s[i];
}
void xuli()
{
    for(int i=0;i<=n;i++)
    {
        p[i]+=C;
        update(1,1,n,i,p[i]);
    }
    ///for(int i=1;i<=15;i++) cout << L[i] << " ";
    ///cout << '\n';
    cin >> q;
    for(int i=1;i<=q;i++)
    {
        ll u,v;
        cin >> u >> v;
        cout << findmax(1,1,n,u,v) << '\n';
    }
    ///for(int i=1;i<=100;i++) cout << L[i] << " ";
}
int main()
{
    FastIO
    readfile();
    xuli();
    return 0;
}
