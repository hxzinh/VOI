#include <bits/stdc++.h>
#define ll long long
#define int long long
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

const int NM = 1005 + 10;
const int MOD = 998244353;
int n, lim, k;
pii a[NM];
int frac[NM], finv[NM], dp[NM][NM];

void add(int &a, int b){
    a = (a + b) % MOD;
    if(a < 0) a += MOD;
}
int pw(int x, int k) {
    if(k <= 1) return k ? x : 1;
    int u = pw(x, k >> 1);
    if(k & 1) return 1LL * u * u % MOD * x % MOD;
    else return 1LL * u * u % MOD;
}
int comb(int k, int n) {
	return k > n ? 0 : (1LL * frac[n] * finv[k] % MOD) * finv[n - k] % MOD;
}
int getSum(int u, int v) {
    int sum = 0;
    for(int i = 0; i <= k; i++)
        add(sum, 1LL * comb(i, k) * pw(u, k - i) % MOD * pw(v, i) % MOD);
    return sum;
}
void sub1() {
    int res = 0;
    for(int mask = 0; mask < MASK(n); mask++) {
        int curWei = 0, curSum = 0;
        for(int i = 1; i <= n; i++) if(BIT(mask, i - 1)) {
            curWei += a[i].fi;
            curSum += a[i].se;
        }

        if(curWei <= lim) {
            add(res, pw(curSum, k));
            bitset<5> bit(mask);
            cout << bit << " " << curWei << " " << pw(curSum, k) << '\n';
        }
    }

    cout << res;
}
void xuli() {
    int res = 0;
    for(int i = 1; i <= n; i++) {
        dp[i][a[i].fi] = a[i].se;
        add(res, pw(a[i].se, k));
    }

    for(int i = 1; i < n; i++) {
        for(int j = 0; j <= lim; j++) if(dp[i][j]) {
            if(j + a[i + 1].fi <= lim) {
                add(dp[i + 1][j + a[i + 1].fi], dp[i][j] + a[i + 1].se);
            }
            add(dp[i + 1][j], dp[i][j]);
        }
    }

    for(int i = 1; i <= lim; i++) add(res, pw(dp[n][i], k));
    cout << res;
}
int32_t main()
{
    FastIO
    freopen("DTTUI4.INP", "r", stdin);
    freopen("DTTUI4.OUT", "w", stdout);
    cin >> n >> lim >> k;
    for(int i = 1; i <= n; i++)
        cin >> a[i].fi >> a[i].se;

    frac[0] = 1;
    for(int i = 1; i <= lim; i++) frac[i] = (1LL * frac[i - 1] * i) % MOD;
    finv[lim] = pw(frac[lim], MOD - 2) % MOD;
    for (int i = lim; i >= 1; i--) finv[i - 1] = (1LL * finv[i] * i) % MOD;

    sub1();
    cout << '\n';
    xuli();
    return 0;
}

/* Author: hxzinh */


