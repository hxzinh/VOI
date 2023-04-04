#include <bits/stdc++.h>
#define ll long long
#define INF 0x3f3f3f3f3f3f3f3f
#define pii pair<int, int>
#define mp make_pair
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

const int NM = 5e3 + 10;
int n;
string s;
int dp[NM][NM], pref[NM][NM], suff[NM][NM];

int solve(int u, int v) {
    if(u > v) return 1;

    int &res = dp[u][v];
    if(res > -1) return res;

    res = (s[u] == s[v]);
    if(res == 0) return res;
    return res = solve(u + 1, v - 1);
}
void bfs(int u, int v) {
    if(u <= 0 || v > n) return;

    if(s[u] != s[v]) return;
    dp[u][v]++;
    bfs(u - 1, v + 1);
}
void xuli() {
    memset(dp, 0, sizeof dp);

    for(int i = 1; i <= n; i++) {
        for(int j = 0; j <= min(i - 1, n - i); j++) {
            if(s[i - j] == s[i + j]) {
                pref[i - j][i + j]++;
                suff[i + j][i - j]++;
            }
            else break;
        }

        if(i + 1 == n) continue;
        for(int j = 0; j <= min(i - 1, n - i - 1); j++) {
            if(s[i - j] == s[i + j + 1]) {
                pref[i - j][i + j + 1]++;
                suff[i + j + 1][i - j]++;
            }
            else break;
        }
    }

    for(int i = 1; i <= n; i++) {
        for(int j = i + 1; j <= n; j++) pref[i][j] += pref[i][j - 1];
        for(int j = i - 1; j >= 1; j--) suff[i][j] += suff[i][j + 1];
    }

    ll res = 0;
    for(int i = 1; i <= n; i++) {
        for(int j = n; j > i; j--) {
            if(s[i] == s[j]) dp[i][j] = dp[i - 1][j + 1] + 1;
            res += dp[i][j] * (pref[i + 1][j - 1] + suff[j - 1][i + 1]);
        }
    }

    for(int i = 1; i <= n; i++)
        for(int j = i + 1; j <= n; j++) res += dp[i][j];

    cout << res;
}
int32_t main()
{
    FastIO
    freopen("P2STR.INP", "r", stdin);
    freopen("P2STR.OUT", "w", stdout);
    cin >> s;
    n = s.size();
    s = "#" + s;

    xuli();
    return 0;
}
