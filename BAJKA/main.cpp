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

const int NM = 305;
int n, m;
string s, a;
int dp[NM][NM];

void xuli() {
    memset(dp, INF, sizeof dp);
    for(int i = 1; i <= n; i++) if(s[i] == a[1]) dp[1][i] = 0;

    for(int i = 1; i < m; i++) {
        for(int j = 1; j <= n; j++) if(dp[i][j] < INF) {
            int u = a[i + 1] - 'a';
            for(int k = 1; k <= n; k++) if(s[k] == s[j]) {
                for(int t  = -1; t < 2; t++) {
                    int v = k + t;
                    if(!t || v <= 0 || v > n || s[v] != a[i + 1]) continue;
                    minimize(dp[i + 1][v], dp[i][j] + abs(k - j) + 1);
                }
            }
        }
    }

    int res = INF;
    for(int i = 1; i <= n; i++) minimize(res, dp[m][i]);

    if(res < INF) cout << res;
    else cout << -1;
}
int32_t main()
{
    FastIO
    freopen("BAJKA.INP", "r", stdin);
    freopen("BAJKA.OUT", "w", stdout);
    cin >> n >> m;
    cin >> s >> a;
    s = '#' + s;
    a = '#' + a;

    xuli();
    return 0;
}

/* Author: hxzinh */


