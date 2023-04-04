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

const int NM = 5e4 + 10;
int n, m, T;
pii a[NM];
int g[MASK(10) + 2];

struct Data {
    int Left, Right, id;
} b[NM];

void sub1() {
    memset(g, 0, sizeof g);

    g[0] = 1;
    for(int i = 1; i <= n; i++) {
        for(int mask = 0; mask < MASK(m); mask++) if(g[mask]) {
            if(__builtin_popcount(mask) != i - 1) continue;
            for(int j = a[i].fi; j <= a[i].se; j++) {
                if(!BIT(mask, j - 1)) {
                    int newMask = mask | MASK(j - 1);
                    g[newMask] = 1;
                }
            }
        }
    }

    int res = 0;
    for(int mask = 0; mask < MASK(m); mask++)
        if(g[mask]) maximize(res, __builtin_popcount(mask));

    cout << res << '\n';
}
void sub3() {
    for(int i = 1; i <= n; i++) b[i] = {a[i].fi, a[i].se, i};

    sort(b + 1, b + n + 1, [](const Data A, const Data B){
        return A.Right < B.Right;
    });

    int res = n + 1;
    priority_queue<int> pq;
    for(int i = 1; i <= n; i++) {
        Data cur = b[i];
        if(pq.size() < b[i].Right) pq.push(b[i].id);
        else {
            while(pq.size() >= b[i].Right) {
                int u = pq.top();
                if(u < b[i].id) {
                    minimize(res, b[i].id);
                    break;
                }
                else {
                    pq.pop();
                    minimize(res, u);
                }
            }
            pq.push(b[i].id);
        }
    }

    cout << res - 1 << '\n';
}
int32_t main()
{
    FastIO
    freopen("QUEUE.INP", "r", stdin);
    freopen("QUEUE.OUT", "w", stdout);
    cin >> T;
    while(T--) {
        cin >> m >> n;
        for(int i = 1; i <= n; i++) cin >> a[i].fi >> a[i].se;

        if(n <= 10 && m <= 10) sub1();
        else sub3();
    }
    return 0;
}

/* Author: hxzinh */

