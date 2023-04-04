#include <bits/stdc++.h>
#define int long long
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

const int NM = 1e5 + 10;
int n, q;
int a[NM];

struct SegmentTree {
    int n;
    vector<int> sum, lazy;

    SegmentTree(int _n = 0){
        n = _n;
        sum.assign(4 * n + 7, 0);
        lazy.assign(4 * n + 7, 0);
    }

    void pushDown(int i, int l, int r){
        if(!lazy[i]) return;

        int m = (l + r) >> 1;
        sum[2 * i] += lazy[i];
        lazy[2 * i] += lazy[i];
        sum[2 * i + 1] += lazy[i];
        lazy[2 * i + 1] += lazy[i];

        lazy[i] = 0;
    }

    void build(int i, int l, int r, int u, int x){
        if(u < l || u > r || l > r) return;
        if(l == r && l == u){
            sum[i] = x;
            return;
        }

        int m = (l + r) >> 1;
        build(2 * i, l, m, u, x);
        build(2 * i + 1, m + 1, r, u, x);
        sum[i] = max(sum[2 * i], sum[2 * i + 1]);
    }

    void update(int i, int l, int r, int u, int v, int x){
        if(u > r || v < l || l > r) return;
        if(u <= l && v >= r){
            sum[i] += x;
            lazy[i] += x;
            return;
        }
        pushDown(i, l, r);

        int m = (l + r) >> 1;
        update(2 * i, l, m, u, v, x);
        update(2 * i + 1, m + 1, r, u, v, x);
        sum[i] = max(sum[2 * i], sum[2 * i + 1]);
    }

    int getSum(int i, int l, int r, int u, int v){
        if(u > r || v < l || l > r) return -INF;
        if(u <= l && v >= r) return sum[i];
        pushDown(i, l, r);

        int m = (l + r) >> 1;
        int sumL = getSum(2 * i, l, m, u, v);
        int sumR = getSum(2 * i + 1, m + 1, r, u, v);
        return max(sumL, sumR);
    }

    void build(int u, int x){
        build(1, 1, n, u, x);
    }

    void update(int u, int v, int x){
        update(1, 1, n, u, v, x);
    }

    int getSum(int u, int v){
        return getSum(1, 1, n, u, v);
    }
};

void xuli(){
    SegmentTree tree(n);
    for(int i = 1; i <= n; i++) tree.build(i, a[i]);

    //cout << tree.getSum(1, n) << '\n';

    while(q--){
        int type, l, r, x;
        cin >> type;
        if(type == 1){
            cin >> l >> r >> x;
            tree.update(l, r, x);
        } else {
            cin >> l >> r;
            cout << tree.getSum(l, r) << '\n';
        }

        //cout << tree.getSum(1, n) << '\n';
    }
}
int32_t main()
{
    FastIO
    freopen("ITLAZY.INP", "r", stdin);
    freopen("ITLAZY.OUT", "w", stdout);
    cin >> n;
    for(int i = 1; i <= n; i++) cin >> a[i];
    cin >> q;

    xuli();
    return 0;
}

/* Author: hxzinh */
