#include <bits/stdc++.h>
#define int long long
#define INF 1e9
#define FastIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

template<class X, class Y>
	inline bool maximize(X &x, const Y &y) {return (x < y ? x = y, 1 : 0);}
template<class X, class Y>
	inline bool minimize(X &x, const Y &y) {return (x > y ? x = y, 1 : 0);}

const int NM = 1e2 + 10;
int n, m, k;
int fin[NM], t[NM], numRoad[NM];
bool ok[NM];
vector<int> edges[NM];

struct Data {
    int u, last, time;
    bool visited;

    bool inline operator < (const Data &A) const {
        return time > A.time;
    }
};

void readfile(){
    freopen("INFOR.INP", "r", stdin);
    freopen("INFOR.OUT", "w", stdout);
    cin >> n >> m;
    for(int i = 1; i <= m; i++){
        int u, v;
        cin >> u >> v;
        edges[u].push_back(v);
        edges[v].push_back(u);
    }
    cin >> k;
    for(int i = 1; i <= k; i++){
        cin >> fin[i];
        ok[fin[i]] = true;
    }
}
void dfs(int x, int par){
    for(int v : edges[x]) if(v != par) {
        dfs(v, x);
        if(ok[v]) ok[x] = true;
        if(ok[v]) numRoad[x] += numRoad[v] + 1;
    }
}
void xuli(){
    int res = 0;
    dfs(1, 0);
    for(int u : edges[1]) if(ok[u]) maximize(res, numRoad[u] + 1);
    cout << res;
}
int32_t main()
{
    FastIO
    readfile();
    xuli();
    return 0;
}
