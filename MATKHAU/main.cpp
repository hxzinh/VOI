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
int n, m;
int a[NM], b[NM];
int f[NM][NM];

void readfile(){
    freopen("PASSWORD.INP", "r", stdin);
    freopen("PASSWORD.OUT", "w", stdout);
    cin >> n >> m;
    for(int i = 1; i <= n; i++) cin >> a[i];
    for(int i = 1; i <= m; i++) cin >> b[i];
}
int dp(int x, int y){
    if(x > n || y > m) return 0;
    int &res = f[x][y];
    if(res > -1) return res;
    if(a[x] == b[y]) maximize(res, 1 + dp(x + 2, y + 2));
    maximize(res, dp(x + 1, y));
    maximize(res, dp(x, y + 1));
    return res;
}
void xuli(){
    memset(f, -1, sizeof(f));
    cout << dp(1, 1);
}

void full(){
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            if(a[i] == b[j]) maximize(f[i + 2][j + 2], f[i][j] + 1);
            maximize(f[i + 1][j], f[i][j]);
            maximize(f[i][j + 1], f[i][j]);
        }
    }

    int res = 0;
    for(int i = 1; i <= n + 2; i++){
        for(int j = 1; j <= m + 2; j++) maximize(res, f[i][j]);
    }
    cout << res;
}
int32_t main()
{
    FastIO
    readfile();
    xuli();
    return 0;
}
