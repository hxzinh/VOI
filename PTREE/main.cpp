#include <bits/stdc++.h>
#define ll long long
#define INF 1e9
#define FastIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

template<class X, class Y>
	inline bool maximize(X &x, const Y &y) {return (x < y ? x = y, 1 : 0);}
template<class X, class Y>
	inline bool minimize(X &x, const Y &y) {return (x > y ? x = y, 1 : 0);}

const int NM = 1e6 + 10;
int n;
int cnt = 0, numLeaf = 0;
int color[NM], par[NM], leaf[NM], p[NM], f[NM], t[NM];
vector<int> edges[NM];

void readfile(){
    freopen("INP", "r", stdin);
    freopen("OUT", "w", stdout);
    cin >> n;
    for(int i = 1; i <= n; i++) cin >> color[i];
    for(int i = 2; i <= n; i++){
        int u; cin >> u;
        edges[u].push_back(i);
        par[i + 1] = u;
    }
    for(int i = 1; i <= n; i++)
        if(!edges[i].size()){
            f[i] = 1;
            numLeaf++;
        }
}
void dfs(int x){
    if(edges[x].empty()){
        leaf[++cnt] = x;
        return;
    }
    for(int v : edges[x]) dfs(v);
}
int getAns(int x){
    if(p[x] != 0) return p[x];
    int ans = (color[x] == 1 ? -1 : INF);
    for(int v : edges[x]){
        if(color[x] == 1) maximize(ans, getAns(v));
        else minimize(ans, getAns(v));
    }
    return ans;
}
void sub1(){
    dfs(1);
    int res = -1;
    while(next_permutation(leaf + 1, leaf + n + 1)){
        memset(p, 0, sizeof(p));
        for(int i = 1; i <= cnt; i++) p[leaf[i]] = i;
        maximize(res, getAns(1));
    }
    cout << res;
}
void dfs_full(int x){
    if(!edges[x].size()){
        f[x] = 1;
        return;
    }
    if(color[x]) f[x] = INF;
    else f[x] = 0;
    for(int v : edges[x]){
        dfs(v);
        if(color[x]) f[x] = min(f[x], f[v]);
        else f[x] += f[v];
    }
}
void full(){
    dfs_full(1);
    cout << numLeaf - f[1] + 1;
}
int32_t main()
{
    FastIO
    readfile();
    if(n <= 10) sub1();
    else full();
    return 0;
}
