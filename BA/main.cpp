#include <bits/stdc++.h>
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

const int NM = 1e6 + 10;
const int MOD = 1e9 + 7;
int n, k, m;
int result = 0;
int frac[NM], finv[NM];
int f[NM][3];

int pw(int x, int t){
    if(t == 0) return 1;
    if(t == 1) return x;
    int w = pw(x, t >> 1);
    if(t % 2 == 0) return (1LL * w * w) % MOD;
    else return (1LL * w * w % MOD) * 1LL * x % MOD;
}
void add(int &a, int b){
    if(a + b >= MOD) a += b - MOD;
    else a += b;
}
int comb(int t, int n) {
	return t > n ? 0 : (1LL * frac[n] * finv[t] % MOD) * finv[n - t] % MOD;
}
void backtrack(int x, int u){
    if(x > n){
        if(u == 0) result++;
        return;
    }
    for(int i = 0; i <= 9; i++){
        if(x == 1 && i == 0) continue;
        backtrack(x + 1, (u + i) % 3);
    }
}
void sub12(){
    int res = comb(k, n);
    backtrack(1, 0);
    cout << result << '\n';

    for(int i = 1; i <= 9; i++) f[0][i % 3]++;
    for(int i = 0; i < n - k - 1; i++){
        for(int u = 0; u <= 9; u++)
        for(int j = 0; j < 3; j++) add(f[i + 1][(j + u) % 3], f[i][j]);
    }

    int tmp = pw(10, n - k - 1) % MOD;
    res = (res * 3 * tmp) % MOD;
    cout << res - 1;

    //cout << f[n][0];
}
int32_t main()
{
    FastIO
    freopen("BA.INP", "r", stdin);
    freopen("BA.OUT", "w", stdout);
    cin >> n >> k >> m;

    frac[0] = 1;
    for(int i = 1; i <= n; i++) frac[i] = (1LL * frac[i - 1] * i) % MOD;
    finv[n] = pw(frac[n], MOD - 2) % MOD;
    for (int i = n; i >= 1; i--) finv[i - 1] = (1LL * finv[i] * i) % MOD;

    sub12();
    return 0;
}
