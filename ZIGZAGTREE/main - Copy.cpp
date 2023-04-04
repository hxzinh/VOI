#include <bits/stdc++.h>
#define int long long
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

const int NM = 3e3 + 10;
const int MOD = 998244353;
int n;
int a[NM], id[NM], par[NM];
vector<int> edges[NM];

void dfs(int u, int p){
    if(u != 1) par[u] = p;
    for(int v : edges[u]) if(v != p){
        dfs(v, u);
    }
}
void sub1(){
    dfs(1, 1);

    int res = 0;
    do {
        bool ok = true;
        for(int i = 2; i <= n; i++) if(edges[i].size() > 1){
            for(int u : edges[i]) if(u != par[i]){
                if(a[par[i]] < a[i] && a[i] > a[u]) continue;
                else if(a[par[i]] > a[i] && a[i] < a[u]) continue;
                else ok = false;
            }
            res += ok;
        }
    } while(next_permutation(a + 1, a + n + 1));
    cout << res;
}
int32_t main()
{
    FastIO
    cin >> n;
    for(int i = 1; i < n; i++){
        int u, v; cin >> u >> v;
        edges[u].push_back(v);
        edges[v].push_back(u);
    }
    for(int i = 1; i <= n; i++) a[i] = i;

    sub1();
    return 0;
}
