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

int n;

int32_t main()
{
    FastIO
    freopen("DOFF.INP", "r", stdin);
    freopen("DOFF.OUT", "w", stdout);
    cin >> n;
    int res = 0, ans = , cnt = 0;
    for(int i = 1; i <= n; i++)
        if(i % 6 == 0 || i % 7 == 0) res++;
    n -= 3;
    for(int i = 1; i <= n; i++)
        if(i % 6 == 0 || i % 7 == 0) ans++;

    cout << res << " " << ans;
    return 0;
}

/* Author: hxzinh */
