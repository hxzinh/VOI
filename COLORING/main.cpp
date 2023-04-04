#include <bits/stdc++.h>
#define ll long long
#define INF 0x3f3f3f3f
#define pii pair<int, int>
#define mp make_pair
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

const int NM = 5e5 + 10;
const int LOG = 19;
int n;
int curColor = 0, Time = 0;
int minNode[NM], ans[NM], child[NM], t[NM], high[NM], P[NM][20];
vector<int> edges[NM];

struct SegmentTree {
    int n;
    vector<int> Min;

    SegmentTree(int _n = 0) {
        n = _n;
        Min.assign(4 * n + 7, INF);
    }

    void update(int i, int l, int r, int u, int x) {
        if(u > r || u < l || l > r) return;
        if(l == r || u == l) {
            Min[i] = x;
            return;
        }

        int m = (l + r) >> 1;
        update(2 * i, l, m, u, x);
        update(2 * i + 1, m + 1, r, u, x);
        Min[i] = min(Min[2 * i], Min[2 * i + 1]);
        return;
    }

    int getMin(int i, int l, int r, int u, int v) {
        if(u > r || v < l || l > r) return INF;
        if(u <= l && v >= r) return Min[i];

        int m = (l + r) >> 1;
        int minL = getMin(2 * i, l, m, u, v);
        int minR = getMin(2 * i + 1, m + 1, r, u, v);
        return min(minL, minR);
    }
} tree;

void dfs(int u, int p) {
    minNode[u] = INF;
    for(int v : edges[u]) if(v != p && !ans[v]) {
        dfs(v, u);
        minimize(minNode[u], min(minNode[v], v));
    }
}
void dfs2(int u, int p) {
    ans[u] = curColor;
    for(int v : edges[u]) if(v != p && !ans[v]) {
        if(v == minNode[u] || minNode[v] == minNode[u]) dfs2(v, u);
    }
}
void sub12() {
    for(int i = 1; i <= n; i++) {
        if(!ans[i]) {
            ans[i] = ++curColor;

            pii A = {INF, INF}, B = {INF, INF};
            for(int v : edges[i]) if(!ans[v]) {
                dfs(v, i);
                int curMin = min(minNode[v], v);
                if(curMin < A.fi) {
                    B = A;
                    A = {curMin, v};
                } else if(curMin < B.fi) {
                    B = {curMin, v};
                }
            }

            if(A.fi < INF) dfs2(A.se, i);
            if(B.fi < INF) dfs2(B.se, i);
        }

        //for(int j = 1; j <= n; j++) cout << ans[j] << " ";
        //cout << '\n';
    }

    for(int i = 1; i <= n; i++) cout << ans[i] << " ";
}
void Dfs(int u, int p) {
    child[u] = 1;
    t[u] = ++Time;
    for(int i = 0; i <= LOG; i++) P[u][i] = P[P[u][i - 1]][i - 1];

    for(int v : edges[u]) if(v != p) {
        high[v] = high[u] + 1;
        Dfs(v, u);
        child[v] += child[u];
    }
}
int getLca(int u, int v) {
    if(high[u] > high[v]) swap(u, v);
    for(int i = LOG; i >= 0; i--)
        if(high[u] < high[v]) u = P[u][i];

    if(u == v) return u;
    for(int i = LOG; i >= 0; i--) {
        if(P[u][i] != P[v][i]) {
            u = P[u][i];
            v = P[v][i];
        }
    }
    return P[u][0];
}
void solve() {
    for(int i = 1; i <= n; i++) P[i][0] = i;

    pii cur = {-1, -1};
    int minn =
}
void xuli() {

}
int32_t main()
{
    FastIO
    freopen("COLORING.INP", "r", stdin);
    freopen("COLORING.OUT", "w", stdout);
    cin >> n;
    for(int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        edges[u].push_back(v);
        edges[v].push_back(u);
    }


    sub12();
    return 0;
}

/* Author: hxzinh */

/*
-----code ko bug-----code ko bug-----code ko bug--------------

          _.-/`)
         // / / )
      .=// / / / )
     //`/ / / / /
    // /     ` /
   ||         /
    \\       /
     ))    .'
    //    /
         /
*/
