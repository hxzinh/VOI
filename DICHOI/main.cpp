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

const int NM = 1e5 + 10;
int n, m, q;
int Time = 0, numNode = 0, curId = 0;
int a[NM], Num[NM], Low[NM], par[NM], child[NM], head[NM], id[NM], high[NM], heavy[NM], root[NM];
vector<int> edges[NM], node[NM], criticalNode;
stack<int> st;
bool isCritical[NM];

struct SegmentTree {
    int n;
    vector<int> Min;

    SegmentTree(int _n = 0) {
        n = _n;
        Min.assign(4 * n + 7, INF);
    }

    void update(int i, int l, int r, int u, int x) {
        if(u < l || u > r || l > r) return;
        if(l == r) {
            Min[i] = x;
            return;
        }

        int m = (l + r) >> 1;
        if(u <= m) update(2 * i, l, m, u, x);
        else update(2 * i + 1, m + 1, r, u, x);

        Min[i] = min(Min[2 * i], Min[2 * i + 1]);
    }

    int getMin(int i, int l, int r, int u, int v) {
        if(u > r || v < l || l > r) return INF;
        if(u <= l && v >= r) return Min[i];

        int m = (l + r) >> 1;
        int minL = getMin(2 * i, l, m, u, v);
        int minR = getMin(2 * i + 1, m + 1, r, u, v);
        return max(minL, minR);
    }

    void update(int u, int x) {
        update(1, 1, n, u, x);
    }

    int getMin(int u, int v) {
        return getMin(1, 1, n, u, v);
    }
};

SegmentTree tree;

void tarjan(int u, int p) {
    Num[u] = Low[u] = ++Time;
    st.push(u);

    for(int v : edges[u]) if(v != p) {
        if(Num[v]) minimize(Low[u], Num[v]);
        else {
            tarjan(v, u);
            minimize(Low[u], Low[v]);
        }
    }

    if(Num[u] == Low[u]) {
        numNode++;
        criticalNode.push_back(u);
        int v;
        do {
            v = st.top();
            node[numNode].push_back(v);
            st.pop();
            Num[v] = Low[v] = INF;
        } while(v != u);
    }
}
void visit(int u, int p) {
    Low[u] = Num[u] = ++Time;

    for(int v : edges[u]) if(v != p) {
        if(Num[v]) minimize(Low[u], Num[v]);
        else {
            st.push(u);
            visit(v, u);
            minimize(Low[u], Low[v]);
            if(Low[v] >= Num[u]) {
                int curCnt = 0, v = 0;
                criticalNode.push_back(u);
                do {
                    v = st.top(); st.pop();
                    curCnt++;
                } while(u != v);
            }
        }
    }
    st.push(u);
}
void dfs(int u, int p) {
    int mx = 0;
    par[u] = p;
    child[u] = 1;
    for(int v : edges[u]) if(v != p) {
        high[v] = high[u] + 1;
        dfs(v, u);
        child[u] += child[v];
        if(maximize(mx, child[v])) heavy[u] = v;
    }
}
void hld(int u, int h) {
    head[u] = h;
    id[u] = ++curId;
    tree.update(id[u], a[u]);
    if(heavy[u]) hld(heavy[u], h);
    for(int v : edges[u]) if(v != par[u] && v != heavy[u]) {
        hld(v, u);
    }
}
int query(int u, int v) {
    int res = INF;
    while(head[u] != head[v]) {
        if(high[head[u]] < high[head[v]]) swap(u, v);
        maximize(res, tree.getMin(id[head[u]], id[u]));
        u = par[head[u]];
    }
    if(high[u] > high[v]) swap(u, v);
    maximize(res, tree.getMin(id[u], id[v]));
    return res;
}
void buildTree() {
    for(int u : criticalNode) cout << u << " ";
}
void xuli() {
    for(int i = 1; i <= n; i++) if(!Num[i]) tarjan(i, -1);

    Time = 0;
    while(st.size()) st.pop();
    for(int i = 1; i <= n; i++) {
        Low[i] = Num[i] = 0;
    }
    for(int i = 1; i <= n; i++) if(!Num[i]) visit(i, -1);
    buildTree();
}
int32_t main()
{
    FastIO
    freopen("DICHOI.INP", "r", stdin);
    freopen("DICHOI.OUT", "w", stdout);
    cin >> n >> m >> q;
    for(int i = 1; i <= n; i++) cin >> a[i];
    for(int i = 1; i <= m; i++) {
        int u, v;
        cin >> u >> v;
        edges[u].push_back(v);
        edges[v].push_back(u);
    }

    xuli();
    return 0;
}

/* Author: hxzinh */



