#include <bits/stdc++.h>
#define ll long long
#define INF 0x3f3f3f3f
#define pii pair<int, int>
#define mp make_pair
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

const int NM = 5e3 + 10;
int n, m;
int a[NM][NM], Max = -INF, Min = INF;
bool ok[NM][NM];

struct Edge {
    int u, v, cap, flow;
};

struct maxFlow {
    int n, start, target;
    vector<int> d, ptr, q;
    vector<Edge> e;
    vector<vector<int>> g, idx;

    maxFlow(int _n = 0) : n(_n), d(_n), ptr(_n), q(_n), g(_n) {
        e.clear();
        for(int i = 0; i < n; i++) {
            g[i].clear();
            ptr[i] = 0;
        }
        idx.assign(n + 7, vector<int>(n + 7, 0));
    }

    void addEdge(int u, int v, ll cap) {
        Edge e1 = {u, v, cap, 0};
        Edge e2 = {v, u, 0, 0};
        if(!idx[u][v]) {
            idx[u][v] = idx[v][u] = e.size();
            g[u].push_back(e.size());
            e.push_back(e1);
            g[v].push_back(e.size());
            e.push_back(e2);
        } else {
            e[idx[u][v]].cap += cap;
            e[idx[u][v] ^ 1].cap += cap;
        }
    }

    bool bfs() {
        int qh = 0, qt = 0; //first, last
        q[qt++] = start;
        fill(ALL(d), -1);
        d[start] = 0;

        while(qh < qt && d[target] == -1) {
            int v = q[qh++];
            for(int i = 0; i < g[v].size(); i++) {
                int id = g[v][i], to = e[id].v;
                if(d[to] == -1 && e[id].flow < e[id].cap) {
                    q[qt++] = to;
                    d[to] = d[v] + 1;
                }
            }
        }
        return (d[target] != -1);
    }

    int dfs(int u, int flow) {
        if(!flow) return 0;
        if(u == target) return flow;
        for(; ptr[u] < g[u].size(); ptr[u]++) {
            int id = g[u][ptr[u]], to = e[id].v;
            if(d[to] != d[u] + 1) continue;

            int pushed = dfs(to, min(flow, e[id].cap - e[id].flow));
            if(pushed) {
                e[id].flow += pushed;
                e[id ^ 1].flow -= pushed;
                return pushed;
            }
        }
        return 0;
    }

    int getMaxFlow(int _start, int _target) {
        start = _start; target = _target;
        int flow = 0;
        while(bfs()) {
            fill(ALL(ptr), 0);
            while(int pushed = dfs(start, INF)) {
                flow += pushed;
            }
        }
        return flow;
    }
};

bool check(int x) {
    maxFlow graph(2 * n + 5);

    for(int i = 1; i <= n; i++) {
        graph.addEdge(0, i, 1);
        graph.addEdge(i, 2 * n + 1, 1);
    }

    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= n; j++)
            if(a[i][j] <= x) graph.addEdge(i, j + n, a[i][j]);

    int res = graph.getMaxFlow(0, 2 * n + 1);
    return (res == n);
}
void xuli() {
    int l = Min, r = Max, res = INF, k = 2 * n + 1;
    while(l <= r) {
        int m = (l + r) >> 1;
        if(check(m)) {
            res = m;
            r = m - 1;
        } else l = m + 1;
    }

    cout << res;
}
int32_t main()
{
    FastIO
    freopen("FFLOW.INP", "r", stdin);
    freopen("FFLOW.OUT", "w", stdout);
    cin >> n >> m;

    maxFlow graph(2 * n + 5);

    for(int i = 1; i <= m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        ok[u][v] = true;

        graph.addEdge(u, v, w);
    }

    cout << graph.getMaxFlow(1, n);
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
