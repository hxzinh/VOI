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

const int NM = 1e4 + 10;
int n, k;

typedef long double ld;
pair<ld, ld> a[NM];

bool check(ld x) {
    int cnt = 0, i = 1;
    while(i <= n) {
        ld u = a[i].fi + x / a[i].se;
        while(i + 1 <= n && a[i + 1].se * abs(a[i + 1].fi - u) <= x) i++;
        cnt++;

        if(cnt > k) return false;

        i++;
    }

    return true;
}
void xuli() {
    sort(a + 1, a + n + 1);

    ld l = 0, r = 1e18, res = 1e18;
    for(int i = 1; i <= 70; i++) {
        ld m = (l + r) / 2.00;
        if(check(m)) {
            r = m;
            res = m;
        }
        else l = m;
    }

    cout << fixed << setprecision(2) << res;
}
int32_t main()
{
    FastIO
    freopen("SPHONE.INP", "r", stdin);
    freopen("SPHONE.OUT", "w", stdout);
    cin >> n >> k;
    for(int i = 1; i <= n; i++) cin >> a[i].fi;
    for(int i = 1; i <= n; i++) cin >> a[i].se;

    xuli();
    return 0;
}

/* Author: hxzinh */

