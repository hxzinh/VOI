#include <bits/stdc++.h>
#define int long long
#define INF 1e9
#define FastIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

template<class X, class Y>
	inline bool maximize(X &x, const Y &y) {return (x < y ? x = y, 1 : 0);}
template<class X, class Y>
	inline bool minimize(X &x, const Y &y) {return (x > y ? x = y, 1 : 0);}

const int NM = 1e5 + 10;
int n, m, h;
bool cx[NM];

vector<int> edges[NM];

void readfile(){
    freopen("INP", "r", stdin);
    freopen("OUT", "w", stdout);
    cin >> n >> m >> h;
    for(int i = 1; i <= m; i++){
        int u, v, w;
        cin >> u >> v >> w;
        if(w < h) continue;
        edges[u].push_back(v);
        edges[v].push_back(u);
    }
    memset(cx, true, sizeof(cx));
}
void dfs(int x, int par){
    cx[x] = false;
    for(int v : edges[x]) if(v != par && cx[v]){
        dfs(v, x);
    }
    return;
}
void xuli(){
    int res = 0;
    for(int i = 1; i <= n; i++) if(cx[i]) {
        res++;
        dfs(i, 0);
    }
    cout << res;
}
int32_t main()
{
    FastIO
    readfile();
    xuli();
    return 0;
}
