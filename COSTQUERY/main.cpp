#include <bits/stdc++.h>
#define int long long
#define INF 0x3f3f3f3f3f3f
#define ALL(v) (v).begin(), (v).end()
#define pii pair<int, int>
#define fi first
#define se second
#define MASK(x) (1LL << (x))
#define BIT(i, x) ((x) >> (i) & 1)
#define FastIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

template<class X, class Y>
	inline bool maximize(X &x, const Y &y) {return (x < y ? x = y, 1 : 0);}
template<class X, class Y>
	inline bool minimize(X &x, const Y &y) {return (x > y ? x = y, 1 : 0);}

const int NM = 1e5 + 10;
int n, q;
int high[NM], par[NM], f[NM], s[NM];
int val[1000005], c[1005][1005], cnt = 0;

struct Data {
    int u, v, cost;

    bool inline operator < (const Data &A) const {
        return cost < A.cost;
    }
} a[NM];

struct EDGES {
    int v, cost;
};
vector<EDGES> edges[NM];


int root(int x){
    if(par[x] < 0) return x;
    else return par[x] = root(par[x]);
}
void join(int x, int y){
    if(s[x] > s[y]) swap(x, y);
    par[x] = y;
    s[y] += s[x];
}
void dfs(int u, int p){
    high[u] = high[p] + 1;
    for(auto v : edges[u]) if(v.v != p){
        par[v.v] = u;
        dfs(v.v, u);
    }
}
pii getLCA(int u, int v){
    int res = 0;
    if(high[u] < high[v]) swap(u, v);
    while(high[u] > high[v]){
        maximize(res, c[u][par[u]]);
        u = par[u];
    }
    while(u != v){
        maximize(res, c[u][par[u]]);
        maximize(res, c[v][par[v]]);
        u = par[u]; v = par[v];
    }
    return {res, u};
}
void sub1(){
    memset(par, -1, sizeof par);
    for(int i = 1; i <= n; i++) c[a[i].u][a[i].v] = c[a[i].v][a[i].u] = a[i].cost;
    dfs(1, 1);

    for(int i = 1; i <= n; i++){
        for(int j = i + 1; j <= n; j++){
            val[++cnt] = getLCA(i, j).fi;
        }
    }
    sort(val + 1, val + cnt + 1);

    while(q--){
        int u, v;
        cin >> u >> v;
        if(u > n || v > n){cout << 0 << " "; continue;}

        int head = 1, last = cnt, l;
        while(head <= last){
            int m = (head + last) >> 1;
            if(val[m] >= u){
                l = m;
                last = m - 1;
            } else head = m + 1;
        }

        int left = 1, right = cnt, r;
        while(left <= right){
            int m = (left + right) >> 1;
            if(val[m] <= v){
                r = m;
                left = m + 1;
            } else right = m - 1;
        }
        cout << r - l + 1 << " ";
    }
}
int getID(int x){
    int l = 1, r = n - 1, res = 0;
    while(l <= r){
        int m = (l + r) >> 1;
        if(a[m].cost <= x){
            res = m;
            l = m + 1;
        } else r = m - 1;
    }
    return res;
}
void xuli(){
    for(int i = 1; i <= n; i++) s[i] = 1;
    memset(par, -1, sizeof par);
    memset(f, 0, sizeof f);
    sort(a + 1, a + n);

    for(int i = 1; i < n; i++){
        int u = root(a[i].u), v = root(a[i].v);
        f[i] = f[i - 1] + s[u] * s[v];
        join(u, v);
    }

    while(q--){
        int u, v;
        cin >> u >> v;
        cout << f[getID(v)] - f[getID(u - 1)] << " ";
    }
}
int32_t main(){
    FastIO
    freopen("COSTQUERY.INP", "r", stdin);
    freopen("COSTQUERY.OUT", "w", stdout);
    cin >> n >> q;
    for(int i = 1; i < n; i++){
        int u, v, w;
        cin >> u >> v >> w;
        a[i] = {u, v, w};
        edges[u].push_back({v, w});
        edges[v].push_back({u, w});
    }

    xuli();
    return 0;
}
