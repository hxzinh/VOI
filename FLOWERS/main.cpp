#include <bits/stdc++.h>
#define int long long
#define INF 0x3f3f3f3f3f3f3f3f
#define pii pair<int, int>
#define fi first
#define se second
#define ALL(v) (v).begin(), (v).end()
#define popcount(x) __builtin_popcount(x)
#define set(x) setprecision(x)
#define MASK(x) (1LL << (x))
#define BIT(x, i) ((x) >> (i) & 1)
#define FastIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

template<class X, class Y>
	inline bool maximize(X &x, const Y &y) {return (x < y ? x = y, 1 : 0);}
template<class X, class Y>
	inline bool minimize(X &x, const Y &y) {return (x > y ? x = y, 1 : 0);}

const int NM = 2e5 + 10;
int n, maxHigh = -1;
int a[NM], h[NM], f[NM];

struct FenwickTree {
    int n;
    vector<int> val;

    FenwickTree(int _n = 0){
        n = _n;
        val.assign(n + 7, 0);
    }

    void update(int x, int c){
        for(; x <= n; x += x & -x) maximize(val[x], c);
    }

    int getMax(int u){
        int res = 0;
        for(; u > 0; u -= u & -u) maximize(res, val[u]);
        return res;
    }
};

void xuli(){
    FenwickTree tree(maxHigh + 1);

    int res = -INF;
    for(int i = 1; i <= n; i++){
        maximize(f[i], tree.getMax(h[i] - 1) + a[i]);
        tree.update(h[i], f[i]);
        maximize(res, f[i]);
    }

    cout << res;
}
int32_t main()
{
    FastIO
    freopen("FLOWERS.INP", "r", stdin);
    freopen("FLOWERS.OUT", "w", stdout);
    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> h[i];
        maximize(maxHigh, h[i]);
    }
    for(int i = 1; i <= n; i++) cin >> a[i];

    xuli();
    return 0;
}
