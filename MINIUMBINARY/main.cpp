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
int e[NM], ans[NM];
pii a[NM];
vector<pii> edges[NM];

void dfs(int u, int p) {
    for(pii x : edges[u]) {
        int v = x.fi, t = x.se;
        if(ans[v] == -1) {
            ans[v] = (t ? (ans[u] ^ 1) : ans[u]);
            dfs(v, u);
        } else
            if((t && ans[u] == ans[v]) || (!t && ans[u] != ans[v])) {
                cout << -1;
                exit(0);
            }
    }
}
void xuli() {
    memset(ans, -1, sizeof ans);

    for(int i = 1; i <= n; i++) if(ans[(i + 1) / 2] == -1) {
        ans[(i + 1) / 2] = 0;
        dfs((i + 1) / 2, -1);
    }

    for(int i = 1; i <= n; i++) {
        if(!ans[(i + 1) / 2]) {
            if(i & 1) cout << 0;
            else cout << 1;
        } else {
            if(i & 1) cout << 1;
            else cout << 0;
        }
    }
}
int32_t main()
{
    FastIO
    freopen("MINIUMBINARY.INP", "r", stdin);
    freopen("MINIUMBINARY.OUT", "w", stdout);
    cin >> n >> m;
    for(int i = 1; i <= m; i++) {
        cin >> a[i].fi >> a[i].se;

        int u = (a[i].fi + 1) / 2, v = (a[i].se + 1) / 2;
        if(u == v) {
            cout << -1;
            return 0;
        }

        int t = (a[i].fi % 2) != (a[i].se % 2);
        edges[u].push_back({v, t});
        edges[v].push_back({u, t});
    }

    xuli();
    return 0;
}

/* Author: hxzinh */


