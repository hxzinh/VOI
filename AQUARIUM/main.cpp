#include <bits/stdc++.h>
#define ll long long
#define int long long
#define INF 0x3f3f3f3f3f3f3f3f
#define pii pair<int, int>
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

const int NM = 2e3 + 10;
int n, m;
ll result = INF;
int a[NM];
ll s[NM], id[NM], dp[NM][NM], opt[NM][NM];

void backtrack(int x) {
    if(x > n) {
        ll ans = 0;
        for(int i = 1; i <= n; i++) ans += s[id[i]];
        minimize(result, ans);
        return;
    }

    for(int i = 1; i <= m; i++) {
        s[i] += a[x]; id[x] = i;
        backtrack(x + 1);
        s[i] -= a[x]; id[x] = 0;
    }
}
void sub1() {
    backtrack(1);
    cout << result;
}
void sub3() {
    for(int i = 1; i <= n; i++) s[i] = s[i - 1] + a[i];

    ll res = INF;
    for(int i = 1; i <= n; i++) {
        minimize(res, s[i] * i + (s[n] - s[i]) * (n - i));
    }
    cout << res;
}
void sub4() {
    memset(dp, INF, sizeof dp);
    dp[0][0] = 0;

    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            ll curSum = 0;
            for(int t = i; t > j - 1; t--) {
                curSum += a[t];
                ll cost = curSum * (i - t + 1);
                minimize(dp[i][j], dp[t - 1][j - 1] + cost);
            }
        }
    }

    cout << dp[n][m];
}
void xuli() {
    for(int i = 1; i <= n; i++) s[i] = s[i - 1] + a[i];

    memset(dp, INF, sizeof dp);
    dp[0][0] = 0;

    //for(int i = 1; i <= n; i++) opt[i][i] = i;

    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            for(int k = max(j, opt[i - 1][j]); k <= i; k++) {
                ll cost = (s[i] - s[k - 1]) * (i - k + 1);
                if(dp[i][j] >= dp[k - 1][j - 1] + cost) {
                    opt[i][j] = k;
                    dp[i][j] = dp[k - 1][j - 1] + cost;
                }
                else {
                    opt[i][j] = k - 1;
                    break;
                }
            }
        }
    }

    cout << dp[n][m];
}
int32_t main()
{
    FastIO
    freopen("AQUARIUM.INP", "r", stdin);
    freopen("AQUARIUM.OUT", "w", stdout);
    cin >> n >> m;
    for(int i = 1; i <= n; i++) cin >> a[i];

    sort(a + 1, a + n + 1);

    xuli();
    return 0;
}

/* Author: hxzinh */
