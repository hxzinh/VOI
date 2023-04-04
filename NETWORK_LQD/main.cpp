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
int n, k, m;
int Time = 0, numBigger = 0;
int a[NM], high[NM], sz[NM], e[NM];
vector<int> edges[NM], group[NM], ans[NM], G[NM];
bool cx[NM];

void dfs(int u, int p) {
    cx[u] = true;
    for(int v : edges[u]) if(v != p && !cx[v]) {
        high[v] = high[u] + 1;
        ans[u].push_back(v);
        G[u].push_back(v);
        G[v].push_back(u);
        dfs(v, u);
    }
}
void dfs2(int u, int p) {
    for(int v : G[u]) if(v != p) {
        high[v] = high[u] + 1;
        dfs2(v, u);
    }
}
void sub2() {
    ll res = (k - 1) * n;
    for(int i = 1; i <= k; i++) res += (sz[i] - 1) * n;

    dfs(1, -1);
    int maxHigh = -1, parNode = 1, lastNode = 1;
    for(int i = 1; i <= k; i++)
        if(high[i] > high[parNode]) parNode = i;
    for(int i = 1; i <= k; i++) high[i] = 0;
    dfs2(parNode, -1);
    for(int i = 1; i <= k; i++)
        if(maximize(maxHigh, high[i])) lastNode = i;
    maxHigh += (sz[lastNode] > 1 ? 1 : 0) + (sz[parNode] > 1 ? 1 : 0);
    res += maxHigh;


    cout << res << '\n';
    //if((res - maxHigh) / n > 100000) return;
    for(int i = 1; i <= k; i++)
        for(int j = 1; j < group[i].size(); j++)
            cout << group[i][0] << " " << group[i][j] << '\n';

    for(int i = 1; i <= k; i++)
        for(int v : ans[i]) cout << group[i][0] << " " << group[v][0] << '\n';
}
int32_t main()
{
    FastIO
    freopen("NETWORK.INP", "r", stdin);
    freopen("NETWORK.OUT", "w", stdout);
    cin >> n >> k >> m;
    for(int i = 1; i <= n; i++) cin >> a[i];
    for(int i = 1; i <= k; i++) {
        int num; cin >> num;
        sz[i] = num;
        if(sz[i] > 1) numBigger++;
        for(int j = 1; j <= num; j++) {
            int u; cin >> u;
            group[i].push_back(u);
        }
    }
    for(int i = 1; i <= m; i++) {
        int u, v;
        cin >> u >> v;
        edges[u].push_back(v);
        edges[v].push_back(u);
    }

    sub2();
    return 0;
}

/* Author: hxzinh */

