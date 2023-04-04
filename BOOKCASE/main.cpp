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

const int NM = 1e6 + 10;
int n, m, q;
int sum[NM];
vector<vector<int>> a;
multiset<int> S[NM];

struct SegmentTree {
    int n;
    vector<int> Min;

    SegmentTree(int _n = 0) {
        n = _n;
        Min.assign(4 * n + 7, INF);
    }

    void update(int i, int l, int r, int u, int x) {
        if(u > r || u < l || l > r) return;
        if(l == r && l == u) {
            Min[i] = x;
            return;
        }

        int m = (l + r) >> 1;
        if(u <= m) update(2 * i, l, m, u, x);
        else update(2 * i + 1, m + 1, r, u , x);

        Min[i] = min(Min[2 * i], Min[2 * i + 1]);
    }

    int getMin(int i, int l, int r, int u, int v) {
        if(u > r || v < l || l > r) return INF;
        if(u <= l && v >= r) return Min[i];

        int m = (l + r) >> 1;
        return min(getMin(2 * i, l, m, u, v), getMin(2 * i + 1, m + 1, r, u, v));
    }

    void update(int u, int x) {
        update(1, 1, n, u, x);
    }

    int getMin(int u, int v) {
        return getMin(1, 1, n, u, v);
    }
};

void sub1() {
    while(q--) {
        int type, x, y, u, v;
        cin >> type >> x >> y;
        if(type == 1) {
            cin >> u >> v;
            swap(a[x][y], a[u][v]);
        }
        else {
            int ans = INF;
            for(int i = x; i <= y; i++) {
                int cur = max(a[i][1], a[i][2]) * 2;
                minimize(ans, cur);
            }
            cout << ans << '\n';
        }
    }
}
void sub2() {
    SegmentTree tree(n);
    for(int i = 1; i <= n; i++) tree.update(i, 2 * max(a[i][1], a[i][2]));

    while(q--) {
        int type, x, y, u, v;
        cin >> type >> x >> y;
        if(type == 1) {
            cin >> u >> v;
            swap(a[x][y], a[u][v]);
            tree.update(x, 2 * max(a[x][1], a[x][2]));
            tree.update(u, 2 * max(a[u][1], a[u][2]));
        }
        else {
            int res = tree.getMin(x, y);
            cout << res << '\n';
        }
    }
}
void xuli() {
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            S[i].insert(a[i][j]);
            sum[i] += a[i][j];
        }
    }

    SegmentTree tree(n);
    for(int i = 1; i <= n; i++) {
        int u = *S[i].rbegin();
        if(u > sum[i] - u) tree.update(i, 2 * u);
        else tree.update(i, sum[i]);
    }

    while(q--) {
        int type, x, y, u, v;
        cin >> type >> x >> y;
        if(type == 1) {
            cin >> u >> v;
            int valx = a[x][y], valu = a[u][v];
            swap(a[x][y], a[u][v]);

            S[x].erase(S[x].find(valx));
            S[x].insert(valu);

            S[u].erase(S[u].find(valu));
            S[u].insert(valx);

            sum[x] += valu - valx;
            sum[u] += valx - valu;

            int tmp = *S[x].rbegin();
            if(tmp > sum[x] - tmp) tree.update(x, 2 * tmp);
            else tree.update(x, sum[x]);

            int tmp2 = *S[u].rbegin();
            if(tmp2 > sum[u] - tmp) tree.update(u, 2 * tmp2);
            else tree.update(u, sum[u]);
        }
        else {
            int res = tree.getMin(x, y);
            cout << res << '\n';
        }
    }
}
int32_t main()
{
    FastIO
    freopen("BOOKCASE.INP", "r", stdin);
    freopen("BOOKCASE.OUT", "w", stdout);
    cin >> n >> m >> q;
    a.assign(n + 7, vector<int>(m + 7, 0));
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= m; j++) cin >> a[i][j];

    if(m == 2) sub2();
    else xuli();
    return 0;
}

/* Author: hxzinh */

