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

const int NM = 1e3 + 10;
int n, m, a, b, h, k;
int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};
bool ok[NM][NM], cx[NM][NM];

struct Data {
    int x, y, u, v;
};

bool check(int x, int y, int u, int v) {
    if(x <= 0 || y <= 0 || u > n || v > m) return false;
    bool isEmpty = false;
    for(int i = x; i <= u; i++)
    for(int j = y; j <= v; j++) {
        if(!cx[i][j]) isEmpty = true;
        if(ok[i][j]) return false;
    }

    return isEmpty;
}
void xuli() {
    queue<Data> q;
    q.push({1, 1, a, b});
    for(int i = 1; i <= a; i++)
        for(int j = 1; j <= b; j++) cx[i][j] = true;

    while(q.size()) {
        Data cur = q.front();
        q.pop();

        for(int i = 0; i < 4; i++) {
            int x = cur.x + dx[i] * a, y = cur.y + dy[i] * a;
            int u = cur.u + dx[i] * a, v = cur.v + dy[i] * a;
            if(!check(x, y, u, v)) continue;
            for(int r = x; r <= u; r++)
                for(int c = y; c <= v; c++) cx[r][c] = true;
            q.push({x, y, u, v});
        }
    }

    int res = 0;
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= m; j++) if(cx[i][j]) res++;

    cout << res;
}
int32_t main()
{
    FastIO
    freopen("BLGAME.INP", "r", stdin);
    freopen("BLGAME.OUT", "w", stdout);
    cin >> a >> b >> h >> n >> m >> k;
    for(int i = 1; i <= k; i++) {
        int u, v;
        cin >> u >> v;
        ok[u][v] = true;
    }

    xuli();
    return 0;
}

/* Author: hxzinh */

