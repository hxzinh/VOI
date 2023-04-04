#include <bits/stdc++.h>
#define int long long
#define INF 1e9
#define FastIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

template<class X, class Y>
	inline bool maximize(X &x, const Y &y) {return (x < y ? x = y, 1 : 0);}
template<class X, class Y>
	inline bool minimize(X &x, const Y &y) {return (x > y ? x = y, 1 : 0);}

const int NM = 3e3 + 10;
const int MOD = 998244353;
int dx[] = {0, 1, 1, 1, 2};
int dy[] = {1, 0, 1, 2, 1};
int n, m;
int f[2500][2500][5];
bool cx[NM][NM];

void add(int &a, int b){
    if(a + b >= MOD) a += b - MOD;
    else a += b;
}
void readfile(){
    freopen("CHANGEDIR.INP", "r", stdin);
    freopen("CHANGEDIR.OUT", "w", stdout);
    cin >> n >> m;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            char u; cin >> u;
            if(u == '.') cx[i][j] = true;
            else cx[i][j] = false;
        }
    }
}
void xuli(){
    memset(f, 0, sizeof(f));
    for(int i = 0; i < 5; i++){
        int x = 1 + dx[i];
        int y = 1 + dy[i];
        f[x][y][i] = 1;
    }
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++) if(cx[i][j]) {
            for(int k = 0; k < 5; k++) if(f[i][j][k] > 0) {
                for(int u = 0; u < 5; u++) if(u != k) {
                    int x = i + dx[u];
                    int y = j + dy[u];
                    if(cx[x][y]) add(f[x][y][u], f[i][j][k]);
                }
            }
        }
    }
    int res = 0;
    for(int i = 0; i < 5; i++) add(res, f[n][m][i]);
    cout << res;
}
int32_t main()
{
    FastIO
    readfile();
    xuli();
    return 0;
}
