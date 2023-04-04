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
int n, m;
int par[NM];
vector<int> a[NM], edges[NM];
set<int> S[NM];

void dfs(int u, int p){
    S[u].insert(ALL(a[u]));
    for(int v : edges[u]) if(v != p){
        dfs(v, u);
        S[u].insert(ALL(S[v]));
    }
}
void sub1(){
    dfs(1, 1);
    for(int i = 1; i <= n; i++) cout << S[i].size() << " ";
}
int main()
{
    FastIO
    freopen("SORTPROBLEM.INP", "r", stdin);
    freopen("SORTPROBLEM.OUT", "w", stdout);
    cin >> n >> m;
    for(int i = 1; i <= n; i++){
        int t;
        cin >> t;
        for(int j = 1; j <= t; j++){
            int u; cin >> u;
            a[i].push_back(u);
        }
    }
    for(int i = 2; i <= n; i++){
        int u; cin >> u;
        par[i] = u;
        edges[u].push_back(i);
    }

    sub1();
    return 0;
}
