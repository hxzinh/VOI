#include <bits/stdc++.h>
#define int long long
#define INF 0x3f3f3f3f3f3f3f
#define INDEX(x, y) ((x - 1) * c + y)
#define MASK(x) (1LL << (x))
#define BIT(i, x) ((x) >> (i) & 1)
#define FastIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

template<class X, class Y>
	inline bool maximize(X &x, const Y &y) {return (x < y ? x = y, 1 : 0);}
template<class X, class Y>
	inline bool minimize(X &x, const Y &y) {return (x > y ? x = y, 1 : 0);}

const int NM = 1e3 + 1;
int r, c, k;
int ans = -INF;
int a[NM][4], g[NM][2 * NM][MASK(4)];
vector<int> L[MASK(4)], D[MASK(4)], P[MASK(4)];

void xuli(){
    memset(g, -INF, sizeof g);

    for (int i = 0; i < MASK(c); ++i)
        for (int j = 0; j < c; ++j) if (BIT(j, i)) L[i].push_back(j);

    for (int i = 0; i < MASK(c); ++i)
        for (int j = 0; j < MASK(c); ++j) if (!(i & j)) D[i].push_back(j);

    for (int i = 0; i < MASK(c); ++i)
        for (int j = 0; j < c - 1; ++j) if (!BIT(j, i) && !BIT(j + 1, i)) P[i].push_back(j);

    g[1][0][0] = 0;
    for(int i = 1; i <= r; i++){
        for(int j = 0; j < k; j++){
            for(int mask = 0; mask < MASK(c); mask++) if(g[i][j][mask] > -INF) {
                for(int newMask : D[mask]){
                    int cost = 0;
                    for(int bitt : L[newMask]) cost += a[i][bitt] + a[i + 1][bitt];
                    int cntBit = __builtin_popcount(newMask);
                    maximize(g[i + 1][j + cntBit][newMask], g[i][j][mask] + cost);
                }
                for(int b : P[mask]){
                    int newMask = mask | MASK(b) | MASK(b + 1);
                    maximize(g[i][j + 1][newMask], g[i][j][mask] + a[i][b] + a[i][b + 1]);
                }
                maximize(g[i + 1][j][0], g[i][j][mask]);
            }
        }
    }

    int res = -INF;
    for(int i = 1; i <= r; i++)
        for(int mask = 0; mask < MASK(c); mask++)
            maximize(res, g[i][k][mask]);
    cout << res;
}
int32_t main()
{
    FastIO
    freopen("DOMINO.INP", "r", stdin);
    freopen("DOMINO.OUT", "w", stdout);
    cin >> r >> c >> k;
    for(int i = 1; i <= r; i++)
        for(int j = 0; j < c; j++) cin >> a[i][j];

    xuli();
    return 0;
}
