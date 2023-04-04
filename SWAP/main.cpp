#include <bits/stdc++.h>
#define ll long long
#define oo 99999999999
#define FastIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;
const int NM=1e5+10;
ll n,k;
ll a[NM];
bool cx[NM];

void readfile()
{
    ll dem;
    freopen("SWAP.INP","r",stdin);
    freopen("SWAP.OUT","w",stdout);
    cin >> n >> k;
    for(int i=1;i<=n;i++) cx[i]=true;
    dem=n;
    for(int i=1;i<=k;i++)
    {
        ll u,v;
        cin >> u >> v;
        if(u<=n && cx[u])
        {
            if(!cx[v] && v>n)
            {
                dem--;
                cx[v]=true;
                cx[u]=false;
            }
            else if(v<=n && !cx[v])
            {
                cx[u]=false;
                cx[v]=true;
            }
        }
        else if(u<=n && !cx[u])
        {
            if(v>n && cx[v])
            {
                dem++;
                cx[u]=true;
                cx[v]=false;
            }
            else if(v<n && cx[v])
            {
                cx[v]=false;
                cx[u]=true;
            }
        }
        else if(u>n && cx[u])
        {
            if(v<=n && !cx[v])
            {
                dem++;
                cx[v]=true;
                cx[u]=false;
            }
            else if(v>n && !cx[v])
            {
                cx[u]=false;
                cx[v]=true;
            }
        }
        else if(u>n && !cx[u])
        {
            if(v<=n && cx[v])
            {
                cx[v]=false;
                cx[u]=true;
                dem--;
            }
        }
        cout << dem << '\n';
    }
}
int main()
{
    FastIO
    readfile();
    return 0;
}
