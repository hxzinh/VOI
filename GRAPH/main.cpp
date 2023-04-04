#include <bits/stdc++.h>
#define int long long
#define INF 1e18
#define FastIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

template<class X, class Y>
	inline bool maximize(X &x, const Y &y) {return (x < y ? x = y, 1 : 0);}
template<class X, class Y>
	inline bool minimize(X &x, const Y &y) {return (x > y ? x = y, 1 : 0);}

const int NM = 2e5 + 10;
int T, sub;
int n, m;
int L[NM], D[NM];
int ans = INF;

struct Data{
    int v, cost;
};
vector<Data> edges[NM];

struct Edges {
    int u, v, cost;
};
Edges a[NM];

struct Graph {
    int u, cost;

    bool inline operator < (const Graph &A) const {
        return cost > A.cost;
    }
};

void refresh(){
    for(int i = 1; i <= n; i++) edges[i].clear();
}
void dijtra(int x, int g[]){
    for(int i = 1; i <= n; i++) g[i] = INF;
    priority_queue<Graph> pq;
    pq.push({x, 0});
    g[x] = 0;

    while(!pq.empty()){
        int u = pq.top().u, cost = pq.top().cost;
        pq.pop();
        if(g[u] != cost) continue;

        for(auto t : edges[u]) if(t.v != u){
            if(minimize(g[t.v], g[u] + t.cost))
                pq.push({t.v, g[t.v]});
        }
    }
}
int32_t main()
{
    FastIO
    freopen("GRAPH.INP", "r", stdin);
    freopen("GRAPH.OUT", "w", stdout);
    cin >> sub >> T;
    while(T--){
        cin >> n >> m;
        refresh();
        bool s1 = true;
        for(int i = 1; i <= n; i++){
            int u, v, w;
            cin >> u >> v >> w;
            a[i].u = u, a[i].v = v, a[i].cost = w;
            edges[u].push_back({v, w});
            edges[v].push_back({u, w});
            if(w != 1) s1 = false;
        }
        dijtra(1, L);
        dijtra(n, D);

        int res = INF;
        for(int i = 1; i <= m; i++){
            minimize(res, (L[a[i].u] + D[a[i].v] + a[i].cost) * a[i].cost);
            minimize(res, (L[a[i].v] + D[a[i].u] + a[i].cost) * a[i].cost);
        }
        cout << res << " ";
    }
    return 0;
}
