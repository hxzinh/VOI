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

const int NM = 1e3 + 10;
int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};
int n, m, k;
int curId = 0;
int id[NM][NM], cnt[100005];
char a[NM][NM];
bool cx[100005];

void bfs(int s, int t) {
    queue<pii> q;
    q.push({s, t});

    while(q.size()) {
        int x = q.front().fi, y = q.front().se;
        q.pop();

        if(!id[x][y]) id[x][y] = curId;
        else continue;

        cnt[curId]++;
        if(x == 1 || x == n || y == 1 || y == m) cx[curId] = true;

        for(int i = 0; i < 4; i++) {
            int u = x + dx[i], v = y + dy[i];
            if(a[u][v] != '.' || id[u][v]) continue;
            q.push({u, v});
        }
    }
}
void xuli() {
    vector<pii> vec;
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) if(a[i][j] == '.' && !id[i][j]) {
            curId++;
            bfs(i, j);
            if(!cx[curId]) vec.push_back({cnt[curId], curId});
        }
    }

    memset(cx, false, sizeof cx);
    int res = 0;
    sort(ALL(vec));
    for(int i = 0; i < vec.size() - k; i++) {
        res += vec[i].fi;
        cx[vec[i].se] = true;
    }

    cout << res << '\n';
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            if(cx[id[i][j]]) a[i][j] = '#';
            cout << a[i][j];
        }
        cout << '\n';
    }
}
int32_t main()
{
    FastIO
    freopen("HANOI.INP", "r", stdin);
    freopen("HANOI.OUT", "w", stdout);
    cin >> n >> m >> k;
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= m; j++) cin >> a[i][j];

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
