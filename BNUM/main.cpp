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

const int MOD = 1000000123;
ll n;
int f[100005][2][2][2][2], f[100005][10][2][2];

void add(int &a, int b) {
    if((a += b) >= MOD) a -= MOD;
}
int dp(int i, int ok, int cx, int x, int y) {
    if(i > n) return ((ok || cx) && (!ok || x == 1) && (!cx || y == 0));
    int &res = f[i][ok][cx][x][y];
    if(res > -1) return res;

    res = 0;
    if(ok || cx) {
        add(res, 5LL * dp(i + 1, 1, cx, x ^ 1, y) % MOD);
        add(res, 5LL * dp(i + 1, ok, 1, x, y ^ 1) % MOD);
    }
    else {
        add(res, dp(i + 1, 0, 0, x, y));
        add(res, 5LL * dp(i + 1, 1, 0, x ^ 1, y) % MOD);
        add(res, 4LL * dp(i + 1, 0, 1, x, y ^ 1) % MOD);
    }

    return res;
}
void sub1() {
    memset(f, -1, sizeof f);
    cout << dp(1, 0, 0, 0, 0) << '\n';
}
void xuli() {

}
int32_t main()
{
    FastIO
    freopen("BTY.INP", "r", stdin);
    freopen("BTY.OUT", "w", stdout);
    while(cin >> n) sub1();
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
