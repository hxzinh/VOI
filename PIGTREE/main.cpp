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
int n, q;
int par[NM], s[NM], f[NM];
vector<int> vec;

struct Data {
    int u, v, w;
} e[NM];

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
void xuli() {
    memset(par, -1, sizeof par);

    sort(e + 1, e + n, [](const Data A, const Data B) {
        return A.w < B.w;
    });
    e[n].w = n;

    for(int i = 1; i < n; i++) {
        int u = root(e[i].u), v = root(e[i].v);
        s[e[i].w] += -par[u] * -par[v];
        join(u, v);
    }

    for(int i = 0; i < n; i++) s[i] += s[i - 1];
    //cout << '\n';

    while(q--) {
        int u, v;
        cin >> u >> v;
        u = lower_bound(ALL(vec), u) - vec.begin() + 1;
        v = upper_bound(ALL(vec), v) - vec.begin();

        int res = s[v] - s[u - 1];

        cout << res << '\n';
    }
}
int32_t main()
{
    FastIO
    freopen("PIGTREE.INP", "r", stdin);
    freopen("PIGTREE.OUT", "w", stdout);
    cin >> n >> q;
    for(int i = 1; i < n; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        e[i] = {u, v, w};
    }

    for(int i = 1; i < n; i++) vec.push_back(e[i].w);
    vec.push_back(INF);
    sort(ALL(vec));
    for(int i = 1; i < n; i++) e[i].w = lower_bound(ALL(vec), e[i].w) - vec.begin() + 1;

    xuli();
    return 0;
}

/* Author: hxzinh */

