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

const int NM = 1e4 + 10;
int n, m;
char a[105][105];
int curId = 0, numNode = 0;
int Low[NM], Num[NM], id[105][105], cost[NM], f[NM], par[NM];
stack<int> st;
vector<int> edges[NM], h[NM];
bool visited[NM];

int getId(int x, int y) {
    return (x - 1) * m + y;
}
void dfs(int u, int p) {
    Low[u] = Num[u] = ++curId;
    st.push(u);
    for(int v : edges[u]) if(v != p) {
        if(visited[u]) continue;
        if(!Num[v]) {
            dfs(v, u);
            minimize(Low[u], Low[v]);
        } else  minimize(Low[u], Num[v]);
    }

    if(Low[u] == Num[u]) {
        numNode++;
        int v;
        do {
            v = st.top();
            st.pop();
            if(v != u) cost[u] += cost[v];
            visited[v] = true;
            par[v] = u;
        } while(v != u);
    }
}
int solve(int u) {
    if(h[u].empty()) return cost[u];
    if(f[u] > -1) return f[u];

    int &res = f[u];
    for(int v : h[u]) maximize(res, solve(v) + cost[u]);
    return res;
}
void xuli() {
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            int u = (i - 1) * m + j;
            if(!Num[u] && a[i][j] != '#') dfs(u, -1);
        }
    }

    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) if(a[i][j] != '#') {
            int u = (i - 1) * m + j;
            int rootu = par[u];

            for(int v : edges[u]) {
                int rootv = par[v];
                if(rootu != rootv) {
                    h[rootu].push_back(rootv);
                    //h[rootv].push_back(rootu);
                }
            }
        }
    }

    memset(f, -1, sizeof f);
    int res = solve(1);
    cout << res;
}
int32_t main()
{
    FastIO
    freopen("KCOLLECT.INP", "r", stdin);
    freopen("KCOLLECT.OUT", "w", stdout);
    cin >> n >> m;
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            cin >> a[i][j];
            id[i][j] = (i - 1) * m + j;
            if(a[i][j] >= '0' && a[i][j] <= '9') cost[getId(i, j)] = int(a[i][j] - '0');

            if(j < m && a[i][j + 1] != '#') edges[id[i][j]].push_back(id[i][j] + 1);
            if(i < n && a[i + 1][j] != '#') edges[id[i][j]].push_back(id[i][j] + m);

            if(a[i][j] == 'N' && i > 1 && a[i - 1][j] != '#') edges[id[i][j]].push_back(id[i][j] - m);
            if(a[i][j] == 'W' && j > 1 && a[i][j - 1] != '#') edges[id[i][j]].push_back(id[i][j] - 1);
        }
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
