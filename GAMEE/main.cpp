#include <bits/stdc++.h>
#define ll long long
#define INF 0x3f3f3f3f
#define pii pair<int, int>
#define mp make_pair
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

const int NM = 55;
int n;
int a[NM], par[NM], L[NM], R[NM], f[NM][NM];
int curId = 0;
vector<int> edges[NM];

void dfs(int u, int p) {
    L[u] = ++curId;
    for(int v : edges[u]) if(v != p) {
        dfs(v, u);
    }
    R[u] = curId;
}
int dp(int u, int v) {
    if(u == v) return f[u][v];
    int &res = f[u][v];
    if(res > INF) return res;

    for(int i = u; i < v; i++) {
        maximize(res, min(dp(u, i), dp(i + 1, v)));
    }
}
void xuli() {
    int res = 0;
    for(int i = 1; i <= n; i++) {
        if(edges[i].size() < 2) maximize(res, a[i]);
    }
    cout << res;
}
int32_t main()
{
    FastIO
    freopen("GAME.INP", "r", stdin);
    freopen("GAME.OUT", "w", stdout);
    cin >> n;
    for(int i = 2; i <= n; i++) {
        int u; cin >> u;
        par[u] = i;
        edges[u].push_back(i);
        edges[i].push_back(u);
    }
    for(int i = 1; i <= n; i++) cin >> a[i];

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
