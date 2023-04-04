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

const int NM = 1e5 + 10;
const int MOD = 1e9 + 7;
int n;
int L[NM], R[NM];
ll f[NM][11][2][2];
string sL, sR;

ll dp(int x, int pre, bool okL, bool okR) {
    if(x >= n) return 1;
    ll &res = f[x][pre][okL][okR];
    if(res > -1) return res;

    res = 0;
    for(int i = 0; i < 10; i++) {
        if((okL || i >= L[x])
        && (okR || i <= R[x])){
            if(pre == 10 && i == 0)
                maximize(res, dp(x + 1, pre, okL | (i > L[x]), okR | (i < R[x])) * i);
            else maximize(res, dp(x + 1, i, okL | (i > L[x]), okR | (i < R[x])) * i);
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

    ll ans = 1;
    for(int i = 0; i < n; i++)
        ans = ans * R[i] % MOD;

    ll res = 1, id = -1;
    for(int i = 0; i < n; i++) {
        if(L[i] == R[i]) res = res * L[i] % MOD;
        else break;
        id = i;
    }

    res = res * max(R[id + 1] - 1, 1) % MOD;
    for(int i = id + 2; i < n; i++) res = res * 9 % MOD;

    maximize(res, ans);
    cout << res;
}
int32_t main()
{
    FastIO
    freopen("H.INP", "r", stdin);
    freopen("H.OUT", "w", stdout);
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
