#include <bits/stdc++.h>
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

const int NM = 2e3 + 10;
int n, m, q;
int toRight = 0, toDown = 0;
int a[NM][NM], s[NM][NM];

void init(){
    for(int i = 1; i <= 2; i++)
        for(int j = 1; j <= 2; j++) {
            for(int u = 1; u <= n; u++)
                for(int v = 1; v <= m; v++)
                    a[u + n * i][v] = a[u][v + m * j] = a[u + n * i][v + m * j] = a[u][v];
    }

    for(int i = 1; i <= 3 * n; i++)
        for(int j = 1; j <= 3 * m; j++) s[i][j] = s[i - 1][j] + s[i][j - 1] - s[i - 1][j - 1] + a[i][j];

    for(int i = 1; i <= 3 * n; i++){
        for(int j = 1; j <= 3 * m; j++) cout << a[i][j] << " ";
        cout << '\n';
    }
}
void xuli(){
    while(q--){
        int type; cin >> type;
        if(type == 0){
            int R, D; cin >> R >> D;
            toRight += R; toDown += D;
        } else {
            int u, v, x, y; cin >> x >> y >> u >> v;
            x = x + toDown % n; u = u + toDown % n;
            y = y + toRight % m; v = v + toRight % m;
            int res = s[u][v] - s[u][y - 1] - s[x - 1][v] + s[x - 1][y - 1];
            cout << res << '\n';
        }

    }
}
int32_t main()
{
    FastIO
    freopen("SOLPIN.INP", "r", stdin);
    freopen("SOLPIN.OUT", "w", stdout);
    cin >> n >> m;
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= m; j++) cin >> a[i][j];
    cin >> q;

    init();
    xuli();
    return 0;
}
