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

const int NM = 3e5 + 10;
const int MOD = 1e9 + 7;
int n, m, numEdges = 0, numAlone = 0;
int h[NM], dp[500005][2];
vector<int> edges[NM];
map<pii, int> mp;

struct Data {
    int u, v, w, cnt;
} e[500005];

void add(int &a, int b) {
    if((a += b) >= MOD) a -= MOD;
}
bool cmp(const Data A, const Data B) {
    return A.w < B.w;
}
bool cmp2(const int A, const int B) {
    return e[A].w > e[B].w;
}
void xuli() {
    sort(e + 1, e + numEdges + 1, cmp);
    for(int i = 1; i <= m; i++) {
        e[i].cnt = mp[{e[i].u, e[i].v}];
        edges[e[i].v].push_back(i);
    }
    for(int i = 1; i <= n; i++) sort(ALL(edges[i]), cmp2);

    for(int i = 1; i <= numEdges; i++) {
        dp[i][0] = 2;
        dp[i][1] = e[i].cnt;

        //cout << e[i].u << " " << e[i].v << " " << e[i].w << " " << e[i].cnt << '\n';
    }

    for(int i = 1; i <= numEdges; i++) if(dp[i][0] > 0) {
        int u = e[i].u;
        while(edges[u].size() && edges[u].back() < i) edges[u].pop_back();

        for(int j : edges[u]) if(e[j].w > e[i].w) {
            int v = e[j].u;
            if(maximize(dp[j][0], dp[i][0] + 1)) {
                dp[j][1] = 1LL * dp[i][1] * e[j].cnt % MOD;
            }
            else if(dp[j][0] == dp[i][0] + 1) {
                add(dp[j][1], 1LL * dp[i][1] * e[j].cnt % MOD);
            }
        }
    }

    int res = 1, ans = n;
    for(int i = 1; i <= numEdges; i++) {
        if(maximize(res, dp[i][0])) ans = dp[i][1];
        else if(res == dp[i][0]) add(ans, dp[i][1]);
    }

    cout << res << '\n' << ans;
}
int32_t main()
{
    FastIO
    freopen("DINCPATH.INP", "r", stdin);
    freopen("DINCPATH.OUT", "w", stdout);
    cin >> n >> m;
    for(int i = 1; i <= n; i++) cin >> h[i];
    for(int i = 1; i <= m; i++) {
        int u, v, w;
        cin >> u >> v;

        if(u == v || h[u] == h[v]) continue;

        if(h[u] < h[v]) swap(u, v);
        w = h[u] - h[v];

        mp[{u, v}]++;
        if(mp[{u, v}] == 1) e[++numEdges] = {u, v, w};
    }

    xuli();
    return 0;
}

/* Author: hxzinh */

