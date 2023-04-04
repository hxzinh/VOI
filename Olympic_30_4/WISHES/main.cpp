#include <bits/stdc++.h>
#define ll long long
#define oo 99999999999
#define FastIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;
const int NM=1e5+10;
ll n,m;
ll T[NM];
bool cx[NM];
vector <ll> a[NM];

void readfile()
{
    freopen("WISHES.INP","r",stdin);
    freopen("WISHES.OUT","w",stdout);
    cin >> n >> m;
    memset(cx,true,sizeof(cx));
    for(int i=1;i<=m;i++)
    {
        ll u,v;
        cin >> u >> v;
        cx[v]=false;
        a[u].push_back(v);
    }
    memset(T,-1,sizeof(T));
}
void xuli()
{
    ll dem=0;
    for(int i=1;i<=n;i++)
    {
        if(!cx[i])
        {
            dem++;
            ///BFS(i);
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
