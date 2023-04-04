#include <bits/stdc++.h>
#define ll long long
#define oo 99999999999
#define FastIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;
const int NM=1e5+10;
ll n,st,f;
ll s[NM];
struct Data
{
    ll v,w;
};
vector <Data> a[NM];
///----------------------------------///
struct level
{
    ll u,cost;
};
bool operator < (const level &A,const level &B)
{
    return A.cost > B.cost;
}

void readfile()
{
    freopen("RUNNING.INP","r",stdin);
    freopen("RUNNING.OUT","w",stdout);
    cin >> n >> st >> f;
    for(int i=1;i<=n-1;i++)
    {
        ll u,v,w;
        cin >> u >> v >> w;
        a[u].push_back({v,w});
        a[v].push_back({u,w});
    }
    for(int i=1;i<=n;i++) s[i]=oo;
}
void dijtra()
{
    priority_queue <level> pq;
    s[st]=0;
    pq.push({st,0});
    while(!pq.empty())
    {
        ll u=pq.top().u, cost=pq.top().cost;
        pq.pop();
    }
}
int main()
{
    FastIO
    cout << "Hello world!" << endl;
    return 0;
}
