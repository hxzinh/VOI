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
int n, m;
pii dp[NM][NM][NM][2];

pii solve(int x, int u, int v, int t) {
    if(x == 0) {
        if(!u && !v) return {0, 0};

        if(t == 0) {
            pii ans = solve(u, 0, 0, 0);
            return {ans.fi, ans.se + v};
        }
        else {
            pii ans = solve(v, 0, 0, 1);
            return {u + ans.fi, ans.se};
        }
    }

    pii &res = dp[x][u][v][t];
    if(res.fi > -1 || res.se > -1) return res;

    res = {0, 0};
    for(int i = 1; i <= m; i++) if(i <= x) {
        if(t == 0) {
            pii ans = solve(x - i, u + i, v, 1);
            if(res.fi < ans.fi) res = ans;
        }
        else {
            pii ans = solve(x - i, u, v + i, 0);
            if(res.se < ans.se) res = ans;
        }
    }

    return res;
}
void xuli() {
    for(int i = 0; i <= n; i++)
        for(int j = 0; j <= n; j++)
            for(int k = 0; k <= n; k++)
                for(int t = 0; t < 2; t++) dp[i][j][k][t] = {-1, -1};

    cout << solve(n, 0, 0, 0).fi;
}
int32_t main()
{
    FastIO
    freopen("NIMGAME.INP", "r", stdin);
    freopen("NIMGAME.OUT", "w", stdout);
    cin >> n >> m;

    xuli();
    return 0;
}

/* Author: hxzinh */

