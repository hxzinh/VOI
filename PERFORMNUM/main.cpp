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

ll a[] = {0, 11, 111, 1111, 11111, 111111, 1111111, 11111111, 111111111};
ll n;
bool ok = false;

void backtrack(ll x, ll u){
    if(x == 1){
        if(u == 0) ok = true;
        return;
    }

    if(u >= x) backtrack(x / 10, u % x);
    backtrack(x / 10, u);
    return;
}
int32_t main()
{
    FastIO
    cin >> n;

    backtrack(1111111111, n);
    if(ok) cout << "YES";
    else cout << "NO";
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
