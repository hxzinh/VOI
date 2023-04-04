#include <bits/stdc++.h>
#define int long long
#define INF 0x3f3f3f3f3f3f3f3f
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

const int NM = 405;
int n;
int a[NM], f[NM][NM], s[NM];

int dp(int x, int y){
    if(x > y) return INF;
    int &res = f[x][y];
    if(res < INF) return res;
    for(int i = x; i < y; i++){
        minimize(res, dp(x, i) + dp(i + 1, y) + s[y] - s[x - 1]);
    }
    return res;
}
void xuli(){
    for(int i = 0; i <= n; i++)
        for(int j = 0; j <= n; j++) f[i][j] = INF;

    for (int i = 1; i + 1 <= n; ++i) f[i][i + 1] = a[i] + a[i + 1];
    for(int i = 0; i <= n; i++) f[i][i] = 0;

    cout << dp(1, n);
}
int32_t main()
{
    FastIO
    freopen("SLIMES.INP", "r", stdin);
    freopen("SLIMES.OUT", "w", stdout);
    cin >> n;
    for(int i = 1; i <= n; i++) cin >> a[i];

    for(int i = 1; i <= n; i++) s[i] = s[i - 1] + a[i];

    xuli();
    return 0;
}
