#include <bits/stdc++.h>
#define ll long long
#define INF 0x3f3f3f3f3f3f3f
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
ll a[25];
ll res = INF;

void backtrack(int x, ll sumL, ll sumR){
    if(x > n){
        minimize(res, abs(sumL - sumR));
        return;
    }
    backtrack(x + 1, sumL + a[x], sumR);
    backtrack(x + 1, sumL, sumR + a[x]);
}
int32_t main()
{
    FastIO
    cin >> n;
    for(int i = 1; i <= n; i++) cin >> a[i];

    backtrack(1, 0, 0);
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
