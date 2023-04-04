#include <bits/stdc++.h>
#define ll long long
#define int long long
#define INF 0x3f3f3f3f3f3f3f3f
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

const int NM = 3e5 + 10;
int n;
int high[NM];
vector<int> edges[NM];

void dfs(int u, int p) {
    for(int v : edges[u]) if(v != p) {
        high[v] = high[u] + 1;
        dfs(v, u);
    }
}
void xuli() {
    dfs(1, 0);
    int maxHigh = 0, parNode = 1;
    for(int i = 1; i <= n; i++) {
        if(maximize(maxHigh, high[i])) parNode = i;
        high[i] = 0;
    }

    //cout << parNode << '\n';

    dfs(parNode, 0);
    for(int i = 1; i <= n; i++) maximize(maxHigh, high[i]);

    cout << 3 * maxHigh;
}
int32_t main()
{
    FastIO
    freopen("CIRCUMFERENCE.INP", "r", stdin);
    freopen("CIRCUMFERENCE.OUT", "w", stdout);
    cin >> n;
    for(int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        edges[u].push_back(v);
        edges[v].push_back(u);
    }

    xuli();
    return 0;
}
