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
const int MOD = 1e9 + 7;
int n, k;
int frac[NM], finv[NM], f[NM];

void add(int &a, int b) {
    if(a + b >= MOD) a += b - MOD;
    else a += b;
}
int pw(int x, int k) {
    if(k <= 1) return k ? x : 1;
    int tmp = pw(x, k >> 1);
    if(k & 1) return 1LL * tmp * tmp % MOD * x % MOD;
    else return 1LL * tmp * tmp % MOD;
}
int comb(int k, int n) {
	return k > n ? 0 : (1LL * frac[n] * finv[k] % MOD) * finv[n - k] % MOD;
}
void sub1() {
    for(int i = k; i <= n; i++) {
        int res = 0;
        for(int mask = 0; mask < MASK(i); mask++) {
            if(__builtin_popcount(mask) != k) continue;
            int curGcd = -1;
            for(int j = 1; j <= n; j++) if(BIT(mask, j - 1)) {
                if(curGcd == -1) curGcd = j;
                else curGcd = __gcd(curGcd, j);
            }
            add(res, 1LL * curGcd * frac[k] % MOD);
        }

        cout << res << '\n';
    }


    /**
    int res = 0;
    for(int i = k + 1; i <= n; i++) {
        for(int j = 1 : uoc) {
            res += comb(k - 1, (i - 1) / j) * frac[k] * f[j];
        }
    }
    **/
}
void xuli() {
    for(int i = 1; i <= n; i++) f[i] = i;

    for(int i = 1; i <= n; i++)
        for(int j = i + i; j <= n; j += i) f[j] -= f[i];

    int res = frac[k];
    cout << res << '\n';
    for(int i = k + 1; i <= n; i++) {
        vector<int> tmp;

        tmp.push_back(1);
        for(int j = 2; j * j <= i; j++) if(i % j == 0) {
            tmp.push_back(j);
            if(i / j != j) tmp.push_back(i / j);
        }

        for(int u : tmp) add(res, 1LL * comb(k - 1, (i - 1) / u) * frac[k] % MOD * f[u] % MOD);

        cout << res << '\n';
    }
}
int32_t main()
{
    FastIO
    freopen("KGCD.INP", "r", stdin);
    freopen("KGCD.OUT", "w", stdout);
    cin >> n >> k;

    frac[0] = 1;
    for(int i = 1; i <= n; i++) frac[i] = (1LL * frac[i - 1] * i) % MOD;
    finv[n] = pw(frac[n], MOD - 2) % MOD;
    for (int i = n; i >= 1; i--) finv[i - 1] = (1LL * finv[i] * i) % MOD;

    if(n <= 20) sub1();
    else xuli();
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
