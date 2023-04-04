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
int n, m, k;
int a[NM];
vector<pii> edeges[NM];
int d[505][505];

void sub3() {
    memset(d, INF, sizeof d);

    for(int i = 1; i <= n; i++)
        for(pii u : edges[i]) d[i][u.fi] = u.se;

    for(int k = 1; k <= n; k++)
        for(int i = 1; i <= n; i++)
            for(int j = 1; j <= n; j++) minimize(d[i][j], d[i][k] + d[k][j]);

    vector<int> res;
    sort(a + 1, a + n + 1);

}
int32_t main()
{
    FastIO
    freopen("C.INP", "r", stdin);
    freopen("C.OUT", "w", stdout);
    cin >> n >> m >> k;
    for(int i = 1; i <= k; i++) cin >> a[i];
    for(int i = 1; i <= m; i++) {
        int u, v, w;
        cin >> u >> v;
        edges[u].push_back({v, w});
        edges[v].push_back({u, w});
    }


    return 0;
}

/* Author: hxzinh */

