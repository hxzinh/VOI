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

const int NM = 505;
int n, m;
int a[NM];
string c[NM];

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

            for(int id : g[u]) if(e[id].cap > e[id].flow) {
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

    pii getFlow(int start, int target) {
        int totalFlow = 0, totalCost = 0;
        while(FordBellman(start, target)) {
            int delta = INF;
            for(int u = target; u != start; u = e[tr[u]].u) minimize(delta, e[tr[u]].cap - e[tr[u]].flow);
            for(int u = target; u != start; u = e[tr[u]].u) {
                e[tr[u]].flow += delta;
                e[tr[u] ^ 1].flow -= delta;
            }
            totalFlow += delta;
            totalCost += delta * d[target];
        }
        return make_pair(totalFlow, totalCost);
    }
};

bool check() {
    int cnt = 0;
    vector<bool> ok(m + 7, 0);

    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) if(c[i][j] == 'Y') {
            if(!ok[j]) cnt++;
            ok[j] = true;
        }
    }

    return (cnt == m);
}
void xuli() {
    MaxFlowMinCost graph(n + m + 7);
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) if(c[i][j] == 'Y') {
            ll cost = a[i] * (j - 1) * (j - 1);
            graph.addEdges(i, j + n, 1, cost);
        }
    }

    for(int i = 1; i <= n; i++) {
        graph.addEdges(m + n + 1, i, m, 0);
        graph.addEdges(i + n, m + n + 2, 1, 0);
    }

    pii res = graph.getFlow(m + n + 1, m + n + 2);

    //cout << res.fi << " " << res.se << '\n';

    if(res.fi < m) {
        cout << -1;
        return;
    }
    cout << res.se;
}
int32_t main()
{
    FastIO
    freopen("COST.INP", "r", stdin);
    freopen("COST.OUT", "w", stdout);
    cin >> n;
    for(int i = 1; i <= n; i++) cin >> a[i];

    for(int i = 1; i <= n; i++) {
        cin >> c[i];
        if(!m) m = c[i].size();
        c[i] = '#' + c[i];
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
