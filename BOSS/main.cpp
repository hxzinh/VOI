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

const int NM = 2e5 + 10;
int n, m, A, B, T, d;
int a[NM], f[NM];
vector<int> edges[NM];
bool visited[NM];

struct Data {
    int u, cost;

    bool inline operator < (const Data &A) const {
        return cost > A.cost;
    }
};

void bfs() {
    queue<int> q;
    f[1] = 0;
    q.push(1);

    while(q.size()) {
        int u = q.front();
        q.pop();

        if(u == n) break;

        for(int v : edges[u]) {
            if(a[1] + f[u] * A > a[v] + (f[u] + 1) * B) {
                if(minimize(f[v], f[u] + 1)) q.push(v);
            }
        }
    }

    if(f[n] < INF) cout << f[n] << '\n';
    else cout << -1 << '\n';
}
void solve() {
    priority_queue<Data> pq;
    visited[1] = true;

    for(int v : edges[1]) pq.push({v, a[v]});

    int res = 0, cnt = 0, curStrength = a[1];
    while(pq.size()) {
        queue<pii> q;
        while(pq.size() && pq.top().cost + B < curStrength) {
            int u = pq.top().u, cost = pq.top().cost;
            pq.pop();

            if(visited[u]) continue;

            if(u == n) {
                cout << res + 1 << '\n';
                return;
            }

            cnt++;
            visited[u] = true;
            q.push({u, cost});
        }

        if(!cnt) {
            cout << -1 << '\n';
            return;
        } else {
            curStrength += d;
            cnt--;
            res++;
        }

        while(q.size()) {
            int u = q.front().fi;
            q.pop();
            for(int v : edges[u]) if(!visited[v])
                pq.push({v, a[v]});
        }
    }

    cout << -1 << '\n';
}
void init() {
    for(int i = 1; i <= n; i++) {
        edges[i].clear();
        f[i] = INF;
        visited[i] = false;
    }
}
int32_t main()
{
    FastIO
    freopen("BOSS.INP", "r", stdin);
    freopen("BOSS.OUT", "w", stdout);
    cin >> T;
    while(T--) {
        cin >> n >> m >> A >> B;
        init();
        for(int i = 1; i <= m; i++) {
            int u, v;
            cin >> u >> v;
            edges[u].push_back(v);
            edges[v].push_back(u);
        }
        for(int i = 1; i <= n; i++) cin >> a[i];

        d = A - B;

        if(d < 0) bfs();
        else solve();
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
