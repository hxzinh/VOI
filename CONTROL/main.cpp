
#include <bits/stdc++.h>
#define ll long long
#define INF 0x3f3f3f3f
#define pii pair<int, int>
#define pll pair<long long, long long>
#define fi first
#define se second
#define ALL(v) (v).begin(), (v).end()
#define popcount(x) __builtin_popcount(x)
#define setp(x) setprecision(x)
#define MASK(x) (1LL << (x))
#define BIT(x, i) ((x) >> (i) & 1)
#define FastIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

/**
//PRAGMA
#pragma GCC target("popcnt")
**/

/**
//ordered_set
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
typedef tree<pii,
             null_type,
             less<pii>,
             rb_tree_tag,
             tree_order_statistics_node_update> ordered_set;
**/

template<class X, class Y>
	inline bool maximize(X &x, const Y &y) {return (x < y ? x = y, 1 : 0);}
template<class X, class Y>
	inline bool minimize(X &x, const Y &y) {return (x > y ? x = y, 1 : 0);}

const int NM = 2e5 + 10;
int n;
int curSize = 0;
int a[NM], child[NM], ans[NM];
set<int> edges[NM];
vector<pii> dist;

struct FenwickTree {
    int n;
    vector<int> val;

    FenwickTree(int _n = 0) {
        n = _n;
        val = vector<int>(n + 7, 0);
    }

    void update(int u, int x) {
        for(; u > 0; u -= u & -u) val[u] += x;
    }

    int getSum(int u) {
        int res = 0;
        for(; u <= n; u += u & -u) res += val[u];
        return res;
    }
} tree;

void dfs(int u, int p) {
    child[u] = 1;
    for(int v : edges[u]) if(v != p) {
        dfs(v, u);
        child[u] += child[v];
    }
}
int centroid(int u, int p, int node) {
    for(int v : edges[u]) if(v != p) {
        if(child[v] > node / 2) return centroid(v, u, node);
    }
    return u;
}
void dfs2(int u, int p, int h, int root, int t, vector<pii> &tmp) {
    if(t && h <= a[u]) ans[root]++;
    if(t && h <= a[root]) ans[u]++;
    ans[u] += tree.getSum(h);

    if(a[u] - h > 0) tmp.push_back({h, u});
    for(int v : edges[u]) if(v != p) {
        dfs2(v, u, h + 1, root, t, tmp);
    }
}
void solve(int u, int p) {
    dfs(u, -1);
    int cen = centroid(u, -1, child[u]);
    curSize = child[u];

    tree = FenwickTree(child[u]);

    for(int v : edges[cen]) {
        vector<pii> tmp;
        dfs2(v, cen, 1, cen, 1, tmp);
        for(pii h : tmp)
            tree.update(min(a[h.se] - h.fi, curSize), 1);
    }

    tree = FenwickTree(child[u]);

    auto it = edges[cen].end();
    while(it != edges[cen].begin()) {
        it--;
        vector<pii> tmp;
        dfs2(*it, cen, 1, cen, 0, tmp);
        for(pii h : tmp)
            tree.update(min(a[h.se] - h.fi, curSize), 1);
    }

    vector<int> tmp(ALL(edges[cen]));
    for(int v : tmp) {
        edges[cen].erase(v);
        edges[v].erase(cen);
        solve(v, cen);
    }
}
void xuli() {
    solve(1, -1);

    for(int i = 1; i <= n; i++) cout << ans[i] << " ";
}
void dfssub(int u, int p, int h, int root) {
    for(int v : edges[u]) if(v != p) {
        if(h + 1 <= a[root]) ans[v]++;
        else return;
        dfssub(v, u, h + 1, root);
    }
}
void sub1() {
    for(int i = 1; i <= n; i++) dfssub(i, -1, 0, i);

    for(int i = 1; i <= n; i++) cout << ans[i] << " ";
}
int32_t main()
{
    FastIO
    freopen("CONTROL.INP", "r", stdin);
    freopen("CONTROL.OUT", "w", stdout);
    cin >> n;
    for(int i = 1; i <= n; i++) cin >> a[i];
    for(int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        edges[u].insert(v);
        edges[v].insert(u);
    }

    xuli();
    //sub1();
    return 0;
}

/* Author: hxzinh */


