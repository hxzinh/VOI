#include <bits/stdc++.h>
#define ll long long
#define INF 0x3f3f3f3f
#define pii pair<int, int>
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

const int NM = 5e5 + 10;
int Sub, n, k;
int a[NM];

struct SegmentTree {
    int n;
    vector<int> Max;

    SegmentTree(int _n = 0){
        n = _n;
        Max.assign(4 * n + 7, -INF);
    }

    void build(int i, int l, int r) {
        if(l > r) return;
        if(l == r) {
            Max[i] = a[l];
            return;
        }

        int m = (l + r) >> 1;
        build(2 * i, l, m);
        build(2 * i + 1, m + 1, r);
        Max[i] = max(Max[2 * i], Max[2 * i + 1]);
    }

    void update(int i, int l, int r, int u, int x){
        if(u < l || u > r || l > r) return;
        if(l == r && l == u){
            Max[i] = x;
            return;
        }

        int m = (l + r) >> 1;
        update(2 * i, l, m, u, x);
        update(2 * i + 1, m + 1, r, u, x);
        Max[i] = max(Max[2 * i], Max[2 * i + 1]);
    }

    int getMax(int i, int l, int r, int u, int v){
        if(u > r || v < l || l > r) return -INF;
        if(u <= l && v >= r) return Max[i];

        int m = (l + r) >> 1;
        int maxL = getMax(2 * i, l, m, u, v);
        int maxR = getMax(2 * i + 1, m + 1, r, u, v);
        return max(maxL, maxR);
    }

    void update(int u, int x){
        update(1, 1, n, u, x);
    }

    int getMax(int u, int v){
        return getMax(1, 1, n, u, v);
    }
};

void xuli() {
    SegmentTree tree(n);
    tree.build(1, 1, n);

    for(int i = k; i <= n; i++) {
        cout << tree.getMax(i - k + 1, i) << " ";
    }
}
int main()
{
    FastIO
    freopen("MAXSEGMENT.INP", "r", stdin);
    freopen("MAXSEGMENT.OUT", "w", stdout);
    cin >> Sub;
    cin >> n >> k;
    for(int i = 1; i <= n; i++) cin >> a[i];

    xuli();
    return 0;
}

/* Author: hxzinh */
