#include <bits/stdc++.h>
#define int long long
#define INF 0x3f3f3f3f3f3f3f3f
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
int n, k;
int a[NM], f[NM];

struct SegmentTree {
    int n;
    vector<int> Max;

    SegmentTree(int _n = 0){
        n = _n;
        Max.assign(4 * n + 7, -INF);
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

void xuli(){
    SegmentTree tree(n);
    for(int i = 1; i <= k; i++) maximize(f[i], a[i]);
    for(int i = 1; i <= k; i++) tree.update(i, f[i]);
    for(int i = k + 1; i <= n; i++){
        if(maximize(f[i], tree.getMax(max(1LL, i - k), i - 1) + a[i]))
            tree.update(i, f[i]);
    }

    cout << tree.getMax(1, n);
}
void sub1(){
    for(int i = 1; i <= n; i++) maximize(f[i], a[i]);
    for(int i = 1; i <= n; i++){
        for(int j = max(1LL, i - k); j < i; j++) maximize(f[i], f[j] + a[i]);
    }

    int res = 0;
    for(int i = 1; i <= n; i++) maximize(res, f[i]);
    cout << res;
}
int32_t main()
{
    FastIO
    freopen("ITMED.INP", "r", stdin);
    freopen("ITMED.OUT", "w", stdout);
    cin >> n >> k;
    for(int i = 1; i <= n; i++) cin >> a[i];

    xuli();
    return 0;
}

/* Author: hxzinh */
