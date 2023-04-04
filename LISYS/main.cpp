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

const int NM = 1e6 + 7;
const int MOD = 1e9 + 7;
int n;
int result = 0;
int a[NM];
ll f[1005][1005], frac[2000005], finv[NM];

void add(ll &a, ll b){
    if(a + b >= MOD) a += b - MOD;
    else a += b;
}
ll pw(int x, int t){
    if(t == 0) return 1;
    if(t == 1) return x;
    ll w = pw(x, t >> 1);
    if(t % 2 == 0) return (1LL * w * w) % MOD;
    else return (1LL * w * w % MOD) * 1LL * x % MOD;
}
void backtrack(int x, int sum){
    if(x > n){
        result += (sum == 2 * (n - 1));
        return;
    }
    if(a[x] > 0){
        backtrack(x + 1, sum + a[x]);
        return;
    }
    for(int i = 1; i <= n - 1; i++){
        if(sum + i > 2 * (n - 1)) break;
        backtrack(x + 1, sum + i);
    }
}
void sub12(){
    backtrack(1, 0);
    cout << result;
}
void sub3(){
    sort(a + 1, a + n + 1, greater<int>());

    if(a[1] == -1){
        for(int i = 1; i < n; i++) f[1][i] = 1;
    } else f[1][a[1]] = 1;

    for(int i = 1; i < n; i++){
        for(int j = 1; j < n; j++) if(f[i][j]) {
            if(a[i + 1] == -1){
                for(int u = 1; u <= n - 1; u++) if(j + u - 1 < n)
                    add(f[i + 1][j + u - 1], f[i][j]);
            } else if(j + a[i + 1] - 1 < n) add(f[i + 1][j + a[i + 1] - 1], f[i][j]);
        }
    }

    cout << f[n][n - 1];
}
ll comb(int k, int n) {
	return k > n ? 0 : (1LL * frac[n] * finv[k] % MOD) * finv[n - k] % MOD;
}
void full(){
    int sum = 0, cnt = 0;
    for(int i = 1; i <= n; i++){
        if(a[i] > 0){
            sum += a[i];
            cnt++;
        }
    }
    int m = 2 * (n - 1) - sum, k = n - cnt;

    frac[0] = 1;
    for(int i = 1; i <= m; i++) frac[i] = (1LL * frac[i - 1] * i) % MOD;
    finv[m] = pw(frac[m], MOD - 2) % MOD;
    for (int i = m; i >= 1; i--) finv[i - 1] = (1LL * finv[i] * i) % MOD;

    cout << comb(k - 1, m - 1);
}
int32_t main()
{
    FastIO
    freopen("LISYS.INP", "r", stdin);
    freopen("LISYS.OUT", "w", stdout);
    cin >> n;
    for(int i = 1; i <= n; i++) cin >> a[i];

    if(n <= 10) sub12();
    else if(n <= 100) sub3();
    else full();
    return 0;
}

/* Author: hxzinh */

/*



-=Buddha=- code ko bug | code ko bug | code ko bug

                                  _

                                ooOoo
                              o8888888o
                              88" . "88
                              (| -_- |)
                              O\  =  /O
                           ___/`---'\___
                         .'  \\|     |//  `.
                        /  \\|||  :  |||//  \
                       /  ||||| -:- |||||  \
                       |   | \\\  -  /'| |   |
                       | \_|  `\`---'//  |_/ |
                       \  .-\__ `-. -'__/-.  /
                     ___. .'  /--.--\  . .'___
                  ."" '<  `.___\_<|>_/___.' _> \"".
                 | | :  - \. ;`. _/; .'/ /  .' ; |
                 \  \ -.   \_\_. _.'_/_/  -' _.' /
       ===========`-.`___`-.__\ \___  /__.-'.'.-'================
                          `=--=-'

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
