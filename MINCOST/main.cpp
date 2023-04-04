#include <bits/stdc++.h>
#define ll long long
#define INF 0x3f3f3f3f
#define pii pair<int, int>
#define pll pair<long long, long long>
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

const int NM = 105;
int n, m, k, s, t;

struct Edge {
    int u, v, cap, flow, cost;

    Edge(int _u = 0, int _v = 0, int _cap = 0, int _cost = 0) {
        u = _u; v = _v; cap = _cap; flow = 0; cost = _cost;
    }
};

struct MaxFlowMinCost {
    int n;
    vector<vector<int>> g;
    vector<Edge> e;
    vector<int> d, tr;

    MaxFlowMinCost(int _n = 0) {
        n = _n;
        g.assign(n + 7, vector<int>());
        e.clear();
        d = vector<int>(n + 7, 0);
        tr = vector<int>(n + 7, 0);
    }

    void addEdges(int u, int v, int cap, int cost) {
        g[u].push_back(e.size());
        e.push_back(Edge(u, v, cap, cost));
        g[v].push_back(e.size());
        e.push_back(Edge(v, u, 0, -cost));
    }

    bool FordBellman(int start, int target) {
        for(int i = 1; i <= n; i++) {
            d[i] = INF;
            tr[i] = -1;
        }

        vector<bool> inq(n + 7, 0);
        queue<int> q;

        q.push(start);
        inq[start] = true;
        d[start] = 0;

        while(!q.empty()) {
            int u = q.front();
            q.pop();
            inq[u] = false;

            for(auto id : g[u]) if(e[id].cap > e[id].flow) {
                int v = e[id].v;
                if(minimize(d[v], d[u] + e[id].cost)) {
                    tr[v] = id;
                    if(!inq[v]) {
                        q.push(v);
                        inq[v] = true;
                    }
                }
            }
        }

        return (d[target] < INF);
    }

    pll getFlow(int start, int target) {
        ll totalFlow = 0, totalCost = 0;
        while(FordBellman(start, target)) {
            ll delta = INF;
            for(int u = target; u != start; u = e[tr[u]].u) minimize(delta, e[tr[u]].cap - e[tr[u]].flow);
            for(int u = target; u != start; u = e[tr[u]].u) {
                e[tr[u]].flow += delta;
                e[tr[u] ^ 1].flow -= delta;
            }
            totalFlow += delta;
            totalCost += 1LL * delta * d[target];
        }
        return make_pair(totalFlow, totalCost);
    }

};

int32_t main()
{
    FastIO
    freopen("MINCOST.INP", "r", stdin);
    freopen("MINCOST.OUT", "w", stdout);
    cin >> n >> m >> k >> s >> t;

    MaxFlowMinCost graph(n + 7);

    for(int i = 1; i <= m; i++) {
        int u, v, cost, cap;
        cin >> u >> v >> cost >> cap;
        graph.addEdges(u, v, cap, cost);
        graph.addEdges(v, u, cap, cost);
    }
    graph.addEdges(n + 1, s, k, 0);

    pll res = graph.getFlow(n + 1, t);

    if(res.fi < k) {
        cout << -1;
        return 0;
    }

    cout << res.se << '\n';
    for(int i = 0; i < graph.e.size(); i += 2) if(graph.e[i].flow > 0) {
        if(graph.e[i].u <= n) cout << graph.e[i].u << " " << graph.e[i].v << " " << graph.e[i].flow << '\n';
    }
    cout << "0 0 0";

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
