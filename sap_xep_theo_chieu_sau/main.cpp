#include <bits/stdc++.h>
#define ll long long

using namespace std;
const int NM=1e4;
ll n,s,f,m,u,v;
bool a[NM][NM],F[NM];
ll T[NM];

void readifle()
{
    freopen("DFS.INP","r",stdin);
    freopen("DFS.OUT","w",stdout);
    cin >> n >> m >> s >> f;
    for(i=1;i<=m;i++)
    {
        cin >> u >> v;
        a[u][v]=true;
        a[v][u]=true;
    }
}
void DFS(ll u)
{
    ll v;
}
int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
