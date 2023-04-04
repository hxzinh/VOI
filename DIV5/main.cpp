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

const int NM = 1e6 + 10;
int T, n;
string s;
unordered_map<int, int> mp;

void sub1() {
    mp.clear();
    ll res = 0;
    for(int mask = 1; mask < MASK(n); mask++) {
        int curNum = 0;
        for(int i = 0; i < n; i++) if(BIT(mask, i))
            curNum = curNum * 10 + (s[i] - '0');

        //cout << curNum << " ";

        if(curNum % 5 == 0 && !mp[curNum]) {
            res++;
            mp[curNum] = 1;
        }
    }

    cout << res << '\n';
}
int32_t main()
{
    FastIO
    freopen("DIV5.INP", "r", stdin);
    freopen("DIV5.OUT", "w", stdout);
    cin >> T;
    while(T--) {
        cin >> n >> s;
        sub1();
    }
    return 0;
}

/* Author: hxzinh */

