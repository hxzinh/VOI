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

const int NM = 5e3 + 10;
int n, m, x, y;
int dist[NM], range[NM];
int f[NM][NM], s[NM];
vector<int> edges[NM], bridge[NM];
vector<ii> h[NM], k[NM];
int cx[NM], ok[NM];

void readfile(){
    freopen("INP", "r", stdin);
    freopen("OUT", "w", stdout);
    cin >> n >> m >> x >> y;
    for(int i = 1; i <= m; i++){
        int u, v; cin >> u >> v;
        edges[u].push_back(v);
        bridge[v].push_back(u);
    }
}
void prepare(){
    for(int i = 1; i <= n; i++){
        s[i] = dist[i];
        for(int j = 1; j <= n; j++) f[i][j] = dist[i] + range[j];
    }
}
void dfs(int x){
    if(edges[x].empty()){
        cx[x] = 0;
        return;
    }
    for(int v : edges[x]){
        dfs(v);
        maximize(dist[x], dist[v] + 1);
        h[x].push_back({dist[v] + 1, v});
        if(cx[v] != 0) cx[x]--;
        else cx[x]++;
    }
}
void dfs_back(int x){
    for(int v : bridge[x]){
        dfs_back(v);
        maximize(range[x], range[v] + 1);
        k[x].push_back({dist[v] + 1, v});
    }
}
bool tmp(const ii &A, const ii &B){
    return A.fi > B.fi;
}
int getDist(int x){
    if(dist[x] == 1) return s[x] = 0;
    if(dist[x] % 2 != 0){
        for(int v : edges[x]) minimize(s[x], getDist(v) + 1);
    } else {
        for(int v : edges[x]) maximize(s[x], getDist(v) + 1);
    }
    return s[x];
}
void sub1(){
    dfs(x);
    prepare();
    cout << getDist(x);
}
int getCost(int x, int y){
    if(dist[x] == 1 && range[y] == 1) return f[x][y] = 0;
    if(dist[x] + range[y] % 2 != 0){
        for(int v : edges[x]) minimize(f[x][y], getCost(v, y) + 1);
        for(int v : bridge[y]) minimize(f[x][y], getCost(x, v) + 1);
    } else {
        for(int v : edges[x]) maximize(f[x][y], getCost(v, y) + 1);
        for(int v : bridge[y]) maximize(f[x][y], getCost(x, v) + 1);
    }
    return f[x][y];
}
void sub2(){
    ///chan thi win, le thi lose <=> true / false
    dfs(x);
    dfs_back(y);
    prepare();
    cout << getCost(x, y);
}
int main()
{
    FastIO
    readfile();
    sub2();
    return 0;
}
