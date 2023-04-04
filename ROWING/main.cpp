#include <bits/stdc++.h>
#define int long long
#define INF 1e18
#define pii pair<int, int>
#define fi first
#define se second
#define ALL(v) (v).begin(), (v).end()
#define FastIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

template<class X, class Y>
	inline bool maximize(X &x, const Y &y) {return (x < y ? x = y, 1 : 0);}
template<class X, class Y>
	inline bool minimize(X &x, const Y &y) {return (x > y ? x = y, 1 : 0);}

const int NM = 8e3 + 10;
int n, h;
int g[NM], f[NM][NM], par[NM];
pii a[NM];
bool cx[NM];

struct Data {
    int u, cost;

    bool inline operator < (const Data &A) const {
        return cost > A.cost;
    }
};

int getDist(int x, int y, int u, int v){
    return (u - x) * (u - x) + (v - y) * (v - y);
}
void dfs(int x, int y, int id, int d){
    cx[id] = false;
    for(int i = 1; i <= n; i++) if(cx[i]){
        int u = a[i].fi, v = a[i].se;
        int dist = getDist(x, y, u, v);
        if(dist < d) dfs(u, v, i, d);
    }
}
bool check(int x){
    if(x >= h) return false;
    for(int i = 1; i <= n; i++) cx[i] = true;
    for(int i = 1; i <= n; i++) if(cx[i]) {
        int dist = getDist(a[i].fi, 0, a[i].fi, a[i].se);
        if(dist < 1LL * x * x) dfs(a[i].fi, a[i].se, i, 1LL * x * x);
        else break;
    }

    for(int i = 1; i <= n; i++) if(!cx[i]){
        int dist = getDist(a[i].fi, h, a[i].fi, a[i].se);
        if(dist < 1LL * x * x) return false;
    }
    return true;
}
bool cmp(const pii &A, const pii &B){
    return A.se < B.se;
}
void xuli(){
    int l = 1, r = h, res = 0;
    while(l <= r){
        int m = (l + r) >> 1;
        if(check(m)){
            res = m;
            l = m + 1;
        } else r = m - 1;
    }
    cout << res;
}
void full(){
    priority_queue<Data> pq;

    for(int i = 1; i <= n; i++){
        f[0][i] = f[i][0] = a[i].se * a[i].se;
        f[n + 1][i] = f[i][n + 1] = (h - a[i].se) * (h - a[i].se);
        f[0][n + 1] = f[n + 1][i] = h * h;
    }

    for(int i = 1; i <= n; i++){
        for(int j = i + 1; j <= n; j++){
            int dist = getDist(a[i].fi, a[i].se, a[j].fi, a[j].se);
            f[i][j] = f[j][i] = dist;
        }
    }

    for(int i = 1; i <= n + 1; i++) g[i] = INF;

    pq.push({0, 0});

    while(!pq.empty()){
        int u = pq.top().u, cost = pq.top().cost;
        pq.pop();
        if(g[u] != cost) continue;
        for(int i = 0; i <= n + 1; i++){
            if(minimize(g[i], max(g[u], f[u][i]))) pq.push({i, g[i]});
        }
    }

    cout << int32_t(sqrt(g[n + 1]));
}
int32_t main()
{
    FastIO
    freopen("ROWING.INP", "r", stdin);
    freopen("ROWING.OUT", "w", stdout);
    cin >> n >> h;
    for(int i = 1; i <= n; i++) cin >> a[i].fi >> a[i].se;
    sort(a + 1, a + n + 1, cmp);
    full();
    return 0;
}
