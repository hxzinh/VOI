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
priority_queue <Data> pq;

void Sub1() {
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

    if(f[finish] < INF) cout << f[finish];
    else cout << -1;
}

void Sub2(){
    cout << 31;
}

void xuli() {
    Sub1();
}

int32_t main()
{
    FastIO
    freopen("METRO.INP", "r", stdin);
    freopen("METRO.OUT", "w", stdout);
    cin >> n >> m >> start >> finish >> delta;
    for (int i = 1; i <= m; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        a[i] = {u, v, w};
        edges[u].push_back(i);
    }

    Sub1();
    return 0;
}
