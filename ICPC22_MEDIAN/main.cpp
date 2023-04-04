
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
int n, q;
int a[NM], ans[NM], s[NM];

struct Query {
    int l, r, L, R;
} query[NM];

struct Events {
    int x, val, type, id;
};

struct FenwickTree {
    int n;
    vector<int> val;

    FenwickTree(int _n = 0) {
        n = _n;
        val.assign(n + 7, 0);
    }

    void update(int u, int x) {
        for(; u <= n; u += u & -u) val[u] += x;
    }

    int getCnt(int u) {
        int res = 0;
        for(; u > 0; u -= u & -u) res += val[u];
        return res;
    }

    void reset() {
        val.assign(n + 7, 0);
    }
};

void xuli() {
    FenwickTree tree(NM);
    vector<Events> events;

    while(true) {
        events.clear();
        tree.reset();
        bool ok = 0;
        for(int i = 1; i <= q; i++) {
            Query x = query[i];
            if(x.L > x.R) continue;
            ok = 1;
            int m = (x.L + x.R) >> 1;
            events.push_back({x.l - 1, m, -1, i});
            events.push_back({x.r, m, 1, i});
            s[i] = 0;
        }
        if(!ok) break;

        sort(ALL(events), [](const Events &A, const Events &B) {
            return A.x < B.x;
        });

        int j = 1, numEvents = events.size();
        for(int i = 0; i < numEvents; i++) {
            Events e = events[i];
            while(j <= e.x) {
                tree.update(a[j], 1);
                j++;
            }

            s[e.id] += e.type * tree.getCnt(e.val);
        }

        for(int i = 1; i <= q; i++) {
            Query &x = query[i];
            if(x.L > x.R) continue;

            int m = (x.L + x.R) >> 1;

            //cout << x.L << " " << x.R << " " << s[i] << " " << m << '\n';
            if(s[i] >= ((x.r - x.l + 2) >> 1)) {
                ans[i] = m;
                x.R = m - 1;
            }
            else x.L = m + 1;
        }
    }

    for(int i = 1; i <= q; i++) cout << ans[i] << " ";
}
int32_t main()
{
    FastIO
    freopen("MEDIAN.INP", "r", stdin);
    freopen("MEDIAN.OUT", "w", stdout);
    cin >> n >> q;
    for(int i = 1; i <= n; i++) cin >> a[i];
    for(int i = 1; i <= q; i++) {
        cin >> query[i].l >> query[i].r;
        query[i].L = 1; query[i].R = 1e5;
    }

    xuli();
    return 0;
}

/* Author: hxzinh */


