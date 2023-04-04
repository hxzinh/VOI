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

const int NM = 1e6 + 10;
const int MOD = 1e9 + 7;
ll n, a, b;

void add(ll &a, ll b){
    a = (a + b) % MOD;
    if(a < 0) a += MOD;
}
void sub1(){
    int res = 0;
    for(int i = 1; i <= n; i++) res = (res + a * i + b * int32_t(sqrt(i))) % MOD;
    cout << res;
}
void sub2(){
    n %= MOD;
    ll res = (a * n * (n + 1) / 2) % MOD;
    cout << res << '\n';
}
void full(){
    ll m = n % MOD, res = 0, ans = 0;

    if(n % 2 == 0) res = (((n + 1) % MOD) * ((n / 2) % MOD) * (a % MOD)) % MOD;
    else res = ((n % MOD) * ((n / 2 + 1) % MOD) % MOD) * (a % MOD) % MOD;

    for(ll i = 1; i * i <= n; i++){
        ll nxt = min(1LL * (i + 1) * (i + 1) - 1, n);
        add(ans, ((nxt - 1LL * i * i + 1) % MOD * i) % MOD);
    }

    ans = ans * (b % MOD) % MOD;
    add(res, ans);
    cout << res;
}
int32_t main()
{
    FastIO
    freopen("SUM.INP", "r", stdin);
    freopen("SUM.OUT", "w", stdout);
    cin >> n >> a >> b;
    a %= MOD; b %= MOD;

    if(n <= 100) sub1();
    else if(b == 0 && a == 1) sub2();
    else full();
    return 0;
}

/* Author: hxzinh */
