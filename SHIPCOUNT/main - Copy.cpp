#include <bits/stdc++.h>
#define int long long
#define INF 1e18
#define FastIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

template<class X, class Y>
	inline bool maximize(X &x, const Y &y) {return (x < y ? x = y, 1 : 0);}
template<class X, class Y>
	inline bool minimize(X &x, const Y &y) {return (x > y ? x = y, 1 : 0);}

const int NM = 2e3 + 10;
const int MOD = 1e9 + 7;
int n, k;
int res = 0;
int frac[NM], finv[NM], f[NM][NM];
int cnt[11];

void add(int &a, int b){
    if(a + b >= MOD) a += b - MOD;
    else a += b;
    return;
}
int pw(int x, int k){
    if(k == 0) return 1;
    if(k == 1) return x;
    int t = pw(x, k / 2) % MOD;
    if(k % 2 == 0) return (t * t) % MOD;
    else return (t * t % MOD) * x % MOD;
}
int comb(int t, int h){
    return (t > h ? 0 : (1LL * frac[h] * finv[t] % MOD) * finv[h - t] % MOD);
}
void sub3(){
    for(int i = 0; i <= max(k, n); i++) f[i][i] = f[0][i] = 1;
    for(int i = 1; i <= max(k, n); i++)
        for(int j = i + 1; j <= max(k, n); j++) f[i][j] = (f[i][j - 1] + f[i - 1][j - 1]) % MOD;

    int ans = 0;
    for(int i = 1; i <= min(k, n); i++)
        add(ans, frac[n] * f[i][k] % MOD * f[i - 1][n - 1] % MOD);
    cout << ans;
}
int32_t main()
{
    FastIO
    cin >> k >> n;

    frac[0] = 1;
    for(int i = 1; i <= n; i++) frac[i] = (frac[i - 1] * i) % MOD;
    finv[n] = pw(frac[n], MOD - 2) % MOD;
    for(int i = n; i >= 1; i--) finv[i - 1] = (finv[i] * i) % MOD;

    int res = 0;
    for(int i = 0; i <= k; i++){
        res = (res + ((frac[n] % MOD) * (comb(i, k) % MOD) * (comb(i - 1, n - 1) % MOD))) % MOD;
    }
    sub3();
    return 0;
}
