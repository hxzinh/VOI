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

const int NM = 3e3 + 10;
int n;
int a[NM], dp[NM][NM], b[NM], cnt[NM];

void xuli() {
    int num = 0;
    sort(a + 1, a + n + 1);
    a[0] = -1;
    for(int i = 1; i <= n; i++) {
        if(a[i] != a[i - 1]) {
            b[++num] = a[i];
            cnt[num] = 1;
        }
        else cnt[num]++;
    }

    memset(dp, INF, sizeof dp);
    dp[0][0] = 0;
    for(int i = 0; i < num; i++) {
        for(int mask = 0; mask < MASK(10); mask++) if(dp[i][mask] < INF) {
            bool ok = true;
            for(int j = 1; j <= 10; j++) if(BIT(mask, j - 1)) {
                int u = b[i + 1] - b[i - j + 1];
                if(u == 1 || u == 8 || u == 9) {
                    ok = false;
                    break;
                }
            }

            int newMask = (mask << 1) & (MASK(10) - 1);
            if(ok) minimize(dp[i + 1][newMask + 1], dp[i][mask]);
            minimize(dp[i + 1][newMask], dp[i][mask] + cnt[i + 1]);
        }
    }

    int res = INF;
    for(int mask = 0; mask < MASK(10); mask++) minimize(res, dp[num][mask]);
    cout << res;
}
int32_t main()
{
    FastIO
    freopen("SEQ198.INP", "r", stdin);
    freopen("SEQ198.OUT", "w", stdout);
    cin >> n;
    for(int i = 1; i <= n; i++) cin >> a[i];

    xuli();
    return 0;
}

/* Author: hxzinh */

