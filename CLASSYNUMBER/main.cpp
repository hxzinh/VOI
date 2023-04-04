#include <bits/stdc++.h>
#define ll long long
#define INF 0x3f3f3f3f3f3f3f3f
#define pii pair<int, int>
#define mp make_pair
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

int T;
vector<ll> tmp;

void backtrack(int x, int cnt, ll u) {
    if(x == 18) {
        tmp.push_back(u);
        return;
    }

    backtrack(x + 1, cnt, u * 10);
    if(cnt < 3) {
        for(int i = 0; i < 10; i++) {
            backtrack(x + 1, cnt + 1, u * 10 + i);
        }
    }
}
void xuli() {
    backtrack(0, 0, 0);
    tmp.push_back(1000000000000000000);

    sort(ALL(tmp));
    tmp.resize(unique(ALL(tmp)) - tmp.begin());

    while(T--) {
        ll u, v;
        cin >> u >> v;

        ll res = upper_bound(ALL(tmp), v) - lower_bound(ALL(tmp), u);
        cout << res << '\n';
    }
}
int32_t main()
{
    FastIO
    freopen("CODE.INP", "r", stdin);
    freopen("CODE.OUT", "w", stdout);
    cin >> T;

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
