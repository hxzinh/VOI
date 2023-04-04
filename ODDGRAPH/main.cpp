#include <bits/stdc++.h>
#define ll long long
#define INF 1e9
#define pii pair<int, int>
#define fi first
#define se second
#define FastIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

template<class X, class Y>
	inline bool maximize(X &x, const Y &y) {return (x < y ? x = y, 1 : 0);}
template<class X, class Y>
	inline bool minimize(X &x, const Y &y) {return (x > y ? x = y, 1 : 0);}

const int NM = 1e5 + 10;
const int MAX = 1e6 + 10;
int n, m;
int numEdges[NM], ans[NM], par[NM], h[NM];
bool cx[NM], visited[NM];

struct Data {
    int v, id;
};
vector<pii> edges[NM];

struct Graph {
    int u, v, id;
    bool inline operator < (const Graph &A) const {
        return u > A.u;
    }
};
Graph a[MAX];

int root(int x){
    if(par[x] == -1) return x;
    return par[x] = root(par[x]);
}
bool join(int u, int v){
    u = root(u), v = root(v);
    if(u == v) return false;
    if(h[u] == h[v]) h[u]++;
    if(h[u] < h[v]) par[u] = v;
    else par[v] = u;
    return true;
}
void dfs(int x, int p, int id){
    visited[x] = true;
    for(pii v : edges[x]) if(v.fi != p) {
        dfs(v.fi, x, v.se);
    }
    if(numEdges[x] % 2 == 0 && x != p){
        numEdges[x]--;
        numEdges[p]--;
        ans[id] = 0;
    }
}
void xuli(){
    int d = 0;
    sort(a + 1, a + n + 1);

    for(int i = 1; i <= n; i++){
        par[i] = -1;
        h[i] = 0;
    }

    for(int i = 1; i <= m; i++){
        if(d == n - 1) break;
        int u = a[i].u, v = a[i].v, id = a[i].id;
        if(join(u, v)){
            ans[id] = 1;
            d++;
            numEdges[u]++; numEdges[v]++;
            edges[u].push_back({v, id});
            edges[v].push_back({u, id});
        }
    }

    for(int i = 1; i <= n; i++) if(!visited[i]) dfs(i, i, 0);

    for(int i = 1; i <= n; i++){
        if(numEdges[i] % 2 == 0){
            cout << -1;
            return;
        }
    }
    for(int i = 1; i <= m; i++) cout << ans[i];
}
int main()
{
    FastIO
    freopen("ODDGRAPH.INP", "r", stdin);
    freopen("ODDGRAPH.OUT", "w", stdout);
    cin >> n >> m;
    for(int i = 1; i <= m; i++){
        cin >> a[i].u >> a[i].v;
        a[i].id = i;
    }

    xuli();
    return 0;
}
