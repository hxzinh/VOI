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

const int NM = 5e4 + 10;
int n, d;
pii a[NM], c[NM];

struct SegmentTree {
    int n;
    vector<int> val;

    SegmentTree(int _n = 0) {
        n = _n;
        val.assign(4 * n + 7, 0);
    }

    void build(int i, int l, int r) {
        if(l > r) return;
        if(l == r) {
            val[i] = a[l].se;
            return;
        }

        int m = (l + r) >> 1;
        build(2 * i, l, m);
        build(2 * i + 1, m + 1, r);
        val[i] = max(val[2 * i], val[2 * i + 1]);
    }

    void update(int i, int l, int r, int u, int x) {
        if(l > r || u < l || u > r) return;
        if(l == r && l == u) {
            val[i] = x;
            return;
        }

        int m = (l + r) >> 1;
        update(2 * i, l, m, u, x);
        update(2 * i + 1, m + 1, r, u, x);
        val[i] = max(val[2 * i], val[2 * i + 1]);
    }

    int getMax(int i, int l, int r, int u, int v) {
        if(u > r || v < l || l > r) return 0;
        if(u <= l && v >= r) return val[i];

        int m = (l + r) >> 1;
        int maxL = getMax(2 * i, l, m, u, v);
        int maxR = getMax(2 * i + 1, m + 1, r, u, v);
        return max(maxL, maxR);
    }

    void update(int u, int x) {
        update(1, 1, n, u, x);
    }

    int getMax(int u, int v) {
        return getMax(1, 1, n, u, v);
    }
};

bool cmp(const pii A, const pii B) {
    return A.se > B.se;
}
void xuli() {
    sort(a + 1, a + n + 1);
    vector<int> vec;
    for(int i = 1; i <= n; i++) vec.push_back(a[i].fi);
    vec.push_back(INF);

    SegmentTree tree(n);
    sort(c + 1, c + n + 1, cmp);

    //for(int i = 1; i <= n; i++) cout << c[i].fi << " " << c[i].se << '\n';

    int res = 0;
    for(int i = 1; i <= n; i++) {
        int l = lower_bound(ALL(vec), c[i].fi - d) - vec.begin() + 1;
        int r = upper_bound(ALL(vec), c[i].fi + d) - vec.begin();
        int id = lower_bound(ALL(vec), c[i].fi) - vec.begin() + 1;

        int maxL = tree.getMax(l, id), maxR = tree.getMax(id, r);
        if(maxL >= 2 * c[i].se && maxR >= 2 * c[i].se) {
            res++;
            continue;
        }
        tree.update(id, c[i].se);
    }

    cout << res;
}
int32_t main()
{
    FastIO
    freopen("PETROL.INP", "r", stdin);
    freopen("PETROL.OUT", "w", stdout);
    cin >> n >> d;
    for(int i = 1; i <= n; i++) {
        cin >> a[i].fi >> a[i].se;
        c[i] = a[i];
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
