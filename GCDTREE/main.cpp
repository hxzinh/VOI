#include <bits/stdc++.h>
#define int long long
#define INF 0x3f3f3f3f
#define pii pair<int, int>
#define fi first
#define se second
#define ALL(v) (v).begin(), (v).end()
#define popcount(x) __builtin_popcount(x)
#define setp(x) setprecision(x)
#define MASK(x) (1LL << (x))
#define BIT(x, i) ((x) >> (i) & 1)
#define FastIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

template<class X, class Y>
	inline bool maximize(X &x, const Y &y) {return (x < y ? x = y, 1 : 0);}
template<class X, class Y>
	inline bool minimize(X &x, const Y &y) {return (x > y ? x = y, 1 : 0);}

const int NM = 2e5 + 10;
int n, Id;
int a[NM], child[NM], exist[NM], dist[NM];
set<int> edges[NM];
set<int> g;

void dfs(int u, int p) {
    child[u] = 1;
    for(int v : edges[u]) if(v != p) {
        dfs(v, u);
        child[u] += child[v];
    }
}
int centroid(int u, int p, int node) {
    for(int v : edges[u]) if(v != p){
        if(child[v] > node / 2) return centroid(v, u, node);
    }
    return u;
}
int dfs2(int u, int p, int curGcd, int h, vector<pii> &tmp) {
    if(curGcd == 1) return 0;
    int ans = 0;
    for(int v : g) if(__gcd(curGcd, v) > 1 && exist[v] == Id)
        maximize(ans, h + dist[v]);

    if(curGcd > 1) {
        tmp.push_back({curGcd, h});
        for(int v : edges[u]) if(v != p){
            int newGcd = __gcd(a[v], curGcd);
            if(newGcd > 1) maximize(ans, dfs2(v, u, newGcd, h + 1, tmp));
        }
    }

    return ans;
}
int solve(int u, int p){
    dfs(u, p);
    int node = child[u];
    int cen = centroid(u, p, node);

    int res = 0;

    g.clear();
    g.insert(a[cen]);
    int curId = ++Id;
    exist[a[cen]] = curId;
    dist[a[cen]] = 1;

    for(int v : edges[cen]) if(v != p) {
        vector<pii> tmp;
        maximize(res, dfs2(v, cen, __gcd(a[v], a[cen]), 1, tmp));
        for(pii t : tmp){
            g.insert(t.fi);
            if(exist[t.fi] == curId) maximize(dist[t.fi], t.se + 1);
            else {
                exist[t.fi] = curId;
                dist[t.fi] = t.se + 1;
            }
        }
    }

    vector<int> tmp(ALL(edges[cen]));
    for(int v : tmp) if(v != p) {
        edges[cen].erase(v);
        edges[v].erase(cen);
        maximize(res, solve(v, cen));
    }

    return res;
}
void xuli(){
    cout << solve(1, 0);
}
int32_t main()
{
    FastIO
    freopen("GCDTREE.INP", "r", stdin);
    freopen("GCDTREE.OUT", "w", stdout);
    cin >> n;
    for(int i = 1; i <= n; i++) cin >> a[i];
    for(int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        edges[u].insert(v);
        edges[v].insert(u);
    }

    xuli();
    return 0;
}

/* Author: hxzinh */

/*
-----code ko bug-----code ko bug-----code ko bug--------------

          _.-/`)
         // / / )
      .=// / / / )
     //`/ / / / /
    // /     ` /
   ||         /
    \\       /
     ))    .'
    //    /
         /
*/
