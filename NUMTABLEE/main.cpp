#include <bits/stdc++.h>
#define ll long long
#define INF 1e8
#define FastIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;
const int MAX = 1e7 + 100;
const int NM = 1e6 + 10;
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};
int sub, n, m;
int g[MAX];
vector<int> a[NM];

void maximize(int &a, int b){
    if(a < b){
        a = b; return;
    } else return;
}
void readfile(){
    freopen("NUMTABLE.INP", "r", stdin);
    freopen("NUMTABLE.OUT", "w", stdout);
    cin >> sub;
    cin >> n >> m;
    for(int i = 1; i <= n; i++) a[i].push_back(1);
    for(int i = 1; i <= n; i++)
    for(int j = 1; j <= m; j++){
        int k; cin >> k;
        a[i].push_back(k);
    }
}
bool check(int u, int v, int x){
    if(u > n || u <= 0 || v > m || v <= 0 || a[u][v] % x != 0 || a[u][v] == 1) return false;
    return true;
}
int dfs(int u, int v, int x){
    while(a[u][v] % x == 0){
        int tam = a[u][v];
        a[u][v] /= x;
        tam = a[u][v];
        tam++;
    }
    int res = 1;
    for(int i = 0; i < 4; i++){
        int r = u + dx[i], c = v + dy[i];
        if(check(r, c, x)) res += dfs(r, c, x);
    }
    return res;
}
void prepare(){
    for(int i = 2; i <= MAX; i++){
        if(g[i] == 0){
            g[i] = i;
            int j =  i + i;
            while(j <= MAX){
                g[j] = i;
                j += i;
            }
        }
    }
}
void xuli(){
    prepare();
    int res = -INF;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            while(a[i][j] != 1)
                maximize(res, dfs(i, j, g[a[i][j]]));
        }
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
