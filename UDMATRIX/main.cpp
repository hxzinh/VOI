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
int dx[] = {1, 0, 1};
int dy[] = {1, 1, 0};
int n, t;
int a[NM][NM];
double f[NM][NM];
stack<pii> st;

double dp(int x, int y){
    if(x > n || y > n) return 0;
    double &res = f[x][y];
    if(res < INF) return res;
    for(int i = 0; i < 3; i++){
        int u = x + dx[i], v = y + dy[i];
        if(u > n || v > n) continue;
        if(a[u][v] >= a[x][y]) if(res <= 1 + abs(a[x][y] - a[u][v]) + dp(u, v)){
            res = 1 + abs(a[x][y] - a[u][v]) + f[u][v];
        }
        else if(res <= 1 + (0,01 * abs(a[x][y] - a[u][v]) + dp(u, v)))
                res = 1 + (0,01 * abs(a[x][y] - a[u][v]) + f[u][v]);
    }
    return res;
}
void trace(int x, int y){
    if(x > n || y > n) return;
    for(int i = 0; i < 3; i++){
        int u = x + dx[i], v = y + dy[i];
        if(a[u][v] >= a[x][y]){
            if(f[x][y] - abs(a[u][v] - a[x][y])) return;
        }
    }
    return;
}
void xuli(){
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= n; j++) f[i][j] = INF;
    f[n][n] = 0;

    if(dp(1, 1) <= 1.00 * t) trace(1, 1);
    else cout << "Can’t solve" << '\n';

    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++) cout << f[i][j] << " ";
        cout << '\n';
    }
}
int main()
{
    FastIO
    freopen("UDMATRIX.INP", "r", stdin);
    freopen("UDMATRIX.OUT", "w", stdout);
    cin >> n >> t;
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= n; j++) cin >> a[i][j];

    xuli();
    return 0;
}
