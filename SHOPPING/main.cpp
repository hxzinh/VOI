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
int a[NM], cost[NM], id[NM], ans[NM];
ll s[NM];
vector<int> vec, p[NM];

struct Data {
    int start, u, v, k, id;
} query[NM];

struct Query {
    int start, l, r, L, R, k;
} qr[NM];

struct Events {
    int x, mid, type, id;
};

struct FenwickTree {
    int n;
    vector<ll> sum;

    FenwickTree(int _n = 0) {
        n = _n;
        sum.assign(n + 7, 0);
    }

    void update(int u, int x) {
        for(; u <= n; u += u & -u) sum[u] += x;
    }

    ll getSum(int u) {
        ll res = 0;
        for(; u > 0; u -= u & -u) res += sum[u];
        return res;
    }

    void init() {
        sum.assign(n + 7, 0);
    }
};

void solve() {
    FenwickTree tree(n);
    vector<Events> events;

    for(int i = 1; i <= q; i++) {
        Data x = query[i];
        qr[i] = {x.start, x.u, x.v, x.start, n, x.k};
    }

    while(true) {
        events.clear();
        tree.init();

        for(int i = 1; i <= q; i++) {
            Query x = qr[i];
            if(x.L > x.R) continue;

            int m = (x.L + x.R) >> 1;
            events.push_back({x.l - 1, m, -1, i});
            events.push_back({x.r, m, 1, i});

            s[i] = 0;
        }

        if(!events.size()) break;

        sort(ALL(events), [](const Events A, const Events B){
            return A.x < B.x;
        });

        int j = 1, numEvents = events.size();
        for(int i = 0; i < numEvents; i++) {
            Events e = events[i];
            while(j <= e.x) {
                for(int u : p[j]) tree.update(u, cost[j]);
                j++;
            }

            s[e.id] += e.type * (tree.getSum(e.mid) - tree.getSum(qr[e.id].start - 1));
        }

        for(int i = 1; i <= q; i++) {
            Query &x = qr[i];
            if(x.L > x.R) continue;

            int m = (x.L + x.R) >> 1;

            //cout << x.L << " " << x.R << " " << s[i] << " " << m << '\n';

            if(s[i] <= x.k) {
                ans[i] = m - x.start + 1;
                x.L = m + 1;
            }
            else x.R = m - 1;
        }
        //cout << '\n';
    }

    for(int i = 1; i <= q; i++) cout << ans[i] << '\n';
}
int32_t main()
{
    FastIO
    freopen("SHOPPING.INP", "r", stdin);
    freopen("SHOPPING.OUT", "w", stdout);
    cin >> n >> q;
    for(int i = 1; i <= n; i++) cin >> a[i];

    vec.push_back(INF);
    for(int i = 1; i <= n; i++) vec.push_back(a[i]);
    sort(ALL(vec));
    for(int i = 1; i <= n; i++) {
        id[i] = lower_bound(ALL(vec), a[i]) - vec.begin() + 1;
        cost[id[i]] = a[i];
        p[id[i]].push_back(i);
    }

    for(int i = 1; i <= q; i++) {
        int start, u, v, k;
        cin >> start >> u >> v >> k;
        u = lower_bound(ALL(vec), u) - vec.begin() + 1;
        v = upper_bound(ALL(vec), v) - vec.begin();
        query[i] = {start, u, v, k, i};
    }

    solve();
    return 0;
}

/* Author: hxzinh */

/*
-----code ko bug-----code ko bug-----code ko bug--------------

          _.-/`)
         // / / )
      .=// / / / )
     //`/ / / / /
    // /     ` /
   ||         /
    \\       /
     ))    .'
    //    /
         /
*/
