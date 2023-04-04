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

const int NM = 1e3 + 10;
const int MOD = 1e9 + 7;
int n, k, m;
string s[NM];
char a[NM];
int f[NM][2], dp[NM][2][2], frac[NM], finv[NM];
bool cx[30];

int pw(int x, int k) {
    if(k <= 1) return k ? x : 1;
    int u = pw(x, k >> 1);
    if(k & 1) return 1LL * u * u % MOD * x % MOD;
    else return 1LL * u * u % MOD;
}
void add(int &a, int b) {
    if(a + b >= MOD) a += b - MOD;
    else a += b;
}
void sub1() {
    m = (k + 1) / 2;

    for(int i = 1; i <= n; i++) a[i] = s[i][0];
    for(int i = 1; i <= n; i++) cx[a[i] - 'a'] = true;

    f[0][0] = 1;
    for(int i = 0; i < m; i++) {
        for(int j = 0; j < 2; j++) if(f[i][j]) {
            for(int u = 0; u < 26; u++) {
                if(cx[u]) add(f[i + 1][1], f[i][j]);
                else add(f[i + 1][j], f[i][j]);
            }
        }
    }

    cout << f[m][1];
}
int comb(int k, int n) {
	return k > n ? 0 : (1LL * frac[n] * finv[k] % MOD) * finv[n - k] % MOD;
}
void sub3() {
    int m = s[1].size();
    frac[0] = 1;
    for(int i = 1; i <= k; i++) frac[i] = (1LL * frac[i - 1] * i) % MOD;
    finv[m] = pw(frac[k], MOD - 2) % MOD;
    for (int i = k; i >= 1; i--) finv[i - 1] = (1LL * finv[i] * i) % MOD;

    int u = (k + 1) / 2 - m;
    ll res = pw(26, u) * (u + 1) * 2 % MOD;
    cout << res << '\n';
}
void sub2() {
    m = (k + 1) / 2;
    dp[0][0][0] = 1;
    for(int i = 0; i < m; i++) {
        for(int j = 0; j < 2; j++) {
            for(int u = 0; u < 2; u++) if(dp[i][j][u]) {
                for(int v = 0; v < 26; v++) {
                    if(u == 0) {
                        add(dp[i + 1][v == s[1][0]][u], dp[i][j][u]);
                    } else {
                        if(v == s[1][1] - 'a') add(dp[i + 1][v == s[1][0] - 'a'][1], dp[i][j][u]);
                        else add(dp[i + 1][v == s[1][0] - 'a'][u], dp[i][j][u]);
                    }
                }
            }
        }
    }

    int res = (dp[m][0][1] + dp[m][1][1]) % MOD;
    cout << res << '\n';
}
int32_t main()
{
    FastIO
    freopen("UGPALIND.INP", "r", stdin);
    freopen("UGPALIND.OUT", "w", stdout);
    cin >> n >> k;
    bool ok = true;
    for(int i = 1; i <= n; i++) {
        cin >> s[i];
        if(s[i].size() > 1) ok = false;
    }

    if(ok) sub1();
    else sub3();
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
