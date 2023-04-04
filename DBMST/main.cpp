#include <bits/stdc++.h>
#define ll long long
#define INF 1e9
#define pii pair<int, int>
#define fi first
#define se second
#define MASK(x) (1LL << (x))
#define BIT(i, x) ((x) >> (i) & 1LL)
#define FastIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

template<class X, class Y>
	inline bool maximize(X &x, const Y &y) {return (x < y ? x = y, 1 : 0);}
template<class X, class Y>
	inline bool minimize(X &x, const Y &y) {return (x > y ? x = y, 1 : 0);}

const int NM = 25 + 10;
int n, m, k;
int node = 0, sta;
int f[MASK(25)], r[30][30];
pii high[16];
bool cx[16];

struct Road {
    int v, cost, id;
};
vector<Road> edges[NM];

struct Data {
    int u, v, cost;
};
Data a[NM];

bool cmp(const Data &A, const Data &B){
    return A.cost < B.cost;
}
void dfs(int u){
    cx[u] = false;
    node++;
    for(int v = 1; v <= n; v++) if(cx[v] && r[u][v] != 0){
        dfs(v);
        if(maximize(high[u].fi, high[v].fi + 1))
            high[u].se = (high[v].se ? high[v].se : v);
    }
    return;
}
void xuli(){
    for(int mask = 0; mask <= MASK(m); mask++) f[mask] = INF;
    f[0] = 0;

    int res = INF, cnt = 0;
    for(int mask = MASK(n - 1) - 1; mask <= MASK(m); mask++){
        if(__builtin_popcount(mask) != n - 1) continue;
        int ans = 0;
        memset(r, 0, sizeof(r));
        for(int i = 1; i <= m; i++) if(BIT(i - 1, mask)) {
            ans += a[i].cost;
            int u = a[i].u, v = a[i].v;
            r[u][v] = r[v][u] = a[i].cost;
        }
        if(ans < res){
            memset(cx, true, sizeof(cx));
            memset(high, 0, sizeof(high));
            dfs(1);
            int x = high[1].se;
            memset(cx, true, sizeof(cx));
            memset(high, 0, sizeof(high));
            node = 0;
            dfs(x);
            if(high[x].fi <= k && node == n) res = ans;
        }
    }
    cout << res;
}
void readfile(){
    freopen("DBMST.INP", "r", stdin);
    freopen("DBMST.OUT", "w", stdout);
    cin >> n >> m >> k;
    for(int i = 1; i <= m; i++){
        int u, v, w;
        cin >> u >> v >> w;
        a[i] = {u, v, w};
        edges[u].push_back({v, w, i});
        edges[v].push_back({u, w, i});
    }
}
int main()
{
    FastIO
    readfile();
    xuli();
    return 0;
}
