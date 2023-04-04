#include <bits/stdc++.h>
#define ll long long
#define INF 0x3f3f3f3f3f3f3f3f
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
int n, m;
ll s[NM], M[NM][22];

struct Data {
    ll L, R, cost;
} a[NM];

void init() {
    for(int i = 1; i <= n; i++) M[i][0] = s[i];

    for(int k = 1; MASK(k) <= n; k++)
        for(int i = 1; i + MASK(k) - 1 <= n; i++) M[i][k] = max(M[i][k - 1], M[i + MASK(k - 1)][k - 1]);
}
ll getMax(int u, int v) {
    if(v < u) return 0;
    ll k = log2(v - u + 1);
    return max(M[u][k], M[v - MASK(k) + 1][k]);
}
void xuli() {
    s[0] = 0;
    for(int i = 1; i <= n; i++) s[i] += s[i - 1];
    init();

    ll res = INF;
    for(int i = 1; i <= m; i++) {
        ll ans = max(getMax(1, a[i].L - 1), getMax(a[i].R + 1, n));
        minimize(res, max(ans, getMax(a[i].L, a[i].R) - a[i].cost));
    }
    cout << res;
}
int32_t main()
{
    FastIO
    freopen("SEQGAME.INP", "r", stdin);
    freopen("SEQGAME.OUT", "w", stdout);
    cin >> n >> m;
    for(int i = 1; i <= m; i++) {
        ll u, v, w;
        cin >> u >> v >> w;
        a[i] = {u, v, w};
        s[u] += w; s[v + 1] -= w;
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
