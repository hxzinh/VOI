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

const int NM = 5e4 + 10;
const int LOG = 10;
int dx[] = {0, 1};
int dy[] = {1, 0};
int W, H, n, m;
pii a[NM], d[NM];
int matrix[505][505], f[505][505][4][25], dp[NM][35];


struct Data {
    int x, y, t, k, cost;
};

void sub12() {
    for(int i = 1; i <= n; i++) {
        if(a[i].fi <= W && a[i].se <= H)
            matrix[a[i].fi][a[i].se] = 1;
    }
    for(int i = 1; i <= m; i++) {
        if(d[i].fi <= W && d[i].se <= H)
            matrix[d[i].fi][d[i].se] = -1;
    }

    memset(f, INF, sizeof f);
    queue<Data> q;
    q.push({0, 0, 3, 0, 0});
    f[0][0][3][0] = 0;

    int res = INF;
    while(q.size()) {
        Data u = q.front();
        q.pop();

        cout << u.x << " " << u.y << " " << u.t << " " << u.k << " " << u.cost << '\n';

        if(f[u.x][u.y][u.t][u.k] != u.cost) continue;

        if(u.t == 3) {
            for(int i = 0; i < 2; i++) {
                int x = u.x + dx[i] * MASK(u.k);
                int y = u.y + dy[i] * MASK(u.k);
                if(x > W || y > H) continue;
                if(matrix[x][y] == 1) {
                    if(minimize(f[x][y][3][u.k + 1], u.cost + 1))
                        q.push({x, y, 3, u.k + 1, u.cost + 1});

                    if(minimize(f[x][y][3][u.k], u.cost + 1))
                        q.push({x, y, 3, u.k, u.cost + 1});
                }
                else if(matrix[x][y] == -1) {
                    if(minimize(f[x][y][3][0], u.cost + 1))
                        q.push({x, y, 3, 0, u.cost + 1});
                }
                else {
                    if(minimize(f[x][y][i][u.k], u.cost + 1))
                        q.push({x, y, i, u.k, u.cost + 1});
                }
            }
        }
        else {
            int x = u.x + dx[u.t] * MASK(u.k);
            int y = u.y + dy[u.t] * MASK(u.k);
            if(x > W || y > H) continue;
            if(matrix[x][y] == 1) {
                if(minimize(f[x][y][3][u.k + 1], u.cost + 1))
                    q.push({x, y, 3, u.k + 1, u.cost + 1});
                if(minimize(f[x][y][3][u.k], u.cost + 1))
                    q.push({x, y, 3, u.k, u.cost + 1});
            }
            else if(matrix[x][y] == -1) {
                if(minimize(f[x][y][3][0], u.cost + 1))
                    q.push({x, y, 3, 0, u.cost + 1});
            }
            else {
                if(minimize(f[x][y][u.t][u.k], u.cost + 1))
                    q.push({x, y, u.t, u.k, u.cost + 1});
            }
        }
    }

    for(int i = 0; i < 4; i++)
        for(int j = 0; j < LOG; j++) minimize(res, f[W][H][i][j]);
    cout << res;
}
void sub4() {
    vector<pii> tmp;
    for(int i = 1; i <= n; i++) if(a[i].se == 0) tmp.push_back({a[i].fi, 1});
    for(int i = 1; i <= m; i++) if(d[i].se == 0) tmp.push_back({d[i].fi, -1});
    tmp.push_back({W, 1}); tmp.push_back({-INF, 1});
    sort(ALL(tmp));

    memset(dp, INF, sizeof dp);
    dp[0][0] = 0;
    int numNode = tmp.size();
    for(int i = 0; i < numNode; i++) {
        for(int j = 0; j <= 30; j++) if(dp[i][j] < INF) {
            if(tmp[i + 1].se == 1) {
                minimize(dp[i + 1][j + 1], dp[i][j] + 1);
                minimize(dp[i + 1][j], dp[i][j] + 1);
            }
            if(tmp[i + 1].se == 1) {
                minimize(dp[i + 1][0], dp[i][j] + 1);
            }
        }
    }

    int res = INF;
    for(int i = 0; i <= 30; i++) minimize(res, dp[numNode][i]);
    cout << res;
}
int32_t main()
{
    FastIO
    freopen("BOUNCE2D.INP", "r", stdin);
    freopen("BOUNCE2D.OUT", "w", stdout);
    cin >> W >> H >> n >> m;
    for(int i = 1; i <= n; i++) cin >> a[i].fi >> a[i].se;
    for(int i = 1; i <= m; i++) cin >> d[i].fi >> d[i].se;

    sub12();
    return 0;
}

/* Author: hxzinh */


