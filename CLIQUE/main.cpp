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

const int NM = 1e5 + 10;
int n, m, k, T;
int a[5005][5005], cntEdges[NM], trace[NM];
bool ok = false;

bool check(int x) {
    for(int i = 1; i < x; i++) {
        if(!a[trace[x]][trace[i]]) return false;
    }
    return true;
}
void backtrack(int x, int cur) {
    if(cur == k + 1) {
        if(check(cur - 1)) {
            for(int i = 1; i < cur; i++) cout << trace[i] << " ";
            cout << '\n';
            ok = true;
            throw 1;
        }
    }

    for(int i = x + 1; i <= n; i++) {
        if(cntEdges[i] < k - 1) continue;
        trace[cur] = i;
        if(check(cur)) backtrack(i, cur + 1);
    }
}
void xuli() {
    try {
        backtrack(0, 1);
    }
    catch(...){}

    if(!ok) cout << -1 << '\n';
}
void init() {
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) a[i][j] = 0;
        cntEdges[i] = 0;
    }
    ok = false;
}
int32_t main()
{
    FastIO
    freopen("CLIQUE.INP", "r", stdin);
    freopen("CLIQUE.OUT", "w", stdout);
    cin >> T;
    while(T--) {
        cin >> n >> m >> k;

        init();
        for(int i = 1; i <= m; i++) {
            int u, v; cin >> u >> v;
            a[u][v] = 1;
            a[v][u] = 1;
            cntEdges[u]++;
            cntEdges[v]++;
        }
        xuli();

    }

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
