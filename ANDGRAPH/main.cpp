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
#pragma GCC optimize("Os")


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

int n, m;
bool visited[MASK(22) + 1], cx[MASK(22) + 1];

void dfs(int u) {
    visited[u] = true;
    for(int i = 1; i <= n; i++) if(!BIT(u, i - 1)) {
        int v = u | MASK(i - 1);
        if(!visited[v]) dfs(v);
    }

    int tmp = MASK(n) - 1 - u;
    if(cx[tmp]) {
        cx[tmp] = false;
        if(!visited[tmp]) dfs(tmp);
    }
}
void xuli() {
    int numComp = 0;
    for(int i = 0; i < MASK(n); i++) if(cx[i]) {
        cx[i] = false;
        numComp++;
        if(!visited[i]) dfs(i);
    }

    cout << numComp;
}
int32_t main()
{
    FastIO
    freopen("ANDGRAPH.INP", "r", stdin);
    freopen("ANDGRAPH.OUT", "w", stdout);
    cin >> n >> m;
    for(int i = 1; i <= m; i++) {
        int u; cin >> u;
        cx[u] = true;
    }

    xuli();
    return 0;
}

/* Author: hxzinh */

