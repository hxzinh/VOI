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

const int NM = 105;
const int MOD = 1e9;
int n, m;
ll a[NM][NM], f[NM][NM];

void add(ll &a, ll b) {
    if(a + b >= MOD) a += b - MOD;
    else a += b;
}
void xuli() {
    for(int i = 1; i <= n; i++) f[i][1] = 1;

    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            for(int u = 1; u <= i; u++) {
                for(int v = 1; v <= j; v++) if(u + v < i + j && v < m) {
                    int curGcd = __gcd(a[i][j], a[u][v]);
                    if(curGcd > 1) add(f[i][j], f[u][v]);
                }
            }
        }
    }

    ll res = 0;
    for(int i = 1; i <= n; i++) add(res, f[i][m]);
    cout << res;
}
int32_t main()
{
    FastIO
    freopen("NKPATH.INP", "r", stdin);
    freopen("NKPATH.OUT", "w", stdout);
    cin >> n >> m;
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= m; j++) cin >> a[i][j];

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
