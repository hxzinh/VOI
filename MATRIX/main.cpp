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

const int MOD = 1e9 + 7;
const int NM = 1e6 + 10;
int n, m;
int frac[NM], finv[NM];

int pw(int x, int t){
    if(t == 0) return 1;
    if(t == 1) return x;
    int w = pw(x, t >> 1);
    if(t % 2 == 0) return (1LL * w * w) % MOD;
    else return (1LL * w * w % MOD) * 1LL * x % MOD;
}
void add(int &a, int b){
    if(a + b >= MOD) a += b - MOD;
    else a += b;
}
int comb(int k, int n) {
	return k > n ? 0 : (1LL * frac[n] * finv[k] % MOD) * finv[n - k] % MOD;
}
void xuli() {
    ll res = pw(frac[n], m - n + 1);
    for(int i = 1; i < n; i++) res = (res * frac[i] % MOD) * frac[i] % MOD;
    cout << res;
}
int32_t main()
{
    FastIO
    freopen("MATRIX.INP", "r", stdin);
    freopen("MATRIX.OUT", "w", stdout);
    cin >> n >> m;

    if(n > m) swap(n, m);
    frac[0] = 1;
    for(int i = 1; i <= n; i++) frac[i] = (1LL * frac[i - 1] * i) % MOD;
    finv[n] = pw(frac[n], MOD - 2) % MOD;
    for (int i = n; i >= 1; i--) finv[i - 1] = (1LL * finv[i] * i) % MOD;

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
