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
int n, T;
pii a[NM];
bool ok[NM];

void xuli() {
    sort(a + 1, a + n + 1);

    int res = 1;
    multiset<int> S;
    S.insert(a[1].se);
    for(int i = 2; i <= n; i++) {
        auto it = S.upper_bound(a[i].se);
        if(it == S.begin()) {
            res++;
            S.insert(a[i].se);
        } else {
            it--;
            S.erase(it);
            S.insert(a[i].se);
        }
    }

    cout << res << '\n';

}
int32_t main()
{
    FastIO
    freopen("MSTICK.INP", "r", stdin);
    freopen("MSTICK.OUT", "w", stdout);
    cin >> T;
    while(T--) {
        cin >> n;
        for(int i = 1; i <= n; i++) cin >> a[i].fi >> a[i].se;

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
