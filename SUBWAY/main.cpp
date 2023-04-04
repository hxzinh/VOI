#include <bits/stdc++.h>
#define int long long
#define INF 0x3f3f3f3f
#define FastIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

template<class X, class Y>
	inline bool maximize(X &x, const Y &y) {return (x < y ? x = y, 1 : 0);}
template<class X, class Y>
	inline bool minimize(X &x, const Y &y) {return (x > y ? x = y, 1 : 0);}

const int NM = 1e5 + 10;
int n, m, start, finish, delta;
long long f[NM];
map <int, long long> g[NM];

struct EDGE {
    int u, v;
    long long c;
} a[NM];
vector <int> edges[NM];

struct Data {
    int p;
    long long cost;

    bool inline operator < (const Data &A) const {
        return cost > A.cost;
    }
};

struct Subway {
    int u, id, cost;

    bool inline operator < (const Subway &A) const {
        return cost > A.cost;
    }
};

void Sub1() {
    priority_queue <Data> pq;
    for (int i = 1; i <= n; ++i) f[i] = INF;

    f[start] = 0;
    pq.push({start, 0});

    while (!pq.empty()) {
        int u = pq.top().p, cost = pq.top().cost;
        pq.pop();

        if (cost!= f[u]) continue;

        for (int id : edges[u]) {
            int v = a[id].v;
            if (u != start) {
                if (minimize(f[v], cost+ a[id].c + 1LL * id))
                pq.push({v, f[v]});
            } else if (minimize(f[v], cost+ a[id].c)) pq.push({v, f[v]});
        }
    }

    cout << f[finish];
}


void Sub2() {
    priority_queue<Subway> pq;
    a[0] = {0, start, 0};

    for (int i = 0; i <= m; ++i) g[edge[i].v][i] = INF;
    g[start][0] = 0;

    pq.push({start, 0, 0});
    while (!pq.empty()) {
        int u = pq.top().p, id = pq.top().id;
        long long dp = pq.top().cost;
        pq.pop();

        if (dp != g[u][id]) continue;

        for (int i : adj[u])
        {
            int v = edge[i].v;
            if (u != start)
            {
                if (minimize(g[v][i], dp + edge[i].c + 1LL * i + 1LL * delta * id))
                pq.push({v, i, g[v][i]});
            }
            else if (minimize(g[v][i], dp + edge[i].c + 1LL * delta * id)) pq.push({v, i, g[v][i]});
        }
    }

    long long ans = INF;
    for (int i = 1; i <= m; ++i) if (g[finish][i]) minimize(ans, g[finish][i]);
    cout << ans;
}

void xuli() {
    if(delta == 0) Sub1();
    else Sub2();
}

int32_t main()
{
    FastIO
    freopen("SUBWAY.INP", "r", stdin);
    freopen("SUBWAY.OUT", "w", stdout);
    cin >> n >> m >> start >> finish >> delta;
    for (int i = 1; i <= m; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        a[i] = {u, v, w};
        edges[u].push_back(i);
    }
    xuli();
    return 0;
}
