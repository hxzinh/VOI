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

long long calcVND(long long u)
{
    if (u <= 100) return u * 200;
    if (u <= 10000) return calcVND(100) + (u - 100) * 300;
    if (u <= 1000000) return calcVND(10000) + (u - 10000) * 500;
    return calcVND(1000000) + (u - 1000000) * 700;
}

long long calcKWh(long long u)
{
    if (calcVND(100) >= u) return u / 200;
    if (calcVND(10000) >= u) return 100 + (u - calcVND(100)) / 300;
    if (calcVND(1000000) >= u) return 10000 + (u - calcVND(10000)) / 500;
    return 1000000 + (u - calcVND(1000000)) / 700;
}

void xuli() {
    int u = calcKWh(n), l = 0, r = u, res = 0;
    while(l <= r) {
        int m = (l + r) >> 1;
        if(calcVND(u - m) - calcVND(m) >= k) {
            res = m;
            l = m + 1;
        } else r = m - 1;
    }

    cout << calcVND(res);
}
int32_t main()
{
    FastIO
    freopen("BILL.INP", "r", stdin);
    freopen("BILL.OUT", "w", stdout);
    cin >> n >> k;

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
