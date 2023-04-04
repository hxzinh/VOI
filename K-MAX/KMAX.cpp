#include <bits/stdc++.h>
#define int long long
#define INF 1e9
#define FastIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

template<class X, class Y>
	inline bool maximize(X &x, const Y &y) {return (x < y ? x = y, 1 : 0);}
template<class X, class Y>
	inline bool minimize(X &x, const Y &y) {return (x > y ? x = y, 1 : 0);}

const int NM = 305;
const int MOD = 22071997;
int n, m, k;
int res = 0;
int a[NM][NM], f[NM][NM][102], h[NM][NM];

void add(int &a, int b){
    if(a + b >= MOD) a += b - MOD;
    else a += b;
}
void readfile(){
    freopen("KMAX.INP", "r", stdin);
    freopen("KMAX.OUT", "w", stdout);
    cin >> n >> m >> k;
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= m; j++) cin >> a[i][j];
}
void xuli(){
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            maximize(h[i][j], h[i - 1][j] + a[i][j]);
            maximize(h[i][j], h[i][j - 1] + a[i][j]);
        }
    }

    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= m; j++)
            for(int d = 0; d <= k; d++) f[i][j][d] = 0;
    f[1][1][0] = 1;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            for(int d = 0; d <= k; d++) if(f[i][j][d]) {
                int sum = h[i][j] - d;
                int toD = abs(h[i + 1][j] - sum - a[i + 1][j]);
                int toL = abs(h[i][j + 1] - sum - a[i][j + 1]);
                if(toD <= k) add(f[i + 1][j][toD], f[i][j][d]);
                if(toL <= k) add(f[i][j + 1][toL], f[i][j][d]);
            }
        }
    }
    for(int i = 0; i <= k; i++) add(res, f[n][m][i]);
    cout << h[n][m] << '\n' << res;
}
int32_t main()
{
    FastIO
    readfile();
    xuli();
    return 0;
}
