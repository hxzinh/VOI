#include <bits/stdc++.h>
#define int long long
#define INF 0x3f3f3f3f
#define MASK(x) (1LL << (x))
#define BIT(i, x) ((x) >> (i) & 1)
#define pii pair<int, int>
#define fi first
#define se second
#define FastIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

template<class X, class Y>
	inline bool maximize(X &x, const Y &y) {return (x < y ? x = y, 1 : 0);}
template<class X, class Y>
	inline bool minimize(X &x, const Y &y) {return (x > y ? x = y, 1 : 0);}

const int NM = 1e5 + 10;
int n, costx, costy, costz;
int cnt = 0, d = 0;
int a[NM], b[NM];
int h[NM], g[NM];
int f[105][105], s[1001][1001][11][11];

int dp(int x, int y){
    if(x > d && y > cnt) return 0;
    if(x > d) return costy + dp(x, y + 1);
    if(y > cnt)return costx + dp(x + 1, y);
    int &res = f[x][y];
    if(res != INF) return res;
    minimize(res, costx + dp(x + 1, y));
    minimize(res, costy + dp(x, y + 1));
    minimize(res, abs(g[x] - h[y]) * costz + dp(x + 1, y + 1));
    return res;
}
void sub12(){
    for(int i = 1; i <= n; i++){
        if(a[i] > b[i]) h[++cnt] = i; //xoa thg i
        if(a[i] < b[i]) g[++d] = i;   // them thg i
    }
    for(int i = 0; i <= d + 2; i++)
        for(int j = 0; j <= cnt + 2; j++) f[i][j] = INF;
    cout << dp(1, 1) << '\n';
}
int dps3(int x, int y, int u, int v){
    if(x > d && y > cnt) return 0;
    if(x > d) return costy * v + dps3(x, y + 1, 0, a[h[y + 1]]);
    if(y > cnt)return costx * u + dps3(x + 1, y, a[g[x + 1]], 0);
    int &res = s[x][y][u][v];
    minimize(res, costx * u + dps3(x + 1, y, a[g[x + 1]], v));
    minimize(res, costy * v + dps3(x, y + 1, u, a[h[y + 1]]));
    if(u > v) minimize(res, costz * abs(g[x] - h[y]) * v + dps3(x, y + 1, u - v, abs(a[h[y + 1]] - b[h[y + 1]])));
    if(v > u) minimize(res, costz * abs(g[x] - h[y]) * u + dps3(x + 1, y, abs(a[g[x + 1]] - b[g[x + 1]]), v - u));
    if(u == v) minimize(res, costz * abs(g[x] - h[y]) * u + dps3(x + 1, y + 1, abs(a[g[x + 1]] - b[g[x + 1]]), abs(a[h[y + 1]] - b[h[y + 1]])));
    return res;
}
void sub3(){
    for(int i = 1; i <= n; i++){
        if(a[i] > b[i]) h[++cnt] = i; //xoa thg i
        if(a[i] < b[i]) g[++d] = i;   // them thg i
    }
    for(int i = 1; i <= d + 1; i++)
        for(int j = 1; j <= cnt + 1; j++)
            for(int u = 0; u <= 10; u++)
                for(int v = 0; v <= 10; v++) s[i][j][u][v] = INF;
    cout << dps3(1, 1, abs(a[g[1]] - b[g[1]]), abs(a[h[1]] - b[h[1]]));
}

int32_t main()
{
    FastIO
    freopen("ROBOT.INP", "r", stdin);
    freopen("ROBOT.OUT", "w", stdout);
    cin >> n >> costy >> costx >> costz;
    for(int i = 1; i <= n; i++) cin >> a[i];
    for(int i = 1; i <= n; i++) cin >> b[i];

    if(n <= 100) sub12();
    else sub3();
    return 0;
}
