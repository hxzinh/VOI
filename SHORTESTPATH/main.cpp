#include <bits/stdc++.h>
#define ll long long
#define INF 1e18
#define FastIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;
const int NM = 5e5 + 10;
int n, m, p, numComp = 0;
int compID[NM];
ll s[NM];
vector<int> par[NM], comp[NM];
bool cx[NM];

struct Data{
    int v;
    ll cost;
};
vector<Data> edges[NM], to[NM];

struct Nekoo{
    int u;
    ll cost;

    bool inline operator < (const Nekoo &A) const {
        return cost > A.cost;
    }
};
priority_queue<Nekoo> pq;

struct Dijointset{
    vector<int> lab;

    Dijointset(int _n = 0){
        lab.assign(_n + 7, -1);
    }

    int root(int x){
        if(lab[x] < 0) return x;
        else return lab[x] = root(lab[x]);
    }

    bool join(int u, int v){
        int x = root(u), y = root(v);
        if(x == y) return false;
        if(lab[x] > lab[y]) swap(x, y);
        lab[x] += lab[y];
        lab[y] = x;
        return true;
    }
};

void readfile(){
    freopen("SHORTESTPATH.INP", "r", stdin);
    freopen("SHORTESTPATH.OUT", "w", stdout);
    cin >> n >> m >> p;
    for(int i = 1; i <= m; i++){
        int u, v;
        ll w; cin >> u >> v >> w;
        edges[u].push_back({v, w});
        edges[v].push_back({u, w});
    }
    for(int i = 1; i <= p; i++){
        int u, v;
        ll w; cin >> u >> v >> w;
        to[u].push_back({v, w});
        par[v].push_back(u);
    }
}
void progress(){
    Dijointset dsu(n);
    for(int i = 1; i <= n; i++){
        for(auto u : edges[i]) dsu.join(i, u.v);
    }
    for(int i = 1; i <= n; i++){
        if(dsu.root(i) == i){
            compID[i] = ++numComp;
            comp[numComp].push_back(i);
        }
    }
    for(int i = 1; i <= n; i++){
        int j = dsu.root(i);
        if(i != j) compID[i] =  compID[j];
        comp[compID[j]].push_back(i);
    }
    for(int i = 1; i <= n; i++) s[i] = INF;
    s[1] = 0;
}
void dijtra(int x){
    if(cx[x]) return;
    cx[x] = true;
    for(auto u : comp[x])
        for(auto v : par[u]) dijtra(compID[v]);
    for(auto u : comp[x]){
        if(s[u] < INF) pq.push({u, s[u]});
    }
    while(!pq.empty()){
        int u = pq.top().u;
        ll cost = pq.top().cost;
        pq.pop();
        if(s[u] != cost) continue;
        for(auto v : edges[u]){
            if(s[v.v] > s[u] + v.cost){
                s[v.v] = s[u] + v.cost;
                pq.push({v.v, s[v.v]});
            }
        }
    }
    for(auto i : comp[x])
        for(auto j : to[i])
            if(s[j.v] > s[i] + j.cost) s[j.v] = s[i] + j.cost;
}
void xuli(){
    progress();
    for(int i = 1; i <= n; i++) dijtra(i);
    for(int i = 1; i <= n; i++)
        if(s[i] < INF / 2) cout << s[i] << " ";
        else cout << -1 << " ";
}
int32_t main()
{
    FastIO
    readfile();
    xuli();
    return 0;
}
