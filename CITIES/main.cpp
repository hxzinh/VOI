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
const int MOD = 1e9 + 7;
int n, k, m;
int a[NM];
vector<pii> edges[NM];

void xuli(){

}
int main()
{
    FastIO
    freopen("CITIES.INP", "r", stdin);
    freopen("CITIES.OUT", "w", stdout);
    cin >> n >> k >> m;
    for(int i = 1; i <= k; i++) cin >> a[i];
    for(int i = 1; i <= m; i++){
        int u, v, w; cin >> u >> v >> w;
        edges[u].push_back({v, w});
        edges[v].push_back({u, w});
    }
    return 0;
}
