#include <bits/stdc++.h>
#define ll long long
#define INF 0x3f3f3f3f
#define pii pair<int, int>
#define FastIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

template<class X, class Y>
	inline bool maximize(X &x, const Y &y) {return (x < y ? x = y, 1 : 0);}
template<class X, class Y>
	inline bool minimize(X &x, const Y &y) {return (x > y ? x = y, 1 : 0);}

const int NM = 5e4 + 10;
int n, m, q;
int high[NM], par[NM], g[NM];
vector<int> edges[NM];
bool node[NM], cx[NM];
set<int> S;

void dfs(int u, int p){
    for(int v : edges[u]) if(v != p){
        high[v] = high[u] + 1;
        par[v] = u;
        dfs(v, u);
    }
    return;
}
int LCA(int u, int v){
    if(high[u] < high[v]) swap(u, v);
    while(high[u] > high[v]) u = par[u];
    while(u != v){
        u = par[u];
        v = par[v];
    }
    return u;
}
void bfs(int x){
    queue<int> q;
    g[x] = 0;
    q.push(x);
    while(q.size()){
        int u = q.front();
        q.pop();
        for(int v : edges[u]) if(cx[v]){
            if(minimize(g[v], g[u] + 1)) q.push(v);
        }
    }

    int res = INF, cnt = 0;
    for(int i = 1; i <= n; i++) if(node[i]){
        if(res > g[i]){
            cnt = 1;
            res = g[i];
        } else if(res == g[i]) cnt++;
    }
    cout << res << " " << cnt << '\n';
}
void sub1(){
    while(q--){
        int type, u;
        cin >> type >> u;
        if(type == 1) node[u] = node[u] ^ 1;
        if(type == 2){
            memset(cx, true, sizeof(cx));
            memset(g, INF, sizeof(g));
            bfs(u);
        }
    }
}
void sub2(){
    dfs(1, 1);
    while(q--){
        int type, u;
        cin >> type >> u;
        if(type == 1){
            if(node[u]) S.erase(u);
            else S.insert(u);
            node[u] ^= 1;
        }
        if(type == 2){
            int res = INF, cnt = 0;
            for(int i : S){
                int k = LCA(u, i);
                g[i] = high[i] + high[u] - 2 * high[k];
                if(res > g[i]){
                    cnt = 1;
                    res = g[i];
                }
                else if(res == g[i]) cnt++;
            }
            cout << res << " " << cnt << '\n';
        }
    }
}
int main()
{
    FastIO
    freopen("TREE.INP", "r", stdin);
    freopen("TREE.OUT", "w", stdout);
    cin >> n >> m >> q;
    for(int i = 1; i < n; i++){
        int u, v;
        cin >> u >> v;
        edges[u].push_back(v);
        edges[v].push_back(u);
    }
    for(int i = 1; i <= m; i++){
        int u; cin >> u;
        node[u] = true;
        S.insert(u);
    }
    memset(par, -1, sizeof(par));

    sub2();
    return 0;
}
