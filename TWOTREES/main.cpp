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

const int NM = 4e3 + 10;
int n, numID = 0, numNode;
pii a[NM], b[NM], rTree[NM];
int par[NM], numChild[NM], id[NM], cnt[NM], ans[NM];
vector<int> edges[NM], bridge[NM];
bool cx[NM];

void dfs1(int u, int p){
    id[u] = ++numID;
    rTree[u].fi = rTree[u].se = numID;
    par[u] = (u == p ? -1 : p);
    for(int v : edges[u]) if(v != p){
        dfs1(v, u);
        maximize(rTree[u].se, rTree[v].se);
    }
}
void dfs2(int u, int p){
    cnt[u] += cx[id[u]];
    for(int v : bridge[u]) if(v != p){
        dfs2(v, u);
        numChild[u] += numChild[v];
        cnt[u] += cnt[v];
    }
    numChild[u]++;

    int tmp = cnt[u];
    maximize(tmp, numNode - cnt[u]);
    maximize(tmp, numChild[u] - cnt[u]);
    maximize(tmp, n - numChild[u] - (numNode - cnt[u]));

    ans[tmp] += (u != 1);
}
void xuli(){
    dfs1(1, 1);
    for(int i = 1; i < n; i++){
        for(int j = 1; j <= n; j++) cx[j] = false;
        for(int j = 1; j <= n; j++) cnt[j] = numChild[j] = 0;

        int u = (par[a[i].fi] == a[i].se ? a[i].fi : a[i].se);
        int L = rTree[u].fi, R = rTree[u].se;
        for(int j = L; j <= R; j++) cx[j] = true;
        numNode = R - L + 1;

        dfs2(1, 1);
    }

    for(int i = 0; i <= n; i++) cout << ans[i] << " ";
}
int main()
{
    FastIO
    freopen("TWOTREES.INP", "r", stdin);
    freopen("TWOTREES.OUT", "w", stdout);
    cin >> n;
    for(int i = 1; i < n; i++){
        int u, v; cin >> u >> v;
        a[i] = {u, v};
        edges[u].push_back(v);
        edges[v].push_back(u);
    }
    for(int i = 1; i < n; i++){
        int u, v; cin >> u >> v;
        b[i] = {u, v};
        bridge[u].push_back(v);
        bridge[v].push_back(u);
    }

    xuli();
    return 0;
}

/* Author: hxzinh */
