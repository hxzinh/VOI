#include <bits/stdc++.h>
#define int long long
#define INF 1e9
#define FastIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

template<class X, class Y>
	inline bool maximize(X &x, const Y &y) {return (x < y ? x = y, 1 : 0);}
template<class X, class Y>
	inline bool minimize(X &x, const Y &y) {return (x > y ? x = y, 1 : 0);}

const int NM = 2e5 + 10;
int n;
int fa[NM], child[NM], s[NM];
vector<int> edges[NM];

void readfile(){
    freopen("INP", "r", stdin);
    freopen("OUT", "w", stdout);
    cin >> n;
    for(int i = 2; i <= n; i++){
        cin >> fa[i];
        edges[fa[i]].push_back(i);
    }
}
void dfs(int x, int par){
    if(edges[x].empty()) return;
    for(int v : edges[x]) if(v != par) {
        dfs(v, x);
        child[x] += child[v] + 1;
    }
}
void dp(int x){
    if(edges[x].empty()){
        s[x] = 1;
        return;
    }
    for(int v : edges[x]) if(v != fa[x]){
        dp(v);
        s[x] += s[v];
    }
}
void xuli(){
    dfs(1, 0);
    for(int i = 1; i <= n; i++) s[i] = child[i] + 1;
    dp(1);
    for(int i = 1; i <= n; i++) cout << s[i] << " ";
}
int32_t main()
{
    FastIO
    readfile();
    xuli();
    return 0;
}
