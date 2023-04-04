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

const int NM = 1e3 + 10;
int n, m;
int a[NM], b[NM];
int f[NM][NM];

int dp(int x, int y){
    if(x > n || y > m) return 0;
    int &res = f[x][y];
    if(res > -1) return res;
    if(a[x] == b[y]) maximize(res, 1 + dp(x + 1, y + 1));
    maximize(res, dp(x + 2, y));
    maximize(res, dp(x, y + 2));
    return res;
}
void xuli(){
    memset(f, -1, sizeof f);
    cout << dp(1, 1);
}
int32_t main()
{
    FastIO
    freopen("LNACS.INP", "r", stdin);
    freopen("LNACS.OUT", "w", stdout);
    cin >> n >> m;
    for(int i = 2; i <= n + 1; i++) cin >> a[i];
    for(int j = 2; j <= m + 1; j++) cin >> b[j];

    for(int i = 2; i<= n + 1; i++){
        for(int j = 2;j <= m + 1; j++) {
            f[i][j] = max(f[i - 1][j], f[i][j - 1]);
            if(a[i] == b[j])
                f[i][j] = max(f[i][j], f[i - 2][j - 2] + 1);
        }
    }
    cout << f[n + 1][m + 1];

    return 0;
}
