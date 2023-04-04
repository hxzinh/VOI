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
int n, m;
ll a[NM], b[NM];
bool cx[NM];

void xuli() {
    int L = 1, R = 2, cur = 1;

    int res = 0;
    while(true) {
        while(b[L] >= a[cur] && cur <= n) cur++;
        while(b[R] <= a[cur] && R <= m) R++;

        if(R > m || cur > n) break;
        if(b[L] < a[cur] && a[cur] < b[R]) res++;

        cx[L] = true; cx[R] = true;
        cur++;
        while(cx[L]) L++;
        while(cx[R] || R <= L) {
            R++;
            if(R > m) break;
        }
        if(R > m) break;
    }
    cout << res;
}
int32_t main()
{
    FastIO
    freopen("ELVES.INP", "r", stdin);
    freopen("ELVES.OUT", "w", stdout);
    cin >> n >> m;
    for(int i = 1; i <= n; i++) cin >> a[i];
    for(int i = 1; i <= m; i++) cin >> b[i];

    sort(a + 1, a + n + 1);
    sort(b + 1, b + m + 1);

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
