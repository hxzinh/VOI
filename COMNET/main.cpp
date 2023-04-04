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

const int NM = 1e3 + 10;
int n, k, L, R;
int g[NM][NM], high[NM], par[NM];
vector<int> edges[NM];

void DFS(int u, int p){
    for(int v : edges[u]) if(v != p){
        DFS(v, u);
        high[v] = high[u] + 1;
        par[v] = u;
    }
}
void dfs(int u, int p, int x){
    for(int v : edges[u]) if(v != p){
        g[x][v] = g[x][u] + 1;
        dfs(v, u, x);
    }
}
void sub1(){
    int res = 0;
    for(int i = 1; i <= n; i++)
        for(int j = i + 1; j <= n; j++) if(g[i][j] >= L && g[i][j] <= R) res++;
    cout << res;
}
void sub2(){
    int res = 0;
    for(int i = 1; i <= n; i++)
        for(int j = i + 1; j <= n; j++)
            for(int z = j + 1; z <= n; z++){
                int sum = (g[i][j] + g[i][z] + g[j][z]) / 2;
                if(sum >= L && sum <= R) res++;
            }
    cout << res;
}
void sub4(){
    int res = 0
    for(int t = 1; t <= n; t++){
        f[0][0][0] = 1;
        for(int i = 1; i <= n; i++) if(i != t){
            for(int sum = L; sum <= R; sum++) if(sum >= g[t][i]){
                for(int h = 1; h <= k; h++){
                    f[i][sum][h] += f[i - 1][sum - g[t][i]][h - 1];
                    f[i][sum][h] += f[i - 1][sum][h];
                }
            }
        }
        res += f[n][sum][k];
    }
    cout << res;
}
int main()
{
    FastIO
    freopen("COMNET.INP", "r", stdin);
    freopen("COMNET.OUT", "w", stdout);
    cin >> n >> k >> L >> R;
    for(int i = 1; i < n; i++){
        int u, v; cin >> u >> v;
        edges[u].push_back(v);
        edges[v].push_back(u);
    }
    for(int i = 1; i <= n; i++) dfs(i, i, i);

    if(k == 2) sub1();
    else sub2();
    return 0;
}
