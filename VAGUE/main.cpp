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

const int NM = 3e5 + 10;
int n, m, T, k;
int high[NM], par[NM], mark[NM], dist[1000005];
pii q[1000005];
vector<int> edges[NM];


void dfs(int u, int fa){
    for(int v : edges[u]) if(v != fa){
        dfs(v, u);
        par[v] = u;
        high[v] = high[u] + 1;
    }
}
int LCA(int u, int v){
    if(high[u] < high[v]) swap(u, v);

    int h = 0;
    while(high[u] > high[v]){u = par[u]; h++;}
    while(u != v){
        u = par[u];
        v = par[v];
        h++;
    }
    return u;
}
int getDist(int u, int v){
    return high[u] + high[v] - high[LCA(u, v)];
}
bool query(){
    for(int i = 1; i <= n; i++) mark[i] = 0;
    for(int i = 1; i <= k; i++) dist[i] = LCA(q[i].fi, q[i].se);
    sort(dist + 1, dist + k + 1);

    for(int i = 1; i <= k; i++){

    }
}
void check(int x, int y, int u, int v){
    int a = LCA(x, y), b = LCA(u, v);
    if(a != b && par[a] != b && par[b] != a) return true;
    if(LCA())
}
void sub3(){
    for(int i = 1; i <= q; i++){
        for(int j = i + 1; j <= n; j++)
    }
}
void xuli(){

}
int main()
{
    FastIO
    freopen("VAGUE.INP", "r", stdin);
    freopen("VAGUE.OUT", "w", stdout);
    cin >> T;
    cin >> n;
    for(int i = 1; i < n; i++){
        int u, v;
        cin >> u > v;
        edges[u].push_back(v);
        edges[v].push_back(u);
    }
    cin >> m;
    while(m--)[
        cin >> k;
        for(int i = 1; i <= k; i++) cin >> q[i].fi >> q[i].se;
        query();
    ]
    return 0;
}
