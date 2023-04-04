#include <bits/stdc++.h>
#define int long long
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
int n, q;
int parCen = -1;
int child[NM], par[NM];
map<int, int> high[NM];
set<int> edges[NM];
multiset<int> dist[NM];
bool ok[NM];

void dfs(int u, int p){
    child[u] = 1;
    for(int v : edges[u]) if(v != p){
        dfs(v, u);
        child[u] += child[v];
    }
}
int centroid(int u, int p, int node){
    for(int v : edges[u]) if(v != p){
        if(child[v] > node / 2) return centroid(v, u, node);
    }
    return u;
}
void dfs2(int u, int p, int h, int c){
    high[c][u] = h;
    for(int v : edges[u]) if(v != p){
        dfs2(v, u, h + 1, c);
    }
}
void build(int u, int p){
    dfs(u, p);
    int node = child[u];
    int cen = centroid(u, p, node);

    if(parCen == -1) parCen = p;
    par[cen] = p;

    dfs2(cen, p, 0, cen);

    vector<int> tmp(ALL(edges[cen]));
    for(int v : tmp){
        edges[cen].erase(v);
        edges[v].erase(cen);
        build(v, cen);
    }
}
void update(int u){
    for(int v = u; v != 0; v = par[v]){
        auto it = high[v][u];
        dist[v].insert(it);
    }
}
void Delete(int u){
    for(int v = u; v != 0; v = par[v]) {
        auto it = high[v][u];
        dist[v].erase(dist[v].find(it));
    }
}
int getDist(int u){
    int res = INF;
    for(int v = u; v != 0; v = par[v]) if(dist[v].size()) {
        auto it = high[v][u];
        minimize(res, *dist[v].begin() + it);
    }
    return res;
}
void xuli(){
    for(int i = 1; i <= n; i++) par[i] = 0;
    build(1, 0);

    while(q--){
        int type, u;
        cin >> type >> u;
        if(type == 1){
            if(!ok[u]) update(u);
            else Delete(u);
            ok[u] = ok[u] ^ 1;
        } else {
            int res = getDist(u);
            cout << (res < INF ? res : -1) << '\n';
        }
    }
}
int32_t main()
{
    FastIO
    freopen("MINDISTANCE.INP", "r", stdin);
    freopen("MINDISTANCE.OUT", "w", stdout);
    cin >> n >> q;
    for(int i = 1; i < n; i++){
        int u, v;
        cin >> u >> v;
        edges[u].insert(v);
        edges[v].insert(u);
    }

    xuli();
    return 0;
}

/* Author: hxzinh */

/*
-----code ko bug-----code ko bug-----code ko bug--------------

          _.-/`)
         // / / )
      .=// / / / )
     //`/ / / / /
    // /     ` /
   ||         /
    \\       /
     ))    .'
    //    /
         /
*/
