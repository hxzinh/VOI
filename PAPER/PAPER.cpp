#include <bits/stdc++.h>
#define int long long
#define INF 1e9
#define FastIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

template<class X, class Y>
	inline bool maximize(X &x, const Y &y) {return (x < y ? x = y, 1 : 0);}
template<class X, class Y>
	inline bool minimize(X &x, const Y &y) {return (x > y ? x = y, 1 : 0);}

const int NM = 1e3 + 10;
int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};
int n, k, m;
int l, r, u, d;
long long f[2][2][2][2], T[2][2][2][2];
bool cx[NM][NM], a[NM][NM];
int pw[33];

bool check(int x, int y) {
    return (x >= 1 && x <= pw[k] && y >= 1 && y <= pw[k] && !cx[x][y] && !a[x][y]);
}
void dfs(int x, int y) {
    cx[x][y] = true;
    if (x == 1) u = true;
    if (x == pw[k]) d = true;
    if (y == 1) l = true;
    if (y == pw[k]) r = true;

    for (int i = 0; i < 4; ++i) {
        int u = x + dx[i], v = y + dy[i];
        if (check(u, v)) dfs(u, v);
    }
}
void xuli(){
    memset(f, 0, sizeof f);

    for (int i = 1; i <= pw[k]; ++i) {
        for (int j = 1; j <= pw[k]; ++j) if(check(i, j)){
            l = r = u = d = false;
            dfs(i, j);
            f[l][r][u][d]++;
        }
    }

    for (int i = 1; i <= n - k; ++i) {
        memset(T, 0, sizeof T);
        for (int x = 0; x <= 1; ++x) {
            for (int y = 0; y <= 1; ++y) {
                T[0][0][x][y] += f[1][0][x][y];
                T[1][0][x][y] += f[0][1][x][y];
                T[0][0][x][y] += f[0][0][x][y];
            }
        }

        for (int x = 0; x <= 1; ++x)
            for (int y = 0; y <= 1; ++y) f[1][0][x][y] = 0;

        for (int i = 0; i <= 1; ++i)
            for (int j = 0; j <= 1; ++j)
                for (int x = 0; x <= 1; ++x)
                    for (int y = 0; y <= 1; ++y) f[i][j][x][y] += T[i][j][x][y];

        memset(T, 0, sizeof(T));

        for (int x = 0; x <= 1; ++x) {
            for (int y = 0; y <= 1; ++y) {
                T[x][y][0][0] += f[x][y][0][1];
                T[x][y][0][1] += f[x][y][1][0];
                T[x][y][0][0] += f[x][y][0][0];
            }
        }

        for (int x = 0; x <= 1; ++x)
            for (int y = 0; y <= 1; ++y) f[x][y][0][1] = 0;

        for (int i = 0; i <= 1; ++i)
            for (int j = 0; j <= 1; ++j)
                for (int x = 0; x <= 1; ++x)
                    for (int y = 0; y <= 1; ++y) f[i][j][x][y] += T[i][j][x][y];
    }

    int ans = 0;
    for (int i = 0; i <= 1; ++i)
        for (int j = 0; j <= 1; ++j)
            for (int x = 0; x <= 1; ++x)
                for (int y = 0; y <= 1; ++y) ans += f[i][j][x][y];
    cout << ans;
}
int32_t main()
{
    FastIO
    freopen("PAPER.INP", "r", stdin);
    freopen("PAPER.OUT", "w", stdout);
    cin >> n >> k >> m;
    for(int i = 1; i <= m; i++){
        int u, v;
        cin >> u >> v;
        a[u][v] = true;
    }

    pw[0] = 1;
    for(int i = 1; i <= n; i++) pw[i] = pw[i - 1] * 2;

    xuli();
    return 0;
}
