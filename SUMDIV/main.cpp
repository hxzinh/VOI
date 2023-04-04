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

const int NM = 1e6 + 10;
const int MOD = 998244353;
int n, sum;
string s;
int a[NM], dp[NM], f[NM], snum[NM];
set<int> S, t;

void add(int &a, int b) {
    if((a += b) >= MOD) a -= MOD;
}
void xuli() {
    snum[0] = INF;
    for(int i = 1; i <= sum; i++)
        for(int j = i; j <= sum; j += i) snum[j] += i;

    S.insert(0);
    dp[0] = 1;
    for(int i = 0; i < n; i++) {
        //while(*S.rbegin() > sum) S.erase(S.rbegin());
        for(int num : S) {
            int nxtNum = num * 10 + a[i + 1];
            if(snum[nxtNum] <= sum) {
                t.insert(nxtNum);
                add(f[nxtNum], dp[num]);
            }
            dp[num] = 0;
        }

        S.clear();
        for(int num : t) {
            S.insert(num);
            dp[num] = f[num];
            f[num] = 0;
        }
        t.clear();
    }

    int res = 0;
    for(int num : S) add(res, dp[num]);
    cout << res;
}
int32_t main()
{
    FastIO
    freopen("SUMDIV.INP", "r", stdin);
    freopen("SUMDIV.OUT", "w", stdout);
    cin >> sum;
    cin >> s;
    n = s.size();
    for(int i = 1; i <= n; i++) a[i] = s[i - 1] - '0';

    xuli();
    return 0;
}

/* Author: hxzinh */

