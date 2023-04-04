#include <bits/stdc++.h>
#define ll long long
#define int long long
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

int n;
string sL, sR;
string result = "";
int L[50], R[50];
pair<ll, string> f[50][12][2][2];

pair<ll, string> dp(int x, int p, bool okL, bool okR) {
    if(x >= n) return {1, ""};

    pair<ll, string> &res = f[x][p][okL][okR];
    if(res.fi > -1) return res;

    res.fi = 0;
    for(int i = 0; i < 10; i++) {
        if((okL || i >= L[x])
        && (okR || i <= R[x])) {
            if(p != 10 && i != 0) {
                pair<ll, string> cur = dp(x + 1, (p == 10 && i == 0) ? 10 : i, okL | i > L[x], okR | i < R[x]);
                if(maximize(res.fi, i * cur.fi)) {
                    res.se = "";
                    res.se += char(i + '0');
                    res.se += cur.se;
                }
            }
        }
    }
    return res;
}
void xuli() {
    n = sR.size();
    sL = string(sR.size() - sL.size(), '0') + sL;
    for(int i = 0; i < n; i++) {
        L[i] = sL[i] - '0';
        R[i] = sR[i] - '0';
    }

    for(int i = 0; i <= n; i++)
        for(int j = 0; j <= 10; j++)
            for(int u = 0; u < 2; u++)
                for(int v = 0; v < 2; v++) f[i][j][u][v] = {-1, ""};
    cout << dp(0, 10, 0, 0).se;
}
int32_t main()
{
    FastIO
    freopen("CODE.INP", "r", stdin);
    freopen("CODE.OUT", "w", stdout);
    cin >> sL >> sR;

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
