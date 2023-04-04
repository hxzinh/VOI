#include <bits/stdc++.h>
#define int long long
#define INF 1e18
#define FastIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

template<class X, class Y>
	inline bool maximize(X &x, const Y &y) {return (x < y ? x = y, 1 : 0);}
template<class X, class Y>
	inline bool minimize(X &x, const Y &y) {return (x > y ? x = y, 1 : 0);}

const int NM = 300;
int dx[] = {-1, 0, 1};
int dy[] = {1, 1, 1};
int n, m, k;
int a[NM][NM], f[NM][NM][12];

void readfile(){
    freopen("GARDEN.INP", "r", stdin);
    freopen("GARDEN.OUT", "w", stdout);
    cin >> n >> m >> k;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            cin >> a[i][j];
        }
    }
}
int dp(int x, int y, int t){
    if(x > n || y > m || t > k) return 0;
    int &res = f[x][y][t];
    if(res != -INF) return res;
    maximize(res, a[x][y] + dp(x - 1, y + 1, t));
    maximize(res, a[x][y] + dp(x, y + 1, t));
    maximize(res, a[x][y] + dp(x + 1, y + 1, t));
    if(x == 1) maximize(res, dp(x + 1, y, t));
    maximize(res, a[x][y] + dp(x, 1, t + 1));
    maximize(res, a[x][y] + dp(1, 1, t + 2));
    return res;
}
void xuli(){
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= m; j++)
            for(int t = 0; t <= k; t++) f[i][j][t] = -INF;

    int res = dp(1, 1, 0);
    cout << res;
}
int32_t main()
{
    FastIO
    readfile();
    xuli();
    return 0;
}
