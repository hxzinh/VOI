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

const int NM = 2e3 + 10;
const int MOD = 1e9 + 7;
int m, d, n;
string sL, sR;
int L[NM], R[NM];
ll f[NM][NM][2];

void add(ll &a, ll b) {
    if(a + b >= MOD) a += b - MOD;
    else a += b;
}
ll dp(int x, int u, bool ok) {
    if(x >= n) return (u == 0);

    ll &res = f[x][u][ok];
    if(res > -1) return res;

    int lim = (ok ? 9 : L[x]);

    res = 0;
    if(x & 1) {
        if(ok || d <= L[x]) {
            add(res, dp(x + 1, (u * 10 + d) % m, ok | d < L[x]));
        }
    } else {
        for(int i = 0; i <= lim; i++) if(i != d) {
            if(ok || i <= L[x]) {
                add(res, dp(x + 1, (u * 10 + i) % m, ok | i < L[x]));
            }
        }
    }

    return res;
}
bool check(string s) {
    int p = 10, u = 0;
    for(int i = 0; i < s.size(); i++) {
        if(p == 10 && s[i] == '0') continue;
        else p = s[i] - '0';
        if(i % 2 != 0) {
            if(s[i] - '0' != d) return false;
        }
        else {
            if(s[i] - '0' == d) return false;
        }
        u = (u * 10 + (s[i] - '0')) % m;
    }
    return (u == 0);
}
void xuli() {
    n = sR.size();
    sL = string(sR.size() - sL.size(), '0') + sL;

    memset(f, -1, sizeof f);
    for(int i = 0; i < n; i++) L[i] = sL[i] - '0';
    int cntL = dp(0, 0, 0);

    memset(f, -1, sizeof f);
    for(int i = 0; i < n; i++) L[i] = sR[i] - '0';
    int cntR = dp(0, 0, 0);

    //cout << cntL << " " << cntR << '\n';
    cout << (cntR - cntL + MOD) % MOD + check(sL);
}
int32_t main()
{
    FastIO
    freopen("CODE.INP", "r", stdin);
    freopen("CODE.OUT", "w", stdout);
    cin >> m >> d;
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
