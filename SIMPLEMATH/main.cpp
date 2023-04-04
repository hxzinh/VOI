#include <bits/stdc++.h>
#define ll long long
#define INF 0x3f3f3f3f
#define pii pair<int, int>
#define pll pair<long long, long long>
#define fi first
#define se second
#define ALL(v) (v).begin(), (v).end()
#define popcount(x) __builtin_popcount(x)
#define setp(x) setprecision(x)
#define MASK(x) (1LL << (x))
#define BIT(x, i) ((x) >> (i) & 1)
#define FastIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

/**
//PRAGMA
#pragma GCC target("popcnt")
**/

/**
//ordered_set
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
typedef tree<pii,
             null_type,
             less<pii>,
             rb_tree_tag,
             tree_order_statistics_node_update> ordered_set;
**/

template<class X, class Y>
	inline bool maximize(X &x, const Y &y) {return (x < y ? x = y, 1 : 0);}
template<class X, class Y>
	inline bool minimize(X &x, const Y &y) {return (x > y ? x = y, 1 : 0);}

typedef long double ld;

const int NM = 5e5 + 10;
int n;
string s;
int cnt[NM], add[NM], del[NM];

void xuli() {
    for(int i = 1; i <= n; i++) {
        cnt[i] = cnt[i - 1] + (s[i] == 'U') + (s[i] == 'E')
                + (s[i] == 'O') + (s[i] == 'A') + (s[i] == 'I') + (s[i] == 'Y');
    }

    for (int i = 0; i < n; i++) {
        if (s[i] == 'Y' || s[i] == 'U' || s[i] == 'E' || s[i] == 'O' || s[i] == 'A' || s[i] == 'I') {
            add[1]++;
            add[n - i + 1]--;
            del[i + 2]++;
            del[n + 2]--;
        }
    }

    ld res = 0, ans = 0;
    for(int i = 1; i <= n; i++) {
        add[i] += add[i - 1];
        del[i] += del[i - 1];

        ans += add[i] - del[i];
        res += ans / i;
    }

    cout << fixed << setprecision(7) << res << '\n';
}
int32_t main()
{
    FastIO
    freopen("SIMPLEMATH.INP", "r", stdin);
    freopen("SIMPLEMATH.OUT", "w", stdout);
    cin >> s;
    n = s.size();

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
