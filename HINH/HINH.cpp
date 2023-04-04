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
int n;
pii a[NM];
ll f[NM][2];

void xuli() {
    f[1][0] = a[1].se;
    f[1][1] = a[1].fi;

    for(int i = 1; i < n; i++) {
        for(int j = 0; j < 2; j++) if(f[i][j] > 0) {
            int cur = (j ? a[i].se : a[i].fi);
            maximize(f[i + 1][0], f[i][j] + a[i + 1].se + abs(a[i + 1].fi - cur));
            maximize(f[i + 1][1], f[i][j] + a[i + 1].fi + abs(a[i + 1].se - cur));
        }
    }

    ll res = max(f[n][1], f[n][0]);
    cout << res;
}
int32_t main()
{
    FastIO
    freopen("HINH.INP", "r", stdin);
    freopen("HINH.OUT", "w", stdout);
    cin >> n;
    for(int i = 1; i <= n; i++) cin >> a[i].fi >> a[i].se;

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
