#include <bits/stdc++.h>
#define ll long long
#define oo 99999999999
#define FastIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;
const int NM = 5e5 + 10;
int n, m, p;
int compID[NM], cnt = 0;
vector<int> par[NM];
bool cx[NM];

struct Data{
    int v, cost;
};
vector<Data> adj[NM], arc[NM];


void readfile(){
    freopen("SHORTESTPATH.INP", "r", stdin);
    freopen("SHORTESTPATH.OUT", "w", stdout);
    cin >> n >> m >> p;
    for(int i = 1; i <= m; i++){
        int u, v, w; cin >> u >> v >> w;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }
    for(int i = 1; i <= p; i++){
        int u, v, w; cin >> u >> v >> w;
        arc[u].push_back({v, w});
        par[v].push_back(u);
    }
}
void dfs(int x){

}
void xuli(){

}
int main()
{
    FastIO
    cout << "Hello world!" << endl;
    return 0;
}
