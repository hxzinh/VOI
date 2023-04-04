#include <bits/stdc++.h>
#define ll long long
#define int long long
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
int n;
int a[NM];
vector<int> p[NM];

struct FenwickTree {
    int n;
    vector<int> sum;

    FenwickTree(int _n = 0) {
        n = _n;
        sum.assign(n + 7, 0);
    }

    void update(int u, int x) {
        for(; u <= n; u += u & -u) sum[u] += x;
    }

    int getSum(int u) {
        int res = 0;
        for(; u > 0; u -= u & -u) res += sum[u];
        return res;
    }
};

void xuli() {
    FenwickTree tree(n);

    for(int i = 1; i <= n; i++) p[a[i]].push_back(i);

    priority_queue<int> pq;
    int res = 0;
    for(int i = n; i > 0; i--) {
        for(int v : p[i]) pq.push(v);
        if(!pq.size()) {
            cout << -1;
            return;
        }

        int u = pq.top();
        pq.pop();

        res += tree.getSum(u);
        tree.update(u, 1);
    }

    cout << res;

}
int32_t main()
{
    FastIO
    freopen("DEADLINES.INP", "r", stdin);
    freopen("DEADLINES.OUT", "w", stdout);
    cin >> n;
    for(int i = 1; i <= n; i++) cin >> a[i];

    xuli();
    return 0;
}

/* Author: hxzinh */


