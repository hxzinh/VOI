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

const int NM = 1e4 + 10;
int n;
int p[NM], p2[NM];
int a[NM], b[NM], child[NM], need[NM];
vector<int> edges[NM], G[NM];
bool cx[22];

void dfs2(int u, int p) {
    if(cx[u]) child[u] = 1;
    for(int v : edges[u]) if(v != p) {
        dfs2(v, u);
        child[u] += child[v];
    }
}
void dfs3(int u, int p) {
    if(cx[u]) child[u] = 1;
    for(int v : G[u]) if(v != p) {
        dfs3(v, u);
        child[u] += child[v];
    }
}
bool check(int x) {
    memset(cx, false, sizeof cx);

    int parNode = -1;
    for(int i = 1; i <= n; i++) {
        if(p[i] == 0) parNode = i;
        if(BIT(x, i - 1)) cx[i] = true;
    }
    memset(child, 0, sizeof child);

    dfs2(parNode, -1);
    bool ok = true;
    for(int i = 1; i <= n; i++)
        if(child[i] < a[i]) return false;

    memset(child, 0, sizeof child);
    for(int i = 1; i <= n; i++)
        if(p2[i] == 0) parNode = i;

    dfs3(parNode, -1);
    for(int i = 1; i <= n; i++)
        if(child[i] < b[i]) return false;

    return true;
}
void sub1() {
    int res = n;
    for(int mask = 1; mask < MASK(n); mask++) {
        if(check(mask)) minimize(res, __builtin_popcount(mask));
    }

    cout << res;
}
void dfs(int u, int p) {
    bool ok = false;
    for(int v : edges[u]) if(v != p) {
        dfs(v, u);
        child[u] += child[v];
        if(need[v] > 0) ok = true;
    }

    maximize(child[u], a[u]);
}
void sub2() {
    int parNode = -1;
    for(int i = 1; i <= n; i++) {
        maximize(a[i], b[i]);
        if(p[i] == 0) parNode = i;
    }

    dfs(parNode, -1);
    cout << child[parNode];
}
int32_t main()
{
    FastIO
    freopen("COMPANY.INP", "r", stdin);
    freopen("COMPANY.OUT", "w", stdout);
    cin >> n;
    for(int i = 1; i <= n; i++) {
        cin >> p[i];
        edges[p[i]].push_back(i);
        edges[i].push_back(p[i]);
    }
    for(int i = 1; i <= n; i++) {
        cin >> p2[i];
        G[p2[i]].push_back(i);
        G[i].push_back(p2[i]);
    }
    for(int i = 1; i <= n; i++) cin >> a[i];
    for(int i = 1; i <= n; i++) cin >> b[i];

    if(n <= 20) sub1();
    else sub2();
    return 0;
}

/* Author: hxzinh */

