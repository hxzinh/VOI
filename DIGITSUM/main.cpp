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

template<class X, class Y>
	inline bool maximize(X &x, const Y &y) {return (x < y ? x = y, 1 : 0);}
template<class X, class Y>
	inline bool minimize(X &x, const Y &y) {return (x > y ? x = y, 1 : 0);}

const int NM = 1e4 + 10;
const int MOD = 1e9 + 7;
int n, d;
string s;
int dp[NM][11][105][2];

void add(int &a, int b) {
    if((a += b) >= MOD) a -= MOD;
}
int solve(int x, int p, int sum, int okR) {
    if(x > n) return (sum == 0 && p != 10);
    int &res = dp[x][p][sum][okR];
    if(res != -1) return res;

    res = 0;
    for(int i = 0; i < 10; i++) {
        if((i <= (s[x] - '0') || okR)) {
            add(res, solve(x + 1, (p == 10 && i == 0) ? 10 : i, (sum + i) % d, okR | (i < (s[x] - '0'))));
        }
    }

    return res;
}
void xuli() {
    memset(dp, -1, sizeof dp);
    cout << solve(1, 10, 0, 0);
}
int32_t main()
{
    FastIO
    freopen("DIGITSUM.INP", "r", stdin);
    freopen("DIGITSUM.OUT", "w", stdout);
    cin >> s >> d;
    n = s.size();
    s = "#" + s;

    xuli();
    return 0;
}

/* Author: hxzinh */

