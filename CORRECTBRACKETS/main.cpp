#include <bits/stdc++.h>
#define ll long long
#define INF 0x3f3f3f3f
#define pii pair<int, int>
#define fi first
#define se second
#define ALL(v) (v).begin(), (v).end()
#define popcount(x) __builtin_popcount(x)
#define setp(x) setprecision(x)
#define MASK(x) (1LL << (x))
#define BIT(x, i) ((x) >> (i) & 1)
#define FastIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

template<class X, class Y>
	inline bool maximize(X &x, const Y &y) {return (x < y ? x = y, 1 : 0);}
template<class X, class Y>
	inline bool minimize(X &x, const Y &y) {return (x > y ? x = y, 1 : 0);}

const int NM = 3e5 + 10;
int n;
char s[NM];
int Id = 0;
int child[NM], open[NM], close[NM], exClose[NM], exOpen[NM];
set<int> edges[NM];

void dfs(int u, int p){
    child[u] = 1;
    for(int v : edges[u]) if(v != p){
        dfs(v, u);
        child[u] += child[v];
    }
}
int centroid(int u, int p, int node){
    for(int v : edges[u]) if(v != p) {
        if(child[v] > node / 2) return centroid(v, u, node);
    }
    return u;
}
int dfs2(int u, int p, int cur, int node, vector<int> &op, vector<int> &en){
    int ans = 0, need = -cur;

    if(need < 0 && exOpen[abs(need)] == Id && s[u] == ')') ans += open[abs(need)];
    if(need >= 0 && exClose[abs(need)] == Id && s[u] == '(') ans += close[abs(need)];

    if(abs(cur) <= node / 2){
        if(cur >= 0 && s[u] == '(') op.push_back(cur);
        if(cur < 0 && s[u] == ')') en.push_back(abs(cur));

        for(int v : edges[u]) if(v != p){
            ans += dfs2(v, u, cur + (s[v] == '(' ? 1 : -1), node, op, en);
        }
    }
    return ans;
}
int solve(int u, int p){
    dfs(u, p);
    int node = child[u];
    int cen = centroid(u, p, node);

    int res = 0;
    int curId = ++Id;
    exOpen[0] = exClose[0] = curId;

    for(int i = 1; i <= n; i++) open[i] = close[i] = 0;

    for(int v : edges[cen]) if(v != p) {
        vector<int> op, en;
        int sta = (s[cen] == '(' ? 1 : -1)
        res += dfs2(v, cen, (s[cen] == '(' ? 1 : -1) , node, op, en);

        for(int t : op){
            if(exOpen[t] != curId) exOpen[t] = curId;
            open[t]++;
        }

        for(int t : en){
            if(exClose[t] != curId) exClose[t] = curId;
            close[t]++;
        }
    }

    vector<int> tmp(ALL(edges[cen]));
    for(int v : tmp){
        edges[cen].erase(v);
        edges[v].erase(cen);
        res += solve(v, cen);
    }

    return res;
}
void xuli(){
    cout << solve(1, 0);
}
int32_t main()
{
    FastIO
    freopen("CORRECTBRACKETS.INP", "r", stdin);
    freopen("CORRECTBRACKETS.OUT", "w", stdout);
    cin >> n;
    for(int i = 1; i <= n; i++) cin >> s[i];
    for(int i = 1; i < n; i++){
        int u, v;
        cin >> u >> v;
        edges[u].insert(v);
        edges[v].insert(u);
    }

    xuli();
    return 0;
}

/* Author: hxzinh */

/*
-----code ko bug-----code ko bug-----code ko bug--------------

          _.-/`)
         // / / )
      .=// / / / )
     //`/ / / / /
    // /     ` /
   ||         /
    \\       /
     ))    .'
    //    /
         /
*/
