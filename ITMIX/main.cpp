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
const int MOD = 1e9 + 7;
int n, q;
int a[NM];

void add(int &a, int b){
    if(a + b >= MOD) a += b - MOD;
    else a += b;
}

struct SegmentTree {
    int n;
    vector<int> sum, lazy, mul, ass;

    SegmentTree(int _n = 0){
        n = _n;
        sum.assign(4 * n + 7, 0);
        lazy.assign(4 * n + 7, 0);
        mul.assign(4 * n + 7, 1);
        ass.assign(4 * n + 7, INF);
    }

    void build(int i, int l, int r){
        if(l > r) return;
        if(l == r){
            sum[i] = a[l] % MOD;
            return;
        }

        int m = (l + r) >> 1;
        build(2 * i, l, m);
        build(2 * i + 1, m + 1, r);
        sum[i] = (sum[2 * i] + sum[2 * i + 1]) % MOD;
    }

    void pushDown(int i, int l, int r){
        int m = (l + r) >> 1;
        if(ass[i] < INF){
            sum[2 * i] = ass[i] * (m - l + 1) % MOD;
            sum[2 * i + 1] = ass[i] * (r - m) % MOD;
            ass[2 * i] = ass[2 * i + 1] = ass[i];
            lazy[2 * i] = lazy[2 * i + 1] = 0;
            mul[2 * i] = mul[2 * i + 1] = 1;
            ass[i] = INF;
        }

        sum[2 * i] = sum[2 * i] * mul[i] % MOD;
        sum[2 * i + 1] = sum[2 * i + 1] * mul[i] % MOD;
        mul[2 * i] = mul[2 * i] * mul[i] % MOD;
        mul[2 * i + 1] = mul[2 * i + 1] * mul[i] % MOD;

        sum[2 * i] = (sum[2 * i] + lazy[i] * (m - l + 1)) % MOD;
        sum[2 * i + 1] = (sum[2 * i + 1] + lazy[i] * (r - m)) % MOD;
        lazy[2 * i] = (lazy[2 * i] * mul[i] % MOD + lazy[i]) % MOD;
        lazy[2 * i + 1] = (lazy[2 * i + 1] * mul[i] % MOD + lazy[i]) % MOD;

        mul[i] = 1;
        lazy[i] = 0;
    }

    void updateAdd(int i, int l, int r, int u, int v, int x){
        if(u > r || v < l || l > r) return;
        if(u <= l && v >= r){
            add(sum[i], x * (r - l + 1) % MOD);
            add(lazy[i], x);
            return;
        }
        pushDown(i, l, r);

        int m = (l + r) >> 1;
        updateAdd(2 * i, l, m, u, v, x);
        updateAdd(2 * i + 1, m + 1, r, u, v, x);
        sum[i] = (sum[2 * i] + sum[2 * i + 1]) % MOD;
    }

    void updateMul(int i, int l, int r, int u, int v, int x){
        if(u > r || v < l || l > r) return;
        if(u <= l && v >= r){
            sum[i] = sum[i] * x % MOD;
            mul[i] = mul[i] * x % MOD;
            return;
        }
        pushDown(i, l, r);

        int m = (l + r) >> 1;
        updateMul(2 * i, l, m, u, v, x);
        updateMul(2 * i + 1, m + 1, r, u, v, x);
        sum[i] = (sum[2 * i] + sum[2 * i + 1]) % MOD;
    }

    void updateAss(int i, int l, int r, int u, int v, int x){
        if(u > r || v < l || l > r) return;
        if(u <= l && v >= r){
            sum[i] = x * (r - l + 1) % MOD;
            ass[i] = x;
            lazy[i] = 0; mul[i] = 1;
            return;
        }
        pushDown(i, l, r);

        int m = (l + r) >> 1;
        updateAss(2 * i, l, m, u, v, x);
        updateAss(2 * i + 1, m + 1, r, u, v, x);
        sum[i] = (sum[2 * i] + sum[2 * i + 1]) % MOD;
    }

    int getSum(int i, int l, int r, int u, int v){
        if(u > r || v < l || l > r) return 0;
        if(u <= l && v >= r) return sum[i];
        pushDown(i, l, r);

        int m = (l + r) >> 1;
        int sumL = getSum(2 * i, l, m, u, v);
        int sumR = getSum(2 * i + 1, m + 1, r, u, v);
        return (sumL + sumR) % MOD;
    }

    void updateAdd(int u, int v, int x){
        updateAdd(1, 1, n, u, v, x);
    }

    void updateAss(int u, int v, int x){
        updateAss(1, 1, n, u, v, x);
    }

    void updateMul(int u, int v, int x){
        updateMul(1, 1, n, u, v, x);
    }

    int getSum(int u, int v){
        return getSum(1, 1, n, u, v);
    }
};

void xuli(){
    SegmentTree tree(n);
    tree.build(1, 1, n);

    while(q--){
        int type, u, v, x;
        cin >> type;
        if(type == 1){
            cin >> u >> v >> x;
            tree.updateAdd(u, v, x);
        } else if(type == 2){
            cin >> u >> v >> x;
            tree.updateMul(u, v, x);
        } else if(type == 3){
            cin >> u >> v >> x;
            tree.updateAss(u, v, x);
        } else {
            cin >> u >> v;
            cout << tree.getSum(u, v) << '\n';
        }
    }
}
int32_t main()
{
    FastIO
    freopen("ITMIX.INP", "r", stdin);
    freopen("ITMIX.OUT", "w", stdout);
    cin >> n >> q;
    for(int i = 1; i <= n; i++) cin >> a[i];

    xuli();
    return 0;
}

/* Author: hxzinh */
