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


//PRAGMA
#pragma GCC target ("avx2")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")

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

const int NM = 350005;
const int MOD = 1e9 + 19972207;
int n, k;
int a[NM], f[MASK(24) + 10];

inline void add(int &a, int b) {
    if((a += b) >= MOD) a -= MOD;
}
inline void sub(int &a, int b) {
    if((a -= b) < 0) a += MOD;
}
void xuli() {
    for(int i = 1; i <= n; i++) {
        string s; cin >> s;
        int curMask = 0;
        for(int j = 0; j < s.size(); j++) {
            curMask |= MASK(s[j] - 'a');
        }

        f[curMask]++;
    }

    for(int i = 0; i < k; i++) {
        int nxt = (MASK(k) - 1) ^ MASK(i);
        for(int mask = nxt; mask > 0; mask = (mask - 1) & nxt) {
            add(f[mask], f[mask ^ MASK(i)]);
        }
    }

    //for(int mask = 0; mask < MASK(k); mask++) cout << cnt[mask] << " ";
    //cout <<  '\n';

    for(int mask = 0; mask < MASK(k); mask++) {
        int cntMask = __builtin_popcount(mask);
        f[mask] = f[mask] * ((cntMask & 1) ? 1 : -1);
    }

    for(int i = 0; i < k; i++) {
        for(int mask = MASK(i); mask < MASK(k); mask = (mask + 1) | MASK(i)) {
            add(f[mask], f[mask ^ MASK(i)]);
        }
    }

    ll res = 0, mul = 1;
    for(int mask = 0; mask < MASK(k); mask++) {
        res = (res + f[mask] * mul) % MOD;
        mul = mul * (n + 1) % MOD;
    }

    cout << res;
}
int32_t main()
{
    FastIO
    freopen("URGENT.INP", "r", stdin);
    freopen("URGENT.OUT", "w", stdout);
    cin >> n >> k;

    //sub12();
    xuli();
    return 0;
}

/* Author: hxzinh */

