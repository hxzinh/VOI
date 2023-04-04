#include <bits/stdc++.h>
#define ll long long
#define INF 0x3f3f3f3f
#define pii pair<int, int>
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
ll a[NM];

struct SegmentTree {
    int n;
    vector<ll> Min;

    SegmentTree(int _n = 0) {
        n = _n;
        Min.assign(4 * n + 7, INF);
    }

    void update(int i, int l, int r, int u, int x) {
        if(u < l || u > r || l > r) return;
        if(l == r && l == u) {
            Min[i] = x;
            return;
        }

        int m = (l + r) >> 1;
        if(u <= m) update(2 * i, l, m, u, x);
        else update(2 * i + 1, m + 1, r, u, x);

        Min[i] = min(Min[2 * i], Min[2 * i + 1]);
    }

    ll getMin(int i, int l, int r, int u, int v) {
        if(u > r || v < l || l > r) return INF;
        if(u <= l && v >= r) return Min[i];

        int m = (l + r) >> 1;
        int minL = getMin(2 * i, l, m, u, v);
        int minR = getMin(2 * i + 1, m + 1, r, u, v);
        return min(minL, minR);
    }

    void update(int u, int x) {
        update(1, 1, n, u, x);
    }

    ll getMin(int u, int v) {
        return getMin(1, 1, n, u, v);
    }
};

void xuli() {
    SegmentTree down(n), up(n);
    for(int i = 1; i <= n; i++) {
        down.update(i, a[i] - i);
        up.update(i, a[i] + i);
    }

    while(q--) {
        int type, u, x;
        cin >> type;
        if(type == 1) {
            cin >> u >> x;
            a[u] = x;
            down.update(u, x - u);
            up.update(u, x + u);
        } else {
            cin >> u;
            ll ansL = down.getMin(1, u) + u;
            ll ansR = up.getMin(u, n) - u;
            cout << min(ansL, ansR) << '\n';
        }
    }
}
int32_t main()
{
    FastIO
    freopen("CODE.INP", "r", stdin);
    freopen("CODE.OUT", "w", stdout);
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
