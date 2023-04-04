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

ll n, k;

void xuli() {
    int L = k + 1, R = n;
    vector<bool> isPrime(R - L + 1, true);

    for(ll i = 2; i * i <= R; i++) {
        for(ll j = max(i * i, (L + i - 1) / i * i); j += i)
            isPrime[j - L] = false;
    }

    if(1 >= L) isPrime[1 - L] = false;

    ll cnt = 0;
    for(ll i = L; i <= R; i++) {
        if(isPrime[i - L]) cnt++;
    }

    cout << cnt;
}
int32_t main()
{
    FastIO
    freopen("FLOWERSHOP.INP", "r", stdin);
    freopen("FLOWERSHOP.OUT", "w", stdout);
    cin >> n >> k;

    if(k >= n) cout << 1;
    else xuli();
    return 0;
}

/* Author: hxzinh */


