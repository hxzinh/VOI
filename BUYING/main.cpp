#include <bits/stdc++.h>
#define int long long
#define INF 1e18
#define cntBIT(x) __builtin_popcountll(x)
#define MASK(x) (1LL << (x))
#define BIT(x, i) ((x) >> (i) & 1)
#define FastIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;
const int NM = 50;
int n;
int a[NM][5];
int s[NM][5][NM][NM][NM];

void readfile(){
    freopen("BUYING.INP", "r", stdin);
    freopen("BUYING.OUT", "w", stdout);
    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> a[i][1] >> a[i][2] >> a[i][3];
    }
    for(int i = 1; i <= n; i++)
    for(int j = 1; j <= 3; j++)
        for(int x = 0; x <= n; x++)
        for(int y = 0; y <= n; y++)
        for(int z = 0; z <= n; z++) s[i][j][x][y][z] = INF;
}
int dp(int index, int store, int x, int y, int z){
    if(index > n) return 0;
    if(store > 3) return INF;
    int &res = s[index][store][x][y][z];
    if(res != INF) return res;
    if(store == 1) res = min(res, a[index][store] - x + dp(index + 1, 1, x + 1, y, z));
    else if(store == 2) res = min(res, a[index][store] - y + dp(index + 1, 1, x, y + 1, z));
    else if(store == 3) res = min(res, a[index][store] - z + dp(index + 1, 1, x, y, z + 1));
    res = min(res, dp(index, store + 1, x, y, z));
    return res;
}
void xuli(){
    cout << dp(1, 1, 0, 0, 0);
}
int32_t main()
{
    FastIO
    readfile();
    xuli();
    return 0;
}
