#include <bits/stdc++.h>
#define ll int
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
int n, k;
int parCen = -1, numCen = 0;
int child[NM], exist[NM];
ll cnt[NM];
set<int> edges[NM];

void dfs(int u, int p){
    child[u] = 1;
    for(int v : edges[u]) if(v != p) {
        dfs(v, u);
        child[u] += child[v];
    }
}
int centroid(int u, int p, int node){ //tim centroid
    for(int v : edges[u]) if(v != p) {
        if(child[v] > node / 2) return centroid(v, u, node);
    }
    return u;
}
ll dfs2(int u, int p, int h, int t, vector<int> &tmp){
    int want = k - h;
    ll ans = 0;
    if(want >= 0 && exist[want] == t) ans += cnt[want];

    if(h <= k){
        tmp.push_back(h);
        for(int v : edges[u]) if(v != p){
            ans += dfs2(v, u, h + 1, t, tmp);
        }
    }
    return ans;
}
int solve(int u, int p){
    dfs(u, p);
    int node = child[u];
    int c = centroid(u, p, node);
    ll res = 0;

    int id = ++numCen;
    exist[0] = id;
    for(int i = 0; i <= n; i++) cnt[i] = 0;
    cnt[0] = 1;
    for(int v : edges[c]){
        vector<int> tmp;
        res += dfs2(v, c, 1, id, tmp);
        for(int h : tmp) {
            if(exist[h] != id) exist[h] = id;
            cnt[h]++;
        }
    }

    vector<int> tmp(ALL(edges[c]));
    for(int v : tmp){
        edges[c].erase(v);
        edges[v].erase(c);
        res += solve(v, c);
    }

    return res;
}
void xuli(){
    cout << solve(1, -1);
}
int32_t main()
{
    FastIO
    freopen("DISTANCEK.INP", "r", stdin);
    freopen("DISTANCEK.OUT", "w", stdout);
    cin >> n >> k;
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
