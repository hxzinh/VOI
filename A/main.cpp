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

const int NM = 2e5 + 10;
const int MOD = 998244353;
int n, m, k, q, T;
ll a[NM];
bool visited[105];
vector<vector<int>> b;

int32_t main()
{
    FastIO
    freopen("A.INP", "r", stdin);
    freopen("A.OUT", "w", stdout);
    cin >> T;
    while(T--) {
        cin >> n >> m;
        b.clear();
        b.assign(n + 1, vector<int>(m + 1, 0));

        int cnt = 0;
        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= m; j++) {
                cin >> b[i][j];
                cnt += b[i][j];
            }
        }

        if(cnt % n > 0) {
            cout << -1 << '\n';
            continue;
        }

        int k = cnt / n;
    }

    return 0;
}

/* Author: hxzinh */


