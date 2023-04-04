#include <bits/stdc++.h>
#define ll long long
#define INF 1e9
#define FastIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

template<class X, class Y>
	inline bool maximize(X &x, const Y &y) {return (x < y ? x = y, 1 : 0);}
template<class X, class Y>
	inline bool minimize(X &x, const Y &y) {return (x > y ? x = y, 1 : 0);}

int T;
int f[11][101][101][101];

void readfile(){
    freopen("JELLY.INP", "r", stdin);
    freopen("JELLY.OUT", "w", stdout);
    cin >> T;
}
int dp(int u, int x, int y, int z){
    if (x < y) swap(x, y);
	if (x < z) swap(x, z);
	if (y < z) swap(y, z);
    int &res = f[u][x][y][z];
    if(res != -1) return res;
    if(z < u) return 0;
    res = x * y;
    for(int i = u; i <= x / 2; i++) maximize(res, dp(u, i, y, z) + dp(u, x - i, y, z));
    for(int j = u; j <= y / 2; j++) maximize(res, dp(u, x, j, z) + dp(u, x, y - j, z));
    for(int k = u; k <= z / 2; k++) maximize(res, dp(u, x, y, k) + dp(u, x, y, z - k));
    return res;
}
void xuli(){
    memset(f, -1, sizeof(f));
    while(T--){
        int u, x, y, z;
        cin >> x >> y >> z >> u;
        cout << dp(u, x, y, z) << '\n';
    }
}
int32_t main()
{
    FastIO
    readfile();
    xuli();
    return 0;
}
