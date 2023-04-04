#include <bits/stdc++.h>
#define ll long long
#define INF 1e9
#define FastIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

template<class X, class Y>
	inline bool maximize(X &x, const Y &y) {return (x < y ? x = y, 1 : 0);}
template<class X, class Y>
	inline bool minimize(X &x, const Y &y) {return (x > y ? x = y, 1 : 0);}

const int NM = 2e3 + 20;
int T, n, q, MOD;
int a[NM], s[NM][NM], frac[NM], finv[NM], f[NM][2020];
int C[NM][NM];

void add(int &a, int b){
    if(a + b >= MOD) a += b - MOD;
    else a += b;
}
int pw(const long long n, const long long k){
    if(k == 0) return 1;
    int res = pw(n, k >> 1);
    res = res * res % MOD;
    return (k & 1 ? res * n % MOD : res % MOD);
}
int comb(int n, int k){
    return k > n ? 0 : 1LL * frac[n] * pw(frac[k] * frac[n - k] % MOD, MOD - 2) % MOD;
}
void sub1(){
    for(int i = 0; i <= NM; i++) C[i][i] = C[i][0] = 1;

    for(int i = 2; i <= 2019; i++){
        for(int j = 1; j <= 2019; j++) if(!C[i][j]) {
            C[i][j] = (C[i - 1][j] + C[i - 1][j - 1]) % MOD;
        }
    }

    while(q--){
        int u, v, S;
        cin >> u >> v >> S;
        a[u] -= v;

        memset(f, 0, sizeof(f));
        for(int i = 0; i <= n; i++) f[i][0] = 1;
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= S; j++){
                f[i][j] = 0;
                for(int k = 0; k <= min(j / i, a[i]); k++){
                    //cout << comb(k, a[i]) << '\n';
                    f[i][j] = (f[i][j] + 1LL * f[i - 1][j - k * i] * C[a[i]][k] % MOD) % MOD;
                }
            }
        }
        a[u] += v;
        cout << f[n][S] << '\n';
    }

}
void sub2(){
    while(q--){
        int u, v, S;
        cin >> u >> v >> S;
        a[u] -= v;

        for(int i = 0; i <= n; i++) f[i][0] = 1;
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= S; j++){
                f[i][j] = 0;
                int Comb = 1;
                for(int k = 0; k <= min(j / i, a[i]); k++){
                    if(k > 0) Comb = ((1LL * Comb * (a[i] - k + 1) % MOD) * finv[k]) % MOD;
                    f[i][j] = (f[i][j] + 1LL * f[i - 1][j - k * i] * Comb % MOD) % MOD;
                }
            }
        }
        a[u] += v;
        cout << f[n][S] << '\n';
    }
}
void sub3(){
    while(q--){
        int u, v, S;
        cin >> u >> v >> S;
        a[u] -= v;

        for(int i = 1; i <= S; i++) f[i][0] = 1;
        for(int i = 1; i <= n; i++){
            for(int j = 0; j <= S; j++){

            }
        }
    }
}
int main()
{
    FastIO
    freopen("ORANGEJUICE.INP", "r", stdin);
    freopen("ORANGEJUICE.OUT", "w", stdout);
    cin >> T;
    cin >> n >> q >> MOD;
    for(int i = 1; i <= n; i++) cin >> a[i];

    frac[0] = 1;
    for(int i = 1; i <= n; i++) frac[i] = (frac[i - 1] * i) % MOD;
    finv[n] = pw(frac[n], MOD - 2) % MOD;
    for(int i = n; i >= 1; i--) finv[i - 1] = (finv[i] * i) % MOD;

    sub2();
    return 0;
}
