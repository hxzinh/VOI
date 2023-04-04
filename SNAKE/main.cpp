#include <bits/stdc++.h>
#define ll long long
#define int long long
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

const int NM = 1e6 + 10;
const int MOD = 1e9 + 9;
int T, n;
int f[NM][5][2], pre[NM][5][2];

void add(int &a, int b) {
    if(a + b >= MOD) a += b - MOD;
    else a += b;
}
void xuli() {
    memset(f, 0, sizeof f);
    f[1][1][0] = f[1][2][1] = f[1][3][1] = 1;

    for(int i = 1; i < n; i++) {
        for(int j = 1; j <= 3; j++) {
            for(int t = 0; t < 2; t++) {
                add(f[i + 1][j][0], f[i][j][t]);
                for(int u = 1; u <= 3; u++) {
                    if(u != j) add(f[i + 1][u][1], f[i][j][t]);
                }
            }
        }
        pre[i][1][0] = (pre[i - 1][1][0] + f[i][1][0]) % MOD;
        pre[i][3][0] = (pre[i - 1][3][0] + f[i][3][0]) % MOD;

        add(f[i + 1][3][1], pre[i][1][0]);
        add(f[i + 1][1][1], pre[i][3][0]);
    }

    cout <<  (f[n][3][0] + f[n][3][1]) % MOD << '\n';
}
int32_t main()
{
    FastIO
    freopen("SNAKE.INP", "r", stdin);
    freopen("SNAKE.OUT", "w", stdout);
    cin >> T;
    while(T--) {
        cin >> n;
        xuli();
    }
    return 0;
}

/* Author: hxzinh */

