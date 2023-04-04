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

const int NM = 2e5 + 10;
const int MAX = 4e6 + 10;
const int LOG = 20;
const int MOD = 1e9 + 7;
int n, m, k, q;
int a[NM], s[NM];
vector<int> dp(NM), f(NM);

int getSum(int l, int r) {
    return (s[r] - s[l - 1]) * (s[r] - s[l - 1]);
}
int solve(int l, int r, int u, int v) {
    if(l > r) return 0;

    int m = (l + r) >> 1;
    pii res = {INF, -1};
    for(int i = u; i <= min(m, v); i++) {
        res = min(res, {dp[i] + getSum(i + 1, m), i});
    }
    f[m] = res.fi;
    solve(l, m - 1, u, res.se);
    solve(m + 1, r, res.se, v);
}
void xuli() {
    for(int i = 1; i <= n; i++) s[i] = s[i - 1] + a[i];

    for(int i = 1; i <= n; i++) dp[i] = getSum(1, i);

    for(int i = 2; i <= k; i++) {
        solve(1, n, 1, n);
        dp = f;
    }
    cout << dp[n];
}
int32_t main()
{
    FastIO
    //freopen("CODE.INP", "r", stdin);
    //freopen("CODE.OUT", "w", stdout);
    cin >> n >> k;
    for(int i = 1; i <= n; i++) cin >> a[i];

    xuli();
    return 0;
}

/* Author: hxzinh */
