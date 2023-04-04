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
int n;
int a[NM], f[NM];

struct FenwickTree {
    int n;
    vector<int> val;

    FenwickTree(int _n = 0) {
        n = _n;
        val.assign(n + 7, 0);
    }

    void update(int u, int x) {
        for(; u <= n; u += u & -u) maximize(val[u], x);
    }

    int getMax(int u) {
        int res = 0;
        for(; u > 0; u -= u & -u) maximize(res, val[u]);
        return res;
    }
};

void xuli() {
    FenwickTree tree(n);

    //for(int i = 1; i <= n; i++) cout << a[i] << " ";

    for(int i = 1; i <= n; i++) {
        f[i] = tree.getMax(a[i]) + 1;
        int cur = f[i], tmp = a[i];
        tree.update(a[i], f[i]);
    }

    int res = n - f[n];
    cout << res;
}
int32_t main()
{
    FastIO
    freopen("NUMLOCK.INP", "r", stdin);
    freopen("NUMLOCK.OUT", "w", stdout);
    cin >> n;
    for(int i = 1; i <= n; i++) cin >> a[i];

    vector<int> vec;
    for(int i = 1; i <= n; i++) vec.push_back(a[i]);
    sort(ALL(vec));
    vec.resize(unique(ALL(vec)) - vec.begin());
    for(int i = 1; i <= n; i++) a[i] = lower_bound(ALL(vec), a[i]) - vec.begin() + 1;

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
