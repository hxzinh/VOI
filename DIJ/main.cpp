#include <bits/stdc++.h>
#define ll long long
#define INF 1e9
#define ii pair<int, int>
#define fi first
#define se second
#define ALL(v) (v).begin(), (v).end()
#define FastIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

template<class X, class Y>
	inline bool maximize(X &x, const Y &y) {return (x < y ? x = y, 1 : 0);}
template<class X, class Y>
	inline bool minimize(X &x, const Y &y) {return (x > y ? x = y, 1 : 0);}

const int NM = 1e4 + 10;
int n, m, k;
int t[NM], dist[505][505], g[505][505];
bool cx[NM];

struct Data {
    int v, cost;

    bool inline operator < (const Data &A) const {
        return cost > A.cost;
    }
};
vector<Data> edges[NM], road[NM];

struct Road {
    int u, v, cost;
    bool inline operator < (const Road &A) const {
        return cost > A.cost;
    }
};
Road a[NM];

void readfile(){
    freopen("DIJ.INP", "r", stdin);
    freopen("DIJ.OUT", "w", stdout);
    cin >> n >> m >> k;
    for(int i = 1; i <= m; i++){
        int u, v, w;
        cin >> u >> v >> w;
        edges[u].push_back({v, w});
        a[i].u = u; a[i].v = v; a[i].cost = w;
        dist[u][v] = w;
    }
    memset(cx, true, sizeof(cx));
    memset(t, -1, sizeof(t));
}
int root(int x){
    if(t[x] == -1) return x;
    else return t[x] = root(t[x]);
}
void getDist(int x){
    priority_queue<Data> pq;
    g[x][x] = 0;
    pq.push({x, 0});
    while(!pq.empty()){
        int u = pq.top().v, cost = pq.top().cost;
        pq.pop();
        if(g[x][u] != cost) continue;
        for(auto v : edges[u]){
            if(minimize(g[x][v.v], g[x][u] + dist[u][v.v])){
                g[x][v.v] = g[x][u] + dist[u][v.v];
                pq.push({v.v, g[x][v.v]});
            }
        }
    }
}
void sub1(){
    int newRoad;
    cin >> newRoad;
    for(int i = m + 1; i <= m + newRoad; i++){
        int u, v, w;
        cin >> u >> v >> w;
        dist[u][v] = w;
        edges[u].push_back({v, w});
    }

    n += 3;
    m += newRoad;
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= n; j++) if(!dist[i][j] && i != j) dist[i][j] = g[i][j] = INF;
    int res = 0;
    for(int k = 1; k <= n; k++){
        for(int i = 1; i <= n; i++) if(dist[i][k] != INF) {
            for(int j = 1; j <= n; j++) if(dist[k][j] != INF) {
                minimize(dist[i][j], dist[i][k] + dist[k][j]);
            }
        }
    }

    ///for(int i = 1; i <= n; i++) getDist(i);
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= n; j++) if(i != j && dist[i][j] != INF) res += dist[i][j];
    cout << res;
}
int main()
{
    FastIO
    readfile();
    sub1();
    return 0;
}
