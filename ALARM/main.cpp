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

const int NM = 1e6 + 10;
const int MOD = 1e9 + 7;
int T, n, k, C, D, E1, E2, F;
int x[NM], y[NM], a[NM], s[NM];

void add(int &a, int b) {
    if((a += b) >= MOD) a -= MOD;
}
void sub(int &a, int b) {
    if((a -= b) < 0) a += MOD;
}
int pw(int x, int k) {
    if(k <= 1) return k ? x : 1;
    int u = pw(x, k >> 1);
    if(k & 1) return 1LL * u * u % MOD * x % MOD;
    else return 1LL * u * u % MOD;
}
void sub2() {
    int res = 0;
    for(int t = 1; t <= k; t++) {
        for(int i = 1; i <= n; i++) {
            int ans = 0;
            for(int j = i; j <= n; j++) {
                add(ans, 1LL * a[j] * pw(j - i + 1, t) % MOD);
                add(res, ans);
            }
        }
    }

    cout << res << '\n';
}
void xuli() {
    s[1] = k;
    for(int i = 2; i <= n; i++) {
        s[i] = pw(i, k + 1);
        sub(s[i], i);
        s[i] = 1LL * s[i] * pw(i - 1, MOD - 2) % MOD;
        //s[i] = 1LL * s[i] * a[i] % MOD;

        add(s[i], s[i - 1]);
    }

    int res = 1LL * s[1] * a[1] * n % MOD;
    for(int i = 2; i <= n; i++) {
        int ans = 0;
        add(ans, 1LL * s[i] * (n - i + 1) % MOD);
        ans = 1LL * ans * a[i] % MOD;

        add(res, ans);
    }

    cout << res << '\n';
}
int32_t main()
{
    FastIO
    freopen("ALARM.INP", "r", stdin);
    freopen("ALARM.OUT", "w", stdout);
    cin >> T;
    while(T--) {
        cin >> n >> k >> x[1] >> y[1] >> C >> D >> E1 >> E2 >> F;
        a[1] = (x[1] + y[1]) % F;
        for(int i = 2; i <= n; i++) {
            x[i] = (C * x[i - 1] + D * y[i - 1] + E1) % F;
            y[i] = (D * x[i - 1] + C * y[i - 1] + E2) % F;
            a[i] = (x[i] + y[i]) % F;
        }
        xuli();
    }

    return 0;
}

/* Author: hxzinh */

