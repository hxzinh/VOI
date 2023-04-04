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

const int NM = 5e4 + 10;
const int MOD = 1e9 + 7;
int n, q;
int a[NM], dp[1005][1005];

void add(int &a, int b) {
    if(a + b >= MOD) a += b - MOD;
    else a += b;
}
void sub1() {
    while(q--) {
        int type, l, r, sum;
        cin >> type;
        if(type == 1) {
            cin >> l >> sum;
            a[l] = sum;
        } else {
            cin >> l >> r >> sum;
            int res = 0;
            for(int mask = 0; mask < MASK(n); mask++) {
                int curXor = 0;
                bool ok = true;
                for(int i = 1; i <= n; i++) if(BIT(mask, i - 1)) {
                    if(i < l || i > r) {
                        ok = false;
                        break;
                    }
                    curXor ^= a[i];
                }
                if(ok && curXor == sum) res++;
            }


            cout << res << '\n';
        }
    }
}
void sub2() {
    dp[0][0] = 1;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j <= 1000; j++) if(dp[i][j]) {
            add(dp[i + 1][j ^ a[i + 1]], dp[i][j]);
            add(dp[i + 1][j], dp[i][j]);
        }
    }

    while(q--) {
        int type, u, v, sum;
        cin >> type >> u >> v >> sum;
        if(sum > 1000) cout << 0 << '\n';
        else cout << dp[v][sum] << '\n';
    }
}
int32_t main()
{
    FastIO
    freopen("XORSEG.INP", "r", stdin);
    freopen("XORSEG.OUT", "w", stdout);
    cin >> n >> q;
    for(int i = 1; i <= n; i++) cin >> a[i];

    if(n <= 20) sub1();
    else sub2();
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
