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

const int NM = 1e5 + 10;
int n, k;
pii a[NM];
int f[105][NM];

int32_t main()
{
    FastIO
    freopen("KNAPSACK.INP", "r", stdin);
    freopen("KNAPSACK.OUT", "w", stdout);
    cin >> n >> k;
    for(int i = 1; i <= n; i++) cin >> a[i].fi  >> a[i].se;

    memset(f, -1, sizeof f);
    f[0][0] = 0;
    for(int i = 0; i < n; i++){
        for(int j = 0; j <= k; j++) if(f[i][j] != -1) {
            maximize(f[i + 1][j], f[i][j]);
            if(j + a[i + 1].fi <= k) maximize(f[i + 1][j + a[i + 1].fi], f[i][j] + a[i + 1].se);
        }
    }

    int res = -1;
    for(int i = 0; i <= k; i++) maximize(res, f[n][i]);
    cout << res;
    return 0;
}
