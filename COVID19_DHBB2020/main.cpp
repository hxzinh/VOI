#include <bits/stdc++.h>
#define ll long long
#define INF 0x3f3f3f3f
#define pii pair<int, int>
#define fi first
#define se second
#define ALL(v) (v).begin(), (v).end()
#define popcount(x) __builtin_popcount(x)
#define set(x) setprecision(x)
#define MASK(x) (1LL << (x))
#define BIT(x, i) ((x) >> (i) & 1)
#define FastIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

template<class X, class Y>
	inline bool maximize(X &x, const Y &y) {return (x < y ? x = y, 1 : 0);}
template<class X, class Y>
	inline bool minimize(X &x, const Y &y) {return (x > y ? x = y, 1 : 0);}

const int NM = 1e6 + 10;
const int MAX = 505;
const int MOD = 4;
int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};
int n, m, q;
int a[NM], f[NM];
vector<int> p[NM];

int xuli(int s, int fin){
    queue<int> B[MOD + 2];

    for(int i = 1; i <= n * m + 1; i++) f[i] = INF;
    f[s] = 0;
    B[0].push(s);

    int idx = 0;
    while(true){
        int tmp = idx;
        while(B[idx].empty()){
            if(++idx == MOD) idx = 0;
            if(idx == tmp) return f[fin];
        }

        int u = B[idx].front();
        B[idx].pop();

        if(u == fin) return f[u];

        int px = (u - 1) / m + 1, py = (u - 1) % m + 1;
        if(a[u] <= n * m) for(int v : p[a[u]]) {
            if(f[v] > f[u] + 3){
                f[v] = f[u] + 3;
                B[(idx + 3) % MOD].push(v);
            }
        }

        for(int i = 0; i < 4; i++){
            int x = px + dx[i], y = py + dy[i];
            if(x <= 0 || y <= 0 || x > n || y > m) continue;
            int v = (x - 1) * m + y;
            if(f[v] > f[u] + 1){
                f[v] = f[u] + 1;
                B[(idx + 1) % MOD].push(v);
            }
        }
    }
}
int32_t main()
{
    FastIO
    freopen("COVID19.INP", "r", stdin);
    freopen("COVID19.OUT", "w", stdout);
    cin >> n >> m >> q;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            cin >> a[(i - 1) * m + j];
            p[i * j].push_back((i - 1) * m + j);
        }
    }

    while(q--){
        int x, y, u, v;
        cin >> x >> y >> u >> v;
        cout << xuli((x - 1) * m + y, (u - 1) * m + v) << '\n';
    }
    return 0;
}
