#include <bits/stdc++.h>
#define ll long long
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

const int NM = 305;
const int MOD = 1e9 + 7;
int n, m, limit;
int f[NM][NM][NM];
int frac[NM], finv[NM];

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
void xuli(){
    f[0][0] = 1;  ///dung het i node va j edges
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            for(int k = 1; k <= n - i; k++){
                if(k - 1 + j > m) break;
                add(f[i + k][])
            }
        }
    }
}
int main()
{
    FastIO
    freopen("KIENGRAPH.INP", "r", stdin);
    freopen("KIENGRAPH.OUT", "w", stdout);
    cin >> n >> m >> limit;

    frac[0] = 1;
    for(int i = 1; i <= n; i++) frac[i] = (1LL * frac[i - 1] * i) % MOD;
    finv[n] = pw(frac[n], MOD - 2) % MOD;
    for (int i = n; i >= 1; i--) finv[i - 1] = (1LL * finv[i] * i) % MOD;

    xuli();
    return 0;
}
