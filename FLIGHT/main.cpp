#include <bits/stdc++.h>
#define ll long long
#define INF 0x3f3f3f3f
#define MASK(x) (1LL << (x))
#define BIT(i, x) ((x) >> (i) & 1LL)
#define ALL(v) (v).begin(), (v).end()
#define FastIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

template<class X, class Y>
	inline bool maximize(X &x, const Y &y) {return (x < y ? x = y, 1 : 0);}
template<class X, class Y>
	inline bool minimize(X &x, const Y &y) {return (x > y ? x = y, 1 : 0);}

const int NM = 1501;
int n, m, q;
int a[18], edges[NM][NM];
int distFrom[18][NM], distTo[18][NM], f[18][18][MASK(17)];
bool cx[NM];
vector<int> order;

void dijtra(int x, int dist[], bool sta){
    memset(cx, true, (n + 1) * sizeof(bool));
    dist[x] = 0;

    while(true){
        int u = -1;
        for(int i = 1; i <= n; i++) if(cx[i] && (u < 0 || dist[i] < dist[u])) u = i;
        if(u < 0) break;
        cx[u] = false;
        for(int v = 1; v <= n; v++){
            minimize(dist[v], dist[u] + (sta ? edges[v][u] : edges[u][v]));
        }
    }
}
void xuli(){
    for(int i = 1; i <= m; i++)
        for(int j = 1; j <= n; j++) distFrom[i][j] = distTo[i][j] = INF;
    for(int i = 1; i <= m; i++){
        dijtra(a[i], distFrom[i], false);
        dijtra(a[i], distTo[i], true);
    }

    memset(f, INF, sizeof(f));
    for(int i = 1; i <= m; i++) f[i][i][MASK(i - 1)] = 0;
    for(int mask = 0; mask < MASK(m); mask++){
        for(int i = mask; i > 0; i ^= i & (-i)){
            int u = __builtin_ctz(i & (-i)) + 1;
            for(int j = mask; j > 0; j ^= j & (-j)){
                int v = __builtin_ctz(j & (-j)) + 1;
                if(f[u][v][mask] >= INF) continue;

                for(int k = (MASK(m) - 1) ^ mask; k > 0; k ^= k & (-k)){
                    int t = __builtin_ctz(k & (-k)) + 1;
                    minimize(f[u][t][mask | MASK(t - 1)], f[u][v][mask] + distFrom[v][a[t]]);
                }
            }
        }
    }

    while(q--){
        int u, v;
        cin >> u >> v;

        int res = INF;
        for(int i = 1; i <= m; i++)
        for(int j = 1; j <= m; j++){
            int sum = distTo[i][u] + f[i][j][MASK(m) - 1] + distFrom[j][v];
            minimize(res, sum);
        }
        cout << res << " ";
    }
}
int32_t main()
{
    FastIO
    freopen("FLIGHT.INP", "r", stdin);
    freopen("FLIGHT.OUT", "w", stdout);
    cin >> n >> m >> q;
    for(int i = 1; i <= m; i++) cin >> a[i];
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++) cin >> edges[i][j];
    }

    for(int i = 1; i <= m; i++) order.push_back(i);

    xuli();
    return 0;
}
