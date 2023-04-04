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

const int NM = 5e3 + 10;
int n;
int dp[NM][NM];
bool cx[NM];

struct Data {
    int fi, se, id;

    bool inline operator < (const Data &A) {
        return fi < A.fi;
    }
} a[NM];

void backtrack(int x, int mask) {

}
void xuli() {
    sort(a + 1, a + n + 1);
    priority_queue<pii> pq;

    int res = 0;
    for(int i = 1; i <= n; i++) {
        pq.push({a[i].se, i});
        if(i & 1) {
            pii cur = pq.top();
            pq.pop();
            res += cur.fi;
            cx[cur.se] = true;
        }
    }

    cout << res << '\n';
    stack<int> st;
    for(int i = 1; i <= n; i++) {
        if(cx[i]) st.push(a[i].id);
        else {
            cout << a[i].id << " " << st.top() << '\n';
            st.pop();
        }
    }
}
int32_t main()
{
    FastIO
    freopen("VODIVIDE.INP", "r", stdin);
    freopen("VODIVIDE.OUT", "w", stdout);
    cin >> n;
    for(int i = 1; i <= n; i++) cin >> a[i].fi;
    for(int i = 1; i <= n; i++) cin >> a[i].se;

    for(int i = 1; i <= n; i++) a[i].id = i;

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
