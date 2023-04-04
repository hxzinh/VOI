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

const int NM = 505;
int n, m;
int a[NM], s[NM], par[NM];
vector<int> edges[NM];
bool cx[NM];

void dfs(int u, int p){
    if(cx[u]) return;
    cx[u] = true;
    for(int v : edges[u]) if(v != p){
        dfs(v, u);
        s[u] += s[v];
    }
}
void xuli(){
    for(int i = 1; i <= n; i++) s[i] = a[i];
    for(int i = 1; i <= n; i++) if(!cx[i]) dfs(i, i);

    for(int i = 1; i <= n; i++) cout << s[i] << " ";
}
int main()
{
    FastIO
    freopen("JOBSET.INP", "r", stdin);
    freopen("JOBSET.OUT", "w", stdout);
    cin >> n;
    for(int i = 1; i <= n; i++) cin >> a[i];
    cin >> m;
    for(int i = 1; i <= m; i++){
        int u, v; cin >> u >> v;
        edges[u].push_back(v);
    }

    xuli();
    return 0;
}
