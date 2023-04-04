#include <bits/stdc++.h>
#define ll long long
#define int long long
#define INF 0x3f3f3f3f
#define pii pair<int, int>
#define fi first
#define se second
#define ALL(v) (v).begin(), (v).end()
#define popcount(x) __builtin_popcount(x)
#define set(x) setprecision(x)
#define MASK(x) (1LL << (x))
#define BIT(x, i) ((x) >> (i) & 1)
#define FastIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

template<class X, class Y>
	inline bool maximize(X &x, const Y &y) {return (x < y ? x = y, 1 : 0);}
template<class X, class Y>
	inline bool minimize(X &x, const Y &y) {return (x > y ? x = y, 1 : 0);}

const int NM = 355;
const int MOD = 1e9 + 7;
int n;
ll frac[NM], finv[NM];

int pw(int x, int t){
    if(t == 0) return 1;
    if(t == 1) return x;
    int w = pw(x, t >> 1);
    if(t % 2 == 0) return (1LL * w * w) % MOD;
    else return (1LL * w * w % MOD) * 1LL * x % MOD;
}
void add(int &a, int b){
    a = (a + b) % MOD;
}
int comb(int k, int n) {
	return k > n ? 0 : (1LL * frac[n] * finv[k] % MOD) * finv[n - k] % MOD;
}
void init() {
    frac[0] = 1;
    for(int i = 1; i <= 2 * n; i++) frac[i] = (1LL * frac[i - 1] * i) % MOD;
    finv[2 * n] = pw(frac[2 * n], MOD - 2) % MOD;
    for (int i = 2 * n; i >= 1; i--) finv[i - 1] = (1LL * finv[i] * i) % MOD;
}
void xuli() {
    init();

    int res = 0;
    for(int i = 1; i <= n; i++) {
        int ans = comb(i, n);
        int cur = n - i + n - 1;
        add(res, ans * comb(n - 2, cur - 1) % MOD);
    }
    cout << res;
}
int32_t main()
{
    FastIO
    freopen("ZAPINA.INP", "r", stdin);
    freopen("ZAPINA.OUT", "w", stdout);
    cin >> n;

    xuli();
    return 0;
}
