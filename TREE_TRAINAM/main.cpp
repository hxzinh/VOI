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

const int NM = 1e5 + 10;
int n;
int a[NM];

void xuli() {
    set<pii> S;
    for(int i = 1; i <= n; i++) S.insert({a[i], i});

    for(int i = 1; i < n; i++) {
        pii u = *S.begin(), v = *S.rbegin();
        S.erase({u.fi, u.se});
        S.erase({v.fi, v.se});

        cout << u.se << " " << v.se << '\n';

        u.fi--; v.fi--;
        if(u.fi) S.insert({u.fi, u.se});
        if(v.fi) S.insert({v.fi, v.se});
    }
}
int32_t main()
{
    FastIO
    freopen("TREE.INP", "r", stdin);
    freopen("TREE.OUT", "w", stdout);
    cin >> n;
    for(int i = 1; i <= n; i++) cin >> a[i];

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
