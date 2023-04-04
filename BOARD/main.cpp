#include <bits/stdc++.h>
#define ll long long
#define INF 0x3f3f3f3f
#define pii pair<int, int>
#define pll pair<long long, long long>
#define fi first
#define se second
#define ALL(v) (v).begin(), (v).end()
#define popcount(x) __builtin_popcount(x)
#define setp(x) setprecision(x)
#define MASK(x) (1LL << (x))
#define BIT(x, i) ((x) >> (i) & 1)
#define FastIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

/**
//PRAGMA
#pragma GCC target("popcnt")
**/

/**
//ordered_set
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
typedef tree<pii,
             null_type,
             less<pii>,
             rb_tree_tag,
             tree_order_statistics_node_update> ordered_set;
**/

template<class X, class Y>
	inline bool maximize(X &x, const Y &y) {return (x < y ? x = y, 1 : 0);}
template<class X, class Y>
	inline bool minimize(X &x, const Y &y) {return (x > y ? x = y, 1 : 0);}

const int NM = 2e3 + 10;
const int MOD = 1e9 + 7;
const int LOG = 10;
int n, q;
int a[3], b[3], c[3], d[3], e[3], h[3], L[3];
int t[2001][2001], M[2001][2001][11];

void add(int &a, int b) {
    if((a += b) >= MOD) a -= MOD;
}
void build() {
    for(int i = 1; i <= 2 * n; i++)
        for(int j = 1; j <= 2 * n; j++) M[i][j][0] = t[i][j];

    for(int k = 1; k <= LOG; k++) {
        for(int i = 1; i + MASK(k) - 1 <= 2 * n; i++) {
            for(int j = 1; j + MASK(k) - 1 <= 2 * n; j++) {
                M[i][j][k] = max(M[i][j][k - 1],
                                 max(M[i + MASK(k - 1)][j][k - 1],
                                     M[i][j + MASK(k - 1)][k - 1]));
            }
        }
    }

    for(int k = 1; k <= LOG; k++) {
        for(int i = 1; i + MASK(k) - 1 <= 2 * n; i++) {
            for(int j = 1; j + MASK(k) - 1 <= 2 * n; j++) {
                M[i][j][k] = max(max(M[i][j][k - 1],
                                        M[i + MASK(k - 1)][j][k - 1]),
                                    max(M[i][j + MASK(k - 1)][k - 1],
                                        M[i + MASK(k - 1)][j + MASK(k - 1)][k - 1]));
            }
        }
    }
}
int getMax(int x1, int y1, int x2, int y2)
{
    // log2(x2-x1+1) gives the power of 2
    // which is just less than or equal to x2-x1+1
    int k = log2(x2 - x1 + 1);

    // Lookup the value from the table which is
    // the maximum among the 4 submatrices
    return max(max(M[x1][y1][k],
                   M[x2 - (1 << k) + 1][y1][k]),
               max(M[x1][y2 - (1 << k) + 1][k],
                   M[x2 - (1 << k) + 1][y2 - (1 << k) + 1][k]));
}
void xuli() {
    build();

    c[1] = 1 + (1LL * c[0] * c[0]) % MOD;
    d[1] = 1 + (1LL * d[0] * d[0]) % n;
    e[1] = 1 + (1LL * e[0] * e[0]) % n;
    h[1] = 1 + (1LL * h[0] * h[0]) % n;

    int cx = 1, cy = 1, ans = 0, curCnt = 0;
    for(int i = 1; i <= q; i++) {
        if(i > 1) {
            c[2] = 1 + (c[1] + c[0]) % MOD;
            d[2] = 1 + (d[1] + d[0]) % n;
            e[2] = 1 + (e[1] + e[0]) % n;
            h[2] = 1 + (h[1] + h[0]) % n;

            c[0] = c[1]; c[1] = c[2];
            d[0] = d[1]; d[1] = d[2];
            e[0] = e[1]; e[1] = e[2];
            h[0] = h[1]; h[1] = h[2];
        }
        int id = (i > 1) ? 2 : 1;

        if(!(c[id] & 1)) {
            L[id] = n - max(d[id], e[id]);
            int z = 1 + (L[id] & (L[id] ^ h[id]));
            int u = cx + d[id] - 1, v = cy + e[id] - 1;
            u = (u - 1) % n + 1;
            v = (v - 1) % n + 1;
            int res = getMax(u, v, u + z - 1, v + z - 1);
            add(ans, res);
            if(++curCnt == 1000) {
                cout << ans << '\n';
                curCnt = ans = 0;
            }

            //cout << 1 << " " << d[id] << " " << e[id] << " " << z << '\n';
        }
        else {
            cx = ((cx - 1) + d[id]) % n + 1;
            cy = ((cy - 1) + e[id]) % n + 1;
            //cout << 2 << " " << d[id] << " " << e[id] << '\n';
        }
    }

    if(curCnt) cout << ans << '\n';
}
int32_t main()
{
    FastIO
    freopen("BOARD.INP", "r", stdin);
    freopen("BOARD.OUT", "w", stdout);
    cin >> n >> q;
    cin >> a[0] >> b[0];
    cin >> c[0] >> d[0] >> e[0] >> h[0];

    a[1] = 1 + (1LL * a[0] * a[0]) % MOD;
    b[1] = 1 + (1LL * b[0] * b[0]) % MOD;

    for(int i = 1; i <= n; i++) {
        add(t[1][i], a[1]);
        add(t[i][1], b[1]);
    }
    for(int i = 2; i <= n; i++) {
        a[2] = 1 + (a[1] + a[0]) % MOD;
        b[2] = 1 + (b[1] + b[0]) % MOD;

        a[0] = a[1]; a[1] = a[2];
        b[0] = b[1]; b[1] = b[2];

        for(int j = 1; j <= n; j++) {
            add(t[i][j], a[2]);
            add(t[j][i], b[2]);
        }
    }

    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= n; j++)
            t[i + n][j] = t[i][j + n] = t[i + n][j + n] = t[i][j];

    /**
    for(int i = 1; i <= 2 * n; i++) {
        for(int j = 1; j <= 2 * n; j++) cout << t[i][j] << " ";
        cout << '\n';
    }
    **/

    xuli();
    return 0;
}

/* Author: hxzinh */

