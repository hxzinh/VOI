#include <bits/stdc++.h>
#define ll long long
#define INF 0x3f3f3f3f
#define pii pair<int, int>
#define pll pair<long long, long long>
#define fi first
#define se second
#define ALL(v) (v).begin(), (v).end()
#define popcount(x) __builtin_popcount(x)
#define setp(x) setprecision(x)
#define MASK(x) (1LL << (x))
#define BIT(x, i) ((x) >> (i) & 1)
#define FastIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

/**
//PRAGMA
#pragma GCC target("popcnt")
**/

/**
//ordered_set
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
typedef tree<pii,
             null_type,
             less<pii>,
             rb_tree_tag,
             tree_order_statistics_node_update> ordered_set;
**/

template<class X, class Y>
	inline bool maximize(X &x, const Y &y) {return (x < y ? x = y, 1 : 0);}
template<class X, class Y>
	inline bool minimize(X &x, const Y &y) {return (x > y ? x = y, 1 : 0);}

const int NM = 3e5 + 2;
const int MAX = 1500000;
int n, m, Sub;
int a[NM], child[NM], cnt[MAX + 2];
set<int> edges[NM];
vector<int> g, tmp;

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
ll dfs2(int u, int p, int cur, vector<int> &tmp){
    ll ans = cur;
    for(int curGcd : g) {
        int newGcd = __gcd(cur, curGcd);
        ans += 1LL * newGcd * cnt[curGcd];
    }

    tmp.push_back(cur);
    for(int v : edges[u]) if(v != p) {
        ans += dfs2(v, u, __gcd(cur, a[v]), tmp);
    }
    return ans;
}
ll solve(int u, int p){
    dfs(u, p);
    int node = child[u];
    int cen = centroid(u, p, node);

    ll res = 0;
    for(int cur : g) cnt[cur] = 0;
    g.clear();

    for(int v : edges[cen]) if(v != p){
        vector<int> tmp;
        res += dfs2(v, cen, __gcd(a[cen], a[v]), tmp);
        for(int h : tmp) {
            if(!cnt[h]) g.push_back(h);
            cnt[h]++;
        }
    }

    vector<int> tam(ALL(edges[cen]));
    for(int v : tam) {
        edges[v].erase(cen);
        edges[cen].erase(v);
        res += solve(v, cen);
    }
    return res;
}
void xuli() {
    cout << solve(1, -1);
}
int32_t main()
{
    FastIO
    freopen("GCDPATH.INP", "r", stdin);
    freopen("GCDPATH.OUT", "w", stdout);
    cin >> Sub;
    cin >> n;
    for(int i = 1; i <= n; i++) cin >> a[i];
    for(int i = 1; i < n; i++) {
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
