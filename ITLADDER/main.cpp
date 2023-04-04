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
int s[NM];

void add(int &a, int b){
    a += b;
    if(a > MOD) a -= MOD;
    if(a < 0) a += MOD;
}

struct SegmentTree {
    int n;
    vector<int> sum, lazy, mul;

    SegmentTree(int _n = 0){
        n = _n;
        sum.assign(4 * n + 7, 0);
        lazy.assign(4 * n + 7, 0);
        mul.assign(4 * n + 7, 0);
    }

    void pushDown(int i, int l, int r){
        if(!lazy[i] && !mul[i]) return;

        int m = (l + r) >> 1;
        add(sum[2 * i], ((s[m] - s[l - 1]) * lazy[i] + (m - l + 1) * mul[i]) % MOD);
        add(lazy[2 * i], lazy[i]);
        add(mul[2 * i], mul[i]);

        add(sum[2 * i + 1], ((s[r] - s[m]) * lazy[i] + (r - m) * mul[i]) % MOD);
        add(lazy[2 * i + 1], lazy[i]);
        add(mul[2 * i + 1], mul[i]);

        lazy[i] = mul[i] = 0;
    }

    void update(int i, int l, int r, int u, int v, int x, int y){
        if(u > r || v < l || l > r) return;
        if(u <= l && v >= r){
            add(sum[i], ((s[r] - s[l - 1]) * x + (r - l + 1) * y) % MOD);
            add(lazy[i], x);
            add(mul[i], y);
            return;
        }
        pushDown(i, l, r);

        int m = (l + r) >> 1;
        update(2 * i, l, m, u, v, x, y);
        update(2 * i + 1, m + 1, r, u, v, x, y);
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

    void update(int u, int v, int x, int y){
        update(1, 1, n, u, v, x, y);
    }

    int getSum(int u, int v){
        return getSum(1, 1, n, u, v);
    }
};

void xuli(){
    for(int i = 1; i <= n; i++) s[i] = s[i - 1] + i;

    SegmentTree tree(n);

    while(q--){
        int type, l, r, u, v;
        cin >> type;
        if(type == 1){
            cin >> l >> r >> u >> v;
            tree.update(l, r, u, (v - u * l) % MOD);
        } else {
            cin >> u >> v;
            cout << tree.getSum(u, v) << '\n';
        }
    }
}
int32_t main()
{
    FastIO
    freopen("ITLADDER.INP", "r", stdin);
    freopen("ITLADDER.OUT", "w", stdout);
    cin >> n >> q;

    xuli();
    return 0;
}

/* Author: hxzinh */
