#include <bits/stdc++.h>
#define ll long long
#define INF 1e9
#define FastIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

template<class X, class Y>
	inline bool maximize(X &x, const Y &y) {return (x < y ? x = y, 1 : 0);}
template<class X, class Y>
	inline bool minimize(X &x, const Y &y) {return (x > y ? x = y, 1 : 0);}

const int NM = 1e6 + 10;
const int MOD = 1e9 + 7;
ll n, k;
ll a[5];
ll frac[NM], finv[NM];

ll pw(ll x, ll t){
    if(t == 0) return 1;
    if(t == 1) return x;
    ll w = pw(x, t >> 1);
    if(t % 2 == 0) return (1LL * w * w) % MOD;
    else return (1LL * w * w % MOD) * 1LL * x % MOD;
}
void add(ll &a, ll b){
    if(a + b >= MOD) a += b - MOD;
    else a += b;
}
ll comb(ll k, ll n) {
	return k > n ? 0 : (1LL * frac[n] * finv[k] % MOD) * finv[n - k] % MOD;
}
int32_t main()
{
    FastIO
    cin >> n;
    for(int i = 0; i < 4; i++) cin >> a[i];

    frac[0] = 1;
    for(int i = 1; i <= n; i++) frac[i] = (1LL * frac[i - 1] * i) % MOD;
    finv[n] = pw(frac[n], MOD - 2) % MOD;
    for (int i = n; i >= 1; i--) finv[i - 1] = (1LL * finv[i] * i) % MOD;


    ll res = frac[n];
    for(int i = 0; i < 4; i++) res = (res * finv[a[i]] + MOD) % MOD;
    cout << res;
    return 0;
}
