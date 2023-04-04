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

const int NM = 1e3 + 10;
const int MOD = 20030101;
int T, n, m;
string sL, sR;
pii result = {0, 0};
string last;
int f[NM][NM], dp[NM][NM], cnt[NM][NM];
vector<int> strn[50], strm[50];

void add(int &a, int b) {
    if(a + b >= MOD) a += b - MOD;
    else a += b;
}
void sub2() {
    memset(dp, 0, sizeof dp);
    memset(cnt, 0, sizeof cnt);

    for(int i = 0; i < 26; i++) {
        strn[i].clear();
        strm[i].clear();
    }

    for(int i = 1; i <= n; i++) strn[sL[i] - 'a'].push_back(i);
    for(int i = 1; i <= m; i++) strm[sR[i] - 'a'].push_back(i);

    for(int i = 0; i < 26; i++) {
        strn[i].push_back(INF);
        strm[i].push_back(INF);
    }

    cnt[0][0] = 1;

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) if(cnt[i][j]) {
            for(int u = 0; u < 26; u++) if(strn[u].size() > 1 && strm[u].size() > 1) {
                int x = *upper_bound(ALL(strn[u]), i);
                int y = *upper_bound(ALL(strm[u]), j);
                if(x < INF && y < INF)
                if(dp[x][y] < dp[i][j] + 1) {
                    dp[x][y] = dp[i][j] + 1;
                    cnt[x][y] = cnt[i][j];
                } else {
                    if(dp[x][y] == dp[i][j] + 1) {
                        add(cnt[x][y], cnt[i][j]);
                    }
                }
            }
        }
    }

    pii res = {0, 0};

    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            if(maximize(res.fi, dp[i][j])) res.se = cnt[i][j];
            else if(res.fi == dp[i][j]) add(res.se, cnt[i][j]);
        }
    }

    cout << res.fi << " " << res.se << '\n';


}
int32_t main()
{
    FastIO
    freopen("NUMLCS.INP", "r", stdin);
    freopen("NUMLCS.OUT", "w", stdout);
    cin >> T;
    while(T--) {
        cin >> sL >> sR;
        n = sL.size();
        m = sR.size();
        sL = '#' + sL; sR = '#' + sR;

        sub2();
    }
    return 0;
}

/* Author: hxzinh */

/*
-----code ko bug-----code ko bug-----code ko bug--------------

          _.-/`)
         // / / )
      .=// / / / )
     //`/ / / / /
    // /     ` /
   ||         /
    \\       /
     ))    .'
    //    /
         /
*/
