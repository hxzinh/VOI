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
int a[NM], L[NM], R[NM];
ll f[5005][5005], s[NM];
pii M[5005][22];

pii getMax(int u, int v) {
    int k = log2(v - u + 1);
    if(M[u][k].fi > M[v - MASK(k) + 1][k].fi) return M[u][k];
    else return M[v - MASK(k) + 1][k];
}
ll solve(int l, int r) {
    if(l > r) return 0;
    ll   &res = f[l][r];
    if(res > -1) return res;

    res = 0;
    pii m = getMax(l, r);
    res += (r - l + 1) + solve(l, m.se - 1) + solve(m.se + 1, r);
    return res;
}
void sub12() {
    for(int i = 1; i <= n; i++) M[i][0] = {a[i], i};
    for(int k = 1; MASK(k) <= n; k++)
        for(int i = 1; i + MASK(k) - 1 <= n; i++) {
            if(M[i][k - 1].fi > M[i + MASK(k - 1)][k - 1].fi) M[i][k] = M[i][k - 1];
            else M[i][k] = M[i + MASK(k - 1)][k - 1];
        }

    memset(f, -1, sizeof f);
    for(int i = 1; i <= q; i++) cout << solve(L[i], R[i]) << " ";
}
void sub3() {
    for(int i = 1; i <= n; i++) s[i] = s[i - 1] + i;

    for(int i = 1; i <= q; i++) {
        cout << s[abs(R[i] - L[i]) + 1] << " ";
    }
}
int32_t main()
{
    FastIO
    freopen("RECUR.INP", "r", stdin);
    freopen("RECUR.OUT", "w", stdout);
    cin >> n >> q;
    bool ok = true, cx = true;
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
        if(a[i] != i) ok = false;
        if(a[i] != n - i + 1) cx = false;
    }
    for(int i = 1; i <= q; i++) cin >> L[i];
    for(int i = 1; i <= q; i++) cin >> R[i];

    if(ok || cx) sub3();
    else sub12();
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
