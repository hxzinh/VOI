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

const int NM = 4e3 + 10;
const int Log = 19;
int n, m, q;
int par[NM];
int maxWeight[NM][22], P[NM][22], high[NM];
vector<pii> edges[NM];

struct Data {
    int u, v, cost;
} e[400005];

int root(int x) {
    if(par[x] < 0) return x;
    return par[x] = root(par[x]);
}
bool join(int u, int v) {
    u = root(u); v = root(v);
    if(u == v) return false;

    if(par[u] > par[v]) swap(u, v);
    par[u] += par[v];
    par[v] = u;
    return true;
}
bool cmp(const Data A, const Data B) {
    return A.cost < B.cost;
}
void dfs(int u, int p) {
    P[u][0] = p;

    for(int i = 1; i <= Log; i++) {
        if(P[u][i - 1] != -1) {
            P[u][i] = P[P[u][i - 1]][i - 1];
            maxWeight[u][i] = max(maxWeight[u][i - 1], maxWeight[P[u][i - 1]][i - 1]);
        }
    }

    for(pii v : edges[u]) if(v.fi != p) {
        maxWeight[v.fi][0] = v.se;
        high[v.fi] = high[u] + 1;
        dfs(v.fi, u);
    }
}
int query(int u, int v) {
    int res = -INF;
    if(high[u] > high[v]) swap(u, v);

    for(int i = Log - 1; i >= 0; i--) {
        if(P[v][i] != -1 && high[P[v][i]] >= high[u]) {
            maximize(res, maxWeight[v][i]);
            v = P[v][i];
        }
    }

    if(v == u) return res;

    for(int i = Log - 1; i >= 0; i--) {
        if(P[u][i] != P[v][i]) {
            int ans = max(maxWeight[v][i], maxWeight[u][i]);
            maximize(res, ans);

            u = P[u][i];
            v = P[v][i];
        }
    }

    int parMax = max(maxWeight[u][0], maxWeight[v][0]);
    maximize(res, parMax);

    return res;
}
void xuli() {
    memset(par, -1, sizeof par);
    memset(P, -1, sizeof P);
    sort(e + 1, e + m + 1, cmp);

    int cntEdges = 0;
    ll totalCost = 0;
    for(int i = 1; i <= m; i++) {
        int u = e[i].u, v = e[i].v, cost = e[i].cost;
        if(join(u, v)) {
            cntEdges++;
            totalCost += cost;
            edges[u].push_back({v, cost});
            edges[v].push_back({u, cost});
        }
    }

    memset(maxWeight, -INF, sizeof maxWeight);
    dfs(1, -1);

    while(q--) {
        int u, v;
        cin >> u >> v;

        ll res = totalCost - query(u, v);
        cout << res << '\n';
    }
}
int32_t main()
{
    FastIO
    freopen("ELECTRIC.INP", "r", stdin);
    freopen("ELECTRIC.OUT", "w", stdout);
    cin >> n >> m;
    for(int i = 1; i <= m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        e[i] = {u, v, w};
    }
    cin >> q;

    xuli();
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
