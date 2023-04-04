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
int n, m, T;
pair<ll, ll> preMax = {-INF, 0}, curMax = {-INF, 0}, curMin = {INF, 0}, preMin = {INF, 0};
int a[NM];

void xuli() {
    /**
    for (int i = 1; i <= n; i++) Max[i][0] = Min[i][0] = a[i];

    for (int k = 1; MASK(k) <= n; k++) {
        for (int i = 1; i + MASK(k) - 1 <= n; i++) {
            Max[i][k] = max(Max[i][k - 1], Max[i + MASK(k - 1)][k - 1]);
            Min[i][k] = min(Min[i][k - 1], Min[i + MASK(k - 1)][k - 1]);
        }
    }
    **/

    sort(a + 1, a + n + 1);
    curMax = {-INF, 0}; preMax = curMax;
    curMin = {INF, 0}; preMin = curMin;

    for(int i = 1; i <= n; i++) {
        if(a[i] >= curMax.fi) {
            preMax = curMax;
            curMax = {a[i], i};
        }
    }

    for(int i = n; i > 0; i--) {
        if(a[i] <= curMin.fi) {
            preMin = curMin;
            curMin = {a[i], i};
        }
    }

    ll res = curMax.fi + preMax.fi - curMin.fi - preMin.fi;
    cout << res << '\n';
}
int32_t main()
{
    FastIO
    freopen("CODE.INP", "r", stdin);
    freopen("CODE.OUT", "w", stdout);
    cin >> T;
    while(T--) {
        cin >> n;
        for(int i = 1; i <= n; i++) cin >> a[i];

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
