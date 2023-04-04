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

const int NM = 1e3 + 10;
int n, m, cnt = 0;
int a[NM];
vector<int> edges[NM];
bool visited[NM];

void dfs(int u) {
    visited[u] = true;
    for(int v : edges[u]) if(!visited[v]) dfs(v);
}
void xuli() {
    int res = 0;
    for(int i = 1; i <= n; i++) if(!visited[i]) {
        a[i] = 1;
        dfs(i);
    }

    memset(visited, false, sizeof visited);

    for(int i = n; i > 0; i--) if(a[i] && !visited[i]) {
        res++;
        dfs(i);
    }


    cout << res;
}
int32_t main()
{
    FastIO
    freopen("MESSAGE.INP", "r", stdin);
    freopen("MESSAGE.OUT", "w", stdout);
    cin >> n >> m;
    for(int i = 1; i <= m; i++) {
        int u, v;
        cin >> u >> v;
        edges[u].push_back(v);
    }

    xuli();
    return 0;
}

/* Author: hxzinh */

