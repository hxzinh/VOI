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

const int NM = 1e3 + 10;
int n, m, k;
int f[NM][NM];
vector<pii> edges[NM];

struct Data {
    int u, numOda, cost;

    bool inline operator < (const Data &A) const {
        return cost > A.cost;
    }
};

void xuli() {
    memset(f, INF, sizeof f);
    priority_queue<Data> pq;
    f[1][0] = 0;

    pq.push({1, 0, 0});
    while(pq.size()) {
        int u = pq.top().u, numOda = pq.top().numOda, cost = pq.top().cost;
        pq.pop();

        if(cost != f[u][numOda]) continue;
        if(u == n) continue;

        for(pii cur : edges[u]) {
            int v = cur.fi, w = cur.se;
            if(minimize(f[v][numOda], max(cost, w)))
                pq.push({v, numOda, f[v][numOda]});
            if(numOda + 1 <= k) {
                if(minimize(f[v][numOda + 1], cost))
                    pq.push({v, numOda + 1, f[v][numOda + 1]});
            }
        }
    }

    if(f[n][k] < INF) cout << f[n][k];
    else cout << -1;
}
int32_t main()
{
    FastIO
    freopen("ODAROAD.INP", "r", stdin);
    freopen("ODAROAD.OUT", "w", stdout);
    cin >> n >> m >> k;
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
