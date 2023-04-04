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

const int NM = 105;
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, -1, 1};
int n;
int a[NM][NM], minHigh = INF, maxHigh = -1;
int ok[NM][NM];
bool visited[NM][NM];

void dfs(int x, int y) {
    ok[x][y] = 2;
    for(int i = 0; i < 4; i++) {
        int u = x + dx[i], v = y + dy[i];
        if(ok[u][v] == 1) dfs(u, v);
    }
}
bool inRange(int Min, int Max) {
    for(int i = 1; i <= n; i++)
    for(int j = 1; j <= n; j++) {
        if(a[i][j] > Max || a[i][j] < Min) ok[i][j] = 0;
        else ok[i][j] = 1;
    }
    if(!ok[1][1] || !ok[n][n]) return false;

    dfs(1, 1);
    return (ok[n][n] == 2);
}
bool check(int cost) {
    if(cost > maxHigh - minHigh) return true;
    for(int i = minHigh; i + cost <= maxHigh; i++)
        if(inRange(i, i + cost)) return true;
    return false;
}
void xuli() {
    int l = 0, r = 110, res = INF;
    while(l <= r) {
        int m = (l + r) >> 1;
        if(check(m)) {
            res = m;
            r = m - 1;
        } else l = m + 1;
    }
    cout << res;
}
int32_t main()
{
    FastIO
    freopen("MTWALK.INP", "r", stdin);
    freopen("MTWALK.OUT", "w", stdout);
    cin >> n;
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= n; j++) {
            cin >> a[i][j];
            minimize(minHigh, a[i][j]);
            maximize(maxHigh, a[i][j]);
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
