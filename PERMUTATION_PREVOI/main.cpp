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
const int LOG = 20;
int n;
int high[NM], par[NM], a[NM], P[NM][22];
vector<int> edges[NM];

void dfs(int u, int p) {
    P[u][0] = p;
    for(int v : edges[u]) if(v != p) {
        high[v] = high[u] + 1;
        dfs(v, u);
    }
}
int getLca(int u, int v) {
    for(int i = LOG; i >= 0; i--)
        if(high[P[u][i]] >= high[v]) u = P[u][i];

    for(int i = LOG; i >= 0; i--)
        if(high[P[v][i]] >= high[u]) v = P[v][i];

    if(u == v) return u;

    for(int i = LOG; i >= 0; i--) {
        if(P[u][i] != P[v][i]) {
            u = P[u][i];
            v = P[v][i];
        }
    }

    return P[u][0];
}
void sub1() {
    for(int i = 1; i <= n; i++) a[i] = i;
    do {
        high[a[1]] = 0;
        dfs(a[1], 0);

        for(int k = 1; k <= LOG; k++)
            for(int i = 1; i <= n; i++) P[i][k] = P[P[i][k - 1]][k - 1];

        int curDist = 0;
        bool ok = true;
        for(int i = 2; i <= n; i++) {
            int p = getLca(a[i], a[i - 1]);
            int h = high[a[i]] + high[a[i - 1]] - 2 * high[p];
            if(curDist > h) {
                ok = false;
                break;
            }
            else curDist = h;
        }

        if(ok) {
            for(int i = 1; i <= n; i++) cout << a[i] << " ";
            break;
        }
    } while(next_permutation(a + 1, a + n + 1));
}
int32_t main()
{
    FastIO
    freopen("PERMUTATION.INP", "r", stdin);
    freopen("PERMUTATION.OUT", "w", stdout);
    cin >> n;
    for(int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        edges[u].push_back(v);
        edges[v].push_back(u);
    }

    sub1();
    return 0;
}

/* Author: hxzinh */

