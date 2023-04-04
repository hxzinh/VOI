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

ll T, n, k, s, b;

void xuli() {
    if(s >= b * k && s <= n * (k - 1) + b * k) {
        if(s >= b * k) {
            s -= b * k;
            cout << b * k + min(s, k - 1) << " ";
            s -= min(s, k - 1);
        }
        for(int i = 2; i <= n; i++) {
            if(s) {
                cout << min(s, k - 1) << " ";
                s -= min(s, k - 1);
            } else cout << 0 << " ";
        }
    } else {
        cout << -1;
    }

    cout << '\n';
}
int32_t main()
{
    FastIO
    freopen("CODE.INP", "r", stdin);
    cin >> T;
    while(T--) {
        cin >> n >> k >> b >> s;
        xuli();
    }
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
