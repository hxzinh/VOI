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
int n, minL, minR;
int a[NM], M[NM][22];
ll s[NM];

int getMin(int u, int v) {
    int k = log2(v - u + 1);
    return min(M[u][k], M[v - MASK(k) + 1][k]);
}
void sub12() {
    for(int i = 1; i <= n; i++) s[i] = s[i - 1] + a[i];

    ll res = -INF;
    pii trace;
    for(int i = 1; i <= n; i++) {
        for(int j = i; j <= n; j++) {
            int curMin = getMin(i, j);
            if(curMin < minL || curMin > minR) continue;

            if(maximize(res, s[j] - s[i - 1])) trace = {i, j};
        }
    }
    cout << res << '\n';
    cout << trace.fi << " " << trace.se;
}
void xuli() {

}
int32_t main()
{
    FastIO
    freopen("FUNFAIR.INP", "r", stdin);
    freopen("FUNFAIR.OUT", "w", stdout);
    cin >> n >> minL >> minR;
    for(int i = 1; i <= n; i++) cin >> a[i];

    memset(M, INF, sizeof M);
    for(int i = 1; i <= n; i++) M[i][0] = a[i];

    for(int k = 1; MASK(k) <= n; k++)
        for(int i = 1; i + MASK(k) - 1 <= n; i++)
            M[i][k] = min(M[i][k - 1], M[i + MASK(k - 1)][k - 1]);

    sub12();
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
