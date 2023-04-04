#include <bits/stdc++.h>
#define ll long long
#define INF 1e9
#define FastIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

template<class X, class Y>
	inline bool maximize(X &x, const Y &y) {return (x < y ? x = y, 1 : 0);}
template<class X, class Y>
	inline bool minimize(X &x, const Y &y) {return (x > y ? x = y, 1 : 0);}

const int NM = 2e3 + 10;
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};
int n;
int cnt = 0;
int a[10][10];
bool cx[10][10], L, R, U, D;
string f[2][2][2][2], g[2][2][2][2];

void add(string &s, string t)
{
    while (s.size() < t.size()) s = '0' + s;
    while (s.size() > t.size()) t = '0' + t;

    int d = 0;
    for (int i = s.length() - 1; i >= 0; --i)
    {
        int x = int(s[i]) - 48, y = int(t[i]) - 48;
        int p = x + y + d;
        s[i] = char(p % 10 + 48);
        d = p / 10;
    }
    if (d == 1) s = '1' + s;
}
bool check(int x, int y){
    return (x >= 1 && x <= 8 && y >= 1 && y <= 8 && !cx[x][y] && !a[x][y]);
}
void dfs(int u, int v){
    cx[u][v] = true;
    if (u == 1) U = true;
    if (u == 8) D = true;
    if (v == 1) L = true;
    if (v == 8) R = true;

    for(int i = 0; i < 4; i++){
        int x = u + dx[i], y = v + dy[i];
        if(check(x, y)) dfs(x, y);
    }
}
void xuli(){
    memset(cx, false, sizeof(cx));
    for(int i = 0; i <= 1; i++)
        for(int j = 0; j <= 1; j++)
            for(int u = 0; u <= 1; u++)
                for(int v = 0; v <= 1; v++) f[i][j][u][v] = "0";

    for(int i = 1; i <= 8; i++)
    for(int j = 1; j <= 8; j++) if(check(i, j)) {
        L = R = U = D = false;
        dfs(i, j);
        add(f[L][R][U][D], "1");
    }

    for(int k = 1; k <= n - 3; k++){
        for(int i = 0; i <= 1; i++)
            for(int j = 0; j <= 1; j++)
                for(int u = 0; u <= 1; u++)
                    for(int v = 0; v <= 1; v++) g[i][j][u][v] = "0";

        for(int x = 0; x <= 1; x++)
        for(int y = 0; y <= 1; y++){
            add(g[x][y][0][0], f[x][y][0][1]);
            add(g[x][y][0][1], f[x][y][1][0]);
            add(g[x][y][0][0], f[x][y][0][0]);
        }

        for(int x = 0; x <= 1; x++)
            for(int y = 0; y <= 1; y++) f[x][y][0][1] = "0";

        for(int i = 0; i <= 1; i++)
            for(int j = 0; j <= 1; j++)
                for(int x = 0; x <= 1; x++)
                    for(int y = 0; y <= 1; y++) add(f[i][j][x][y], g[i][j][x][y]);

        for(int i = 0; i <= 1; i++)
            for(int j = 0; j <= 1; j++)
                for(int x = 0; x <= 1; x++)
                    for(int y = 0; y <= 1; y++) g[i][j][x][y] = "0";

        for(int x = 0; x <= 1; x++)
        for(int y = 0; y <= 1; y++) {
            add(g[0][0][x][y], f[0][1][x][y]);
            add(g[0][1][x][y], f[1][0][x][y]);
            add(g[0][0][x][y], f[0][0][x][y]);
        }

        for(int x = 0; x <= 1; x++)
            for(int y = 0; y <= 1; y++) f[0][1][x][y] = "0";

        for(int i = 0; i <= 1; i++)
            for(int j = 0; j <= 1; j++)
                for(int x = 0; x <= 1; x++)
                    for(int y = 0; y <= 1; y++) add(f[i][j][x][y], g[i][j][x][y]);
    }

    string res = "0";
    for(int i = 0; i <= 1; i++)
        for(int j = 0; j <= 1; j++)
            for(int x = 0; x <= 1; x++)
                for(int y = 0; y <= 1; y++) add(res, f[i][j][x][y]);
    cout << res;
}
void readfile(){
    freopen("PUNCHER.INP", "r", stdin);
    freopen("PUNCHER.OUT", "w", stdout);
    cin >> n;
    for(int i = 1; i <= 8; i++)
        for(int j = 1; j <= 8; j++) cin >> a[i][j];

}
int main()
{
    FastIO
    readfile();
    xuli();
    return 0;
}
