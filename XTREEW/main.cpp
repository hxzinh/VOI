#include <bits/stdc++.h>
#define int long long
#define INF 1e9
#define ii pair<int, int>
#define fi first
#define se second
#define FastIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

template<class X, class Y>
	inline bool maximize(X &x, const Y &y) {return (x < y ? x = y, 1 : 0);}
template<class X, class Y>
	inline bool minimize(X &x, const Y &y) {return (x > y ? x = y, 1 : 0);}

const int NM = 5e3 + 10;
int n;

struct Data {
    int u, cost;
};
vector<Data> edges[NM];
///--------------------------------sub3-------------------------------------
ii a[NM][NM];
///--------------------------------sub2-------------------------------------
int f[NM][NM], cx[NM];

void readfile(){
    freopen("INP", "r", stdin);
    freopen("OUT", "w", stdout);
    cin >> n;
    for(int i = 1; i < n; i++){
        int u, v, w; cin >> u >> v >> w;
        edges[u].push_back({v, w});
        edges[v].push_back({u, w});
    }

    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= n; j++) if(i != j) a[i][j].fi = INF;
    for(int i = 1; i <= n; i++)
        for(int j = 0; j < edges[i].size(); j++){
            int u = edges[i][j].u;
            a[i][u].fi = a[i][u].se = edges[i][j].cost;
            a[u][i].fi = a[u][i].se = edges[i][j].cost;
        }
}
void sub3(){
    for(int k = 1; k <= n; k++)
        for(int i = 1; i <= n; i++)
            for(int j = 1; j <= n; j++) if(i != j){
                if(a[i][j].fi > a[i][k].fi + a[j][k].fi){
                    a[i][j].fi = a[i][k].fi + a[j][k].fi;
                    a[i][j].se = a[i][k].se ^ a[j][k].se;
                }
            }

    int res = 0;
    for(int i = 1; i <= n; i++)
        for(int j = i + 1; j <= n; j++) res += a[i][j].se;
    cout << res;
}
void dfs(int x, int par){
    cx[x] = true;
    for(auto v : edges[x]) if(!cx[v.u]) {
        f[par][v.u] = f[par][x] ^ v.cost;
        f[v.u][par] = f[par][x] ^ v.cost;
        dfs(v.u, par);
    }
}
void sub1(){
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= n; j++) f[i][j] = a[i][j].fi;
    for(int i = 1; i <= n; i++){
        dfs(i, i);
        memset(cx, false, sizeof(cx));
    }
    int res = 0;
    for(int i = 1; i <= n; i++)
        for(int j = i + 1; j <= n; j++) res += f[i][j];
    cout << res;
}
int32_t main()
{
    FastIO
    readfile();
    if(n <= 200) sub3();
    else if(n <= 5000) sub1();
    else cout << 0;
    return 0;
}
