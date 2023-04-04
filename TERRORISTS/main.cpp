#include <bits/stdc++.h>
#define ll long long
#define INF 1e9
#define ALL(v) (v).begin(), (v).end()
#define ii pair<int, int>
#define fi first
#define se second
#define FastIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

template<class X, class Y>
	inline bool maximize(X &x, const Y &y) {return (x < y ? x = y, 1 : 0);}
template<class X, class Y>
	inline bool minimize(X &x, const Y &y) {return (x > y ? x = y, 1 : 0);}

const int NM = 1e5 + 55;
int n, m, q, T;
int cnt = 0;
int deep[NM], s[NM], fa[NM], num[NM];
int dist[60][NM];
ii a[NM];
bool visited[NM], visEdges[NM];

struct Road {
    int v, cost, id;
};
vector<Road> edges[NM];

struct Data {
    int u, cost;

    bool inline operator < (const Data &A) const {
        return cost > A.cost;
    }
};

void readfile(){
    freopen("TERRORISTS.INP", "r", stdin);
    freopen("TERRORISTS.OUT", "w", stdout);
    cin >> T;
}
void dfs(int u, int par){
    visited[u] = true;
    for(Road x : edges[u]){
        int v = x.v, cost = x.cost, id = x.id;
        if(visited[v] || v == par) continue;
        fa[v] = u;
        deep[v] = deep[u] + 1;
        s[v] = s[u] + cost;
        visEdges[id] = true;
        dfs(v, u);
    }
    return;
}
int LCA(int u, int v){
    if(deep[u] < deep[v]) swap(u, v);
    while(deep[u] > deep[v]) u = fa[u];
    while(u != v){
        u = fa[u];
        v = fa[v];
    }
    return u;
}
void dijtra(int st){
    if(num[st] > 0) return;
    num[st] = ++cnt;
    int x = cnt;

    priority_queue<Data> pq;
    dist[x][st] = 0;
    pq.push({st, 0});
    while(!pq.empty()){
        int u = pq.top().u, cost = pq.top().cost;
        pq.pop();
        if(cost > dist[x][u]) continue;
        for(Road v : edges[u]){
            if(minimize(dist[x][v.v], dist[x][u] + v.cost))
                pq.push({v.v, dist[x][v.v]});
        }
    }
    return;
}
bool cmp(const Road &A, const Road &B){
    return A.cost < B.cost;
}
void solve(){
    for(int i = 1; i <= n; i++) sort(ALL(edges[i]), cmp);
    dfs(1, 0);

    for(int i = 1; i <= m; i++) if(!visEdges[i]) dijtra(a[i].fi);

    while(q--){
        int u, v;
        cin >> u >> v;

        int res = s[u] + s[v] - 2 * s[LCA(u, v)];
        for(int i = 1; i <= cnt; i++) minimize(res, dist[i][u] + dist[i][v]);
        cout << res << '\n';
    }
}
void refresh(){
    for(int i = 1; i <= n; i++){
        edges[i].clear();
        deep[i] = fa[i] = s[i] = num[i] = 0;
        visited[i] = false;
    }

    for(int i = 1; i <= 50; i++)
        for(int j = 1; j <= n; j++) dist[i][j] = INF;
    for(int i = 1; i <= m; i++) visEdges[i] = false;
}
void xuli(){
    while(T--){
        cin >> n >> m >> q;
        refresh();
        for(int i = 1; i <= m; i++){
            int u, v, w;
            cin >> u >> v >> w;
            edges[u].push_back({v, w, i});
            edges[v].push_back({u, w, i});
            a[i] = make_pair(u, v);
        }
        solve();
    }
}
int32_t main()
{
    FastIO
    readfile();
    xuli();
    return 0;
}
