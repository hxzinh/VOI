#include <bits/stdc++.h>
#define ll long long
#define INF 0x3f3f3f3f
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

const int NM = 1e5 + 10;
int n, m, a[NM], ok[NM];
vector <int> node, edges[NM];
stack <int> st;
int ans = 0, high[NM];

void dfs(int u, int p) {
    st.push(u);
    if (ok[u]) {
        while (st.size()) {
            node.push_back(st.top());
            st.pop();
        }
    }

    for (int v : edges[u])
        if (v != p) dfs(v, u);

    if (st.size()) st.pop();
}

void Dfs(int u, int p) {
    for (int v : edges[u]) if (v != p) {
        high[v] = high[u] + 1;
        Dfs(v, u);
    }
}

signed main()
{
    FastIO
    freopen("PHO.INP", "r", stdin);
    freopen("PHO.OUT", "w", stdout);
    cin >> n >> m;
    for(int i = 1; i <= m; i++) {
        cin >> a[i];
        a[i]++;
        ok[a[i]] = 1;
    }
    for(int i = 1; i < n; i++) {
        int u, v; cin >> u >> v;
        u++; v++;
        edges[u].push_back(v);
        edges[v].push_back(u);
    }
    dfs(a[1], -1);
    int s = node[0];
    Dfs(s, -1);
    int maxc = 0;
    for (int u : node) if (maxc < high[u]) {
        maxc = high[u];
        s = u;
    }
    memset(high, 0, sizeof high);
    Dfs(s, s);
    maxc = 0;
    for (int u : node) if (maxc < high[u]) {
        maxc = high[u];
        s = u;
    }
    ans = -high[s];
    ans += (node.size() - 1) * 2LL;
    cout << ans;
    return 0;
}
