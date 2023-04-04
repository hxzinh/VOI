#include <bits/stdc++.h>
#define ll long long
#define INF 0x3f3f3f3f
#define pii pair<int, int>
#define mp make_pair
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

const int NM = (1 << 19) + 10;
const int MOD = 1e9 + 7;
const int LOG = 19;
int n;
ll a[NM], s[NM], f[NM];

void add(ll &a, ll b) {
    a = (a + b) % MOD;
}
void sub(ll &a, ll b) {
    a = (a - b) % MOD;
    if(a < 0) a += MOD;
}
int pw(int x, int k) {
    if(k <= 1) return k ? x : 1;
    int tmp = pw(x, k >> 1);
    if(k & 1) return 1LL * tmp * tmp % MOD * x % MOD;
    else return 1LL * tmp * tmp % MOD;
}
void sub1() {
    ll res = 0;
    for(int mask = 0; mask < n; mask++) {
        ll sum = 0;
        for(int i = 0; i < n; i++) {
            if(i > mask) break;
            for(int j = 0; j < n; j++) {
                if(j > mask) break;
                if((i | j) <= mask) add(sum, a[i] * a[j] % MOD);
            }
        }

        cout << sum << " ";
    }
}
void sub2() {

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            int curMask = i | j;
            add(s[curMask], a[i] * a[j] % MOD);
        }
    }

    for(int mask = 0; mask < n; mask++) {
        if(mask) add(s[mask], s[mask - 1]);
        cout << s[mask] << " ";
    }
}
void xuli() {
    for(int i = 0; i < n; i++) s[i] = a[i];

    for(int i = 0; i < LOG; i++) {
        for(int mask = 0; mask < MASK(LOG); mask++) if(BIT(mask, i)) {
                add(s[mask], s[mask ^ MASK(i)]);
        }
    }

    for(int mask = 0; mask < MASK(LOG); mask++)
        f[mask] = 1LL * s[mask] * s[mask] % MOD;

    for(int i = 0; i < LOG; i++) {
        for(int mask = 0; mask < MASK(LOG); mask++) if(BIT(mask, i)) {
            sub(f[mask], f[mask ^ MASK(i)]);
        }
    }

    for(int i = 0; i < n; i++) {
        add(f[i], f[i - 1]);
        cout << f[i] << " ";
    }


}
int32_t main()
{
    FastIO
    freopen("SUMARR.INP", "r", stdin);
    freopen("SUMARR.OUT", "w", stdout);
    cin >> n;
    for(int i = 0; i < n; i++) cin >> a[i];

    if(n <= 500) sub1();
    else if(n <= 10000) sub2();
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
