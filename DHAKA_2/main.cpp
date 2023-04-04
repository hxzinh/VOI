#include <bits/stdc++.h>
#define ll long long
#define INF 1e18
#define MASK(x) (1LL << (x))
#define BIT(i, x) ((x) >> (i))
#define FastIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

template<class X, class Y>
	inline bool maximize(X &x, const Y &y) {return (x < y ? x = y, 1 : 0);}
template<class X, class Y>
	inline bool minimize(X &x, const Y &y) {return (x > y ? x = y, 1 : 0);}

const int NM = 1e5 + 10;
int n, m, k, l;
int melon[NM];
long long f[NM][100];

struct Data {
    int v;
    long long cost;
};
vector<Data> edges[NM];

struct Road {
    int u, mask;
    long long cost;
    bool inline operator < (const Road &A) const {
        return cost > A.cost || (cost == A.cost && __builtin_popcount(mask) < __builtin_popcount(A.mask));
    }
};

void readfile(){
    freopen("INP", "r", stdin);
    freopen("OUT", "w", stdout);
    cin >> n >> m >> k >> l;
    for(int i = 1; i <= n; i++){
        int u; cin >> u;
        for(int j = 1; j <= u; j++){
            int v; cin >> v;
            melon[i] |= MASK(v - 1);
        }
    }
    for(int i = 1; i <= m; i++){
        int u, v, w;
        cin >> u >> v >> w;
        edges[u].push_back({v, w});
        edges[v].push_back({u, w});
    }
    for(int i = 1; i <= n; i++)
        for(int j = 0; j <= MASK(k); j++) f[i][j] = INF;
}
void xuli(){
    f[1][melon[1]] = 0;
    priority_queue<Road> pq;
    pq.push({1, melon[1], 0});
    while(!pq.empty()){
        int u = pq.top().u, mask = pq.top().mask;
        long long cost = pq.top().cost;
        pq.pop();
        if(f[u][mask] != cost) continue;
        for(auto v : edges[u]){
            int newMask = mask | melon[v.v];
            if(f[v.v][newMask] > f[u][mask] + v.cost){
                f[v.v][newMask] = f[u][mask] + v.cost;
                pq.push({v.v, newMask, f[v.v][newMask]});
            }
        }
    }
    long long res = INF;
    for(int i = 0; i <= MASK(k); i++){
        int numMelon = __builtin_popcount(i);
        if(numMelon >= l) minimize(res, f[n][i]);
    }
    cout << (res < INF ? res : -1);
}
int32_t main()
{
    FastIO
    readfile();
    xuli();
    return 0;
}
