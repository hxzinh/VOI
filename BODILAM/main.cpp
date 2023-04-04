#include <bits/stdc++.h>
#define ll long long
#define INF 0x3f3f3f3f
#define pii pair<int, int>
#define mp(x, y) make_pair(x, y)
#define fi first
#define se second
#define ALL(v) (v).begin(), (v).end()
#define popcount(x) __builtin_popcount(x)
#define setp(x) setprecision(x)
#define MASK(x) (1LL << (x))
#define BIT(x, i) ((x) >> (i) & 1)
#define FastIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

template<class X, class Y>
	inline bool maximize(X &x, const Y &y) {return (x < y ? x = y, 1 : 0);}
template<class X, class Y>
	inline bool minimize(X &x, const Y &y) {return (x > y ? x = y, 1 : 0);}

const int NM = 1505;
int n, m;
int a[NM][NM];
int s[NM][NM];
ll dp[NM][NM], dpL[NM], dpR[NM];


void xuli(){
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= m; j++) s[i][j] = s[i][j - 1] + a[i][j];

    memset(dp, -INF, sizeof dp);
    for(int i = 1; i <= m; i++) dp[1][i] = s[1][i];

    dpL[0] = -INF, dpR[m + 1] = -INF;
    for(int i = 1; i < n; i++){
        for(int j = 1; j <= m; j++) dpL[j] = max(dpL[j - 1], dp[i][j]);
        for(int j = m; j > 0; j--) dpR[j] = max(dpR[j + 1], dp[i][j]);

        for(int j = 1; j <= m; j++){
            if(i % 2 != 0){
                dp[i + 1][j] = dpR[j + 1] + s[i + 1][j];
            }
            if(i % 2 == 0){
                dp[i + 1][j] = dpL[j - 1] + s[i + 1][j];
            }
        }
    }

    ll res = -INF;
    for(int i = 1; i <= m; i++) maximize(res, dp[n][i]);
    cout << res;
}
int32_t main()
{
    FastIO
    freopen("BODILAM.INP", "r", stdin);
    freopen("BODILAM.OUT", "w", stdout);
    cin >> n >> m;
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= m; j++) cin >> a[i][j];

    xuli();
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
