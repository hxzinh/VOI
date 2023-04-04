#include <bits/stdc++.h>
#define ll long long
#define INF 0x3f3f3f3f
#define pii pair<int, int>
#define fi first
#define se second
#define ALL(v) (v).begin(), (v).end()
#define popcount(x) __builtin_popcount(x)
#define set(x) setprecision(x)
#define MASK(x) (1LL << (x))
#define BIT(x, i) ((x) >> (i) & 1)
#define FastIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

template<class X, class Y>
	inline bool maximize(X &x, const Y &y) {return (x < y ? x = y, 1 : 0);}
template<class X, class Y>
	inline bool minimize(X &x, const Y &y) {return (x > y ? x = y, 1 : 0);}

const int NM = 2e3 + 10;
int n, m;
int a[201][201], query[2001];
int g[2001][201][201], f[2][201][201];

int DP(int x, int u, int v){
    if(x > m) return 0;
    int pre = query[x - 1];
    if(pre == u || pre == v || u == v) return INF - 1;
    int &res = g[x][u][v];
    if(res < INF) return res;
    int cur = query[x];
    minimize(res, a[pre][cur] + DP(x + 1, u, v));
    minimize(res, a[u][cur] + DP(x + 1, pre, v));
    minimize(res, a[v][cur] + DP(x + 1, u, pre));
    return res;
}
void full(){
    memset(g, INF, sizeof g);
    query[0] = 1;
    cout << DP(1, 2, 3);
}
void qhd(){
    memset(f, INF, sizeof f);
    query[0] = 1;
    f[0][2][3] = f[0][3][2] = 0;
    int serv = 1;
    for (int t = 1; t <= m; ++t)
    {
        bool cur = t & 1;
        bool pre = !cur;

        int c = query[t - 1];
        int serv = query[t];
        for (int u = 1; u <= n; ++u)
            for (int v = 1; v <= n; ++v)
                f[cur][u][v] = +INF;

        for (int u = 1; u <= n; ++u)
        {
            if (u == c) continue;
            for (int v = 1; v <= n; ++v)
            {
                if (v == c || v == u) continue;
                if (f[pre][u][v] == +INF) continue;
                minimize(f[cur][u][v], f[pre][u][v] + a[c][serv]);
                minimize(f[cur][v][c], f[pre][u][v] + a[u][serv]);
                minimize(f[cur][c][u], f[pre][u][v] + a[v][serv]);
            }
        }
    }

    int res = +INF;
    bool cur = m & 1;
    for (int u = 1; u <= n; ++u)
        for (int v = 1; v <= n; ++v)
            minimize(res, f[cur][u][v]);

    cout << res;
}
int main()
{
    FastIO
    freopen("SERVICE.INP", "r", stdin);
    freopen("SERVICE.OUT", "w", stdout);
    cin >> n >> m;
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= n; j++) cin >> a[i][j];

    for(int i = 1; i <= m; i++) cin >> query[i];

    qhd();
    return 0;
}
