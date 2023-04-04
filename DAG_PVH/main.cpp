
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

const int NM = 5e5 + 10;
int n, m;
int cnt = 0, numEdges = 0;
int ans[NM], visited[NM];
bool cx[NM], used[NM];

struct Data {
    int v, id;
};
vector<Data> edges[NM];

void dfs(int u) {
    if(visited[u] >= cnt || edges[u].empty()) return;
    cx[u] = true;
    visited[u] = cnt;
    for(Data x : edges[u]) if(!cx[x.v] && !used[x.id]) {
        used[x.id] = true;
        ans[x.id] = cnt;
        numEdges++;
        dfs(x.v);
    }
    cx[u] = false;
}
void xuli() {
    while(numEdges < m) {
        cnt++;
        for(int i = 1; i <= n; i++) dfs(i);
    }

    cout << cnt << '\n';
    for(int i = 1; i <= m; i++) cout << ans[i] << ' ';
}
int32_t main()
{
    FastIO
    freopen("DAG.INP", "r", stdin);
    freopen("DAG.OUT", "w", stdout);
    cin >> n >> m;
    for(int i = 1; i <= m; i++) {
        int u, v;
        cin >> u >> v;

        if(u == v) {
            cout << -1;
            return 0;
        }

        edges[u].push_back({v, i});
    }

    xuli();
    return 0;
}

/* Author: hxzinh */


