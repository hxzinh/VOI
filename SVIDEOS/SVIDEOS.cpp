#include <bits/stdc++.h>
#define ll long long
#define int long long
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

const int NM = 1e5 + 10;
int n, q, k;
int par[NM], high[NM], ans[NM];
vector<pii> edges[NM];

struct Data {
    int u, v, cost;
} e[NM];

struct Query {
    int cost, u, id;
};

int dfs(int u, int p) {
    int res = 1;
    for(pii v : edges[u]) if(v.fi != p) {
        if(v.se >= k) res += dfs(v.fi, u);
    }
    return res;
}
void sub1() {
    while(q--) {
        int x;
        cin >> k >> x;

        int res = dfs(x, -1);
        cout << res - 1 << '\n';
    }
}
int root(int x) {
    if(par[x] < 0) return x;
    else return par[x] = root(par[x]);
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
    return A.cost > B.cost;
}
bool cmp2(const Query A, const Query B) {
    return A.cost < B.cost;
}
void xuli() {
    vector<Query> vec;

    for(int i = 1; i <= q; i++) {
        int u;
        cin >> k >> u;
        vec.push_back({k, u, i});
    }
    sort(ALL(vec), cmp2);

    //for(auto u : vec) cout << u.cost << " ";
    //cout << '\n';

    sort(e + 1, e + n, cmp);
    memset(par, -1, sizeof par);
    for(int i = 1; i < n; i++) {
        int u = e[i].u, v = e[i].v, cost = e[i].cost;

        if(vec.size()) {
            while(vec.back().cost > cost) {
                Query cur = vec.back();
                vec.pop_back();
                ans[cur.id] = -par[root(cur.u)] - 1;
                if(vec.empty()) break;
            }
        }

        join(u, v);
    }
    while(vec.size()) {
        Query cur = vec.back();
        vec.pop_back();
        ans[cur.id] = -par[root(cur.u)] - 1;
    }

    for(int i = 1; i <= q; i++) cout << ans[i] << '\n';
}
int32_t main()
{
    freopen("SVIDEOS.INP", "r", stdin);
    freopen("SVIDEOS.OUT", "w", stdout);
    cin >> n >> q;
    for(int i = 1; i < n; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        edges[u].push_back({v, w});
        edges[v].push_back({u, w});
        e[i] = {u, v, w};
    }

    //if(n <= 5000) sub1();
    xuli();
    return 0;
}
