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

const int NM = 2e3 + 10;
int n;
int a[NM], s[NM];
int dp[NM][NM], opt[NM][NM];

int solve(int x, int y) {
    if(x == y) return 0;
    if(x > y || x > n || y <= 0) return INF;
    int &res = dp[x][y];
    if(res != -1) return res;

    res = 0;
    for(int i = x; i < y; i++) {
        maximize(res, min(s[i] - s[x - 1] + solve(x, i),
                          s[y] - s[i] + solve(i + 1, y)));
    }

    return res;
}
void sub1() {
    memset(dp, -1, sizeof dp);
    //cout << solve(1, n);

    for(int i = 1; i <= n; i++) dp[i][i] = 0;
    for(int i = 1; i <= n; i++) {
        for(int j = i - 1; j > 0; j--) {
            for(int k = j; k < i; k++) {
                maximize(dp[j][i], min(s[k] - s[j - 1] + dp[j][k],
                                       s[i] - s[k] + dp[k + 1][i]));
            }
        }
    }

    cout << dp[1][n];
}
void xuli() {
    memset(dp, -1, sizeof dp);
    for(int i = 1; i <= n; i++) {
        dp[i][i] = 0;
        opt[i][i] = i;
    }

    for(int i = n; i > 0; i--) {
        for(int j = i + 1; j <= n; j++) {
            int ans = -INF;
            for(int k = opt[i][j - 1]; k <= min(j - 1, opt[i + 1][j]); k++) {
                int cur = min(s[k] - s[i - 1] + dp[i][k], s[j] - s[k] + dp[k + 1][j]);
                if(ans <= cur) {
                    opt[i][j] = k;
                    ans = cur;
                }
            }

            dp[i][j] = ans;
        }
    }

    cout << dp[1][n];
}
int32_t main()
{
    FastIO
    freopen("DTGAME.INP", "r", stdin);
    freopen("DTGAME.OUT", "w", stdout);
    cin >> n;
    for(int i = 1; i <= n; i++) cin >> a[i];
    for(int i = 1; i <= n; i++) s[i] = s[i - 1] + a[i];

    xuli();
    return 0;
}

/* Author: hxzinh */

