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

const int NM = 5e4 + 10;
int n, q;
int P[NM][25], high[NM];
pii qr[NM];
vector<int> edges[NM];

struct Data {
    int x, y;
}  a[NM];

void dfs(int u, int p) {
    P[u][0] = p;
    for(int v : edges[u]) if(v != p) {
        high[v] = high[u] + 1;
        dfs(v, u);
    }
}
void init() {
    dfs(1, -1);
    for(int k = 1; k <= 20; k++)
        for(int i = 1; i <= n; i++) P[i][k] = P[P[i][k - 1]][k - 1];
}
int lca(int u, int v) {
    for(int i = 20; i >= 0; i--)
        if(high[P[u][i]] >= high[v]) u = P[u][i];
    for(int i = 20; i >= 0; i--)
        if(high[P[v][i]] >= high[u]) v = P[v][i];

    if(u == v) return u;

    for(int i = 20; i >= 0; i--) {
        if(P[u][i] != P[v][i]) {
            u = P[u][i];
            v = P[v][i];
        }
    }

    return P[u][0];
}
void sub1() {
    for(int i = 1; i <= q; i++) {
        pii u = qr[i];
        cout << lca(u.fi, u.se) << '\n';
    }
}
int32_t main()
{
    FastIO
    freopen("MEETING.INP", "r", stdin);
    freopen("MEETING.OUT", "w", stdout);
    cin >> n >> q;
    for(int i = 1; i <= n; i++) cin >> a[i].x;
    for(int i = 1; i <= n; i++) cin >> a[i].y;
    for(int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        edges[u].push_back(v);
        edges[v].push_back(u);
    }
    for(int i = 1; i <= q; i++) {
        int u, v;
        cin >> u >> v;
        qr[i] = {u, v};
    }

    init();

    sub1();
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
