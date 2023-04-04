#include <bits/stdc++.h>
#define ll long long
#define INF 0x3f3f3f3f
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

const int NM = 1e6 + 10;
int n, k;
ll a[NM], cnt[5][5];

void xuli() {
    cin >> n >> k;

    int res = 0;
    if(k % 2 == 0) {
        ll tmp = (n - k / 2) / k + 1;
        res += pow(tmp, 3);
    }

    ll tmp = n / k;
    res += pow(tmp, 3);
    cout << res;
}
int32_t main()
{
    FastIO
    freopen("TRIPLET.INP", "r", stdin);
    freopen("TRIPLET.OUT", "w", stdout);
    cin >> n >> k;

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
