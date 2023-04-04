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

ll T, n, m;

void sub1() {
    int res = 0;
    for(int i = 1; i <= n; i++)
        for(int j = i + 1; j <= n; j++)
            if((i + j) % m == 0) res++;

    cout << res << '\n';
}
bool check(int x) {
    int y = m - x;
    return (y <= n && x < y);
}
void xuli() {
    ll res = 0;
    for(int i = m; i <= 2 * n - 1; i += m) {
        ll l = i / 2, r = (i + 1) / 2;
        if(l == r) {
            l--; r++;
        }
        res += min(l, n - r + 1);
    }

    cout << res << '\n';
}
int32_t main()
{
    FastIO
    freopen("NPAIRS.INP", "r", stdin);
    freopen("NPAIRS.OUT", "w", stdout);
    cin >> T;
    while(T--) {
        cin >> n >> m;
        xuli();
    }
    return 0;
}

/* Author: hxzinh */

