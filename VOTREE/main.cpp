#include <bits/stdc++.h>
#define ll long long
#define INF 0x3f3f3f3f
#define pii pair<int, int>
#define pll pair<long long, long long>
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
int high[NM], tree[4 * NM], P[NM][22];
vector<int> edges[NM];

void dfs(int u, int p) {
    P[u][0] = p;
    for(int v : edges[u]) if(v != p) {
        high[v] = high[u] + 1;
        dfs(v, u);
    }
}
int getLca(int u, int v) {
    for(int i = 20; i >= 0; i--)
        if(high[P[u][i]] >= high[v]) u = P[u][i];
    for(int i = 20; i >= 0; i--)
        if(high[P[v][i]] >= high[u]) v = P[v][i];

    if(u == v) return u;

    for(int i = 20; i >= 0; i--) {
        if(P[u][i] != P[v][i]) {
            u = P[u][i];
            v = P[v][i];
        }
    }

    return P[u][0];
}
void build(int i, int l, int r) {
    if(l > r) return;
    if(l == r) {
        tree[i] = l;
        return;
    }

    int m = (l + r) >> 1;
    build(2 * i, l, m);
    build(2 * i + 1, m + 1, r);
    tree[i] = getLca(tree[2 * i], tree[2 * i + 1]);
}
int query(int i, int l, int r, int u, int v) {
    if(u > r || v < l || l > r) return 0;
    if(u <= l && v >= r) return tree[i];

    int m = (l + r) >> 1;
    int qL = query(2 * i, l, m, u, v);
    int qR = query(2 * i + 1, m + 1, r, u, v);

    if(qL == 0 || qR == 0) return (qL == 0) ? qR : qL;
    else return getLca(qL, qR);
}
void xuli() {
    high[1] = 1;
    dfs(1, 0);

    for(int k = 1; k <= 20; k++)
        for(int i = 1; i <= n; i++) P[i][k] = P[P[i][k - 1]][k - 1];

    build(1, 1, n);

    while(q--) {
        int u, v;
        cin >> u >> v;

        int res = query(1, 1, n, u, v);
        cout << res << '\n';
    }
}
int32_t main()
{
    FastIO
    freopen("VOTREE.INP", "r", stdin);
    freopen("VOTREE.OUT", "w", stdout);
    cin >> n >> q;
    for(int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        edges[u].push_back(v);
        edges[v].push_back(u);
    }

    xuli();
    return 0;
}

/* Author: hxzinh */

