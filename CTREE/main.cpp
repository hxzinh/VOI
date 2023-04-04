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

/**
//PRAGMA
#pragma GCC target("popcnt")
**/

/**
//ordered_set
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
typedef tree<pii,
             null_type,
             less<pii>,
             rb_tree_tag,
             tree_order_statistics_node_update> ordered_set;
**/

template<class X, class Y>
	inline bool maximize(X &x, const Y &y) {return (x < y ? x = y, 1 : 0);}
template<class X, class Y>
	inline bool minimize(X &x, const Y &y) {return (x > y ? x = y, 1 : 0);}

const int NM = 3e5 + 10;
int n, q, Time = 0;
int a[NM], id[NM], high[NM], P[NM][25];
vector<int> edges[NM];

struct Node {
    int left, right;
    int sum;
    Node() {}
    Node(int sum, int left, int right) : sum(sum), left(left), right(right) {}
} tree[50 * NM];

int nNode = 0, nVer = 0;
int ver[NM];

int build(int l, int r) {
    if(l == r) {
        tree[++nNode] = Node(0, 0, 0);
        return nNode;
    }

    int m = (l + r) >> 1, cur(++nNode);
    tree[cur].left = build(l, m);
    tree[cur].right = build(m + 1, r);
    tree[cur].sum = tree[tree[cur].left].sum + tree[tree[cur].right].sum;
    return cur;
}

int update(int l, int r, int u, int x, int oldId) {
    if(l == r) {
        ++nNode;
        tree[nNode] = Node(tree[oldId].sum + x, 0, 0);
        return nNode;
    }

    int m = (l + r) >> 1;
    int curId = ++nNode;

    if(u <= m) {
        tree[curId].left = update(l, m, u, x, tree[oldId].left);
        tree[curId].right = tree[oldId].right;
        tree[curId].sum = tree[tree[curId].left].sum + tree[tree[curId].right].sum;
    }
    else {
        tree[curId].left = tree[oldId].left;
        tree[curId].right = update(m + 1, r, u, x, tree[oldId].right);
        tree[curId].sum = tree[tree[curId].left].sum + tree[tree[curId].right].sum;
    }

    return curId;
}

int getSum(int nodeId, int l, int r, int u, int v) {
    if(v < l || u > r || l > r) return 0;
    if(u <= l && v >= r) return tree[nodeId].sum;

    int m = (l + r) >> 1;
    return getSum(tree[nodeId].left, l, m, u, v) + getSum(tree[nodeId].right, m + 1, r, u, v);
}

void dfs(int u, int p) {
    P[u][0] = p;

    ++nVer;
    id[u] = nVer;
    ver[nVer] = update(1, n, a[u], 1, ver[id[p]]);

    for(int v : edges[u]) if(v != p) {
        high[v] = high[u] + 1;
        dfs(v, u);
    }

}
int getLca(int u, int v) {
    if(high[u] < high[v]) swap(u, v);

    int LOG = log2(high[u]);
    for(int i = LOG; i >= 0; i--)
        if(high[u] - MASK(i) >= high[v]) u = P[u][i];

    if(u == v) return u;

    for(int i = LOG; i >= 0; i--) {
        if(P[u][i] != -1 && P[u][i] != P[v][i]) {
            u = P[u][i];
            v = P[v][i];
        }
    }

    return P[u][0];
}
void xuli() {
    memset(P, -1, sizeof P);

    ver[0] = build(1, n);
    dfs(1, 0);

    for(int j = 1; MASK(j) <= n; j++)
    for(int i = 1; i <= n; i++) {
        if(P[i][j - 1] != -1) {
            P[i][j] = P[P[i][j - 1]][j - 1];
        }
    }

    while(q--) {
        int u, v;
        cin >> u >> v;

        int parNode = getLca(u, v);
        int curLength = high[u] + high[v] - 2 * high[parNode] + 1;

        int l = 1, r = n, res = -1;
        while(l <= r) {
            int m = (l + r) >> 1;
            int curCnt = getSum(ver[id[u]], 1, n, 1, m) + getSum(ver[id[v]], 1, n, 1, m)
                   - 2 * getSum(ver[id[parNode]], 1, n, 1, m) + (a[parNode] <= m);

            //cout << m << ' ' << curCnt << '\n';
            if(curCnt > curLength / 2) {
                res = m;
                r = m - 1;
            } else l = m + 1;
        }

        if(res == -1) {
            cout << "-1\n";
            continue;
        }

        int curCnt = getSum(ver[id[u]], 1, n, res, res) + getSum(ver[id[v]], 1, n, res, res)
                   - 2 * getSum(ver[id[parNode]], 1, n, res, res) + (a[parNode] == res);

        if(curCnt > curLength / 2) {
            cout << res << '\n';
        } else {
            cout << "-1\n";
        }
    }
}
int32_t main()
{
    FastIO
    freopen("TREE.INP", "r", stdin);
    freopen("TREE.OUT", "w", stdout);
    cin >> n >> q;
    for(int i = 1; i <= n; i++) cin >> a[i];

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
