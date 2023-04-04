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
int a[NM];
pll f[NM];
vector<pii> edges[NM];

struct Data {
    ll u, cost, cake;

    bool inline operator < (const Data A) const {
        return (cost == A.cost) ? cake < A.cake : cost > A.cost;
    }
};

void xuli() {
    for(int i = 1; i <= n; i++) f[i] = {INF, -1};
    priority_queue<Data> pq;

    f[1] = {0, 0};
    pq.push({1, 0, a[1]});

    while(pq.size()) {
        ll u = pq.top().u, cost = pq.top().cost, cake = pq.top().cake;
        pq.pop();

        if(cost != f[u].fi) continue;
        if(cake < f[u].se) continue;

        for(pii x : edges[u]) {
            int v = x.fi, w = x.se;
            if(f[v].fi == cost + w) {
                maximize(f[v].se, cake + a[v]);
                pq.push({v, cost + w, cake + a[v]});
            }
            else
            if(minimize(f[v].fi, cost + w)) {
                f[v].se = cake + a[v];
                pq.push({v, cost + w, cake + a[v]});
            }
        }
    }

    if(f[n].fi < INF) cout << f[n].fi << ' ' << f[n].se;
    else cout << "impossible";
}
int32_t main()
{
    FastIO
    freopen("QUANHO.INP", "r", stdin);
    freopen("QUANHO.OUT", "w", stdout);
    cin >> n;
    for(int i = 1; i <= n; i++) cin >> a[i];
    cin >> m;
    for(int i = 1; i <= m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        edges[u].push_back({v, w});
        edges[v].push_back({u, w});
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
