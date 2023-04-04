#include <bits/stdc++.h>
#define ll long long
#define INF 1e9
#define FastIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

template<class X, class Y>
	inline bool maximize(X &x, const Y &y) {return (x < y ? x = y, 1 : 0);}
template<class X, class Y>
	inline bool minimize(X &x, const Y &y) {return (x > y ? x = y, 1 : 0);}

const int NM = 1e5 + 10;
int MOD;
int n, k;
vector<int> edges[NM];
///------------------------sub1-------------------------
int f[5005][5005], h[NM];

void readfile(){
    freopen("DRAWTREE.INP", "r", stdin);
    freopen("DRAWTREE.OUT", "w", stdout);
    cin >> n >> k >> MOD;
    for(int i = 1; i < n; i++){
        int u, v;
        cin >> u >> v;
        edges[u].push_back(v);
        edges[v].push_back(u);
    }
}
void dfs(int x, int u, int par){
    for(int v : edges[u]) if(v != par && h[v] > h[u]) {
        f[x][v] = f[x][u] + 1;
        dfs(x, v, u);
    }
}
void sub1(){
    for(int i = 1; i <= n; i++) h[i] = INF;
    h[1] = 0;
    for(int i = 1; i <= n; i++) dfs(i, i, par[i]);
}
void sub4(){

}
int main()
{
    FastIO
    readfile();
    cout << 0;
    return 0;
}
