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

const int NM = 505;
int n;
int a[NM][NM];
int f[NM], dp[NM];
bool inq[NM];

struct Data {
    int u, cost;

    bool inline operator < (const Data &A) const {
        return cost > A.cost;
    }
};

void dijkstra() {
    memset(f, INF, sizeof f);
    queue<int> q;
    f[1] = 0;
    q.push(1);
    inq[1] = true;

    while(q.size()) {
        int u = q.front();
        q.pop();

        inq[u] = false;
        for(int v = 1; v <= n; v++) if(v != u) {
            if(minimize(f[v], f[u] + a[u][v])) {
                if(!inq[v]) {
                    inq[v] = true;
                    q.push(v);
                }
            }
        }
    }
}
void xuli() {
    dijkstra();

    //for(int i = 1; i <= n; i++) cout << f[i] << " ";

    int res = 0;
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            int cur = a[i][j];
            a[i][j] = INF;

            memset(dp, INF, sizeof dp);
            memset(inq, false, sizeof inq);
            dp[1] = 0;
            queue<int> q;
            q.push(1);
            inq[1] = true;

            while(q.size()) {
                int u = q.front();
                q.pop();
                inq[u] = false;

                for(int v = 1; v <= n; v++) if(v != u) {
                    if(minimize(dp[v], dp[u] + a[u][v])) {
                        if(!inq[v]) {
                            inq[v] = true;
                            q.push(v);
                        }
                    }
                }

            }
            int ans = 0;
            for(int i = 1; i <= n; i++) if(dp[i] > f[i]) ans++;
            maximize(res, ans);

            a[i][j] = cur;
        }
    }
    cout << res;
}
int32_t main()
{
    FastIO
    freopen("DOTHI.INP", "r", stdin);
    freopen("DOTHI.OUT", "w", stdout);
    cin >> n;
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= n; j++) {
            cin >> a[i][j];
            if(a[i][j] == -1) a[i][j] = INF;
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
