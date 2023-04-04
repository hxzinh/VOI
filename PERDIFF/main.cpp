#include <bits/stdc++.h>
#define int long long
#define INF 1e9
#define MASK(x) (1LL << (x))
#define BIT(i, x) ((x) >> (i) & 1)
#define FastIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

template<class X, class Y>
	inline bool maximize(X &x, const Y &y) {return (x < y ? x = y, 1 : 0);}
template<class X, class Y>
	inline bool minimize(X &x, const Y &y) {return (x > y ? x = y, 1 : 0);}

const int MOD = 1e9 + 7;
const int NM = 1e6 + 10;
int n;
int dp[MASK(20)][20], t[1005][1005][3], f[NM], g[NM], h[NM];

int add(int &a, int b){
    if(a + b >= MOD) a += b - MOD;
    else a += b;
}
int Minus(int &a, int b){
    if(a < b) a -= b + MOD;
    else a -= b;
}
void sub12(){
    for(int i = 1; i <= n; i++) dp[MASK(i - 1)][i] = 1;

    for(int mask = 0; mask < MASK(n); mask++){
        for(int i = 1; i <= n; i++) if(dp[mask][i]) {
            for(int j = 1; j <= n; j++) if(abs(j - i) > 1 && !BIT(j - 1, mask)){
                int newMask = mask | MASK(j - 1);
                add(dp[newMask][j], dp[mask][i]);
            }
        }
    }

    int res = 0;
    for(int i = 1; i <= n; i++) add(res, dp[MASK(n) - 1][i]);
    cout << res;
}
void sub3(){
    t[1][1][0] = 1;
    for(int i = 1; i < n; i++){
        for(int j = 0; j <= i; j++){
            for(int k = 0; k <= 2; k++) if(t[i][j][k]) {
                add(t[i + 1][j + 1][2], t[i][j][k]);
                add(t[i + 1][j][1], t[i][j][k] * (2 * j - k) % MOD);
                if(j > k) add(t[i + 1][j - 1][0], t[i][j][k] * (j - k) * (j - 1) % MOD);
            }
        }
    }
    cout << t[n][1][0];
}
void xuli(){

}
int32_t main()
{
    FastIO
    freopen("PERDIFF.INP", "r", stdin);
    freopen("PERDIFF.OUT", "w", stdout);
    cin >> n;

    sub3();
    return 0;
}
