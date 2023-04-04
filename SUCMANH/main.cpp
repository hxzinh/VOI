#include <bits/stdc++.h>
#define ll long long
#define INF 0x3f3f3f3f
#define pii pair<int, int>
#define mp make_pair
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

const int NM = 1e3 + 10;
int n, m, k;
int a[NM], b[NM];
ll f[NM][NM][11];

void xuli() {
    sort(a + 1, a + n + 1);
    sort(b + 1, b + m + 1);

    for(int i = 1; i <= m; i++) f[0][i][0] = f[i][0][0] = 1;

    for(int t = 1; t <= k; t++) {
        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= m; j++) {
                f[i][j][t] += f[i][j - 1][t] + f[i - 1][j][t] - f[i - 1][j - 1][t];
                if(a[i] > b[j]) f[i][j][t] += f[i - 1][j - 1][t - 1];
            }
        }
    }


    ll res = 0;
    for(int i = 1; i <= m; i++) res += f[n][i][k];

    cout << f[n][m][k];
}
int32_t main()
{
    FastIO
    freopen("SUCMANH.INP", "r", stdin);
    freopen("SUCMANH.OUT", "w", stdout);
    cin >> n >> m >> k;
    for(int i = 1; i <= n; i++) cin >> a[i];
    for(int i = 1; i <= m; i++) cin >> b[i];

    xuli();
    return 0;
}

/* Author: hxzinh */

/*
-----code ko bug-----code ko bug-----code ko bug--------------

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
