#include <bits/stdc++.h>
#define ll long long
#define INF 0x3f3f3f3f
#define pii pair<int, int>
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
int dx[] = {-1, 0, 1, 0};
int dy[] = {0, -1, 0, 1};
int n, m, q, curId = 0;
int result = 0;
int a[NM][NM], id[NM][NM], cnt[1000005], par[1000005];
bool cx[NM][NM];

int dfsub(int x, int y) {
    int res = 1;
    cx[x][y] = true;
    for(int i = 0; i < 4; i++) {
        int u = x + dx[i], v = y + dy[i];
        if(u <= 0 || u > n || v <= 0 || v > m || cx[u][v]) continue;
        if(a[u][v]) res += dfsub(u, v);
    }
    return res;
}
void sub1() {
    for(int k = 1; k <= q; k++) {
        int u, v;
        cin >> u >> v;

        a[u][v] = 1;

        memset(cx, false, sizeof cx);

        pii trace;

        int res = 0;
        for(int i = 1; i <= n; i++)
            for(int j = 1; j <= m; j++) if(!cx[i][j] && a[i][j]) {
                if(maximize(res, dfsub(i, j))) trace = {i, j};
            }

        cout << res << '\n';
    }
}
void dfs(int x, int y) {
    id[x][y] = curId;
    cnt[curId]++;
    for(int i = 0; i < 4; i++) {
        int u = x + dx[i], v = y + dy[i];
        if(u <= 0 || u > n || v <= 0 || v > m || id[u][v]) continue;
        if(a[u][v]) dfs(u, v);
    }
}
int root(int x) {
    if(par[x] < 0) return x;
    return par[x] = root(par[x]);
}
void join(int x, int y) {
    int u = root(x), v = root(y);
    if(u == v) return;

    if(par[v] < par[u]) swap(u, v);

    par[u] += par[v];
    par[v] = u;

    maximize(result, -par[u]);
}

void xuli() {
    for(int i = 0; i <= n * m; i++) par[i] = -1;

    int res = 0;
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) if(a[i][j]) {
            id[i][j] = ++curId;
            cnt[curId] = 1;
            for(int k = 0; k < 2; k++) {
                int x = i + dx[k], y = j + dy[k];
                if(i <= 0 || i > n || j <= 0 || j > m || !a[x][y] || !id[x][y]) continue;

                int parNode = root(id[x][y]);
                if(parNode != curId) join(parNode, id[i][j]);
            }
        }
    }

    while(q--){
        int u, v;
        cin >> u >> v;

        if(a[u][v]) cout << result << '\n';
        else {
            id[u][v] = ++curId;
            a[u][v] = 1;
            cnt[id[u][v]] = 1;

            for(int i = 0; i < 4; i++) {
                int x = u + dx[i], y = v + dy[i];
                if(x <= 0 || x > n || y <= 0 || y > m || !a[x][y]) continue;
                int parNode = root(id[x][y]);
                if(parNode != id[u][v]) join(parNode, id[u][v]);
            }
            cout << result << '\n';
        }

        /**
        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= m; j++) cout << id[i][j] << " ";
            cout << '\n';
        }
        cout << '\n';
        **/
    }
}
int32_t main()
{
    FastIO
    freopen("BITMAP.INP", "r", stdin);
    freopen("BITMAP.OUT", "w", stdout);
    cin >> n >> m;
    for(int i = 1; i <= n; i++) {
        string s;
        cin >> s;
        for(int j = 0; j < m; j++) a[i][j + 1] = s[j] - '0';
    }
    cin >> q;

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
