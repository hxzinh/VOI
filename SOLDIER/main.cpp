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

const int NM = 5e3 + 10;
ll n, k, mx = INF;
int ans[NM], dp[505][505];
pll a[NM];

struct FenwickTree {
    int n;
    vector<int> val;
};

void sub1() {
    for(int i = 1; i <= n; i++) ans[i] = 1;

    for(int mask = 0; mask < MASK(n); mask++) {
        ll sum = 0;
        for(int i = 1; i <= n; i++) if(BIT(mask, i - 1)) sum += a[i].fi;

        for(int i = 1; i <= n; i++) if(BIT(mask, i - 1)) {
            if(sum - a[i].fi >= k) ans[i] = 0;
        }
    }

    for(int i = 1; i <= n; i++) cout << ans[i];
}
void sub2() {
    for(int i = 1; i <= n; i++) {
        memset(dp, 0, sizeof dp);
        dp[0][0] = 1;
        for(int j = 0; j < n; j++) {
            for(int sum = 0; sum < k; sum++) if(dp[j][sum]) {
                if(sum + a[j + 1].fi < k && j + 1 != i) dp[j + 1][sum + a[j + 1].fi] = 1;
                dp[j + 1][sum] = 1;
            }
        }

        for(int sum = k - 1; sum > 0; sum--) {
            if(dp[n][sum]) {
                if(sum + a[i].fi >= k) ans[i] = 1;
                break;
            }
        }
    }

    for(int i = 1; i <= n; i++) cout << ans[i];
}
void xuli() {

}
int32_t main()
{
    FastIO
    freopen("SOLDIER.INP", "r", stdin);
    freopen("SOLDIER.OUT", "w", stdout);
    cin >> n >> k;
    for(int i = 1; i <= n; i++) {
        cin >> a[i].fi;
        a[i].se = i;
        minimize(mx, a[i].fi);
    }

    if(mx >= k) {
        for(int i = 1; i <= n; i++) cout << 1;
        return 0;
    }

    sub2();
    return 0;
}

/* Author: hxzinh */


