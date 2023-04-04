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

const int NM = 3e5 + 10;
int Sub, n, m, k;
int a[NM], par[NM], high[NM], cnt[NM];
ll d[NM];
vector<pii> edges[NM], trace;
vector<int> id[800005];
bool isHome[NM];

ll result = 0;

void dfs(int u, int p) {
    for(pii nxt : edges[u]) {
        int v = nxt.fi, cost = nxt.se;
        if(v == p) continue;

        d[v] = d[u] + cost;
        high[v] = high[u] + 1;
        dfs(v, u);
    }
}
vector<int> dfs2(int u, int p) {
    vector<int> vec;
    for(int i = 1; i <= cnt[u]; i++) vec.push_back(u);
    for(pii nxt : edges[u]) if(nxt.fi != p) {
        int v = nxt.fi, cost = nxt.se;
        vector<int> tmp = dfs2(v, u);
        for(int h : tmp) {
            if(vec.size()) {
                int x = id[vec.back()].back();
                id[vec.back()].pop_back();

                int y = id[h].back();
                id[h].pop_back();

                trace.push_back({x, y});
                result += d[vec.back()] + d[tmp.back()] - 2 * d[u];

                vec.pop_back();
            } else {
                vec.push_back(h);
            }
        }
    }

    while(vec.size() > 1) {
        int x = vec.back(), idx = id[x].back();
        id[x].pop_back(); vec.pop_back();
        int y = vec.back(), idy = id[y].back();
        id[y].pop_back(); vec.pop_back();

        trace.push_back({idx, idy});
        result += d[x] + d[y] - 2 * d[u];
    }

    return vec;
}
void xuli() {
    d[1] = high[1] = 0;
    dfs(1, -1);

    //for(int i = 1; i <= n; i++) cout << d[i] << '\n';

    dfs2(1, -1);

    cout << result << '\n';
    for(pii u : trace) cout << u.fi << " " << u.se << '\n';
}
int32_t main()
{
    FastIO
    freopen("PARTNER.INP", "r", stdin);
    freopen("PARTNER.OUT", "w", stdout);
    cin >> Sub;
    cin >> n >> m >> k;
    for(int i = 1; i <= m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        edges[u].push_back({v, w});
        edges[v].push_back({u, w});
    }
    for(int i = 1; i <= k; i++) {
        int u; cin >> u;
        isHome[u] = true;
        id[u].push_back(i);
        cnt[u]++;
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
