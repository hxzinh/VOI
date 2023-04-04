#include <bits/stdc++.h>
#define ll long long
#define int long long
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
int a[NM], cnt[NM], high[NM], d[NM], par[NM], child[NM];
vector<pii> edges[NM], trace;
vector<int> id[800005], gr[800005];

void dfs(int u, int p) {
    child[u] = id[u].size();
    for(pii nxt : edges[u]) if(nxt.fi != p) {
        int v = nxt.fi, cost = nxt.se;
        par[v] = u;
        dfs(v, u);
        child[u] += child[v];
    }
}
void dfs2(int u, vector<int> &group) {
    for(int it : id[u]) group.push_back(it);
    for(pii nxt : edges[u]) if(nxt.fi != par[u]) {
        int v = nxt.fi, cost = nxt.se;
        par[v] = u;
        d[v] = d[u] + cost;
        dfs2(v, group);
    }
}
bool check(int u) {
    if(k - child[u] > k / 2) return false;
    for(pii v : edges[u]) if(v.fi != par[u]) {
        if(child[v.fi] > k / 2) return false;
    }
    return true;
}
void xuli() {
    dfs(1, -1);

    int parNode = -1;
    for(int i = 1; i <= n; i++) if(check(i)) {
        if(parNode < 0 || edges[i].size() < edges[parNode].size()) parNode = i;
    }

    par[parNode] = 0;
    gr[parNode] = id[parNode];
    for(pii nxt : edges[parNode]) {
        int v = nxt.fi, cost = nxt.se;
        par[v] = parNode;
        d[v] = cost;
        dfs2(v, gr[v]);
    }

    ll res = 0;
    for(int i = 1; i <= n; i++) res += d[i] * id[i].size();
    cout << res << '\n';

    priority_queue<pii> pq;
    for(int i = 1; i <= n; i++) if(gr[i].size()) {
        pq.push({gr[i].size(), i});
    }

    while(pq.size() > 1) {
        int x = pq.top().se; pq.pop();
        int y = pq.top().se; pq.pop();

        trace.push_back({gr[x].back(), gr[y].back()});
        gr[x].pop_back();
        gr[y].pop_back();

        if (!gr[x].empty()) pq.push(make_pair(gr[x].size(), x));
        if (!gr[y].empty()) pq.push(make_pair(gr[y].size(), y));
    }

    if(pq.size() == 1) {
        for(int i = 0; i < gr[parNode].size() / 2; i++)
        trace.push_back({gr[parNode][2 * i], gr[parNode][2 * i + 1]});
    }

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
        id[u].push_back(i);
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
