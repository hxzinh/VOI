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

const int NM = 1e6 + 10;
int n, q;
int a[NM], M[NM];

void xuli() {
    vector<int> vec;
    for(int i = 1; i <= n; i++) vec.push_back(a[i]);
    sort(ALL(vec));
    vec.resize(unique(ALL(vec)) - vec.begin());

    memset(M, INF, sizeof M);
    for(int i = 1; i <= n; i++) {
        a[i] = lower_bound(ALL(vec), a[i]) - vec.begin() + 1;
        if(M[a[i]] == INF) M[a[i]] = i;
    }
    vec.push_back(INF);
    for(int i = 1; i <= n + 1; i++) minimize(M[i], M[i - 1]);

    while(q--) {
        int u; cin >> u;

        int it = upper_bound(ALL(vec), u) - vec.begin();
        cout << M[it] << '\n';
    }

}
int32_t main()
{
    FastIO
    freopen("MINPOS.INP", "r", stdin);
    freopen("MINPOS.OUT", "w", stdout);
    cin >> n;
    for(int i = 1; i <= n; i++) cin >> a[i];
    cin >> q;

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
