#include <bits/stdc++.h>
#define ll long long
#define INF 1e18
#define MASK(x) (1LL << (x))
#define BIT(x, i) ((x) >> (i) & 1)
#define FastIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;
const int NM = 1e4 + 10;
#define MOD 1000000007
int n, k;
int a[NM];
int f[NM], g[MASK(10)], newG[MASK(10)];
vector<int> t[NM];
bool ok[NM], cx[NM];

void readfile(){
    freopen("KIOSKS.INP", "r", stdin);
    freopen("KIOSKS.OUT", "w", stdout);
    cin >> n >> k;
    for(int i = 1; i <= n; i++) cin >> a[i];
    for(int i = 1; i < n; i++){
        int u,v; cin >> u >> v;
        t[u].push_back(v); t[v].push_back(u);
    }
}
void add(int &x, int y){
    x += y;
    if(x >= MOD) x -= MOD;
}
void sub(int &x, int y){
    x -= y;
    if(x < 0) x += MOD;
}
void dfs(int u, int fa){
    cx[u] = true;
    f[u] = 1;
    for(int v : t[u]) if(!ok[v] && v != fa) {
        dfs(v, u);
        f[u] = (1LL * f[u] * (f[v] + 1)) % MOD;
    }
}
int cntCC(int mask){
    memset(ok, false, sizeof(ok));
    memset(cx, false, sizeof(cx));
    for(int i = 1; i <= n; i++){ ///da co mat hang a[i] hay chua
        if(a[i] <= k && BIT(mask, a[i] - 1)) ok[i] = true;
    }
    for(int i = 1; i <= n; i++)
        if(!ok[i] && !cx[i]) dfs(i, -1);
    int res = 0;
    for(int i = 1; i <= n; i++)
        if(!ok[i]) add(res, f[i]);
    return res;
}
void xuli(){
    int res = 0;
    for(int mask = 0; mask < MASK(k); mask++){
        if(__builtin_popcount(mask) % 2 == 0) add(res, cntCC(mask));
        else sub(res, cntCC(mask));
    }
    cout << res;
}
int main()
{
    FastIO\
    readfile();
    xuli();
    return 0;
}
