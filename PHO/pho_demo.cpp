#include <bits/stdc++.h>
#define file "pho"
#define int long long
#define pb push_back
#define fi first
#define se second
#define For(i, a, b) for (int i = a; i <= b; i++)
#define Dow(i, a, b) for (int i = a; i >= b; i--)
#define MASK(i) (1LL << (i))
#define BIT(i, a) (((a) >> (i)) & 1)
#define endl '\n'

using namespace std;

template<class X, class Y>
    bool minimize(X &x, const Y &y) {
        X eps = 1e-9;
        if (x > y + eps) {
            x = y;
            return true;
        }
        return false;
    }
template<class X, class Y>
    bool maximize(X &x, const Y &y) {
        X eps = 1e-9;
        if (x + eps < y) {
            x = y;
            return true;
        }
        return false;
    }
template<class T>
    T Abs(const T &x) {
        return (x < 0 ? -x : x);
    }

const int maxN = 100009;
typedef pair <int, int> ii;
int n, m, a[maxN], ok[maxN];
vector <int> node, ke[maxN];
stack <int> st;
int ans = 0, d[maxN];

void dfs(int u, int p) {
    st.push(u);
    if (ok[u]) {
        while (st.size()) {
            node.pb(st.top());
            st.pop();
        }
    }
    for (int v : ke[u]) {
        if (v != p) {
            dfs(v, u);
        }
    }
    if (st.size())
        st.pop();
}

void Dfs(int u, int p) {
    for (int v : ke[u]) {
        if (v != p) {
            d[v] = d[u] + 1;
            Dfs(v, u);
        }
    }
}

signed kk()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    freopen(file".inp", "r", stdin);
    freopen(file".out", "w", stdout);
    cin >> n >> m;
    For (i, 1, m) {
        cin >> a[i];
        a[i]++;
        ok[a[i]] = 1;
    }
    For (i, 1, n - 1) {
        int u, v;
        cin >> u >> v;
        u++;
        v++;
        ke[u].pb(v);
        ke[v].pb(u);
    }
    dfs(a[1], -1);
    int s = node[0];
    Dfs(s, -1);
    int maxc = 0;
    for (int u : node) {
        if (maxc < d[u]) {
            maxc = d[u];
            s = u;
        }
    }
    For (i, 1, n)
        d[i] = 0;
    Dfs(s, -1);
    maxc = 0;
    for (int u : node) {
        if (maxc < d[u]) {
            maxc = d[u];
            s = u;
        }
    }
    ans = -d[s];
    ans += (node.size() - 1) * 2LL;
    cout << ans;
    return 0;
}
