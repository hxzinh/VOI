 #include <bits/stdc++.h>
#define ll long long
#define INF 0x3f3f3f3f
#define pii pair<int, int>
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

const int NM = 1e3 + 10;
int n, m, s, t;
vector<int> cur, d;
vector<vector<int>> a;

struct Edge {
    int u, v, cost, flow;
};
vector<Edge> edges;

void init(){
    a = vector<vector<int>>(n + 7);
    cur = vector<int>(n + 7);
    d = vector<int>(n + 7);
}
int bfs(){
    queue<int> q;
    for(int i = 1; i <= n; i++) d[i] = -1;
    q.push(s);
    d[s] = 0;

    while(q.size() && d[t] < 0){
        int u = q.front();
        q.pop();
        for(int i = 0; i < a[u].size(); i++){
            int id = a[u][i], v = edges[id].v;
            if(d[v] < 0 && edges[id].flow < edges[id].cost){
                q.push(v);
                d[v] = d[u] + 1;
            }
        }
    }

    return (d[t] >= 0);
}
int dfs(int u, int val){
    if(!val) return 0;
    if(u == t) return val;
    for(; cur[u] < a[u].size(); cur[u]++){
        int id = a[u][cur[u]], v = edges[id].v;
        if(d[v] != d[u] + 1) continue;
        int check = dfs(v, min(val, edges[id].cost - edges[id].flow));
        if(check){
            edges[id].flow += check;
            edges[id ^ 1].flow -= check;
            return check;
        }
    }
    return 0;
}
void xuli(){
    int res = 0;
    while(bfs()){
        for(int i = 1; i <= n; i++) cur[i] = 0;
        while(true){
            int val = dfs(s, INF);
            if(!val) break;
            else res += val;
        }
    }
    cout << res;
}
int32_t main()
{
    FastIO
    freopen("NKFLOW.INP", "r", stdin);
    freopen("NKFLOW.OUT", "w", stdout);
    cin >> n >> m >> s >> t;

    init();

    for(int i = 1; i <= m; i++){
        int u, v, w;
        cin >> u >> v >> w;
        Edge e1 = {u, v, w, 0};
        Edge e2 = {v, u, 0, 0};
        a[u].push_back(edges.size()); edges.push_back(e1);
        a[v].push_back(edges.size()); edges.push_back(e2);
    }

    xuli();
    return 0;
}

/* Author: hxzinh */
