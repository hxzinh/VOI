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

const int MAX = 2e3 + 10;
const int MOD = 1e9 + 7;
int n, b;
int a[MAX], f[MAX], s[MAX], dp[MAX][MAX];

void add(int &a, int b){
    if(a + b >= MOD) a += b - MOD;
    else a += b;
}
void full(){
    dp[n][0] = 1;
    for(int i = n; i > 0; i--){
        if(a[i] == -1){
            for(int k = 0; k <= n - i; k++){
                add(dp[i - 1][k], dp[i][k]);
                if(k > 0) add(dp[i - 1][k + 1], dp[i][k] * min(i - 1, b - k));
            }
        } else {
            for(int k = 0; k <= n - i; k++){
                if(k + a[i] > b) break;
                add(dp[i - 1][k + (a[i] > 0)], dp[i][k]);
            }
        }
    }

    int res = 0;
    for(int i = 0; i <= b; i++) add(res, dp[0][i]);
    cout << res;
}
void xuli(){
    dp[n + 1][0] = 1;
    for(int i = n; i > 0; i--) {
        if(a[i] != -1){
            for(int j =(a[i] > 0); j <= b; j++)
            if(j + a[i] - 1 <= b)  dp[i][j] =(dp[i][j] + dp[i + 1][j -(a[i] > 0)]) % MOD;
        }
        else {
            for(int j = 0; j <= b; j++) {
                dp[i][j] =(dp[i][j] + dp[i + 1][j]) % MOD;
                if(j > 0) {
                    int t = b - j + 1;
                    dp[i][j] =(dp[i][j] + dp[i + 1][j - 1] * min(i - 1, t)) % MOD;
                }
            }
        }
    }

    int res = 0;
    for(int j = 0; j <= b; j++) res = 1LL * (res + dp[1][j]) % MOD;

    cout<<res;
}
int32_t main()
{
    FastIO
    freopen("GRAPH.INP", "r", stdin);
    freopen("GRAPH.OUT", "w", stdout);
    cin >> n >> b;
    for(int i = 1; i <= n; i++) cin >> a[i];

    full();
    cout << '\n';
    xuli();
    return 0;
}
