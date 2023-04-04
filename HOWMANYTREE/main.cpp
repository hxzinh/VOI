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

int n, h;
long long f[50][50];

long long dp(int x, int h){
    if(x == 0) return (h <= 0);
    ll &res = f[x][h];
    if(res != -1) return res;
    if(h > x) return 0;

    res = 0;
    for(int j = 0; j < x; j++){
        res += dp(j, max(h - 1, 0)) * dp(x - j - 1, 0) + dp(j, 0) * dp(x - j - 1, max(h - 1, 0));
        res -= dp(j, max(h - 1, 0)) * dp(x - j - 1, max(h - 1, 0));
    }
    return res;
}
void xuli(){
    memset(f, -1, sizeof f);
    cout << dp(n, h);
}
int32_t main()
{
    FastIO
    freopen("TREE.INP", "r", stdin);
    freopen("TREE.OUT", "w", stdout);
    cin >> n >> h;

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
