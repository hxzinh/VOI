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
int child[NM];
vector<int> edges[NM];
set<int> A, B;

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
vector<int> closet(const set<int> &S, int val) {
    vector<int> tmp;
    auto it = S.upper_bound(val);
    if(it != S.end()) tmp.push_back(*it);
    if(it != S.begin()) {
        it--;
        tmp.push_back(*it);
    }
    return tmp;
}
int getAns(int u, int v, int w) {
    return max({u, v, w}) - min({u, v, w});
}
int solve(int u, int p) {
    int res = INF;

    for(auto v : closet(A, (n + child[u]) / 2))
        minimize(res, getAns(child[u], v - child[u], n - v));

    for(auto v : closet(B, (n - child[u]) / 2))
        minimize(res, getAns(child[u], v, n - child[u] - v));

    A.insert(child[u]);
    for(int v : edges[u]) if(v != p) {
        minimize(res, solve(v, u));
    }
    A.erase(child[u]);
    B.insert(child[u]);

    return res;
}
void xuli() {
    dfs(1, -1);
    int cen = centroid(1, -1, child[1]);
    cout << solve(1, -1);
}
int32_t main()
{
    FastIO
    freopen("PAPRICICE.INP", "r", stdin);
    freopen("PAPRICICE.OUT", "w", stdout);
    cin >> n;
    for(int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        edges[u].push_back(v);
        edges[v].push_back(u);
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
