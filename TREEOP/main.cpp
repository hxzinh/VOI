#include <bits/stdc++.h>
#define FOR(i, a, b) for (int i = (a); i <= (b); ++i)
#define FORD(i, a, b) for (int i = (a); i >= (b); --i)
#define REP(i, a) for (int i = 0; i < (a); ++i)
#define DEBUG(x) { cerr << #x << '=' << x << endl; }
#define Arr(a, l, r) { cerr << #a << " = {"; FOR(_, l, r) cerr << ' ' << a[_]; cerr << "}\n"; }
#define N 200100
#define pp pair<int, int>
#define endl '\n'
#define IO ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define taskname "treeop"
#define bit(S, i) (((S) >> (i)) & 1)
using namespace std;
const long long MOD = 1e9 + 7;

void Add(long long &a, long long b) {
    a += b;
    if (a >= MOD) a -= MOD;
    if (a < 0) a += MOD;
}

int n;
vector<int> e[N];
int d[N], LCA[N][21], TIME, tin[N], tout[N];

void dfs(int u, int p) {
    tin[u] = ++TIME;
    for(int v : e[u]) if (v != p) {
        d[v] = d[u] + 1;
        LCA[v][0] = u;
        FOR(i, 1, 19) LCA[v][i] = LCA[LCA[v][i - 1]][i - 1];
        dfs(v, u);
    }
    tout[u] = TIME;
}

int getLCA(int u, int v) {
    if (d[u] < d[v]) swap(u, v);
    int dd = d[u] - d[v];
    FORD(i, 19, 0) if (bit(dd, i)) u = LCA[u][i];
    if (u == v) return u;
    FORD(i, 19, 0) if (LCA[u][i] != LCA[v][i]) {
        u = LCA[u][i];
        v = LCA[v][i];
    }
    return LCA[u][0];
}

vector<int> newE[N];
int mark[N];

long long dfs2(int u, long long &ans) {
    long long sumu = 0;
    if (mark[u]) Add(sumu, u);
    long long now = 0;
    for (int v : newE[u]) {
        long long sumv = dfs2(v, ans);
        Add(now, sumu * sumv % MOD);
        Add(sumu, sumv);
    }
    now = (now * d[u] * -2ll) % MOD ;
    Add(ans, now);
    return sumu;
}

void Solve() {
    freopen("treeop.inp", "r", stdin);
    freopen("treeop.out", "w", stdout);
    int k;
    cin >> k;
    long long ans = 0;
    long long sum = 0;
    vector<int> nodes, origin;
    FOR(i, 1, k) {
        int x; cin >> x;
        mark[x] = 1;
        nodes.push_back(x);
        Add(sum, x);
    }
    origin = nodes;
    for (int x : nodes) Add(ans, 1ll * x * d[x] % MOD * (sum - x + MOD) % MOD);
    sort(nodes.begin(), nodes.end(), [] (int a, int b) {
        return tin[a] < tin[b];
    });
    FOR(i, 1, k - 1) nodes.push_back(getLCA(nodes[i - 1], nodes[i]));
    sort(nodes.begin(), nodes.end(), [] (int a, int b) {
        return tin[a] < tin[b];
    });
    nodes.resize(unique(nodes.begin(), nodes.end()) - nodes.begin());
    vector<int> st;
    for (int x : nodes) {
        newE[x].clear();
        while (!st.empty() && tout[st.back()] < tin[x]) st.pop_back();
        if (!st.empty()) newE[st.back()].push_back(x);
        st.push_back(x);
    }
    dfs2(nodes[0], ans);
    cout << ans << '\n';
    for (int x : origin) mark[x] = 0;
}

int main() {
    IO;
    freopen("treeop.inp", "r", stdin);
    freopen("treeop.out", "w", stdout);
    int q;
    cin >> n >> q;
    FOR(i, 2, n) {
        int u, v;
        cin >> u >> v;
        e[u].push_back(v);
        e[v].push_back(u);
    }
    dfs(1, -1);
    FOR(i, 1, q) Solve();
}
