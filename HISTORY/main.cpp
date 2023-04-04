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

const int NM = 6e5 + 10;
int n, q;

struct Query {
    int type, u, v, k, id;
} query[NM];

struct DijoinsetUnion {
    int n;
    vector<int> par;

    DijoinsetUnion(int _n = 0) {
        n = _n;
        par.assign(n + 7, -1);
    }

    void init() {
        par.assign(n + 7, -1);
    }

    int root(int x) {
        if(par[x] < 0) return x;
        return par[x] = root(par[x]);
    }

    bool join(int u, int v) {
        u = root(u); v = root(v);
        if(u == v) return false;

        if(par[u] > par[v]) swap(u, v);
        par[u] += par[v];
        par[v] = u;
        return true;
    }
};

void xuli() {
    DijoinsetUnion dsu(n);
    while(true) {
        dsu.init();
    }
}
int32_t main()
{
    FastIO
    freopen("HISTORY.INP", "r", stdin);
    freopen("HISTORY.OUT", "w", stdout);
    cin >> n >> q;
    for(int i = 1; i <= q; i++) {
        int type, u, v;
        cin >> type;
        if(type == 3) {
            cin >> u;
            query[i] = {type, 0, 0, u, i};
        }
        else {
            cin >> u >> v;
            query[i] = {type, u, v, 0, i};
        }
    }
    return 0;
}

/* Author: hxzinh */

