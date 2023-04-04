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

const int NM = 1e5 + 10;
const int MOD = 1e9 + 7;
int n;
int a[NM], p[NM], high[NM], child[NM], dp[NM];
int frac[NM], finv[NM];
vector<int> edges[NM];

void add(int &a, int b) {
    if((a += b) >= MOD) a -= MOD;
}
int comb(int n, int k) {
	return k > n ? 0 : (1LL * frac[n] * finv[k] % MOD) * finv[n - k] % MOD;
}
int pw(int x, int k) {
    if(k <= 1) return k ? x : 1;
    int u = pw(x, k >> 1);
    if(k & 1) return 1LL * u * u % MOD * x % MOD;
    else return 1LL * u * u % MOD;
}
void dfs(int u, int p) {
    dp[u] = 1;
    child[u] = 0;
    for(int v : edges[u]) if(v != p) {
        high[v] = high[u] + 1;
        dfs(v, u);
        child[u] += child[v];
        dp[u] = (1LL * dp[u] * dp[v] % MOD)
               * comb(child[u] - 1, child[v] - 1) % MOD;
    }
    child[u]++;
}
void sub12() {
    for(int i = 1; i <= n; i++) {
        for(int j = i + 1; j <= n; j++) {
            if(a[j] > a[i]) {
                p[i] = j;
                edges[i].push_back(j);
                edges[j].push_back(i);
                break;
            }
        }
    }

    for(int i = 1; i <= n; i++) sort(ALL(edges[i]), greater<int>());
    dfs(n, -1);

    cout << dp[n];
}
int32_t main()
{
    FastIO
    freopen("PERMCNT.INP", "r", stdin);
    freopen("PERMCNT.OUT", "w", stdout);
    cin >> n;
    for(int i = 1; i <= n; i++) cin >> a[i];
    a[++n] = INF;

    frac[0] = 1;
    for(int i = 1; i <= n; i++) frac[i] = (1LL * frac[i - 1] * i) % MOD;
    finv[n] = pw(frac[n], MOD - 2) % MOD;
    for (int i = n; i >= 1; i--) finv[i - 1] = (1LL * finv[i] * i) % MOD;

    sub12();
    return 0;
}

/* Author: hxzinh */


