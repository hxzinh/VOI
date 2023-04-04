#include <bits/stdc++.h>
#define ll long long
#define int long long
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
int n, k;
int a[NM], b[NM];
int dp[NM][11][11], pw[NM][11];

void xuli() {
    for(int i = 1; i <= n; i++) pw[i][0] = 1;
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= k; j++) pw[i][j] = pw[i][j - 1] * b[i];

    /**
    for(int i = 1; i <= n; i++) {
        for(int j = 0; j <= k; j++) cout << pw[i][j] << " ";
        cout << '\n';
    }
    **/

    memset(dp, -INF, sizeof dp);
    dp[0][0][0] = 0;

    for(int i = 0; i < n; i++) {
        for(int j = 0; j <= k; j++) {
            for(int u = 0; u <= k; u++) if(dp[i][j][u] > -INF) {
                for(int v = 0; v <= k; v++) {
                    int cost = a[i + 1] * pw[i + 1][v];
                    if(v == u) {
                        maximize(dp[i + 1][j][v],
                             max(dp[i][j][u] + cost, cost));
                    }
                    if(v < u) {
                        maximize(dp[i + 1][j][v],
                             max(dp[i][j][u] + cost, cost));
                    }
                    if(v > u && j + v - u <= k) {
                        maximize(dp[i + 1][j + v - u][v],
                             max(dp[i][j][u] + cost, cost));
                    }
                }
            }
        }
    }

    int res = -INF;
    for(int i = 1; i <= n; i++)
        for(int j = 0; j <= k; j++) maximize(res, dp[i][k][j]);
    cout << res;
}
int32_t main()
{
    FastIO
    freopen("KTURN.INP", "r", stdin);
    freopen("KTURN.OUT", "w", stdout);
    cin >> n >> k;
    for(int i = 1; i <= n; i++) cin >> a[i];
    for(int i = 1; i <= n; i++) cin >> b[i];

    xuli();
    return 0;
}

/* Author: hxzinh */


