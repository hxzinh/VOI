#include <bits/stdc++.h>
#define int long long
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

const int NM = 1e5 + 10;
const int MOD = 1e9 + 7;
int dx[] = {1, 0};
int dy[] = {0, 1};
int n, m, k;

int f[10001][10001];
bool cx[10001][10001];

void add(int &a, int b){
    if(a + b >= MOD) a += b - MOD;
    else a += b;
}
void sub1(){
    f[1][1] = 1;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++) if(f[i][j]){
            for(int t = 0; t < 2; t++){
                int x = i + dx[t], y = j + dy[t];
                if(x > n || y > m || cx[x][y]) continue;
                add(f[x][y], f[i][j]);
            }
        }
    }
    cout << f[n][m];
}
int32_t main()
{
    FastIO
    freopen("GRID.INP", "r", stdin);
    freopen("GRID.OUT", "w", stdout);
    cin >> n >> m >> k;
    for(int i = 1; i <= n; i++){
        int u, v;
        cin >> u >> v;
        cx[u][v] = true;
    }

    sub1();
    return 0;
}
