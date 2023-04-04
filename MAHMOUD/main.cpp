#include <bits/stdc++.h>
#define ll long long
#define INF 0x3f3f3f3f
#define pii pair<int, int>
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

const int NM = 1e5 + 10;
int n;
int result = 0, parNode = -1;
int a[NM], bit[NM][25], par[NM];
ll ans[25], f[NM][25][2];
int child[NM], cnt[NM][25][2];
vector<int> edges[NM];
set<int> G[NM];
bool isCen[NM];
map<int, int> dis[NM];

void dfs(int u, int p){
    child[u] = 1;
    for(int v : G[u]) if(v != p && !isCen[v]){
        dfs(v, u);
        child[u] += child[v];
    }
    return;
}
void initHigh(int u, int p, int cen, int h){
    dis[cen][u] = h;
    for(int v : G[u]) if(v != p){
        initHigh(v, u, cen, h + 1);
    }
}
int centroid(int u, int p, int root){
    for(int v : G[u]) if(v != p && !isCen[v]){
        if(child[v] * 2 > child[root]) return centroid(v, u, root);
    }
    return u;
}
void getAns(int u, int cen, int p){
    ll s[25][2];
    memset(s, 0, sizeof s);
    for(int i = 0; i < 25; i++)
        for(int j = 0; j < 2; j++) cnt[u][i][j] = bit[u][i];

    for(int v : G[u]) if(v != p){

    }
}
void build(int u, int p){
    dfs(u, -1);

    int tmp = centroid(u, u, u);
    isCen[tmp] = true;
    par[tmp] = p;

    if(!parNode) parNode = tmp;

    if(p == -1) p = tmp;
    if(p != tmp){
        edges[p].push_back(tmp);
        edges[tmp].push_back(p);
    }


    vector<int> newEdges(ALL(G[tmp]));
    for(int v : newEdges) if(!isCen[v]){
        G[tmp].erase(v);
        G[v].erase(tmp);
        build(v, tmp);
    }
}
void xuli(){
    Dfs(1, -1);

    ll res = 0;
    for(int i = 0; i < 25; i++) res += (ans[i] * MASK(i));

    cout << res;
}
void full(){
    build(1, -1);

    for(int i = 1; i <= n; i++) if(isCen[i]){

    }
}
int32_t main()
{
    FastIO
    freopen("MAHMOUD.INP", "r", stdin);
    freopen("MAHMOUD.OUT", "w", stdout);
    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
        for(int j = 0; j < 25; j++) bit[i][j] = BIT(a[i], j);
    }
    for(int i = 1; i < n; i++){
        int u, v; cin >> u >> v;
        G[u].insert(v); G[v].insert(u);
    }

    xuli();
    return 0;
}

/* Author: hxzinh */
