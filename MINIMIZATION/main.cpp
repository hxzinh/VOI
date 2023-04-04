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

const int NM = 3e5 + 10;
int n, k;
ll result = INF;
int a[NM], s[NM];
ll f[5005][5005];

void xuli() {
    sort(a + 1, a + n + 1);
    memset(f, 0, sizeof f);
    int u = n / k, v = n / k + 1;
    int lenu = k - n % k, lenv = n % k;
    a[0] = a[1];
    for(int i = 0; i <= lenu; i++) {
        for(int j = 0; j <= lenv; j++) {
            if(i == 0 && j == 0) continue;
            if(i) {
                int p = (i - 1) * u + j * v;
                maximize(f[i][j], f[i - 1][j] + abs(a[p] - a[p + 1]));
            }
            if(j) {
                int p = i * u + (j - 1) * v;
                maximize(f[i][j], f[i][j - 1] + abs(a[p] - a[p + 1]));
            }
        }
    }

    ll res = a[n] - a[1] - f[lenu][lenv];
    cout << res;
}
int32_t main()
{
    FastIO
    freopen("MINIMIZATION.INP", "r", stdin);
    freopen("MINIMIZATION.OUT", "w", stdout);
    cin >> n >> k;
    for(int i = 1; i <= n; i++) cin >> a[i];

    if(n <= k) cout << 0;
    else xuli();
    //sub1();
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
