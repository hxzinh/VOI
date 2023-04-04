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
ll a[NM], weight[NM], s[NM], dp[MASK(17)];

void xuli() {
    for(int i = 1; i <= n; i++) s[i] = s[i - 1] + a[i];

    ll res = -1;
    for(int mask = 0; mask < MASK(m); mask++) {
        for(int i = 1; i <= m; i++) if(!BIT(mask, i - 1)) {
            int l = dp[mask] + 1, r = n, ans = 0;
            while(l <= r) {
                int m = (l + r) >> 1;
                if(s[m] - s[dp[mask]] <= weight[i]) {
                    ans = m;
                    l = m + 1;
                } else r = m - 1;
            }
            if(ans) {
                int newMask = mask | MASK(i - 1);
                maximize(dp[newMask], ans);
            }
        }

        if(dp[mask] == n) {
            ll sum = 0;
            for(int i = 1; i <= m; i++)
                if(!BIT(mask, i - 1)) sum += weight[i];
            maximize(res, sum);
        }
    }

    cout << res;
}
int32_t main()
{
    FastIO
    freopen("TRANSPOR.INP", "r", stdin);
    freopen("TRANSPOR.OUT", "w", stdout);
    cin >> m >> n;
    for(int i = 1; i <= m; i++) cin >> weight[i];
    for(int i = 1; i <= n; i++) cin >> a[i];

    xuli();
    return 0;
}

/* Author: hxzinh */

/*
-----code ko bug-----code ko bug-----code ko bug--------------

          _.-/`)
         // / / )
      .=// / / / )
     //`/ / / / /
    // /     ` /
   ||         /
    \\       /
     ))    .'
    //    /
         /
*/
