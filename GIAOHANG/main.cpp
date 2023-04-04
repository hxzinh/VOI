#include <bits/stdc++.h>
#define int long long
#define INF 1e18
#define FastIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;
const int NM = 1e6 + 10;
int numRoad, numHouse, numStore, k;
int dist[550][550], cost[550][550], root[550][550], trace[550][550];
int store[NM];

struct Data {
    int v, cost;
};
vector<Data> edges[NM];

bool minimize(int &a, int b){
    if(a > b){a = b; return true;}
    else return false;
}
void readfile(){
    freopen("GIAOHANG.INP", "r", stdin);
    freopen("GIAOHANG.OUT", "w", stdout);
    cin >> numHouse >> numRoad >> k;

    for(int i = 1; i <= numHouse; i++)
        for(int j = 1; j <= numHouse; j++) cost[i][j] = dist[i][j] = INF;

    for(int i = 1; i <= numRoad; i++){
        int u, v, w;
        cin >> u >> v >> w;
        minimize(cost[u][v], w);
        minimize(cost[v][u], w);
        ///edges[u].push_back({v, w});
    }
}
void prepare(){
    for(int i = 0; i <= numHouse; i++)
        for(int j = 0; j <= numHouse; j++) if(cost[i][j] < INF) dist[i][j] = cost[i][j];

    for(int i = 0; i <= numHouse; i++) dist[i][i] = 0;

    for(int t = 1; t <= numHouse; t++)
        for(int i = 1; i <= numHouse; i++)
            for(int j = 1; j <= numHouse; j++) minimize(dist[i][j], dist[i][t] + dist[t][j]);

    for(int i = 1; i <= numHouse; i++)
        for(int j = 1; j <= numHouse; j++) if(i != j) {
            trace[i][j] = -1;
            for(int v = 1; v <= numHouse; v++){
                if(v != j && dist[i][v] + cost[v][j] == dist[i][j])
                    if(trace[i][j] < 0 || cost[trace[i][j]][j] > cost[v][j]) trace[i][j] = v;
            }
        }
}
void getResult(){
    int res = 0;
    for(int i = 1; i <= numHouse; i++){
        int ans = INF;
        for(int j = 1; j <= numStore; j++) minimize(ans, dist[store[j]][i]);
        if(ans == 0) continue;

        int minCost = INF;
        for(int j = 1; j <= numStore; j++) if(ans == dist[store[j]][i]) {
            int par = trace[store[j]][i];
            assert(par > 0);
            minimize(minCost, cost[par][i]);
        }
        res += minCost;
    }
    cout << res << '\n';
}
void xuli(){
    for(int i = 1; i <= k; i++){
        cin >> numStore;
        for(int j = 1; j <= numStore; j++) cin >> store[j];
        getResult();
    }
}
int32_t main()
{
    FastIO
    readfile();
    prepare();
    xuli();
    return 0;
}
