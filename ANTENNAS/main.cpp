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

const int NM = 2e5 + 10;
int n, start, target, T;
int a[NM], f[NM];
bool inq[NM];

struct SegmentTree {
    int n;
    vector<int> Max;

    SegmentTree(int _n = 0) {
        n = _n;
        Max.assign(4 * n + 7, INF);
    }

    void build(int i, int l, int r, int t) {
        if(l > r) return;
        if(l == r) {
            Max[i] = a[l] + t * l;
            return;
        }

        int m = (l + r) >> 1;
        build(2 * i, l, m, t);
        build(2 * i + 1, m + 1, r, t);
        Max[i] = max(Max[2 * i], Max[2 * i + 1]);
    }

    void update(int i, int l, int r, int u, int x) {
        if(u < l || u > r || l > r) return;
        if(l == r && l == u) {
            Max[i] = x;
            return;
        }

        int m = (l + r) >> 1;
        update(2 * i, l, m, u, x);
        update(2 * i + 1, m + 1, r, u, x);
        Max[i] = max(Max[2 * i], Max[2 * i + 1]);
    }

    int getMax(int i, int l, int r, int u, int v) {
        if(u > r || v < l || l > r) return -INF;
        if(u <= l && v >= r) return Max[i];

        int m = (l + r) >> 1;
        int maxL = getMax(2 * i, l, m, u, v);
        int maxR = getMax(2 * i + 1, m + 1, r, u, v);
        return max(maxL, maxR);
    }

    int getMax(int u, int v) {
        return getMax(1, 1, n, u, v);
    }

    void update(int u, int x) {
        update(1, 1, n, u, x);
    }

    void build(int t) {
        build(1, 1, n, t);
    }
} treeL, treeR;

void sub1() {
    for(int i = 1; i <= n; i++) f[i] = INF;
    queue<int> q;
    q.push(start);
    f[start] = 0;

    while(q.size()) {
        int u = q.front();
        q.pop();

        inq[u] = false;
        if(u == target) break;

        for(int i = 1; i <= n; i++) {
            if(abs(u - i) <= min(a[u], a[i])) {
                if(minimize(f[i], f[u] + 1)) {
                    if(!inq[i]) {
                        inq[i] = true;
                        q.push(i);
                    }
                }
            }
        }
    }

    cout << f[target] << '\n';
}
void xuli() {
    treeL = SegmentTree(n + 7);
    treeR = SegmentTree(n + 7);
    for(int i = 1; i <= n; i++) {
        treeL.update(i, a[i] + i);
        treeR.update(i, a[i] - i);
    }

    for(int i = 1; i <= n; i++) f[i] = INF;

    //for(int i = 1; i <= n; i++) cout << treeR.getMin(i, i) << " ";
    //cout << '\n';
    //cout << treeR.getMin(2, 3) << '\n';

    f[start] = 0;
    queue<int> q;
    q.push(start);

    while(q.size()) {
        int u = q.front();
        q.pop();

        //cout << u << " " << f[u] << '\n';

        while(true) {
            int l = max(1, u - a[u]), r = u - 1, v = INF;
            while(l <= r) {
                int m = (l + r) >> 1;
                int curMax = treeL.getMax(m, r);
                if(u <= curMax) {
                    v = m;
                    l = m + 1;
                } else r = m - 1;
            }
            if(v == INF) break;
            if(minimize(f[v], f[u] + 1)) q.push(v);
            treeL.update(v, -INF);
            treeR.update(v, -INF);
        }

        while(true) {
            int l = u + 1, r = min(n, u + a[u]), v = INF;
            while(l <= r) {
                int m = (l + r) >> 1;
                int curMax = treeR.getMax(l, m);
                if(-u <= curMax) {
                    v = m;
                    r = m - 1;
                } else l = m + 1;
            }
            if(v == INF) break;
            if(minimize(f[v], f[u] + 1)) q.push(v);
            treeR.update(v, -INF);
            treeL.update(v, -INF);
        }
    }

    cout << f[target] << '\n';
}
int32_t main()
{
    FastIO
    freopen("ANTENNAS.INP", "r", stdin);
    freopen("ANTENNAS.OUT", "w", stdout);
    cin >> T;
    while(T--) {
        cin >> n >> start >> target;
        for(int i = 1; i <= n; i++) cin >> a[i];

        xuli();
    }
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
