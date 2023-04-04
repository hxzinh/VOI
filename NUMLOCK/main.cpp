#include <bits/stdc++.h>
#define ll long long
#define INF 1e9
#define FastIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

template<class X, class Y>
	inline bool maximize(X &x, const Y &y) {return (x < y ? x = y, 1 : 0);}
template<class X, class Y>
	inline bool minimize(X &x, const Y &y) {return (x > y ? x = y, 1 : 0);}

const int NM = 3e5 + 10;
int n, subtask, m;
vector<int> edges[NM];
///----------------sub3---------------------
int down[NM], pre[NM];
bool cx[NM];

void readfile(){
    freopen("NUMLOCK.INP", "r", stdin);
    freopen("NUMLOCK.OUT", "w", stdout);
    cin >> subtask;
    cin >> n >> m;
    for(int i = 1; i <= m; i++){
        int u, v; cin >> u >> v;
        edges[u].push_back(v);
        edges[v].push_back(u);
    }
}
void dfs(int x, int par){
    pre[x] += pre[par];
    cx[x] = false;
    for(int u : edges[x]) if(u != par) {
        if(cx[u]){
            dfs(u, x);
            down[x] += down[u];
        }
    }
}
void sub3(){
    memset(cx, true, sizeof(cx));
    for(int i = 1; i <= n; i++) down[i] = pre[i] = 1;
    for(int i = 1; i <= n; i++) dfs(i, 0);
    for(int i = 1; i <= n; i++) cout << down[i] << " ";
    cout << '\n';
    for(int i = 1; i <= n; i++) cout << pre[i] << " ";
}
int main()
{
    FastIO
    readfile();
    sub3();
    return 0;
}
