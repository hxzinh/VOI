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

const int NM = 1e5 + 10;
int n, k;
int sum = 0;
pii a[NM];
int f[105][NM];

int32_t main()
{
    FastIO
    freopen("KNAPSACK2.INP", "r", stdin);
    freopen("KNAPSACK2.OUT", "w", stdout);
    cin >> n >> k;
    for(int i = 1; i <= n; i++){
        cin >> a[i].fi >> a[i].se;
        sum += a[i].se;
    }

    int res = 0;
    memset(f, INF, sizeof f);
    f[0][0] = 0;
    for(int i = 0; i < n; i++){
        for(int j = 0; j <= sum; j++) if(f[i][j] < INF){
            minimize(f[i + 1][j], f[i][j]);
            minimize(f[i + 1][j + a[i + 1].se], f[i][j] + a[i + 1].fi);
        }
    }
    for(int i = 1; i <= sum; i++) if(f[n][i] <= k) res = i;
    cout << res;
    return 0;
}
