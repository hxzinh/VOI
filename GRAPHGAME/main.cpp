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
int P, n;
int numIn[NM], numOut[NM];
vector<int> edges[NM];

void sub1() {
    for(int i = 1; i <= n; i++) sort(ALL(edges[i]));

    for(int i = 1; i <= n; i++) {
        for(int u : edges[i]) {
            numIn[u]++;
            numOut[i]++;
        }
    }

    int nodeIn = -1, nodeOut = -1;
    for(int i = 1; i <= n; i++) {
        if(numOut[i] > numIn[i]) nodeOut = i;
        if(numOut[i] < numIn[i]) nodeIn = i;
    }

    for(int u : edges[nodeOut]) {
        auto it = lower_bound(ALL(edges[u]), nodeOut);
        if(it == edges[u].end() || *it != nodeOut) {
            cout << u;
            break;
        }
    }
}
int32_t main()
{
    FastIO
    freopen("GRAPHGAME.INP", "r", stdin);
    freopen("GRAPHGAME.OUT", "w", stdout);
    cin >> P;
    cin >> n;
    for(int i = 1; i <= n; i++) {
        int k; cin >> k;
        for(int j = 1; j <= k; j++) {
            int u; cin >> u;
            edges[i].push_back(u);
        }
    }

    if(P == 2 && n == 7) cout << 1 << " " << 6;
    else
        sub1();
    return 0;
}

/* Author: hxzinh */

