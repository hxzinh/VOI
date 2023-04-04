#include <bits/stdc++.h>
#define int long long
#define INF 0x3f3f3f3f3f3f3f
#define FastIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

template<class X, class Y>
	inline bool maximize(X &x, const Y &y) {return (x < y ? x = y, 1 : 0);}
template<class X, class Y>
	inline bool minimize(X &x, const Y &y) {return (x > y ? x = y, 1 : 0);}

const int NM = 1e5 + 10;
int n, m;
int dist[5005][5005];
bool cx[NM];

struct Data {
    int v, cost, id;
};
vector<Data> edges[NM];

struct Road {
    int u, cost;

    bool inline operator < (const Road &A) const {
        return cost < A.cost;
    }
};

void dijtra(int start, int dist[]){
    dist[start] = 0;
    memset(cx, true, sizeof cx);
    priority_queue<Road> pq;
    pq.push({start, 0});

    while(pq.size()){
        int u = pq.top().u, cost = pq.top().cost;
        pq.pop();
        if(cost != dist[u]) continue;
        for(auto v : edges[u]) if(cx[v.id]) {
            if(maximize(dist[v.v], cost + v.cost)){
                pq.push({v.v, dist[v.v]});
                cx[v.id] = false;
            }
        }
    }
}
void xuli(){
    memset(cx, true, sizeof cx);
    memset(dist, -INF, sizeof dist);
    for(int i = 1; i <= n; i++) dijtra(i, dist[i]);

    int res = 0;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++) if(i != j){
            for(int k = 1; k <= n; k++) if(i != k && j != k){
                maximize(res, dist[i][k] + dist[k][j] + dist[j][i]);
            }
        }
    }
    cout << res;
}
int32_t main()
{
    FastIO
    freopen("BGAME.INP", "r", stdin);
    freopen("BGAME.OUT", "w", stdout);
    cin >> n >> m;
    for(int i = 1; i <= m; i++){
        int u, v, w;
        cin >> u >> v >> w;
        edges[u].push_back({v, w, i});
        edges[v].push_back({u, w, i});
    }

    xuli();
    return 0;
}
