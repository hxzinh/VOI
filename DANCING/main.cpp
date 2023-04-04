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
int n, m;
int a[NM], b[NM];

int32_t main()
{
    FastIO
    cin >> n >> m;
    for(int i = 1; i <= n; i++) cin >> a[i];
    for(int j = 1; j <= m; j++) cin >> b[j];

    sort(a + 1, a + n + 1);
    sort(b + 1, b + m + 1);

    int x = 1, y = 1, res = 0;
    while(x <= n && y <= m){
        while(a[x] <= b[y] && x <= n) x++;
        if(x > n) break;
        res++;
        x++; y++;
    }
    cout << res;
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
