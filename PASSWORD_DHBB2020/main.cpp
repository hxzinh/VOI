#include <bits/stdc++.h>
#define int long long
#define INF 1e9
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

const int MOD = 1e9 + 7;
const int NM = 1e5 + 10;
int n, m;
int f[NM][31], frac[NM], finv[NM];
string s, t;
pair<char, int> a[NM];


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
int comb(int k, int n) {
	return k > n ? 0 : (1LL * frac[n] * finv[k] % MOD) * finv[n - k] % MOD;
}
void xuli(){
    int u = 1, cnt = 0, maxNum = -INF;
    while(u < s.size()){
        if(s[u] >= 'a' && s[u] <= 'z'){
            a[++cnt].fi = s[u];
            u++;
        } else {
            while(s[u] >= '0' && s[u] <= '9'){
                a[cnt].se = a[cnt].se * 10 + int32_t(s[u] - '0');
                u++;
            }
            maximize(maxNum, a[cnt].se);
        }
    }

    frac[0] = 1;
    for(int i = 1; i <= maxNum; i++) frac[i] = (1LL * frac[i - 1] * i) % MOD;
    finv[maxNum] = pw(frac[maxNum], MOD - 2) % MOD;
    for (int i = maxNum; i >= 1; i--) finv[i - 1] = (1LL * finv[i] * i) % MOD;


    memset(f, 0, sizeof(f));
    f[0][0] = 1;
    for(int i = 0; i < cnt; i++){
        for(int j = 0; j <= m; j++) if(f[i][j]){
            add(f[i + 1][j], f[i][j]);
            for(int k = 1; j + k <= m; k++){
                if(t[j + k] != a[i + 1].fi || k > a[i + 1].se) break;
                add(f[i + 1][j + k], (f[i][j] * 1LL * comb(k, a[i + 1].se)) % MOD);
            }
        }
    }

    cout << f[cnt][m];
}
int32_t main()
{
    FastIO
    freopen("PASSWORD.INP", "r", stdin);
    freopen("PASSWORD.OUT", "w", stdout);
    cin >> n >> m;
    cin >> s >> t;
    s = " " + s, t = " " + t;

    xuli();
    return 0;
}
