#include <bits/stdc++.h>
#define ll long long
#define oo 99999999999
#define FastIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;
const int NM = 5e5 + 10;
int n,m;
int visited[NM], type[NM];
int dem = 0, edge = 0;
bool cx[NM], node[NM];

struct Data{
    int to, index;
};
vector<Data> child[NM];

void dfs(int u){
    if(child[u].empty() || visited[u] >= dem) return;
    cx[u] = true;  visited[u] = dem;
    for(auto v : child[u]){
        if(node[v.index] || cx[v.to]) continue;
        node[v.index] = true;
        type[v.index] = dem;
        edge++;
        dfs(v.to);
    }
    cx[u] = false;
}
void xuli(){
    while(edge < m){
        dem++;
        for(int i = 1; i <= n; i++) dfs(i);
    }
    cout << dem << '\n';
    for(int i = 1; i <= m; i++) cout << type[i] << " ";
}
int main()
{
    FastIO
    freopen("DAG.INP","r",stdin);
    freopen("DAG.OUT","w",stdout);
    cin >> n >> m;
    for(int i = 1; i <= m; i++){
        int u, v;
        cin >> u >> v;
        if(u == v){
            cout << -1;
            return 0;
        }
        child[u].push_back({v, i});
    }
    xuli();
    return 0;
}
