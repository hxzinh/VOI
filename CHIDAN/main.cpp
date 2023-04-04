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

const int NM = 2e2 + 10;
int n, q;
int par[NM], high[NM], M[NM][22];
vector<int> edges[NM];

void dfs(int u, int p) {
    for(int v : edges[u]) if(v != p) {
        par[v] = u;
        high[v] = high[u] + 1;
        dfs(v, u);
    }
}
void make_lca() {
    for(int i = 1; i <= n; i++)
        M[i][0] = par[i];

    for(int k = 1; k <= 20; k++)
        for (int i = 1; i <= n; i++)
            M[i][k] = M[M[i][k - 1]][k - 1];
}
int getLca(int u, int v) {
    for(int i = 20; i >= 0; i--)
        if(high[M[u][i]] >= high[v]) u = M[u][i];

    for(int i = 20; i >= 0; i--)
        if(high[M[v][i]] >= high[u]) v = M[v][i];

    if(u == v) return u;

    for(int i = 20; i >= 0; i--) {
        if(M[u][i] != M[v][i]) {
            u = M[u][i];
            v = M[v][i];
        }
    }

    return par[u];
}
void xuli() {
    par[1] = 1;
    dfs(1, 1);
    make_lca();

    while(q--) {
        int u, v;
        cin >> u >> v;

        int p = getLca(u, v);
        if(u == p) {
            for(int i = 0; i <= 20; i++) {
                if(high[M[v][i]] > p) v = M[v][i];
            }
            cout << v << '\n';
        } else cout << par[u] << '\n';
    }
}
int32_t main()
{
    FastIO
    freopen("CHIDAN.INP", "r", stdin);
    freopen("CHIDAN.OUT", "w", stdout);
    cin >> n;
    for(int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        edges[u].push_back(v);
        edges[v].push_back(u);
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
