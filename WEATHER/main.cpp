#include <bits/stdc++.h>
#define int long long
#define INF 1e9
#define FastIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

template<class X, class Y>
	inline bool maximize(X &x, const Y &y) {return (x < y ? x = y, 1 : 0);}
template<class X, class Y>
	inline bool minimize(X &x, const Y &y) {return (x > y ? x = y, 1 : 0);}

const int NM = 105;
int n, m;
int Time = 0;
int num[NM], low[NM], f[NM], par[NM];
vector<int> edges[NM];
bool critEdges[NM][NM];

void readfile(){
    freopen("INP", "r", stdin);
    freopen("OUT", "w", stdout);
    cin >> n >> m;
    for(int i = 1; i <= m; i++){
        int u, v;
        cin >> u >> v;
        edges[u].push_back(v);
        edges[v].push_back(u);
    }
}
void dfs(int x){
    int numChild = 0;
    f[x] = 1;
    low[x] = num[x] = ++Time;
    for(int v : edges[x]) if(v != par[x]) {
        if(num[v]) minimize(low[x], num[v]);
        else {
            par[v] = x;
            dfs(v);
            numChild++;
            f[x] += f[v];
            minimize(low[x], low[v]);
            if(low[v] >= num[v]) critEdges[x][v] = critEdges[v][x] = true;
        }
    }
}
void xuli(){
    for(int i = 1; i <= n; i++) if(!num[i]) dfs(i);
    int res = 0;
    for(int i = 1; i <= n; i++)
        if(par[i] != 0 && num[i] <= low[i]) res += f[i] * (n - f[i]);
    cout << res;
}
int32_t main()
{
    FastIO
    readfile();
    xuli();
    return 0;
}
