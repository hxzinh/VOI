#include <bits/stdc++.h>
#define ll long long
#define INF 0x3f3f3f3f3f3f3f3f
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
ll n, m, timeHole, timeMove;
ll a[NM];

bool check(ll x) {
    int u = 1;
    for(int i = 1; i <= m; i++) {
        if(u <= a[i]) {
            ll curCost = 1LL * abs(a[i] - u) * timeMove + timeHole;
            ll curDist = 1LL * abs(a[i] - u) * timeMove;
            if(curCost > x) continue;
            u++;

            ll newDist = 0;
            while(curCost + (u > a[i]) * timeMove + timeHole <= x && u <= n) {
                curCost += (u > a[i]) * timeMove + timeHole;
                if(u > a[i]) newDist += timeMove;
                if(curCost + min(newDist, curDist) > x) break;
                u++;
            }
        } else {
            ll curCost = 1LL * abs(a[i] - u) * timeMove + timeHole;
            if(curCost > x) continue;
            u++;

            while(curCost + timeMove + timeHole <= x && u <= n) {
                curCost += timeMove + timeHole;
                u++;
            }
        }
        if(u > n) return true;
    }

    return false;
}
void xuli() {
    sort(a + 1, a + m + 1);

    ll l = 1, r = INF, res = INF;
    while(l <= r) {
        ll m = (l + r) >> 1;
        if(check(m)) {
            res = m;
            r = m - 1;
        } else l = m + 1;
    }

    cout << res;
}
int32_t main()
{
    FastIO
    freopen("HOLES.INP", "r", stdin);
    freopen("HOLES.OUT", "w", stdout);
    cin >> n >> m;
    cin >> timeMove >> timeHole;
    for(int i = 1; i <= m; i++) cin >> a[i];

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
