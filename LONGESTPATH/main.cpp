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
int n, m;
int f[NM];
vector<int> edges[NM];

int dp(int u){
    int &res = f[u];
    if(res != 0) return res;
    for(int v : edges[u]){
        f[v] = dp(v);
        maximize(res, f[v] + 1);
    }
    return res;
}
void xuli(){
    int res = -1;
    for(int i = 1; i <= n; i++) maximize(res, dp(i));
    cout << res;
}
int32_t main()
{
    FastIO
    freopen("PATH.INP", "r", stdin);
    freopen("PATH.OUT", "w", stdout);
    cin >> n >> m;
    for(int i = 1; i <= m; i++){
        int u, v; cin >> u >> v;
        edges[u].push_back(v);
        //edges[v].push_back(u);
    }

    xuli();
    return 0;
}
