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

const int NM = 1e6 + 10;
const int MAX = 1e6 + 1;
int n, q;
int ans[NM];
pii a[NM];
vector<int> query[NM], xs[NM];
vector<pii> qq[NM];

struct FenwickTree {
    int n;
    vector<int> val;

    FenwickTree(int _n = 0){
        n = _n;
        val.assign(n + 7, 0);
    }

    void update(int x, int u){
        for(; x <= n; x += x & -x) val[x] += u;
    }

    int getCnt(int x){
        int cnt = 0;
        for(; x > 0; x -= x & -x) cnt += val[x];
        return cnt;
    }

    int getCnt(int l, int r){
        return getCnt(r) - getCnt(l - 1);
    }
};

void xuli(){
    FenwickTree tree(MAX);

    for(int i = 1; i <= n; i++) xs[a[i].se].push_back(a[i].fi);
    for(int i = 1; i <= q; i++){
        for(int j = 0; j < query[i].size() - 1; j++){
            int u = query[i][j] + 1, v = query[i][j + 1] - 1;
            qq[v].push_back({u, i});
        }
    }

    for(int i = 1; i < MAX; i++){
        for(int u : xs[i]) tree.update(u, 1);
        for(pii u : qq[i]) ans[u.se] += tree.getCnt(u.fi, i);
    }

    for(int i = 1; i <= q; i++) cout << n - ans[i] << '\n';
}
int32_t main()
{
    FastIO
    freopen("VALERA.INP", "r", stdin);
    freopen("VALERA.OUT", "w", stdout);
    cin >> n >> q;
    for(int i = 1; i <= n; i++){
        cin >> a[i].fi >> a[i].se;
    }

    for(int i = 1; i <= q; i++){
        int k; cin >> k;
        query[i].push_back(0);
        for(int j = 1; j <= k; j++){
            int u; cin >> u;
            query[i].push_back(u);
        }
        query[i].push_back(MAX);
    }

    xuli();
    return 0;
}

/* Author: hxzinh */
