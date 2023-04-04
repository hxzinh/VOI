#include <bits/stdc++.h>
#define ll long long
#define oo 1e18
#define FastIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;
const int NM=1e6+10;
ll n,m,k;
ll F[10005][10005],s[NM];
vector <ll> a[NM];
///--------------------------------------///
struct Data
{
    ll cost,more;
};
Data g[NM];
///--------------------------------------///
struct State
{
    ll u,cost,last;
    bool operator < (const State &B)
    const
    {
        return cost>B.cost;
    }
};

void readfile()
{
    freopen("TRAVEL.INP","r",stdin);
    freopen("TRAVEL.OUT","w",stdout);
    cin >> n >> k;
    for(int i=1;i<=n;i++)
    {
        cin >> g[i].cost >> g[i].more;
    }
    for(int i=1;i<=k;i++)
    {
        ll u,v;
        cin >> u >> v;
        a[u].push_back(v);
        a[v].push_back(u);
    }
    for(int i=1;i<=n;i++)
        for(int j=0;j<=n;j++)
        F[i][j]=oo;
    ///for(int i=1;i<=n;i++) d[i]=oo;
}
void dijtra()
{
    ll res=oo;
    priority_queue <State> pq;
    F[1][0]=0;
    pq.push({1,0,0});
    while(!pq.empty())
    {
        ll u=pq.top().u;
        ll cost=pq.top().cost;
        ll last=pq.top().last;
        pq.pop();
        if(F[u][last]!=cost) continue;
        cout << F[u][last] << " " << last << '\n';
        if(last==0)
        {
            for(int i=0;i<a[u].size();i++)
            {
                ll v=a[u][i];
                if(cost+g[u].cost < F[v][g[u].more-1])
                {
                    F[v][g[u].more-1]=cost+g[u].cost;
                    pq.push({v,cost+g[u].cost,g[u].more-1});
                }
            }
        }
        else if(last>0)
        {
            for(int i=0;i<a[u].size();i++)
            {
                ll v=a[u][i];
                if(cost+g[u].cost < F[v][g[u].more-1])
                {
                    F[v][g[u].more-1]=cost+g[u].cost;
                    pq.push({v,cost+g[u].cost,g[u].more-1});
                }
                if(F[v][last-1]>cost)
                {
                    F[v][last-1]=cost;
                    pq.push({v,cost,last-1});
                }
            }
        }
    }
    for(int i=0;i<=n;i++) res=min(res,F[n][i]);
    cout << res;
}
int main()
{
    FastIO
    readfile();
    dijtra();
    return 0;
}
