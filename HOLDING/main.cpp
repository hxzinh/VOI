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

const int NM = 102;
int n, L, R, k;
int a[NM];
int dp[2][NM][10005];

void xuli() {
    int res = 0;
    for(int i = L; i <= R; i++) res += a[i];

    memset(dp, INF, sizeof dp);
    dp[(L - 1) & 1][0][0] = res;

    for(int i = L - 1; i < R; i++) {
        for(int j = 0; j <= n; j++) {
            for(int u = 0; u <= k; u++) if(dp[i & 1][j][u] < INF) {
                minimize(dp[(i + 1) & 1][j][u], dp[i & 1][j][u]);
                for(int v = j + 1; v <= n; v++) if(v < L || v > R) {
                    int cost = u + abs(v - (i + 1));
                    if(cost <= k) minimize(dp[(i + 1) & 1][v][cost], dp[i & 1][j][u] - a[i + 1] + a[v]);
                }
            }
        }
    }

    for(int i = 1; i <= n; i++)
        for(int u = 0; u <= k; u++) minimize(res, dp[R & 1][i][u]);

    cout << res;
}
int32_t main()
{
    FastIO
    freopen("HOLDING.INP", "r", stdin);
    freopen("HOLDING.OUT", "w", stdout);
    cin >> n >> L >> R >> k;
    for(int i = 1; i <= n; i++) cin >> a[i];

    xuli();
    return 0;
}

/* Author: hxzinh */
