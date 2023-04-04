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
int n, s, t;
int curId = 0;
int child[NM];
set<int> edges[NM];

struct FenwickTree {
    int n;
    vector<ll> val;
    vector<int> idx;

    FenwickTree(int _n = 0){
        n = _n;
        val = vector<ll>(n + 7, 0LL);
        idx = vector<int>(n + 7, 0);
    }

    void ClearTree(){
        idx[0]++;
    }

    void update(int u, int x){
        for(; u <= n; u += u & -u) {
            if(idx[u] != idx[0]){
                idx[u] = idx[0];
                val[u] = 0;
            }
            val[u] += x;
        }
    }

    ll getSum(int u){
        int res = 0;
        for(; u > 0; u -= u & -u){
            if(idx[u] != idx[0]){
                idx[u] = 0;
                val[u] = 0;
            }
            res += val[u];
        }
        return res;
    }

    ll getSum(int u, int v){
        return getSum(v) - getSum(u - 1);
    }
} tree;

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
ll dfs2(int u, int p, int h, vector<int> &tmp){
    int wantL = max(s - h, 0), wantR = t - h;
    ll ans = 0;
    if(wantL >= 0 && wantR >= 0) ans += tree.getSum(wantL + 1, wantR + 1);

    if(h <= t){
        tmp.push_back(h);
        for(int v : edges[u]) if(v != p){
            ans += dfs2(v, u, h + 1, tmp);
        }
    }
    return ans;
}
ll solve(int u, int p){
    dfs(u, p);
    int node = child[u];
    int cen = centroid(u, p, node);

    ll res = 0;
    tree.ClearTree();
    tree.update(1, 1);

    for(int v : edges[cen]) if(v != p){
        vector<int> tmp;
        res += dfs2(v, cen, 1, tmp);
        for(int h : tmp) tree.update(h + 1, 1);
    }

    vector<int> tam(ALL(edges[cen]));
    for(int v : tam) {
        edges[v].erase(cen);
        edges[cen].erase(v);
        res += solve(v, cen);
    }
    return res;
}
void xuli(){
    tree = FenwickTree(n);
    cout << solve(1, -1);
}
int32_t main()
{
    FastIO
    freopen("FIXEDLENGTH.INP", "r", stdin);
    freopen("FIXEDLENGTH.OUT", "w", stdout);
    cin >> n >> s >> t;
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
