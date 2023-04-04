#include <bits/stdc++.h>
#define ll long long
#define int long long
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
#define ID(x, y) ((x - 1) * n + y)
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
int dx[] = {0, -1, 0, 1, 0, -1, 0, 1};
int dy[] = {-1, 0, 1, 0, -1, 0, 1, 0};
ll n, Time;
pii start;
char a[NM][NM];
ll dp[1000005][5];

void xuli() {
    ll x = start.fi, y = start.se, t = 0;
    bool ok = false;
    if(y <= 0 || x > n || x <= 0) y -= Time;
    else {
        if(a[x][n] == '.') {
            ok = true;
            Time -= y - n;
            y = n;
        }
        else {
            Time -= y - n - 1;
            y = n + 1;
            x -= Time;
            t = 1;
        }
    }

    if(!ok) {
        cout << x << " " << y;
        return;
    }

    memset(dp, -1, sizeof dp);
    dp[ID(x, y)][t] = Time;
    while(Time > 0) {
        bool ins = true;
        for(int i = t; i <= t + 4; i++) {
            ll u = x + dx[i], v = y + dy[i];
            if(a[u][v] == '#') continue;
            t = i % 4;
            if(u <= 0 || u > n || v <= 0 || v > n) {
                ins = false;
                break;
            }

            Time--;
            if(dp[ID(u, v)][t] > -1) Time = Time % (dp[ID(u, v)][t] - Time);
            dp[ID(u, v)][t] = Time;
            x = u; y = v;
            break;
        }

        if(!ins) {
            x += dx[t] * Time;
            y += dy[t] * Time;
            break;
        }
    }

    cout << x << " " << y;

}
int32_t main()
{
    FastIO
    freopen("ROBOT.INP", "r", stdin);
    freopen("ROBOT.OUT", "w", stdout);
    cin >> n >> start.fi >> start.se >> Time;
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= n; j++) cin >> a[j][i];

    xuli();
    return 0;
}

/* Author: hxzinh */

