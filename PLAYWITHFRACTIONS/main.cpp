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

const int NM = 1e4 + 10;
ll T, a, b, c, d;

void Minimum(ll &u, ll &v) {
    ll tmp = __gcd(u, v);
    while(tmp != 1) {
        u /= tmp;
        v /= tmp;
        tmp = __gcd(u, v);
    }
}
void xuli() {
    double s1 = (a * 1.00) / (b * 1.00), s2 = (c * 1.00) / (d * 1.00);
    int res = 0;
    if(s1 == s2) {
        cout << 0 << '\n';
        return;
    }

    ll u = b * c, v = a * d;
    ll tmp = __gcd(u, v);
    res = (u != tmp) + (v != tmp);

    cout << res << '\n';
}
int32_t main()
{
    FastIO
    freopen("CODE.INP", "r", stdin);
    freopen("CODE.OUT", "w", stdout);
    cin >> T;
    while(T--) {
        cin >> a >> b >> c >> d;

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
