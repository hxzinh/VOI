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

const int NM = 2e3 + 10;
int dx[] = {0, 0, 1, -1};
int dy[] = {-1, 1, 0, 0};
int n, m;
pii start, target;
char a[NM][NM], c[5];
int dp[NM][NM][4], trace[NM][NM][4];

struct Data {
    int x, y, t, cost;

    bool inline operator < (const Data &A) const {
        return cost > A.cost;
    }
};

void xuli() {
    memset(dp, INF, sizeof dp);
    for(int i = 0; i < 4; i++) dp[start.fi][start.se][i] = 0;

    priority_queue<Data> pq;
    for(int i = 0; i < 4; i++) {
        int x = start.fi + dx[i], y = start.se + dy[i];
        if(x > n || y > m || x <= 0 || y <= 0) continue;

        minimize(dp[x][y][i], dp[start.fi][start.se][0]);
        pq.push({x, y, i, 0});
        trace[x][y][i] = -1;
    }

    while(pq.size()) {
        Data u = pq.top();
        pq.pop();

        if(a[u.x][u.y] == 'x') break;
        if(u.cost != dp[u.x][u.y][u.t]) continue;

        for(int i = 0; i < 4; i++) {
            int x = u.x + dx[i], y = u.y + dy[i];
            if(x > n || y > m || x <= 0 || y <= 0) continue;

            if(minimize(dp[x][y][i], u.cost + (c[i] != a[u.x][u.y]))) {
                pq.push({x, y, i, dp[x][y][i]});
                trace[x][y][i] = u.t;
            }
        }
    }

    int res = INF;
    int x = target.fi, y = target.se, t = -1;
    for(int i = 0; i < 4; i++) {
        if(minimize(res, dp[target.fi][target.se][i])) {
            t = i;
        }

    }
    cout << res << '\n';

    while(trace[x][y][t] != -1) {
        int u = x - dx[t], v = y - dy[t];
        a[u][v] = c[t];
        t = trace[x][y][t];
        x = u; y = v;
    }

    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) cout << a[i][j];
        cout << '\n';
    }
}
int32_t main()
{
    FastIO
    freopen("PATKICE.INP", "r", stdin);
    freopen("PATKICE.OUT", "w", stdout);
    cin >> n >> m;
    for(int i = 1; i <= n; i++)
    for(int j = 1; j <= m; j++) {
        cin >> a[i][j];
        if(a[i][j] == 'o') start = {i, j};
        if(a[i][j] == 'x') target = {i, j};
    }

    c[0] = '<'; c[1] = '>'; c[2] = 'v'; c[3] = '^';

    xuli();
    return 0;
}

/* Author: hxzinh */

