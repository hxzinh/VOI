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

const int NM = 1e5 + 10;
const int MOD = 1e9 + 7;
int n, parNode;
int curId = 0;
int par[NM], L[NM], R[NM], child[NM], high[NM], id[NM], t[NM];
pii ans[NM];
vector<int> edges[NM];

struct FenwickTree {
    int n;
    vector<int> sum;

    FenwickTree(int _n = 0) {
        n = _n;
        sum.assign(n + 7, 0);
    }

    void update(int u, int x) {
        for(; u <= n; u += u & -u) sum[u] = (sum[u] + x) % MOD;
    }

    int getSum(int u) {
        int res = 0;
        for(; u > 0; u -= u & -u) res = (res + sum[u]) % MOD;
        return res;
    }

    int getSum(int u, int v) {
        return (getSum(v) - getSum(u - 1) + MOD) % MOD;
    }
};

void dfs(int u, int p) {
    L[u] = ++curId;
    child[u] = 1;

    for(int v : edges[u]) if(v != p) {
        high[v] = high[u] + 1;
        dfs(v, u);
        child[u] += child[v];
    }
    R[u] = curId;
}
void xuli() {
    dfs(parNode, 0);
    FenwickTree tree(n);

    //for(int i = 1; i <= n; i++) tree.update(L[i], a[i]);

    for(int i = 1; i <= n; i++) {
        int u = t[i];
        int res = (tree.getSum(L[u], R[u]) + 1) % MOD;
        tree.update(L[u], res);
        ans[i] = {u, res};
    }

    sort(ans + 1, ans + n + 1);
    for(int i = 1; i <= n; i++) cout << ans[i].se << " ";
}
int32_t main()
{
    FastIO
    freopen("TREETRAVEL.INP", "r", stdin);
    freopen("TREETRAVEL.OUT", "w", stdout);
    cin >> n;
    for(int i = 1; i <= n; i++) {
        cin >> par[i];
        if(!par[i]) parNode = i;

        edges[par[i]].push_back(i);
    }
    for(int i = 1; i <= n; i++) {
        cin >> t[i];
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
