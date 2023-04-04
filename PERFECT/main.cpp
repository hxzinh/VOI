#include <bits/stdc++.h>
#define ll long long
#define INF 0x3f3f3f3f
#define pii pair<int, int>
#define fi first
#define se second
#define ALL(v) (v).begin(), (v).end()
#define popcount(x) __builtin_popcount(x)
#define set(x) setprecision(x)
#define MASK(x) (1LL << (x))
#define BIT(x, i) ((x) >> (i) & 1)
#define FastIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

template<class X, class Y>
	inline bool maximize(X &x, const Y &y) {return (x < y ? x = y, 1 : 0);}
template<class X, class Y>
	inline bool minimize(X &x, const Y &y) {return (x > y ? x = y, 1 : 0);}

const int NM = 1e5 + 10;
int n, k;
int result = 0;
int par[NM];
vector<int> edges[NM];
set<int> child[NM];

void dfs(int u){
    for(int v : edges[u]){
        dfs(v);
        child[u].insert(v);
        child[u].insert(ALL(child[v]));
    }
}
void sub12(){
    for(int i = 1; i <= n; i++){
        if(par[i] == -1){
            dfs(i);
            break;
        }
    }

    int res = 0;
    for(int i = 1; i <= n; i++){
        for(int u : child[i]) cout << u << " ";
        cout << '\n';
        for(int u : child[i]) if(abs(i - u) <= k) res++;
    }
    cout << res;
}
void pushDown(int u, int p){
    for(int v : edges[u]){
        if(abs(p - v) <= k) result++;
        pushDown(v, p);
    }
}
void sub2(){
    for(int i = 1; i <= n; i++) pushDown(i, i);
    cout << result;
}
int main()
{
    FastIO
    freopen("PERFECT.INP", "r", stdin);
    freopen("PERFECT.OUT", "w", stdout);
    cin >> n >> k;
    memset(par, -1, sizeof par);
    for(int i = 1; i < n; i++){
        int u, v; cin >> u >> v;
        par[v] = u;
        edges[u].push_back(v);
    }

    sub2();
    return 0;
}
