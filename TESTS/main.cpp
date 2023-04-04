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
int n, p, T;

struct Point {
    int x, y;
} a[NM];

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int Random(int l, int r) {
    return uniform_int_distribution<int>(l, r)(rng);
}
bool ccw(Point A, Point B, Point C) {
    return A.x * (B.y - C.y) + B.x * (C.y - A.y) + C.x * (A.y - B.y) == 0;
}
void xuli() {
    for(int i = 1; i <= 100; i++) {
        int u = Random(1, n), v = Random(1, n);
        while(u == v) u = Random(1, n);
        if(a[u].x > a[v].x) swap(u, v);

        int cnt = 0;
        for(int j = 1; j <= n; j++)
            if(ccw(a[u], a[v], a[j])) cnt++;

        if(cnt >= p * n / 100 + ((p * n) % 100 != 0)) {
            cout << "YES" << '\n';
            return;
        }
    }
    cout << "NO" << '\n';
}
int32_t main()
{
    FastIO
    freopen("A.INP", "r", stdin);
    freopen("A.OUT", "w", stdout);
    cin >> T;
    while(T--) {
        cin >> n >> p;
        for(int i = 1; i <= n; i++) {
            int x, y;
            cin >> x >> y;
            a[i] = {x, y};
        }

        xuli();
    }
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
