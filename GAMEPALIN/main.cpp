#include <bits/stdc++.h>
#define ll long long
#define INF 1e9
#define FastIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

template<class X, class Y>
	inline bool maximize(X &x, const Y &y) {return (x < y ? x = y, 1 : 0);}
template<class X, class Y>
	inline bool minimize(X &x, const Y &y) {return (x > y ? x = y, 1 : 0);}

const int NM = 1e3 + 10;
int dx[] = {-1, 0, 1};
int dy[] = {-1, 0, 1};
int n;
char a[5][NM];
int f[NM][5][NM][5], g[5][NM][5][NM];

void readfile(){
    freopen("GAME.INP", "r", stdin);
    freopen("GAME.OUT", "w", stdout);
    cin >> n;
    for(int i = 1; i <= 3; i++)
        for(int j = 1; j <= n; j++) cin >> a[i][j];
}
int dp(int x, int y, int u, int v){
    if(x > u || y > 3 || y <= 0 || v > 3 || v <= 0) return 0;
    int &res = f[x][y][u][v];
    if(res != -1) return res;
    if(x == u) return res = 1;
    if(a[x][y] == a[u][v]){
        if(x + 1 == u && abs(y - v) <= 1) return res = 2;
        for(int i = 0; i < 3; i++)
            for(int j = 0; j < 3; j++)
                maximize(res, 2 + dp(x + 1, y + dx[i], u - 1, v + dx[j]));
    }
    for(int i = 0; i < 3; i++) maximize(res, dp(x + 1, y + dx[i], u, v));
    for(int i = 0; i < 3; i++) maximize(res, dp(x, y, u - 1, v + dx[i]));
    return res;
}
void xuli(){
    memset(f, -1, sizeof(f));
    int res = 0;

    for(int i = 1; i <= n; i++){
        for(int j = n; j >= i; j--){
            for(int u = 1; u <= 3; u++)
                for(int v = 1; v <= 3; v++) maximize(res, dp(i, u, j, v));
        }
    }
    cout << res;
}
void full(){
    int res = 1;
    for(int i = n; i >= 1; i--){
        for(int j = 1; j <= 3; j++){
            for(int u = i; u <= n; u++){
                for(int v = 1; v <= 3; v++){
                    if(i == u && j == v){
                        g[j][i][v][u] = 1;
                        continue;
                    }
                    if(i == u - 1){
                        if(abs(j - v) <= 1)
                            if(a[j][i] == a[v][u]) g[j][i][v][u] = g[v][u][j][i] = 2;
                        continue;
                    }
                    if(i < u - 1){
                        if(a[j][i] == a[v][u]){
                            for(int k = 0; k < 3; k++)
                            for(int t = 0; t < 3; t++) if(g[j + dx[k]][i + 1][v + dx[t]][u - 1]) {
                                if(j + dx[k] > 0 && v + dx[t] > 0)
                                    maximize(g[j][i][v][u], g[j + dx[k]][i + 1][v + dx[t]][u - 1] + 2);
                            }
                        }
                    }
                    maximize(res, g[j][i][v][u]);
                }
            }
        }
    }
    cout << res;
}
int32_t main()
{
    FastIO
    readfile();
    full();
    return 0;
}
