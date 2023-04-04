#include <bits/stdc++.h>
#define ll long long
#define INF 0x3f3f3f3f
#define pii pair<int, int>
#define fi first
#define se second
#define ALL(v) (v).begin(), (v).end()
#define popcount(x) __builtin_popcount(x)
#define setp(x) setprecision(x)
#define MASK(x) (1LL << (x))
#define BIT(x, i) ((x) >> (i) & 1)
#define FastIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

template<class X, class Y>
	inline bool maximize(X &x, const Y &y) {return (x < y ? x = y, 1 : 0);}
template<class X, class Y>
	inline bool minimize(X &x, const Y &y) {return (x > y ? x = y, 1 : 0);}

const int MOD = 1e9 + 7;
ll n, k;

ll pw(ll x, ll k){
    if(k == 1) return x;
    if(k == 0) return 1;
    ll tmp = pw(x, k / 2);
    if(k % 2 == 0) return tmp * tmp % MOD;
    else return (tmp * x) % MOD * tmp % MOD;
}
int32_t main()
{
    FastIO
    cin >> n >> k;

    ll res = 0, i = 0;
    while((1LL << i) <= k){
        if(BIT(k, i)) res = (res + pw(n, i)) % MOD;
        i++;
    }
    cout << res;
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
