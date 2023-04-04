#include <bits/stdc++.h>
#define ll long long
#define INF 0x3f3f3f3f3f3f3f3f
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

template<class X, class Y>
	inline bool maximize(X &x, const Y &y) {return (x < y ? x = y, 1 : 0);}
template<class X, class Y>
	inline bool minimize(X &x, const Y &y) {return (x > y ? x = y, 1 : 0);}

const int NM = 4e5 + 10;
int n, m, d;
ll dp[NM];
vector<int> edges[NM];

struct Road {
    int u, v, w;
} e[NM];

struct Data {
    int u, node;
    ll cost;

    bool inline operator < (const Data &A) const {
        return cost > A.cost;
    }
};

void xuli() {
    memset(dp, INF, sizeof dp);
    priority_queue<Data> pq;
    for(int i : edges[1]) {
        int v = 1 ^ e[i].u ^ e[i].v;
        if(minimize(dp[i], e[i].w));
            pq.push({i, v, dp[i]});
    }

    while(pq.size()) {
        Data u = pq.top();
        pq.pop();

        //cout << u.node << " " << u.cost << '\n';

        if(dp[u.u] != u.cost) continue;

        if(u.node == n) break;

        ll preLen = e[u.u].w;
        for(int i : edges[u.node]) if(i != u.u) {
            int v = u.node ^ e[i].u ^ e[i].v;
            if(preLen + d > e[i].w) continue;
            if(minimize(dp[i], dp[u.u] + e[i].w)) {
                pq.push({i, v, dp[i]});
            }
        }
    }

    ll res = INF;
    for(int i : edges[n]) {
        minimize(res, dp[i]);
        if(i & 1) minimize(res, dp[i + 1]);
        else minimize(res, dp[i - 1]);
    }

    if(res < INF) cout << res;
    else cout << -1;
}
int32_t main()
{
    FastIO
    freopen("DANANG.INP", "r", stdin);
    freopen("DANANG.OUT", "w", stdout);
    cin >> n >> m >> d;
    for(int i = 1; i <= 2 * m; i += 2) {
        ll u, v, w;
        cin >> u >> v >> w;
        edges[u].push_back(i);
        edges[v].push_back(i + 1);
        e[i] = {u, v, w};
        e[i + 1] = {u, v, w};
    }

    xuli();
    return 0;
}
