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

const int NM = 2e2 + 10;
int n, t;
int numIn[NM], numOut[NM];
pii a[NM];

void xuli() {
    int res = -INF;
    for(int i = 1; i <= n; i++) numIn[i] = 1;
    for(int i = 1; i <= n; i++) {
        for(int j = i + 1; j <= n; j++) {
            if(a[i].fi < a[j].fi && a[i].se > a[j].se) {
                numIn[i]++;
                numOut[j]++;
            }
            if(a[i].fi > a[j].fi && a[i].se < a[j].se) {
                numOut[i]++;
                numIn[j]++;
            }
        }

        if(a[i].se - a[i].fi <= t) maximize(res, numIn[i] - numOut[i]);
     }

     cout << res;
}
int32_t main()
{
    FastIO
    freopen("SEGMENT.INP", "r", stdin);
    freopen("SEGMENT.OUT", "w", stdout);
    cin >> n >> t;
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
