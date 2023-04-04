#include <bits/stdc++.h>
#define int long long
#define INF 0x3f3f3f3f3f3f3f3f
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

const int NM = 1e5 + 10;
int n, m, k;
int a[NM][20], f[1005][10005], s[NM][20];

void sub12(){
    memset(f, -1, sizeof f);
    f[0][0] = 0;
    for(int i = 0; i < n; i++){
        for(int j = 0; j <= k; j++) if(f[i][j] > -1) {
            maximize(f[i + 1][j], f[i][j]);
            for(int u = 1; u <= m; u++){
                if(u + j > k) break;
                maximize(f[i + 1][j + u], f[i][j] + s[i + 1][u]);
            }
        }
    }

    cout << f[n][k];
}
int32_t main()
{
    FastIO
    freopen("SALE.INP", "r", stdin);
    freopen("SALE.OUT", "w", stdout);
    cin >> n >> m >> k;
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= m; j++) cin >> a[i][j];

    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= m; j++) s[i][j] = s[i][j - 1] + a[i][j];

    sub12();
    return 0;
}

/* Author: hxzinh */
