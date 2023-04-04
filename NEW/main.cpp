#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define cntBit(x) __builtin_popcountll(x)
#define ii pair<int,int>
#define fi first
#define se second
using namespace std;

struct Edge {
	int u, v;
	bool used;
	bool isBridge;
};
bool minimize(int &a,int b)
{
    if(a > b)
    {
        a = b;
        return 1;
    }
    return 0;
}
int n,m,cnt = 0;
Edge G[250005];
int numComp = 0;
int numChild[250005],low[250005],num[250005],compID[250005],compNode[250005];
vector <int> a[250005],newA[250005];
struct DisjointSet{
    vector <int> Far;
    DisjointSet(int _n = 0)
    {
        Far.assign(_n+1,-1);
    }
    int root(int x)
    {
        if(Far[x] == -1) return x;
        return Far[x] = root(Far[x]);
    }
    bool join(int u, int v) {
        int x = root(u), y = root(v);
        if (x == y) return false;
        if (Far[x] > Far[y]) swap(x, y);
        Far[y] = x;
        return true;
    }
};
void dfs(int u)
{
	low[u] = n + 1;
	num[u] = ++cnt;

	for (int i : a[u]) if (!G[i].used) {
		G[i].used = 1;
		int v = G[i].u ^ G[i].v ^ u;
		if (num[v] == 0) {
			numChild[u]++;
			dfs(v);
			minimize(low[u], low[v]);
			G[i].isBridge = low[v] > num[u];
		} else minimize(low[u], num[v]);
	}
}
void buildtree()
{
    for(int i = 1 ; i <= n ; i++) if(!num[i]) dfs(i);
    DisjointSet dsu(n);
    for(int i = 1 ; i <= m ; i++)
    if(!G[i].isBridge)
    {
        dsu.join(G[i].u,G[i].v);
    }

    for(int i = 1 ; i <= n ; i++)
    if(dsu.root(i) == i)
    {
        compID[i] = ++numComp;
        compNode[numComp] = i;
    }
    for(int i = 1 ; i <= n ; i++)
    if(dsu.root(i) != i)
    compID[i] = compID[dsu.root(i)];
    for(int i = 1 ; i <= m ; i++)
    if(G[i].isBridge)
    {
        int u = compID[G[i].u];
        int v = compID[G[i].v];
        newA[u].push_back(v);
        newA[v].push_back(u);
    }

}
vector <int> leaves;
void dfsComp(int u, int par) {
    bool ok = true;
    for(int v : newA[u])
    if (v != par) {
        dfsComp(v, u);
        ok = false;
    }
    if (ok) leaves.push_back(u);
}
void solve()
{
    cin>>n>>m;
    for(int i = 1 ; i <= n ; i++)
    {
        low[i] = 0;
        num[i] = 0;
        compID[i] = 0;
        compNode[i] = 0;
        newA[i].clear();
        a[i].clear();
    }
    for(int i = 1 ; i <= m ; i++)
    {
        G[i].isBridge = 0;
        G[i].used = 0;
        cin>>G[i].u>>G[i].v;
        a[G[i].u].push_back(i);
        a[G[i].v].push_back(i);
    }
    numComp = 0 , cnt = 0;
    leaves.clear();
    buildtree();
    if(numComp == 1)
    {
        cout<<0<<'\n';
        return;
    }
    if(numComp == 2)
    {
        cout<<1<<'\n';
        cout<<compNode[1]<<" "<<compNode[2]<<'\n';
        return;
    }
    int comp = 0;
    while(newA[comp].size() <= 1) comp++;
    dfsComp(comp,-1);

    cout<<(leaves.size()+1)/2<<'\n';
    for(int i = 0 ; i < leaves.size() / 2 ; i++)
    {
        int u = leaves[i];
        int v = leaves[i + leaves.size() / 2];
        cout<<compNode[u]<<" "<<compNode[v]<<'\n';
    }
    if (leaves.size() % 2 != 0) {
        int u = leaves.front();
        int v = leaves.back();
        cout<<compNode[u]<<" "<<compNode[v]<<'\n';
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("BICONNECTED.INP","r",stdin);
    freopen("BICONNECTED.OUT","w",stdout);
    int t;
    cin>>t;
    while(t--)
        solve();
    return 0;

}
