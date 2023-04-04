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
const int MAX = 1000000;
int n, q;
int a[NM];
vector<int> edges[NM];

struct SegmentTree {
    int n;
    vector<int> Max;

    SegmentTree(int _n = 0) {
        n = _n;
        Max.assign(4 * n + 7, 0);
    }

    void update(int i, int l, int r, int u, int x) {
        if(u < l || u > r || l > r) return;
        if(l == r && l == u) {
            Max[i] = x;
            return;
        }

        int m = (l + r) >> 1;
        update(2 * i, l, m, u, x);
        update(2 * i + 1, m + 1, r, u, x);
        Max[i] = max(Max[2 * i], Max[2 * i + 1]);
    }

    int getMax(int i, int l, int r, int u, int v) {
        if(u > r || v < l || l > r) return 0;
        if(u <= l && v >= r) return Max[i];

        int m = (l + r) >> 1;
        int maxL = getMax(2 * i, l, m, u, v);
        int maxR = getMax(2 * i + 1, m + 1, r, u, v);
        return max(maxL, maxR);
    }

    void update(int u, int x) {
        update(1, 1, n, u, x);
    }

    int getMax(int u, int v) {
        return getMax(1, 1, n, u, v);
    }
} tree;

int result = 0, parNode = 0;

void dfs(int u, int p) {
    int cur = tree.getMax(a[u], a[u]);

    int preMax = 0;
    if(a[u] >= a[parNode]) {
        preMax = tree.getMax(a[parNode], a[u]);
        tree.update(a[u], preMax + 1);
        maximize(result, preMax + 1);
    }

    for(int v : edges[u]) if(v != p) dfs(v, u);

    if(a[u] >= a[parNode]) tree.update(a[u], cur);
}
void xuli() {
    tree = SegmentTree(MAX);

    while(q--) {
        cin >> parNode;

        result = 0;
        dfs(parNode, -1);
        cout << result << '\n';
    }
}
int32_t main()
{
    FastIO
    freopen("AGENCY.INP", "r", stdin);
    freopen("AGENCY.OUT", "w", stdout);
    cin >> n >> q;
    for(int i = 1; i <= n; i++) cin >> a[i];
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
