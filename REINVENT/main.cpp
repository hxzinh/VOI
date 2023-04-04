#include <bits/stdc++.h>
#define ll long long
#define oo 99999999999
#define FastIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;
const int NM=1e5+10;
ll n,m,x,s[NM],k[NM],T[NM];
///------------------------------------///
vector <ll> a[NM];
bool cx[NM];
///------------------------------------///
struct level
{
    ll u,w;
};
priority_queue <level> q;
bool operator < (const level &A,const level &B)
{
    return A.w > B.w;
}

void readfile()
{
    freopen("REINVENT.INP","r",stdin);
    freopen("REINVENT.OUT","w",stdout);
    cin >> n >> m >> x;
    for(int i=1;i<=m;i++)
    {
        ll u,v;
        cin >> u >> v;
        a[u].push_back(v);
        a[v].push_back(u);
    }
    for(int i=1;i<=x;i++)
    {
        ll u;
        cin >> u;
        a[0].push_back(u);
        cx[u]=true;
    }
    for(int i=1;i<=n;i++)
    {
        if(cx[i]) T[i]=i;
    }
}
ll BFS(ll x)
{
    queue <ll> q;
    for(int i=0;i<a[0].size();i++) q.push(a[0][i]);
    while(!q.empty())
    {
        ll u=q.front();
        q.pop();
        for(int i=0;i<a[u].size();i++)
        {
            ll v=a[u][i];
            if(T[u]==T[v]) continue;
            if(T[v]==0)
            {
                T[v]=T[u];
                s[v]=s[u]+1;
                q.push(v);
            }
            if(T[v]!=T[u]) return s[u]+s[v]+1;
        }
    }
    return -1;
}
void xuli()
{
    cout << BFS(0);
}
int main()
{
    FastIO
    readfile();
    xuli();
    return 0;
}
