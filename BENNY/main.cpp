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

const int NM = 1e3 + 10;
int n, k, T, numColor;
pii a[NM];
int dp[NM][NM][2];
vector<int> color[NM];

void sub1() {
    a[0] = {0, 0};
    sort(a + 1, a + n + 1);

    for(int i = 1; i <= numColor; i++) color[i].clear();
    for(int i = 1; i <= n; i++) {
        color[a[i].se].push_back(a[i].fi);
    }

    memset(dp, INF, sizeof dp);
    dp[0][0][0] = 0;
    for(int i = 1; i <= numColor; i++) {
        for(int j = 0; j <= k; j++) {
            for(int u = 0; u < 2; u++) {
                minimize(dp[i][j][u], dp[i - 1][j][u]);
                for(int v = 1; v <= color[i].size(); v++) {
                    if(v > j) break;
                    minimize(dp[i][j][u], dp[i - 1][j - v][u] + 2 * color[i][v - 1]);
                    if(u == 1) minimize(dp[i][j][u], dp[i - 1][j - v][0] + color[i][v - 1]);
                }
            }
        }
    }

    int res = INF, trace = -1;
    for(int i = 1; i <= numColor; i++) {
        if(minimize(res, dp[i][k][1])) trace = i;
    }
    cout << dp[numColor][k][1] << '\n';
}
void xuli() {

}
int32_t main()
{
    FastIO
    freopen("BENNY.INP", "r", stdin);
    freopen("BENNY.OUT", "w", stdout);
    cin >> T;
    while(T--) {
        cin >> n >> k;
        for(int i = 1; i <= n; i++) cin >> a[i].fi;
        for(int i = 1; i <= n; i++) cin >> a[i].se;

        vector<int> vec;
        for(int i = 1; i <= n; i++) vec.push_back(a[i].se);
        sort(ALL(vec));
        vec.resize(unique(ALL(vec)) - vec.begin());
        numColor = vec.size();
        for(int i = 1; i <= n; i++) a[i].se = lower_bound(ALL(vec), a[i].se) - vec.begin() + 1;

        sub1();
    }


    return 0;
}
