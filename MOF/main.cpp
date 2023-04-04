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

const int NM = 505;
const int maxTime = 10000;
int n, m, s, t;
int f[NM][maxTime + 10];

struct Data {
    int u, Time, cost;

    bool inline operator < (const Data &A) const {
        return cost > A.cost;
    }
};
vector<Data> edges[NM];

void xuli() {
    priority_queue<Data> pq;
    memset(f, INF, sizeof f);
    f[s][0] = 0;

    pq.push({s, 0, 0});
    while(pq.size()) {
        int u = pq.top().u, Time = pq.top().Time, cost = pq.top().cost;
        pq.pop();

        //cout << u << " " << Time << " " << cost << '\n';
        if(u == t || cost != f[u][Time]) continue;

        for(auto nxt : edges[u]) {
            int v = nxt.u, newTime = Time + nxt.Time, newCost = cost + nxt.cost;
            if(newTime > maxTime) continue;
            if(minimize(f[v][newTime], newCost)) pq.push({v, newTime, newCost});
        }
    }

    //for(int i = 0; i <= maxTime; i++) cout << i << " " << f[t][i] << '\n';

    int res = 0, maxCost = INF;
    for(int i = 0; i <= maxTime; i++) {
        if(minimize(maxCost, f[t][i])) res++;
    }
    cout << res;
}
int32_t main()
{
    FastIO
    freopen("MOF.INP", "r", stdin);
    freopen("MOF.OUT", "w", stdout);
    cin >> n >> m >> s >> t;
    for(int i = 1; i <= m; i++) {
        int u, v, cost, Time;
        cin >> u >> v >> cost >> Time;
        edges[u].push_back({v, cost, Time});
        edges[v].push_back({u, cost, Time});
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
