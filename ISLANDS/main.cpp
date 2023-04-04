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

const int NM = 505;
int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};
int n, m;
int a[NM][NM];

int dfs(int x, int y) {
    int child = 1;
    for(int i = 0; i < 4; i++) {
        int u = x + dx[i], v = y + dy[i];
        if(u <= 0 || u > n || v <= 0 || v > m || !a[u][v]) continue;
        child += dfs(u, v);
    }
    return child;
}
void xuli() {

}
int32_t main()
{
    FastIO
    freopen("ISLANDS.INP", "r", stdin);
    freopen("ISLANDS.OUT", "w", stdout);
    cin >> n >> m;
    for(int i = 1; i <= n; i++) {
        string s; cin >> s;
        for(int j = 1; j <= m; j++) a[i][j] = s[j - 1] - '0';
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
