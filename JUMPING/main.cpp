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

const int NM = 2e5 + 10;
int n, k;
int Id = 0;
int a[NM], child[NM], exist[NM], high[NM];
set<int> edges[NM], dist;

void dfs(int u, int p){
    child[u] = 1;
    for(int v : edges[u]) if(v != p) {
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
ll dfs2(int u, int p, int h, vector<int> &tmp){
    ll ans = 0;
    for(int i : dist) if(exist[i] == Id) {
        ans += ((h + i) / k + ((h + i) % k != 0)) * high[i];
    }

    tmp.push_back(h);
    for(int v : edges[u]) if(v != p) {
        ans += dfs2(v, u, h + 1, tmp);
    }

    return ans;
}
ll solve(int u, int p){
    dfs(u, p);
    int node = child[u];
    int cen = centroid(u, p, node);

    ll res = 0, curId = ++Id;
    exist[0] = Id;
    dist.clear();
    dist.insert(0);
    high[0] = 1;

    for(int v : edges[cen]) if(v != p) {
        vector<int> tmp;
        res += dfs2(v, cen, 1, tmp);
        for(int t : tmp){
            dist.insert(t);
            if(exist[t] != curId) {
                exist[t] = curId;
                high[t] = 1;
            } else high[t]++;
        }
    }

    vector<int> tmp(ALL(edges[cen]));
    for(int v : tmp) if(v != p) {
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
    freopen("JUMPING.INP", "r", stdin);
    freopen("JUMPING.OUT", "w", stdout);
    cin >> n >> k;
    for(int i = 1; i <= n; i++){
        int u; cin >> u;
        if(u == 0) continue;
        edges[u].insert(i);
        edges[i].insert(u);
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
