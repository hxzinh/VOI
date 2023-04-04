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

const int NM = 2e3 + 10;
int T, n, x, y;
int result = 0;
bool cx[MASK(20) + 2];

void backtrakc(int i, int mask, int check, int sta) {
    if(i > n) {
        //cout << mask << '\n';
        if(!cx[mask]) {
            result++;
            cx[mask] = true;
        }
        return;
    }

    int curMask = mask, tmp = mask;
    if(i + x - 1 <= n && !BIT(check, 0)) {
        for(int j = i; j <= i + x - 1; j++) curMask |= MASK(j - 1);
        //backtrakc(i, curMask, check | 1, max(sta, i + x - 1));
        backtrakc(i + 1, curMask, 0, max(sta, i + x - 1));
    }

    if(i + y - 1 <= n && !BIT(check, 1)) {
        for(int j = i; j <= i + y - 1; j++)
            if(BIT(tmp, j - 1)) tmp ^= MASK(j - 1);
        //backtrakc(i, tmp, check | 2, max(sta, i + y - 1));
        backtrakc(i + 1, tmp, 0, max(sta, i + y - 1));
    }

    if(i <= sta) backtrakc(i + 1, mask, 0, sta);
}
void sub1() {
    result = 0;
    memset(cx, false, sizeof cx);
    backtrakc(1, 0, 0, 0);
    cout << result << '\n';

    cout << '\n';
}
int32_t main()
{
    FastIO
    freopen("BITSTR.INP", "r", stdin);
    freopen("BITSTR.OUT", "w", stdout);
    cin >> T;
    while(T--) {
        cin >> n >> y >> x;
        sub1();
    }
    return 0;
}

/* Author: hxzinh */

