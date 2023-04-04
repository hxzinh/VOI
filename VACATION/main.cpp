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
int n;
int a[NM], b[NM], c[NM];
int f[NM][5];

int32_t main()
{
    FastIO
    freopen("VACATION.INP", "r", stdin);
    freopen("VACATION.OUT", "w", stdout);
    cin >> n;
    for(int i = 1; i <= n; i++) cin >> a[i] >> b[i] >> c[i];

    for(int i = 1; i <= n; i++){
        f[i][1] = max(f[i - 1][2], f[i - 1][3]) + a[i];
        f[i][2] = max(f[i - 1][1], f[i - 1][3]) + b[i];
        f[i][3] = max(f[i - 1][1], f[i - 1][2]) + c[i];
    }

    int res = max({f[n][1], f[n][2], f[n][3]});
    cout << res;
    return 0;
}
