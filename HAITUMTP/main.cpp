#include <bits/stdc++.h>
#define int long long
#define INF 1e18
#define FastIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

template<class X, class Y>
	inline bool maximize(X &x, const Y &y) {return (x < y ? x = y, 1 : 0);}
template<class X, class Y>
	inline bool minimize(X &x, const Y &y) {return (x > y ? x = y, 1 : 0);}

const int NM = 2300;
int n, m;
int a[NM][NM], f[NM][NM];

void readfile(){
    freopen("HAITUMTP.INP", "r", stdin);
    freopen("HAITUMTP.OUT", "w", stdout);
    cin >> n >> m;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++) cin >> a[i][j];
}
void xuli(){
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++) f[i][j] = INF;
    for(int i = 0; i < n; i++) f[i][0] = a[i][0];

    for(int j = 0; j < m; j++){
        for(int i = 0; i < n; i++){
            int x1 = i * i % n;
            int x2 = i * i * i % n;
            int x3 = i * i * i * i % n;
            minimize(f[x1][j + 1], f[i][j] + a[x1][j + 1]);
            minimize(f[x2][j + 1], f[i][j] + a[x2][j + 1]);
            minimize(f[x3][j + 1], f[i][j] + a[x3][j + 1]);
        }
    }
    int res = INF;
    for(int i = 0; i < n; i++) minimize(res, f[i][m - 1]);
    cout << res;
}
int32_t main()
{
    FastIO
    readfile();
    xuli();
    return 0;
}
