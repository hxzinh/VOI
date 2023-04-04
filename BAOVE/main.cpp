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

struct Edge {
    int u, v, cap, flow;
};

struct maxFlow {
    int n, start, target;
    vector<int> d, ptr, q;
    vector<Edge> e;
    vector<vector<int>> g;

    maxFlow(int _n = 0) : n(_n), d(_n), ptr(_n), q(_n), g(_n) {
        e.clear();
        for(int i = 0; i < n; i++) {
            g[i].clear();
            ptr[i] = 0;
        }
    }

    void addEdge(int u, int v, ll cap) {
        Edge e1 = {u, v, cap, 0};
        Edge e2 = {v, u, 0, 0};
        g[u].push_back(e.size());
        e.push_back(e1);
        g[v].push_back(e.size());
        e.push_back(e2);
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
} graph;


void xuli() {
    cout << graph.getMaxFlow(n, 1);
}
int32_t main()
{
    FastIO
    freopen("BAOVE.INP", "r", stdin);
    freopen("BAOVE.OUT", "w", stdout);
    int start, target;
    cin >> n;

    graph = maxFlow(n + 5);

    int u, v, w;
    while(cin >> u >> v >> w) {
        graph.addEdge(u, v, w);
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
