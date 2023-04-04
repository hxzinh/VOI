#include <bits/stdc++.h>
#define ll long long
#define INF 0x3f3f3f3f
#define pii pair<int, int>
#define mp make_pair
#define fi first
#define se second
#define ALL(v) (v).begin(), (v).end()
#define popcount(x) __builtin_popcount(x)
#define setp(x) setprecision(x)
#define MASK(x) (1LL << (x))
#define BIT(x, i) ((x) >> (i) & 1)
#define FastIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

template<class X, class Y>
	inline bool maximize(X &x, const Y &y) {return (x < y ? x = y, 1 : 0);}
template<class X, class Y>
	inline bool minimize(X &x, const Y &y) {return (x > y ? x = y, 1 : 0);}

const int NM = 1e3 + 10;
int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};
int n, m, xs, ys, xf, yf, k;
int f[NM][NM], dp[NM][NM];
pii a[NM];

struct Data {
    int u, v, cost;
};

void bfs() {
    memset(f, INF, sizeof f);

    queue<pii> q;
    for(int i = 1; i <= k; i++) {
        int x = a[i].fi, y = a[i].se;
        f[x][y] = 0;
        q.push({x, y});
    }

    while(q.size()) {
        int x = q.front().fi, y = q.front().se;
        q.pop();

        for(int i = 0; i < 4; i++) {
            int u = x + dx[i], v = y + dy[i];
            if(u <= 0 || u > n || v <= 0 || v > m) continue;
            if(minimize(f[u][v], f[x][y] + 1))
            q.push({u, v});
        }
    }
}
void xuli() {
    bfs();

    queue<Data> q;
    dp[xs][ys] = f[xs][ys];
    q.push({xs, ys, f[xs][ys]});

    while(q.size()) {
        int x = q.front().u, y = q.front().v, cost = q.front().cost;
        q.pop();

        if(x == xf && y == yf) continue;

        for(int i = 0; i < 4; i++) {
            int u = x + dx[i], v = y + dy[i];
            if(u <= 0 || u > n || v <= 0 || v > m) continue;
            int newCost = min(cost, f[u][v]);
            if(maximize(dp[u][v], newCost))
                q.push({u, v, newCost});
        }
    }

    cout << 1LL * dp[xf][yf] * dp[xf][yf];
}
int32_t main()
{
    FastIO
    freopen("ROBOT.INP", "r", stdin);
    freopen("ROBOT.OUT", "w", stdout);
    cin >> n >> m;
    cin >> xs >> ys >> xf >> yf;
    cin >> k;
    for(int i = 1; i <= k; i++) cin >> a[i].fi >> a[i].se;

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
