#include <bits/stdc++.h>
#define int long long
#define INF 1e18
#define FastIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;
const int NM = 5050;
int n;
int a[NM], b[NM], f[NM][NM];

void readfile(){
    freopen("CONVOL.INP", "r", stdin);
    freopen("CONVOL.OUT", "w", stdout);
    cin >> n;
    for(int i = 1; i <= n; i++) cin >> a[i];
    for(int i = 1; i <= n; i++) cin >> b[i];
    for(int i = 0; i <= n; i++)
        for(int j = 0; j <= n; j++) f[i][j] = -INF;
    ///for(int i = 0; i <= n; i++) f[0][i] = f[i][0] = 0;
}
void xuli(){
    int res = -INF;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            f[i][j] = max(a[i] * b[j] + f[i - 1][j - 1], a[i] * b[j]);
            res = max(f[i][j], res);
        }
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
