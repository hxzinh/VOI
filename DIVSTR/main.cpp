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

const int NM = 2e4 + 10;
int n;
string s;
int lcp[4005][4005];

void sub2() {
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            if(s[i] == s[j]) lcp[i][j] = lcp[i - 1][j - 1] + 1;
            else lcp[i][j] = 0;
        }
    }

    ll res = 0;
    for(int len = 1; len <= n; len++) {
        for(int i = 1; i <= n - 2 * len + 1; i++) {
            int curMin = len;
            for(int j = i; j <= n - 2 * len + 1; j += len) {
                minimize(curMin, lcp[j + len - 1][j + 2 * len - 1]);
                maximize(res, 1LL * curMin * (2 + (j - i) / len));
            }
        }
    }

    cout << res;
}
void xuli() {
    ll res = 0;
}
int32_t main()
{
    FastIO
    freopen("DIVSTR.INP", "r", stdin);
    freopen("DIVSTR.OUT", "w", stdout);
    cin >> s;
    n = s.size();
    s = '#' + s;

    sub2();
    return 0;
}

/* Author: hxzinh */

