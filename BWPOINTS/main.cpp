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
int a[NM], b[NM], f[NM];

void xuli() {
    vector<pii> vec;
    for(int i = 1; i <= n; i++) {
        vec.push_back({a[i], 1});
        vec.push_back({b[i], 2});
    }
    sort(ALL(vec));

    int res = 0;
    pii cur = {0, 0};
    for(int i = 0; i < vec.size(); i++) {
        if(!cur.fi) {
            cur.fi++;
            cur.se = vec[i].se;
        } else {
            if(cur.se != vec[i].se) {
                res++;
                cur = {0, 0};
            }
        }
    }

    cout << res;
}
int32_t main()
{
    FastIO
    freopen("BWPOINTS.INP", "r", stdin);
    freopen("BWPOINTS.OUT", "w", stdout);
    cin >> n;
    for(int i = 1; i <= n; i++) cin >> a[i];
    for(int i = 1; i <= n; i++) cin >> b[i];

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
