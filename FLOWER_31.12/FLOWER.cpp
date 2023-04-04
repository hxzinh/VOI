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

const int NM = 55;
const int MOD = 1e9 + 7;
int n, m, k;
int dp[NM][MASK(4) + 5], f[NM];

void add(int &a, int b) {
    if((a += b) >= MOD) a -= MOD;
}
void xuli() {
    dp[0][0] = 1;
    for(int i = 0; i < m; i++) {
        for(int mask = 0; mask < MASK(4); mask++) {
            for(int j = 0; j < 4; j++) {
                int newMask = mask | MASK(j);
                add(dp[i + 1][newMask], dp[i][mask]);
            }
        }
    }

    int res = 0;
    for(int mask = 0; mask < MASK(4); mask++)
        if(__builtin_popcount(mask) >= k && dp[m][mask]) add(res, dp[m][mask]);

    int ans = 1;
    for(int i = 1; i <= n; i++) ans = 1LL * ans * res % MOD;

    cout << ans;
}
int32_t main()
{
    FastIO
    freopen("FLOWER.INP", "r", stdin);
    freopen("FLOWER.OUT", "w", stdout);
    cin >> n >> m >> k;

    xuli();
    return 0;
}

/* Author: hxzinh */

