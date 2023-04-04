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

int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};
int n, m, q;
char a[55][55];
pii b[55];

void dfs(int x, int y, char k){
    if(x > n || y > m ) return;
    a[x][y] = k;
    for(int i = 0; i < 4; i++){
        int u = x + dx[i];
        int v = y + dy[i];
        if(a[u][v] == '.') dfs(u, v, k);
    }
    return;
}
void xuli(){
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= m; j++) if(a[i][j] != 'X' && a[i][j] != '.') dfs(i, j, a[i][j]);

    bool ok = false;
    for(int i = 1; i <= q; i++){
        int u = b[i].fi;
        int v = b[i].se;
        if(a[u][v] != 'X' && a[u][v] != '.') ok = true;
        if(a[u][v] != 'X' && a[u][v] != '.') cout << a[u][v];
    }
    if(!ok) cout << "Empty";
}
int main()
{
    FastIO
    freopen("KEYBOARD.INP", "r", stdin);
    freopen("KEYBOARD.OUT", "w", stdout);
    cin >> n >> m >> q;
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= m; j++) cin >> a[i][j];
    for(int i = 1; i <= q; i++) cin >> b[i].fi >> b[i].se;


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

