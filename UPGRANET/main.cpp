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

const int NM = 1e5 + 10;
int n, m;
int par[NM];

struct Data {
    int u, v, w;
} e[NM];

vector<pii> edges[NM];

int root(int x) {
    if(par[x] < 0) return x;
    return par[x] = root(par[x]);
}
bool join(int u, int v) {
    u = root(u); v = root(v);
    if(u == v) return false;

    if(par[u] > par[v]) swap(u, v);
    par[u] += par[v];
    par[v] = u;
    return true;
}
void dfs(int u, int p) {

}
void init() {

}
void xuli() {
    sort(e + 1, e + m + 1, [](const Data A, const Data B){
            return A.w < B.w;
    });

    for(int i = 1; i <= m; i++) {
        int u = e[i].u, v = e[i].v, cost = e[i].w;
        cout << u << " " << v << " " << cost << '\n';
    }
    cout << '\n';

    memset(par, -1, sizeof par);
    int cntEdges = 0, maxCost = -1;
    vector<int> vec;

    for(int i = 1; i <= m; i++) {
        int u = e[i].u, v = e[i].v, cost = e[i].w;
        if(join(u, v)) {
            cout << u << " " << v << " " << cost << '\n';
            vec.push_back(cost);
            edges[u].push_back({v, cost});
            edges[v].push_back({u, cost});
            maximize(maxCost, cost);
            cntEdges++;
        }
        if(cntEdges == n - 1) break;
    }

    init();

    int res = 0;
    for(int u : vec) res += maxCost - u;
    cout << res;
}
int32_t main()
{
    FastIO
    freopen("UPGRANET.INP", "r", stdin);
    freopen("UPGRANET.OUT", "w", stdout);
    cin >> n >> m;
    for(int i = 1; i <= m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        e[i] = {u, v, w};
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
