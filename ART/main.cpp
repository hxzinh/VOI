#include <bits/stdc++.h>
#define int long long
#define INF 0x3f3f3f3f
#define MASK(x) (1LL << (x))
#define BIT(i, x) ((x) >> (i) & 1)
#define ALL(v) (v).begin(), (v).end()
#define pii pair<int, int>
#define fi first
#define se second
#define FastIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

template<class X, class Y>
	inline bool maximize(X &x, const Y &y) {return (x < y ? x = y, 1 : 0);}
template<class X, class Y>
	inline bool minimize(X &x, const Y &y) {return (x > y ? x = y, 1 : 0);}

const int NM = 1e2 + 10;
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};
int n, m;
string a[NM];

int cnt = 0, numVisited = 0;
int id[NM][NM], numNode[NM];
int visited[NM], Assigned[NM];
vector<int> edges[NM];
bool choosed[NM];

int f[11][MASK(11)], trace[11][MASK(11)];
bool cx[NM];
vector<int> t[MASK(11)], q[MASK(11)];

struct Data {
    int u, cost;

    bool inline operator < (const Data &A) const {
        return cost > A.cost;
    }
};

bool Check(int id, int mask)
{
    for (int x : t[mask]) if (a[id][x] == '#') return false;

    for (int x : t[mask]) {
        if (x - 1 >= 0 && !BIT(x - 1, mask) && a[id][x] != a[id][x - 1]) return false;
        if (x + 1 < m && !BIT(x + 1, mask) && a[id][x] != a[id][x + 1]) return false;
    }

    return true;
}
int Colored(int id, int mask) {
    int res = 0;
    for (int x : q[mask]) if (a[id][x] != '#') res++;
    return res;
}
void xuli(){
    memset(f, INF, sizeof f);

    for(int mask = 0; mask < MASK(m); mask++)
        for(int i = 0; i < m; i++) if(!BIT(i, mask)) t[mask].push_back(i);

    for(int mask = 0; mask < MASK(m); mask++)
        for(int i = 0; i < m; i++) if(BIT(i, mask)) q[mask].push_back(i);

    for(int mask = 0; mask < MASK(m); mask++) if(Check(1, mask)) f[1][mask] = Colored(1, mask);

    for(int i = 1; i < n; i++){
        for(int mask = 0; mask < MASK(m); mask++) if(f[i][mask] < INF){
            for(int newMask = 0; newMask < MASK(m); newMask++) if(Check(i + 1, newMask)){
                bool ok = true;
                for(int u : t[mask]) if(!BIT(u, newMask) && a[i][u] != a[i + 1][u]){
                    ok = false;
                    break;
                }
                if(ok){
                    if(minimize(f[i + 1][newMask], f[i][mask] + Colored(i + 1, newMask)))
                        trace[i + 1][newMask] = mask;
                }
            }
        }
    }

    int res = INF, preMask;
    for(int mask = 0; mask < MASK(m); mask++){
        if(minimize(res, f[n][mask])) preMask = mask;
    }
    cout << res << '\n';

    set<char> S;
    int id = n;
    while(id > 0){
        for(int u : t[preMask]) S.insert(a[id][u]);
        preMask = trace[id--][preMask];
    }

    vector<char> ans(ALL(S));
    for(char u : ans) cout << u;
}
bool inMatrix(int x, int y){
    return (x > 0 && y > 0 && x <= n && y <= m);
}
void dfs(int x, int y){
    id[x][y] = cnt;
    numNode[cnt]++;
    for(int i = 0; i < 4; i++){
        int u = x + dx[i], v = y + dy[i];
        if(inMatrix(u, v) && a[u][v] == a[x][y] && !id[u][v]) dfs(u, v);
    }
    return;
}
bool visit(int u, int key){
    if(visited[u] == key) return false;
    visited[u] = key;
    for(int v : edges[u]){
        if(!Assigned[v] || visit(Assigned[v], u)){
            Assigned[u] = v;
            Assigned[v] = u;
            return true;
        }
    }
    return false;
}
void Konig(){
    queue<int> q;

    for(int i = 1; i <= cnt; i++) if(!Assigned[i]) q.push(i);

    while(q.size()){
        int u = q.front();
        q.pop();
        for(int v : edges[u]){
            if(!choosed[v]){
                choosed[v] = true;
                q.push(Assigned[v]);
            }
        }
    }

    for(int i = 1; i <= cnt; i++) if(Assigned[i] && !choosed[i] && !choosed[Assigned[i]]){
        choosed[i] = true;
    }
}
void full(){
    for(int i = 1; i <= n; i++) a[i] = ' ' + a[i];
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++) if(a[i][j] != '#' && !id[i][j]) {
            ++cnt;
            dfs(i, j);
        }
    }

    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            for(int k = 0; k < 4; k++){
                int u = i + dx[k], v = j +dy[k];
                if(id[u][v] && id[i][j] != id[u][v]) edges[id[i][j]].push_back(id[u][v]);
            }
        }
    }

    for(int i = 1; i <= cnt; i++) sort(ALL(edges[i]));
    for(int i = 1; i <= cnt; i++) edges[i].resize(unique(ALL(edges[i])) - edges[i].begin());

    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++) cout << id[i][j] << " ";
        cout << '\n';
    }

    int res = 0;
    for(int i = 1; i <= cnt; i++) if(!Assigned[i]) visit(i, ++numVisited);
    Konig();
    for(int i = 1; i <= cnt; i++) if(choosed[i]) cout << i << " ";
}
int32_t main()
{
    FastIO
    freopen("ART.INP", "r", stdin);
    freopen("ART.OUT", "w", stdout);
    cin >> n >> m;
    for(int i = 1; i <= n; i++) cin >> a[i];

    full();
    return 0;
}
