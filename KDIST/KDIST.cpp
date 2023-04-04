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

const int NM = 1e5 + 10;
int n, m, k;
int id[NM], high[NM], s[NM], cnt = 0;
vector<int> edges[NM];
bool isSpec[NM];

struct SegmentTree {

};

bool check(int u, int p, int h) {
    if(isSpec[u] && h > k) return false;
    for(int v : edges[u]) if(v != p) {
        if(!check(v, u, h + 1)) return false;
    }
    return true;
}
void sub1() {
    int res = 0;
    for(int i = 1; i <= n; i++) if(check(i, -1, 0)) res++;
    cout << res;
}
void dfs(int u, int p) {
    for(int v : edges[u]) if(v != p) {
        high[v] = high[u] + 1;
        dfs(v, u);
    }
}
void dfs2(int u, int p) {
    id[u] = ++cnt;
    for(int v : edges[u]) if(v != p) dfs2(v, u);
}
void sub2() {
    int parNode = 1, curHigh = 0;
    dfs(1, -1);
    for(int i = 1; i <= n; i++) if(high[i] > curHigh) parNode = i;
    dfs2(parNode, -1);

    for(int i = 1; i <= n; i++) if(isSpec[i]) {
        s[max(1, id[i] - k)]++;
        s[min(n, id[i] + k) + 1]--;
    }

    int res = 0;
    for(int i = 1; i <= n; i++) {
        s[i] += s[i - 1];
        if(s[i] >= m) res++;
    }
    cout << res;
}
int32_t main()
{
    FastIO
    freopen("KDIST.INP", "r", stdin);
    freopen("KDIST.OUT", "w", stdout);
    cin >> n >> m >> k;
    for(int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        edges[u].push_back(v);
        edges[v].push_back(u);
    }
    for(int i = 1; i <= n; i++) {
        int u; cin >> u;
        isSpec[u] = 1;
    }

    bool ok = true;
    for(int i = 1; i <= n; i++) if(edges[i].size() > 2) ok = false;

    if(ok) sub2();
    else sub1();
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
