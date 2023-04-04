#include <bits/stdc++.h>
#define ll long long
#define INF 1e9
#define FastIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

template<class X, class Y>
	inline bool maximize(X &x, const Y &y) {return (x < y ? x = y, 1 : 0);}
template<class X, class Y>
	inline bool minimize(X &x, const Y &y) {return (x > y ? x = y, 1 : 0);}

const int NM = 505;
const int MOD = 1e9 + 9;
int n, k;
int res = 0;
int frac[NM], finv[NM];
int numChild[NM], child[NM];
vector<int> edges[NM];

int add(int &a, int b){
    if(a + b >= MOD) a += b - MOD;
    else a += b;
}
int pw(int a, int b){
    if(b == 1) return a % MOD;
    int p = pw(a, b / 2);
    if(b % 2 == 0) return p % MOD * p % MOD;
    else return p % MOD * p % MOD * a % MOD;
}
void readfile(){
    freopen("RAINBOW.INP", "r", stdin);
    freopen("RAINBOW.OUT", "w", stdout);
    cin >> n >> k;
    for(int i = 1; i <= n; i++){
        int u, v; cin >> u >> v;
        edges[u].push_back(v);
        edges[v].push_back(u);
    }
}
void progress(){
    frac[0] = 1;
    for(int i = 1; i <= k; i++) frac[i] = 1LL * frac[i - 1] * i % MOD;
    finv[k] = pw(frac[k], MOD - 2);
    for(int i = k; i >= 1; i--) finv[i - 1] = 1LL * finv[i] * i % MOD;
}
int comb(int u, int v){
    return v > n ? 0 : 1LL * frac[u] * finv[v] % MOD * finv[u - v] % MOD;
}
void dfs(int x, int par){
    if(x == 1) add(res, comb(k, edges[x].size()));
    else add(res, comb(k, edges[x].size() - 1));
    for(int u : edges[x]) if(u != par){
        dfs(u, x);
    }
}
void sub2(){
    dfs(1, 1);
    cout << res;
}
int main()
{
    FastIO
    readfile();
    progress();
    sub2();
    return 0;
}
