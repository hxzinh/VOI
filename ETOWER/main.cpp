#include <bits/stdc++.h>
#define ll long long
#define INF 0x3f3f3f3f
#define MAX 0x3f3f3f3f3f3f3f3f
#define pii pair<int, int>
#define mp(x, y) make_pair(x, y)
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

const int NM = 3e6 + 10;
int n, start, target, T;
int a[NM], t[NM];
ll f[NM];
bool inq[NM];

struct Data {
    int u, cost;

    bool inline operator < (const Data &A) const {
        return cost > A.cost;
    }
};

struct SegmentTree {
    int n;
    vector<pii> Max;

    SegmentTree(int _n = 0) {
        n = _n;
        Max.assign(4 * n + 7, mp(-INF, INF));
    }

    void build(int i, int l, int r, int t) {
        if(l > r) return;
        if(l == r) {
            Max[i] = mp(a[l] + t * l, l);
            return;
        }

        int m = (l + r) >> 1;
        build(2 * i, l, m, t);
        build(2 * i + 1, m + 1, r, t);

        if(Max[2 * i].fi > Max[2 * i + 1].fi) Max[i] = Max[2 * i];
        else Max[i] = Max[2 * i + 1];
    }

    void update(int i, int l, int r, int u, int x) {
        if(u < l || u > r || l > r) return;
        if(l == r && l == u) {
            Max[i] = mp(x, u);
            return;
        }

        int m = (l + r) >> 1;
        update(2 * i, l, m, u, x);
        update(2 * i + 1, m + 1, r, u, x);
        if(Max[2 * i].fi > Max[2 * i + 1].fi) Max[i] = Max[2 * i];
        else Max[i] = Max[2 * i + 1];
    }

    pii getMax(int i, int l, int r, int u, int v) {
        if(u > r || v < l || l > r) return mp(-INF, INF);
        if(u <= l && v >= r) return Max[i];

        int m = (l + r) >> 1;
        pii maxL = getMax(2 * i, l, m, u, v);
        pii maxR = getMax(2 * i + 1, m + 1, r, u, v);
        if(maxL.fi > maxR.fi) return maxL;
        else return maxR;
    }

    pii getMax(int u, int v) {
        return getMax(1, 1, n, u, v);
    }

    void update(int u, int x) {
        update(1, 1, n, u, x);
    }

    void build(int t) {
        build(1, 1, n, t);
    }
} treeL, treeR;

void xuli() {
    treeL = SegmentTree(n + 7);
    treeR = SegmentTree(n + 7);
    for(int i = 1; i <= n; i++) {
        treeL.update(i, a[i] + i);
        treeR.update(i, a[i] - i);
    }

    for(int i = 1; i <= n; i++) f[i] = MAX;

    //for(int i = 1; i <= n; i++) cout << treeR.getMin(i, i) << " ";
    //cout << '\n';
    //cout << treeR.getMin(2, 3) << '\n';

    f[start] = 0;
    priority_queue<Data> q;
    q.push({start, 0});

    while(q.size()) {
        int u = q.top().u, cost = q.top().cost;
        q.pop();

        if(cost != f[u]) continue;
        //cout << u << " " << f[u] << '\n';

        while(true) {
            int l = max(1, u - a[u]), r = u - 1;
            pii v = treeL.getMax(l, r);
            if(u > v.fi || v.se == INF) break;
            if(minimize(f[v.se], f[u] + t[v.se])) q.push({v.se, f[v.se]});
            treeL.update(v.se, -INF);
            treeR.update(v.se, -INF);
        }

        while(true) {
            int l = u + 1, r = min(n, u + a[u]);
            pii v = treeR.getMax(l, r);
            if(-u > v.fi || v.se == INF) break;
            if(minimize(f[v.se], f[u] + t[v.se])) q.push({v.se, f[v.se]});
            treeR.update(v.se, -INF);
            treeL.update(v.se, -INF);
        }
    }

    cout << f[target] << '\n';
}
int32_t main()
{
    FastIO
    freopen("ETOWER.INP", "r", stdin);
    freopen("ETOWER.OUT", "w", stdout);
    cin >> n >> start >> target;
    for(int i = 1; i <= n; i++) cin >> a[i];
    for(int i = 1; i <= n; i++) cin >> t[i];

    xuli();
    return 0;
}

/* Author: hxzinh */
