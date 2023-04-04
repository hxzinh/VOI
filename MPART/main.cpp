#include <bits/stdc++.h>
#define ll long long
#define INF 0x3f3f3f3f
#define pii pair<int, int>
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

// END OF TEMPLATE
/* Author: hxzinh */


const int NM = 1e3 + 10;
int n, m, curCnt = 0, idLast = 0;
int id[NM];
string name[NM];
map<string, int> mp;
vector<int> adj[NM];

struct Edge {
    int u, v, cap, flow;

    Edge(int _u = 0, int _v = 0, int _cap = 0, int _flow = 0) {
        u = _u; v = _v; cap = _cap; flow = _flow;
    }
};

struct maxFlow {
    int n, start, target;
    vector<int> d, ptr;
    vector<Edge> e;
    vector<vector<int>> g;

    maxFlow(int _n = 0) {
        n = _n;
        d = vector<int>(n + 7, 0);
        g.assign(n + 7, vector<int>());
        e.clear();
        ptr = vector<int>(n + 7, 0);
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
        queue<int> q;
        q.push(start);
        fill(ALL(d), -1);
        d[start] = 0;

        while(q.size() && d[target] == -1) {
            int u = q.front();
            q.pop();

            for(int id : g[u]) {
                int v = e[id].v;
                if(d[v] == -1 && e[id].flow < e[id].cap) {
                    q.push(v);
                    d[v] = d[u] + 1;
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

bool check(int x) {
    graph = maxFlow(2 * n + 7);

    for(int i = 1; i <= n; i++) graph.addEdge(0, i, 1);
    for(int i = 1; i <= n; i++)
        for(int v : adj[i]) graph.addEdge(i, v + n, 1);

    idLast = graph.e.size();
    for(int i = n + 1; i <= n + m; i++) {
        graph.addEdge(i, n + m + 1, x);
    }
    /**
    for(int i = idLast; i < graph.e.size(); i++) {
        Edge cur = graph.e[i];
        cout << cur.u << " " << cur.v << " " << cur.cap << " " << cur.flow << '\n';
    }
    cout << '\n';
    **/

    int res = graph.getMaxFlow(0, n + m + 1);
    if(res < n) return false;
    else return true;
}
void xuli() {
    int l = 1, r = n, res = 0;
    while(l <= r) {
        int m = (l + r) >> 1;
        if(check(m)) {
            res = m;
            r = m - 1;
        } else l = m + 1;
    }

    cout << res << '\n';
}
void test() {
    for(int i = 1; i <= n; i++) {
        for(int u : adj[i]) cout << u << " ";
        cout << '\n';
    }
    cout << '\n';
}
int32_t main()
{
    FastIO
    freopen("MPART.INP", "r", stdin);
    freopen("MPART.OUT", "w", stdout);
    while(cin >> n >> m) {
        if(!n && !m) break;
        mp.clear();

        for(int i = 1; i <= n; i++) {
            string s;
            cin >> s;

            adj[i].clear();
            if(!mp[s]) mp[s] = ++curCnt;
            id[i] = mp[s];

            getline(cin, s);

            stringstream ss(s);
            int u;
            while(ss >> u) adj[i].push_back(u + 1);
        }

        xuli();
    }
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
