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

template<class X, class Y>
	inline bool maximize(X &x, const Y &y) {return (x < y ? x = y, 1 : 0);}
template<class X, class Y>
	inline bool minimize(X &x, const Y &y) {return (x > y ? x = y, 1 : 0);}

const int NM = 1e5 + 10;
int n, q;
int a[NM];

struct SegmentTree {
    int n;
    vector<int> Odds, Evens, lazyOdd, lazyEven;

    SegmentTree(int _n = 0) {
        n = _n;
        Odds.assign(4 * n + 7, 0);
        Evens.assign(4 * n + 7, 0);
        lazyEven.assign(4 * n + 7, 0);
        lazyOdd.assign(4 * n + 7, 0);
    }

    void update(int i, int l, int r, int u, int v, int x) {
        if(l > v || r < u || l > r) return;
        if(u)
    }
};

int32_t main()
{
    FastIO
    freopen("QUERYSUMS.INP", "r", stdin);
    freopen("QUERYSUMS.OUT", "w", stdout);
    return 0;
}

/* Author: hxzinh */

