#include <bits/stdc++.h>
#define ll long long
#define INF 1e9
#define FastIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

template<class X, class Y>
	inline bool maximize(X &x, const Y &y) {return (x < y ? x = y, 1 : 0);}
template<class X, class Y>
	inline bool minimize(X &x, const Y &y) {return (x > y ? x = y, 1 : 0);}

const int NM = 1e5 + 10;
int n, q;
int numChild[NM], cost[NM], numRoad[NM];

struct Data {
    int v, cost;
};
vector<Data> edges[NM];

void readfile(){
    freopen("COSTQUERY.INP", "r", stdin);
    freopen("COSTQUERY.OUT", "w", stdout);
    cin >> n >> q;
    for(int i = 1; i < n; i++){
        int u, v, w;
        cin >> u >> v >> w;
        edges[u].push_back({v, w});
        edges[v].push_back({u, w});
    }
}
void dfs(int x, int par, int pay){
    cost[x] = max(pay , cost[par]);
    for(auto u : edges[x]) if(u.v != par) {
        dfs(u.v, x, u.cost);
        numChild[x] += numChild[u.v] + 1;
        numRoad[x] += numRoad[u.v] + numChild[u.v] + 1;
    }
    return;
}
void xuli(){
    dfs(1, 0, 0);
    for(int i = 1; i <= n; i++) cout << numChild[i] << " " << numRoad[i] << " " << cost[i] << '\n';
}
int main()
{
    FastIO
    readfile();
    xuli();
    return 0;
}
