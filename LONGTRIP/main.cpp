#include <bits/stdc++.h>
#define ll long long
#define oo -1e18

using namespace std;
const int NM=75;
ll n,m,t;
struct Data
{
    ll v,w;
};
vector <Data> a[NM];
///----------------------------------------------------------///
struct LONGTRIP
{
    ll u,cost,time;
};

priority_queue <LONGTRIP> pq;

bool operator < (const LONGTRIP &A,const LONGTRIP &B)
{
    return A.time > B.time;
}


void readfile()
{
    freopen("LONGTRIP.inp","r",stdin);
    cin >> n >> m >> t;
    for(int i=1;i<=m;i++)
    {
        ll u,v,w;
        cin >> u >> v >> w;
        a[u].push_back({v,w}); a[v].push_back({u,w});
    }
    for(int i=1;i<=n;i++) {
        for(int j=0;j<a[i].size();j++)
           cout << a[i][j].v << " ";
        cout << '\n';
    }
}
int main()
{
    readfile();
    return 0;
}
