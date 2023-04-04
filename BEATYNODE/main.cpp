#include <bits/stdc++.h>
#define ll long long
#define INF 1e9
#define ALL(v) (v).begin(), (v).end()
#define ii pair<int, int>
#define fi first
#define se second
#define FastIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

template<class X, class Y>
	inline bool maximize(X &x, const Y &y) {return (x < y ? x = y, 1 : 0);}
template<class X, class Y>
	inline bool minimize(X &x, const Y &y) {return (x > y ? x = y, 1 : 0);}

const int NM = 5e4 + 10;
int n, q;
int a[NM], h[NM], par[NM];
int color[NM], totalColor[NM];
vector<int> edges[NM];
vector<int> child[NM];
vector<int> c;
///--------------------------sub3------------------------------
int g[NM][5], f[NM][5], dem[5];

void readfile(){
    freopen("BEAUTYNODE.INP", "r", stdin);
    freopen("BEAUTYNODE.OUT", "w", stdout);
    cin >> n >> q;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
        totalColor[a[i]]++;
    }
    for(int i = 1; i < n; i++){
        int u, v; cin >> u >> v;
        edges[u].push_back(v);
        edges[v].push_back(u);
    }
    for(int i = 1; i <= n; i++) child[i].push_back(i);
}
void dfs(int u, int fa){
    par[u] = fa;
    h[u] = h[fa] + 1;
    f[u][1] += f[fa][1];
    f[u][2] += f[fa][2];
    for(int v : edges[u]) if(v != fa) {
        dfs(v, u);
        g[u][1] += g[v][1];
        g[u][2] += g[v][2];
        child[u].insert(child[u].end(), ALL(child[v]));
    }
}
int typeOne(int u){
    int t = child[u].size();
    for(int v : child[u]){
        if(++color[a[v]] > child[u].size() / 2) return a[v];
    }
    return -1;
}
int typeTwo(int u){
    for(int v : child[u]) color[a[v]]++;
    int numchild = (n - child[u].size()) / 2;
    for(int i = 1; i <= n; i++) if(totalColor[a[i]] - color[a[i]] > (n - child[u].size()) / 2) return a[i];
    return -1;
}
int LCA(int u, int v){
    if(h[u] < h[v]) swap(u, v);
    while(h[u] > h[v]){
        c.push_back(u);
        u = par[u];
    }
    while(u != v){
        c.push_back(u);
        c.push_back(v);
        u = par[u];
        v = par[v];
    }
    c.push_back(u);
    return u;
}
int typeThree(int u, int v){
    int root = LCA(u, v);
    int numChild = c.size();
    for(int v : c) if(++color[a[v]] > numChild / 2) return a[v];
    return -1;
}
void sub1(){
    dfs(1, 0);
    while(q--){
        int type, u, v;
        cin >> type;
        memset(color, 0, (n + 1) * sizeof(int));
        if(type == 1){
            cin >> u;
            cout << typeOne(u) << '\n';
        } else if(type == 2) {
            cin >> u;
            cout << typeTwo(u) << '\n';
        } else {
            c.clear();
            cin >> u >> v;
            cout << typeThree(u, v) << '\n';
        }
    }
}
int LCAsub3(int u, int v){
    if(h[u] < h[v]) swap(u, v);
    while(h[u] > h[v]){
        u = par[u];
    }
    while(u != v){
        u = par[u];
        v = par[v];
    }
    return u;
}
void sub3(){
    for(int i = 1; i <= n; i++)
        if(a[i] == 1) g[i][1] = f[i][1] = 1;
        else g[i][2] = f[i][2] = 1;
    dfs(1, 0);
    while(q--){
        int type, u, v;
        cin >> type;
        if(type == 1){
            cin >> u;
            cout << (g[u][1] == g[u][2] ? -1 : (g[u][1] > g[u][2] ? 1 : 2)) << '\n';
        } else if(type == 2) {
            cin >> u;
            int colorOne = g[1][1] - g[u][1];
            int colotTwo = g[1][2] - g[u][2];
            cout << (colorOne == colotTwo ? -1 : (colorOne > colotTwo ? 1 : 2)) << '\n';
        } else if(type == 3) {
            cin >> u >> v;
            int root = LCAsub3(u, v);
            int t1 = f[u][1] + f[v][1] - 2 * f[root][1] + (a[root] == 1);
            int t2 = f[u][2] + f[v][2] - 2 * f[root][2] + (a[root] == 2);
            cout << (t1 == t2 ? -1 : (t1 > t2 ? 1 : 2)) << '\n';
        }
    }
}
int main()
{
    FastIO
    readfile();
    if(n <= 3000 && q <= 3000) sub1();
    else sub3();
    return 0;
}
