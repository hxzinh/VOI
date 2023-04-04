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
int n, k;
pii a[NM];
ll sum[NM], t[NM];

bool check(int x, int u) {
    for(int i = 30; i >= u; i--)
        if(BIT(k, i) < BIT(a[x].fi, i)) return false;
    return true;
}
void xuli() {
    int pre = 0;
    for(int i = 30; i >= 0; i--) {
        for(int j = 1; j <= n; j++) {
            if(BIT(k, i) > BIT(a[j].fi, i))
                if(check(j, i + 1)) sum[i] += a[j].se;
        }
    }

    ll res = 0;
    for(int i = 1; i <= n; i++)
        if((k | a[i].fi) == k) res += a[i].se;

    for(int i = 0; i <= 30; i++) maximize(res, sum[i]);
    cout << res;
}
int32_t main()
{
    FastIO
    freopen("GREEDY.INP", "r", stdin);
    freopen("GREEDY.OUT", "w", stdout);
    cin >> n >> k;
    for(int i = 1; i <= n; i++) cin >> a[i].fi >> a[i].se;

    xuli();
    return 0;
}

/* Author: hxzinh */


