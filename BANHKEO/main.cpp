#include <bits/stdc++.h>
#define ll long long
#define oo 99999999999
#define FastIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;
const int NM=1e3+10;
ll n,m,k,minn=oo,dem=0;
///--------------------------------------///
struct Data
{
    ll v,w;
};
vector <ll> a[NM];
bool cx[NM];

void readfile()
{
    freopen("BANHKEO.INP","r",stdin);
    freopen("BANHKEO.OUT","w",stdout);
    cin >> n >> m >> k;
    for(int i=1;i<=k;i++)
    {
        ll u;
        cin >> u;
        minn=min(minn,u);
    }
    for(int i=1;i<=m;i++)
    {
        ll u,v,w;
        cin >> u >> v >> w;
        if(w>=minn)
        {
            a[u].push_back(v);
            a[v].push_back(u);
        }
    }
    memset(cx,true,sizeof(cx));
}
void DFS(ll x)
{
    queue <ll> q;
    cx[x]=false;
    q.push(x);
    while(!q.empty())
    {
        ll u=q.front();
        q.pop();
        for(int i=0;i<a[u].size();i++)
        {
            ll v=a[u][i];
            if(cx[v])
            {
                cx[v]=false;
                q.push(v);
            }
        }
    }
}
void xuli()
{
    for(int i=1;i<=n;i++)
    {
        if(cx[i])
        {
            dem++;
            DFS(i);
        }
    }
    cout << dem;
}
int main()
{
    FastIO
    readfile();
    xuli();
    return 0;
}
