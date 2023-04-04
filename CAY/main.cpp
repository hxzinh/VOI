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

const int NM = 3e5 + 10;
int n, k, Sub;
int a[NM];
vector<pii> edges[NM];

int d[50][50];

void dfs(int u, int p, int parNode) {
    for(pii v : edges[u]) if(v.fi != p) {
        d[parNode][v.fi] = d[parNode][u] + v.se;
        dfs(v.fi, u, parNode);
    }
}
bool check(ll x, ll y, ll z) {
    return (d[x][y] + d[y][z] > d[z][x]) && (d[x][y] + d[x][z] > d[y][z]) && (d[x][z] + d[y][z] > d[x][y]);
}
void sub1() {
    for(int i = 1; i <= n; i++) dfs(i, 0, i);

    ll res = 0, trace = 0;
    for(int mask = 0; mask < MASK(n); mask++) {
        vector<int> tmp;
        int m = __builtin_popcount(mask);
        for(int i = 1; i <= n; i++) if(BIT(mask, i - 1)) tmp.push_back(i);

        bool ok = true;
        for(int i = 0; i < m; i++) {
            for(int j = i + 1; j < m; j++) {
                int u = tmp[i], v = tmp[j];
                if(d[u][v] < k) {
                    ok = false;
                    break;
                }
            }
            if(!ok) break;
        }
        if(!ok) continue;

        ok = true;
        for(int i = 0; i < m; i++) {
            for(int j = i + 1; j < m; j++) {
                for(int k = j + 1; k < m; k++) {
                    if(!check(tmp[i], tmp[j], tmp[k])) {
                        ok = false;
                        break;
                    }
                }
                if(!ok) break;
            }
            if(!ok) break;
        }
        if(!ok) continue;

        ll ans = 0;
        for(int i = 1; i <= n; i++) if(BIT(mask, i - 1)) ans += a[i];
        if(maximize(res, ans)) trace = mask;
    }

    cout << res << '\n';
    cout << __builtin_popcount(trace) << '\n';
    for(int i = 1; i <= n; i++) if(BIT(trace, i - 1)) cout << i << " ";
}
int32_t main()
{
    FastIO
    freopen("CAY.INP", "r", stdin);
    freopen("CAY.OUT", "w", stdout);
    cin >> Sub;
    cin >> n >> k;
    for(int i = 1; i <= n; i++) cin >> a[i];
    for(int i = 1; i < n; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        edges[u].push_back({v, w});
        edges[v].push_back({u, w});
    }

    sub1();
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
