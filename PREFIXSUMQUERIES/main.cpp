#include <bits/stdc++.h>
#define ll long long
#define INF 0x3f3f3f3f
#define pii pair<int, int>
#define pll pair<long long, long long>
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

template<class X, class Y>
	inline bool maximize(X &x, const Y &y) {return (x < y ? x = y, 1 : 0);}
template<class X, class Y>
	inline bool minimize(X &x, const Y &y) {return (x > y ? x = y, 1 : 0);}

const int NM = 2e5 + 10;
int n, q;
int a[NM];

struct SegmentTree {
    int n;
    vector<ll> sum, maxSum;

    SegmentTree(int _n = 0) {
        n = _n;
        sum.assign(4 * n + 7, 0);
        maxSum.assign(4 * n + 7, 0);
    }

    void build(int i, int l, int r) {
        if(l > r) return;
        if(l == r) {
            sum[i] = a[l];
            maxSum[i] = a[l];
            return;
        }

        int m = (l + r) >> 1;
        build(2 * i, l, m);
        build(2 * i + 1, m + 1, r);
        sum[i] = sum[2 * i] + sum[2 * i + 1];
        maxSum[i] = max(maxSum[2 * i], sum[2 * i] + maxSum[2 * i + 1]);
    }

    void update(int i, int l, int r, int u, int x) {
        if(u < l || u > r || l > r) return;
        if(l == r && l == u) {
            sum[i] = x;
            maxSum[i] = x;
            return;
        }

        int m = (l + r) >> 1;
        update(2 * i, l, m, u, x);
        update(2 * i + 1, m + 1, r, u, x);
        sum[i] = sum[2 * i] + sum[2 * i + 1];
        maxSum[i] = max(maxSum[2 * i], sum[2 * i] + maxSum[2 * i + 1]);
    }

    pll getQuery(int i, int l, int r, int u, int v) {
        if(u > r || v < l || l > r) return mp(0, 0);
        if(u <= l && v >= r) return mp(sum[i], maxSum[i]);

        int m = (l + r) >> 1;
        pll sumL = getQuery(2 * i, l, m, u, v);
        pll sumR = getQuery(2 * i + 1, m + 1, r, u, v);
        return mp(sumL.fi + sumR.fi, max(sumL.se, sumL.fi + sumR.se));
    }

    void update(int u, int x) {
        update(1, 1, n, u, x);
    }

    ll getQuery(int u, int v) {
        return getQuery(1, 1, n, u, v).se;
    }
};

void xuli() {
    SegmentTree tree(n);
    tree.build(1, 1, n);

    while(q--) {
        int k, u, v;
        cin >> k >> u >> v;
        if(k == 1) {
            tree.update(u, v);
        } else {
            cout << max(0LL, tree.getQuery(u, v)) << '\n';
        }
    }
}
int32_t main()
{
    FastIO
    freopen("CODE.INP", "r", stdin);
    cin >> n >> q;
    for(int i = 1; i <= n; i++) cin >> a[i];

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
