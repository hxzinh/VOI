#include <bits/stdc++.h>
#define INF 1e8
#define FASTIO

using namespace std;
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};
const int NM = 1000010;
const int MAX = 10000010;
int n, m;
vector<int> a[NM];
int g[MAX]; /// uoc cua 2...1e7

void readfile(){
    freopen("NUMTABLE.INP", "r", stdin);
    freopen("NUMTABLE.OUT", "w", stdout);
    int subtask; cin >> subtask;
    cin >> n >> m;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            int u; cin >> u;
            a[i].push_back(u);
        }
    }
    memset(g, 0, sizeof(g));
}
void prepare(){
    for(int i = 2; i <= MAX; i++){
        if(g[i] == 0) {
            g[i] = i;
            for(long long j = i + i; j <= MAX; j += i) g[j] = i;
        }
    }
}
int dfs(int u, int v, int x){
    int res = 1;
    while(a[u][v - 1] % x == 0) a[u][v - 1] /= x;
    for(int i = 0; i < 4; i++){
        int r = u + dx[i];
        int c = v + dy[i];
        if(r > n || r < 1 || c > m || c < 1 || a[r][c - 1] % x != 0 || a[r][c - 1] == 1) continue;
        res += dfs(r, c, x);
    }
    return res;
}
void xuli(){
    prepare();
    int res = -INF;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            while(a[i][j - 1] > 1) res = max(res, dfs(i, j, g[a[i][j - 1]]));
        }
    }
    cout << res;
}
int32_t main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    readfile();
    xuli();
    return 0;
}
