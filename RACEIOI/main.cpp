#include <bits/stdc++.h>
#define ll long long
#define INF 0x3f3f3f3f
#define pii pair<int, int>
#define mp(x, y) make_pair(x, y)
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

const int NM = 2e5 + 10;
const int MAX = 1e6 + 10;
int n, k, Id = 0;
int child[NM], exist[NM];
pii dist[MAX];
set<pii> edges[NM];
set<int> road;

struct FenwickTree {
    int n;
    vector<int> val, idx;

    FenwickTree(int _n = 0){
        n = _n;
        val.assign(n + 7, 0);
        idx.assign(n + 7, 0);
    }

    void resetBit() {
        idx[0]++;
    }

    void update(int u, int x) {
        for(; u <= n; u += u & -u){
            if(idx[u] != idx[0]){
                idx[u] = idx[0];
                val[u] = 0;
            }
            val[u] += x;
        }
    }

    int getCnt(int u) {
        int res = 0;
        for(; u > 0; u -= u & -u) {
            if(idx[u] != idx[0]) {
                idx[u] = idx[0];
                val[u] = 0;
            }
            res += val[u];
        }
        return res;
    }
} tree;

void operator += (pii &A, pii B) {
    A.se += B.se; A.se += B.se;
}
void dfs(int u, int p){
    child[u] = 1;
    for(pii v : edges[u]) if(v.fi != p) {
        dfs(v.fi, u);
        child[u] += child[v.fi];
    }
}
int centroid(int u, int p, int node){
    for(pii v : edges[u]) if(v.fi != p) {
        if(child[v.fi] > node / 2) return centroid(v.fi, u, node);
    }
    return u;
}
pii dfs2(int u, int p, int d, int cnt, vector<pii> &tmp){
    if(d > k) return mp(0, 0);
    pii ans = mp(0, 0);
    int need = k - d;
    if(exist[need] == Id) ans += dist[need];

    tmp.push_back(mp(d, cnt));
    for(pii v : edges[u]) if(v.fi != p && d + v.se <= k) {
        pii cur = dfs2(v.fi, u, d + v.se, cnt + 1, tmp);
    }
    return ans;
}
pii solve(int u, int p){
    dfs(u, p);
    int node = child[u];
    int cen = centroid(u, p, node);

    pii res = mp(0, 0);
    int curId = ++Id;

    exist[0] = curId;
    dist[0] = mp(1, 1);

    for(pii v : edges[cen]) if(v.fi != p) {
        vector<pii> tmp;
        pii cur = dfs2(v.fi, cen, v.se, tmp);
        res += cur;
        for(pii d : tmp){
            if(exist[d.fi] != curId){
                exist[d.fi] = curId;
                dist[d.fi] = mp(0, 0);
            }
            if(maximize(dist[d.fi].fi, tmp.se)) dist[d.fi].se = 1;
            else if(dist[d.fi].fi == tmp.se) dist[d.fi]++;
        }
    }

    vector<pii> G(ALL(edges[cen]));
    for(pii v : G) if(v.fi != p) {
        edges[cen].erase(v);
        edges[v.fi].erase(mp(cen, v.se));
        res += solve(v.fi, cen);
    }
    return res;
}
void xuli(){
    cout << solve(1, 0).se;
}
int32_t main()
{
    FastIO
    freopen("RACE.INP", "r", stdin);
    freopen("RACE.OUT", "w", stdout);
    cin >> n >> k;
    for(int i = 1; i < n; i++){
        int u, v, w;
        cin >> u >> v >> w;
        u++; v++;
        edges[u].insert(mp(v, w));
        edges[v].insert(mp(u, w));
    }
    n++;
    tree = FenwickTree(k + 1);

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
