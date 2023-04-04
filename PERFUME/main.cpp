#include <bits/stdc++.h>
#define ll long long
#define int long long
#define INF 0x3f3f3f3f3f3f3f
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

const int NM = 1e3 + 10;
int n, W, h;
int f[NM], c[NM][NM];
vector<pii> edges[NM];

struct Building {
    int x, y, u, v;
} a[NM];

bool checkInW(Building u, Building v) {
    return (u.x <= v.x && v.x <= u.u) || (u.x <= v.u && v.u <= u.u);
}
bool checkInH(Building u, Building v) {
    return (u.y <= v.y && v.y <= u.v) || (u.y <= v.v && v.v <= u.v);
}
void xuli() {
    sort(a + 1, a + n + 1, [](const Building A, const Building B){
        return A.x < B.x;
    });
    memset(c, INF, sizeof c);

    for(int i = 1; i <= n + 1; i++) f[i] = W;

    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) if(i != j) {
            int w;
            if((a[j].x >= a[i].x && a[j].x <= a[i].u)
            || (a[j].u >= a[i].x && a[j].u <= a[i].u)) {
                w = min(abs(a[i].y - a[j].v), abs(a[j].y - a[i].v)) - 1;
            }
            else
            if((a[j].y >= a[i].y && a[j].y <= a[i].v)
            || (a[j].v >= a[i].y && a[j].v <= a[i].v)) {
                w = min(abs(a[i].x - a[j].u), abs(a[j].x - a[i].u)) - 1;
            }
            else {
                if(a[j].y > a[i].v) {
                    if(a[j].u < a[i].x) w = max(abs(a[j].u - a[i].x), abs(a[j].y - a[i].v)) - 1;
                    else w = max(abs(a[j].x - a[i].u), abs(a[j].y - a[i].v)) - 1;
                } else {
                    if(a[j].u < a[i].x) w = max(abs(a[j].u - a[i].x), abs(a[i].y - a[j].v)) - 1;
                    else w = max(abs(a[j].x - a[i].u), abs(a[i].y - a[j].v)) - 1;
                }
            }

            minimize(c[i][j], w);
            minimize(c[j][i], w);
        }
        minimize(c[i][n + 1], abs(W - a[i].u) - 1) - 1;
    }

    queue<pii> q;

    for(int i = 1; i <= n; i++) {
        f[i] = a[i].x;
        q.push({i, f[i]});
    }

    while(q.size()) {
        int u = q.front().fi, cost = q.front().se;
        q.pop();

        if(f[u] < cost) continue;

        for(int v = 1; v <= n + 1; v++) {
            if(minimize(f[v], cost + c[u][v])) {
                q.push({v, f[v]});
            }
        }
    }

    cout << f[n + 1];
}
int32_t main()
{
    FastIO
    freopen("PERFUME.INP", "r", stdin);
    freopen("PERFUME.OUT", "w", stdout);
    cin >> W >> h >> n;
    for(int i = 1; i <= n; i++) {
        int x, y, u, v;
        cin >> x >> y >> u >> v;
        a[i].x = x; a[i].u = u;
        a[i].y = y; a[i].v = v;
    }


    xuli();
    return 0;
}

/* Author: hxzinh */


