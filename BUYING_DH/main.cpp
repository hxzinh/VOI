#include <bits/stdc++.h>
#define int long long
#define INF 1e18
#define FastIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;
const int NM = 3e3 + 10;
int n;
int x[NM], y[NM], z[NM], f[NM][NM][2];

void readfile(){
    freopen("BUYING.INP", "r", stdin);
    freopen("BUYING.OUT", "w", stdout);
    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> x[i] >> y[i] >> z[i];
    }
    for(int i = 0; i <= n; i++)
        for(int j = 0; j <= n; j++)
            for(int k = 0; k < 2; k++) f[i][j][k] = INF;
    f[0][0][0] = 0;
}
void xuli(){
    int res = INF;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < i; j++){
            for(int na = 0; na < 2; na++) if(f[i][j][na] < INF){
                f[i + 1][j][1] = min(f[i + 1][j][1], f[i][j][na] + x[i + 1]);
                f[i + 1][j + 1][0] = min(f[i + 1][j + 1][0], f[i][j][na] + z[i + 1] - j);
                if(na == 0) f[i + 1][j][0] = min(f[i + 1][j][0], f[i][j][na] + y[i] - (i - j));
            }
        }
    }
    for(int i = 1; i <= n; i++)
        for(int na = 0; na < 2; na++) res = min(res, f[n][i][na]);
    cout << res;
}
int32_t main()
{
    FastIO
    readfile();
    xuli();
    return 0;
}
