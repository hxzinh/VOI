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

const int NM = 1e5 + 10;
const int BLSIZE = 320;
int n, q;
int a[NM];
int f[NM][BLSIZE + 1];

void xuli() {
    for(int i = n; i > 0; i--) {
        for(int j = 1; j <= BLSIZE; j++) {
            if(i + a[i] + j > n) f[i][j] = 1;
            else f[i][j] = f[i + a[i] + j][j] + 1;
        }
    }

    while(q--) {
        int x, k;
        cin >> x >> k;

        if(k >= 320) {
            int res = 0;
            while(x <= n) {
                res++;
                x += a[x] + k;
            }
            cout << res << '\n';
        }
        else cout << f[x][k] << '\n';
    }
}
int32_t main()
{
    FastIO
    //freopen("ARRAY.INP", "r", stdin);
    //freopen("ARRAY.OUT", "w", stdout);
    cin >> n;
    for(int i = 1; i <= n; i++) cin >> a[i];
    cin >> q;

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
