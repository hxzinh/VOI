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
int cnt = 0;
int par[NM], high[NM], cost[15][15], s[NM], val[NM];
pii a[NM];

struct EDGES {
    int v, cost;
};
vector<EDGES> edges[NM];

int getRand(int l, int r){
    return rand() % (r - l + 1) + l;
}
void dfs(int u, int p){
    high[u] = high[p] + 1;
    for(auto v : edges[u]) if(v.v != p){
        par[v.v] = u;
        s[v.v] = s[u] + v.cost;
        dfs(v.v, u);
    }
}
int LCA(int u, int v){
    if(high[u] < high[v]) swap(u, v);
    while(high[u] > high[v]) u = par[u];
    while(u != v){
        u = par[u];
        v = par[v];
    }
    return u;
}
void sub1(){
    memset(par, -1, sizeof par);
    dfs(1, 1);

    for(int i = 1; i <= n; i++){
        for(int j = i + 1; j <= n; j++){
            int p = LCA(i, j);
            cost[i][j] = cost[j][i] = s[i] + s[j] - 2 * s[p];
            int tmp = cost[i][j];
            val[++cnt] = cost[i][j];
        }
    }
    sort(val + 1, val + cnt + 1);
    for(int i = 1; i <= cnt; i++) cout << val[i] << " ";
    cout << '\n';

    while(q--){
        int u, v;
        cin >> u >> v;

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
int32_t main()
{
    freopen("COSTQUERY.INP", "r", stdin);
    freopen("COSTQUERY.OUT", "w", stdout);
    cin >> n >> q;
    for(int i = 1; i < n; i++){
        int u, v, w;
        cin >> u >> v >> w;
        edges[u].push_back({v, w});
        edges[v].push_back({u, w});
    }

    sub1();
    return 0;
}
