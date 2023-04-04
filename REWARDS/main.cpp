#include <bits/stdc++.h>
#define ll long long
#define int long long
#define INF 0x3f3f3f3f
#define pii pair<int, int>
#define fi first
#define se second
#define ALL(v) (v).begin(), (v).end()
#define popcount(x) __builtin_popcount(x)
#define set(x) setprecision(x)
#define MASK(x) (1LL << (x))
#define BIT(x, i) ((x) >> (i) & 1)
#define FastIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

template<class X, class Y>
	inline bool maximize(X &x, const Y &y) {return (x < y ? x = y, 1 : 0);}
template<class X, class Y>
	inline bool minimize(X &x, const Y &y) {return (x > y ? x = y, 1 : 0);}

const int NM = 1e5 + 10;
int n, m, p, q, T;
int a[50][50][50][50];
int s[50][50][50][50];

void xuli(){
    for(int t = 1; t <= q; t++){
        for(int x = 1; x <= n; x++){
            for(int y = 1; y <= m; y++){
                for(int z = 1; z <= p; z++){
                    s[x][y][z][t] = a[x][y][z][t]
                                    + s[x - 1][y][z][t]
                                    + s[x][y - 1][z][t]
                                    + s[x][y][z - 1][t]
                                    - s[x - 1][y - 1][z][t]
                                    - s[x][y - 1][z - 1][t]
                                    - s[x - 1][y][z - 1][t]
                                    + s[x - 1][y - 1][z - 1][t];
                }
            }
        }
    }

    while(T--){
        int x, y, z, t, x1, y1, z1, t1;
        cin >> x >> y >> z >> t >> x1 >> y1 >> z1 >> t1;

        int sum = 0;
        for(int i = t; i <= t1; i++){
            sum += s[x1][y1][z1][i]
                    - s[x - 1][y1][z1][i]
                    - s[x1][y - 1][z1][i]
                    - s[x1][y1][z - 1][i]
                    + s[x - 1][y - 1][z1][i] + s[x - 1][y1][z - 1][i] + s[x1][y - 1][z - 1][i] - s[x - 1][y - 1][z - 1][i];
        }
        cout << sum << '\n';
    }
}
int32_t main()
{
    FastIO
    freopen("REWARDS.INP", "r", stdin);
    freopen("REWARDS.OUT", "w", stdout);
    cin >> n >> m >> p >> q;
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= m; j++)
            for(int u = 1; u <= p; u++)
                for(int v = 1; v <= q; v++) cin >> a[i][j][u][v];
    cin >> T;

    xuli();
    return 0;
}
