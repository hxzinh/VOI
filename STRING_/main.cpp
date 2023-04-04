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

const int NM = 1e6 + 10;
string s;
int n;
int cnt[NM][30];

void sub1() {
    ll res = 0;

    for(int i = 1; i <= n; i++)
        for(int j = 0; j < 26; j++) cnt[i][j] = cnt[i - 1][j] + (s[i] == char(j + 'a'));

    for(int i = 1; i <= n; i++) {
        ll minAns = INF, maxAns = 0;
        for(int j = 1; j <= i; j++) {
            int u = s[j] - 'a';
            minimize(minAns, cnt[i][u] - cnt[0][u]);
            maximize(maxAns, cnt[i][u] - cnt[0][u]);
        }
        maximize(res, maxAns - minAns);

        for(int j = i + 1; j <= n; j++) {
            int u = s[j] - 'a';
            minimize(minAns, cnt[j][u] - cnt[j - i][u]);
            maximize(maxAns, cnt[j][u] - cnt[j - i][u]);
            maximize(res, maxAns - minAns);
        }
    }

    cout << res;
}
int32_t main()
{
    FastIO
    freopen("STRING.INP", "r", stdin);
    freopen("STRING.OUT", "w", stdout);
    cin >> n;
    cin >> s;
    s = '#' + s;

    sub1();
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
