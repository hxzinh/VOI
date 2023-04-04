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

const int NM = 1e5 + 10;
int n, q;
int a[NM];

struct SegmentTree {
    int n;
    vector<multiset<int>> val;

    SegmentTree(int _n = 0){
        n = _n;
        val.assign(4 * n + 7, multiset<int>());
    }

    void build(int i, int l, int r){
        if(l > r) return;
        if(l == r){
            val[i].insert(a[l]);
            return;
        }

        int m = (l + r) >> 1;
        build(2 * i, l, m);
        build(2 * i + 1, m + 1, r);
        val[i] = val[2 * i];
        val[i].insert(ALL(val[2 * i + 1]));
    }

    void update(int i, int l, int r, int u, int x){
        if(u < l || u > r || l > r) return;
        val[i].erase(val[i].lower_bound(a[u]));
        val[i].insert(x);
        if(l == r && l == u) return;

        int m = (l + r) >> 1;
        if(u <= m) update(2 * i, l, m, u, x);
        else update(2 * i + 1, m + 1, r, u, x);
    }

    int getQuery(int i, int l, int r, int u, int v, int k){
        if(u > r || v < l || l > r) return INF;
        if(u <= l && v >= r){
            if(*val[i].rbegin() < k) return INF;
            int tmp = *val[i].lower_bound(k);
            return (tmp >= k ? tmp : INF);
        }

        int m = (l + r) >> 1;
        int queryL = getQuery(2 * i, l, m, u, v, k);
        int queryR = getQuery(2 * i + 1, m + 1, r, u, v, k);
        return min(queryL, queryR);
    }

    void update(int u, int x){
        update(1, 1, n, u, x);
    }

    int getQuery(int u, int v, int k){
        return getQuery(1, 1, n, u, v, k);
    }
};

void xuli(){
    SegmentTree tree(n);
    tree.build(1, 1, n);

    while(q--){
        int type, u, v, k;
        cin >> type;
        if(type == 1){
            cin >> u >> v;
            tree.update(u, v);
            a[u] = v;
        } else {
            cin >> u >> v >> k;
            int res = tree.getQuery(u, v, k);
            cout << (res < INF ? res : -1) << '\n';
        }
    }
}
int32_t main()
{
    FastIO
    freopen("ITDS1.INP", "r", stdin);
    freopen("ITDS1.OUT", "w", stdout);
    cin >> n >> q;
    for(int i = 1; i <= n; i++) cin >> a[i];

    xuli();
    return 0;
}

/* Author: hxzinh */
