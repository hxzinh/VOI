#include <bits/stdc++.h>
#define ll long long
#define int long long
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
int n, sumL, sumR;
ll a[NM], s[NM];

struct FenwickTree {
    int n;
    vector<int> sum;

    FenwickTree(int _n = 0) {
        n = _n;
        sum.assign(n + 7, 0);
    }

    void update(int u, int x) {
        for(; u <= n; u += u & -u) sum[u] += x;
    }

    int getSum(int u) {
        int res = 0;
        for(; u > 0; u -=  u & -u) res += sum[u];
        return res;
    }
};

void xuli() {
    vector<int> vec;
    vec.push_back(0);
    for(int i = 1; i <= n; i++) vec.push_back(s[i]);
    sort(ALL(vec));
    vec.resize(unique(ALL(vec)) - vec.begin());

    FenwickTree tree(vec.size() + 10);
    tree.update(1, 1);

    int res = 0;
    for(int i = 1; i <= n; i++) {
        int l = lower_bound(ALL(vec), s[i] - sumR) - vec.begin() + 1;
        int r = upper_bound(ALL(vec), s[i] - sumL) - vec.begin() + 1;
        if(l < r) res += tree.getSum(r - 1) - tree.getSum(l - 1);

        int cur = lower_bound(ALL(vec), s[i]) - vec.begin() + 1;
        tree.update(cur, 1);
    }

    cout << res;
}
int32_t main()
{
    FastIO
    freopen("C11SEQ.INP", "r", stdin);
    freopen("C11SEQ.OUT", "w", stdout);
    cin >> n >> sumL >> sumR;
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
        s[i] = s[i - 1] + a[i];
    }

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
