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

const int NM = 105;
int n;
map<string, int> mp;

int32_t main()
{
    FastIO
    freopen("LOZINKA.INP", "r", stdin);
    freopen("LOZINKA.OUT", "w", stdout);
    cin >> n;

    pair<int, char> res = {0, '0'};
    for(int i = 1; i <= n; i++) {
        string s; cin >> s;

        mp[s]++;
        reverse(ALL(s));
        if(mp[s]) {
            if(maximize(res.fi, s.size())) res.se = s[s.size() / 2];
        }
    }

    cout << res.fi << " " << res.se;
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
