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

const int NM = 1e4 + 10;
int n, m, T;
string s;
ll f[55][MASK(13)], c[55][55];

struct Edge {
    int u, cost;

    bool inline operator < (const Edge &A) const {
        return cost > A.cost;
    }
};
vector<pii> edges[55];

struct Data {
    int u, cost, mask;

    bool inline operator < (const Data &A) const {
        return cost > A.cost;
    }
};

void sub1() {
    for(int k = 1; k <= n; k++)
        for(int i = 1; i <= n; i++)
            for(int j = 1; j <= n; j++) minimize(c[i][j], c[i][k] + c[k][j]);

    cout << (c[1][n] < INF ? c[1][n] : -1) << '\n';
}
void xuli() {
    priority_queue<Data> pq;
    memset(f, INF, sizeof f);
    f[1][0] = 0;
    pq.push({1, 0, 0});

    while(pq.size()) {
        ll u = pq.top().u, cost = pq.top().cost, mask = pq.top().mask;
        pq.pop();

        if(cost != f[u][mask] ) continue;

        for(pii v : edges[u]) {
            bool ok = true;
            int newMask = MASK(v.se % 13);;
            for(int i = 0; i < 13; i++) if(BIT(mask, i)) {
                newMask |= MASK((i + v.se) % 13);
                if((i + v.se) % 13 == 0) break;
            }
            if(!BIT(newMask, 0)) if(minimize(f[v.fi][newMask], cost + v.se))
                pq.push({v.fi, f[v.fi][newMask], newMask});
        }
    }

    ll res = INF;
    for(int i = 0; i < MASK(13); i++) minimize(res, f[n][i]);
    cout << (res < INF ? res : -1) << '\n';
}
void init() {
    for(int i = 1; i <= n; i++) edges[i].clear();
    memset(c, INF, sizeof c);
    for(int i = 1; i <= n; i++) c[i][i] = 0;
}
int32_t main()
{
    FastIO
    freopen("PATH13.INP", "r", stdin);
    freopen("PATH13.OUT", "w", stdout);
    cin >> T;
    while(T--) {
        cin >> n >> m;
        init();
        for(int i = 1; i <= m; i++) {
            int u, v, w;
            cin >> u >> v >> w;
            edges[u].push_back({v, w});
            minimize(c[u][v], w);
        }
        cin >> s;

        if(s == "False") sub1();
        else xuli();
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
