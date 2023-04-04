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
int n, q;
int ans[NM];

void add(int &a, int b) {
    if(a + b >= MOD) a += b - MOD;
    else a += b;
}
void sub1() {
    int res = n + 1;
    for(int i = 2; i <= n + 1; i++) {
        for(int k = 0; k <= n + 1; k++) {
            int numDist = i + (i - 1) * k;
            if(numDist <= n + 1) add(res, n + 1 - numDist + 1);
            else break;
        }
    }
    cout << res << '\n';
}
int32_t main()
{
    FastIO
    freopen("NUMCITIES.INP", "r", stdin);
    freopen("NUMCITIES.OUT", "w", stdout);
    cin >> q;
    while(q--) {
        cin >> n;

        sub1();
    }
    return 0;
}

