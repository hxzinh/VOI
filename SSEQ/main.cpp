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

const int NM = 1e6 + 10;
const int MAX = 1e6 + 10;
int n;
int s[MAX];
vector<int> p[MAX];

struct Data {
    int L, R, w;

    bool inline operator < (const Data &A) const {
        return (L == A.L ? R < A.R : L < A.L);
    }
};
Data a[NM];

struct SegmentTree {
    int n;
    vector<int> val, lazy;

    SegmentTree(int _n = 0){
        n = _n;
        val.assign(4 * n + 7, 0);
        lazy.assign(4 * n + 7, 0);
    }

    void pushDown(int i){
        if(!lazy[i]) return;
        for(int k = 0; k < 2; k++){
            val[2 * i + k] += lazy[i];
            lazy[2 * i + k] += lazy[i];
        }
        lazy[i] = 0;
    }

    void update(int i, int l, int r, int u, int v, int x){
        if(l > r || v < l || u > r) return;
        if(u <= l && v >= r){
            val[i] +=  x;
            lazy[i] += x;
            return;
        }
        pushDown(i);
        int m = (l + r) >> 1;
        update(2 * i, l, m, u, v, x);
        update(2 * i + 1, m + 1, r, u, v, x);
        val[i] = max(val[2 * i], val[2 * i + 1]);
    }
};

void xuli(){
    //for(int i = 1; i <= n; i++) cout << a[i].L << " " << a[i].R << " " << a[i].w << '\n';

    SegmentTree tree(MAX);
    for(int i = 1; i <= n; i++) tree.update(1, 0, MAX, a[i].R, MAX, a[i].w);

    int res = -INF;
    for(int i = 0; i <= MAX; i++){
        for(int u : p[i]) tree.update(1, 0, MAX, a[u].R, MAX, -a[u].w);
        maximize(res, tree.val[1]);
    }
    cout << res;
}
int32_t main()
{
    FastIO
    freopen("SSEQ.INP", "r", stdin);
    freopen("SSEQ.OUT", "w", stdout);
    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> a[i].L >> a[i].R >> a[i].w;
        p[a[i].L].push_back(i);
    }

    xuli();
    return 0;
}
