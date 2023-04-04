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

const int NM = 2e5 + 10;
int n;
int a[NM], b[NM];

void xuli() {
    int maxSum = 0, minSum = INF, maxDel = 0, minDel = INF;
    for(int i = 1; i <= n; i++) {
        maximize(maxSum, a[i] + b[i]);
        minimize(minSum, a[i] + b[i]);
        maximize(maxDel, a[i] - b[i]);
        minimize(minDel, a[i] - b[i]);
    }

    for(int i = 1; i <= n; i++) {
        int ans = 0;
        int sum = a[i] + b[i], del = a[i] - b[i];
        maximize(ans, max(maxSum - sum, sum - minSum));
        maximize(ans, max(maxDel - del, del - minDel));

        cout << ans << " ";
    }
}
int32_t main()
{
    FastIO
    freopen("DISPOINT.INP", "r", stdin);
    freopen("DISPOINT.OUT", "w", stdout);
    cin >> n;
    for(int i = 1; i <= n; i++) cin >> a[i];
    for(int i = 1; i <= n; i++) cin >> b[i];

    xuli();
    return 0;
}

/* Author: hxzinh */


