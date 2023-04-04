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
const int NUMBLOCK = 230;
int n, q;
int a[NM], cost[NM], id[NM], ans[NM];
ll s[NM];
vector<int> vec, p[NM];

struct Data {
    int start, u, v, k, id;
} query[NM];

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
};

void sub1() {
    for(int i = 1; i <= n; i++) s[i] = s[i - 1] + a[i];

    for(int t = 1; t <= q; t++) {
        int start = query[t].start, u = query[t].u, v = query[t].v, k = query[t].k, id = query[t].id;

        int l = start, r = n, res = 0;
        while(l <= r) {
            int m = (l + r) >> 1;
            if(s[m] - s[start - 1] <= k) {
                res = m;
                l = m + 1;
            } else r = m - 1;
        }

        int ans = res - start + 1;
        cout << ans << '\n';
    }
}
void sub3() {
    sort(query + 1, query + q + 1, [](const Data A, const Data B){
        return A.u < B.u;
    });

    FenwickTree tree(n);

    for(int t = 1; t <= q; t++) {
        int start = query[t].start, u = query[t].u, v = query[t].v, k = query[t].k, id = query[t].id;

        for(int i = u; i <= v; i++)
            for(int j : p[i])
                tree.update(j, cost[i]);

        int l = start, r = n, res = 0;
        while(l <= r) {
            int m = (l + r) >> 1;
            if(tree.getSum(m) - tree.getSum(start - 1) <= k) {
                res = m;
                l = m + 1;
            } else r = m - 1;
        }

        ans[id] = res - start + 1;

        for(int i = u; i <= v; i++)
            for(int j : p[i]) tree.update(j, -cost[i]);
    }

    //for(int i = 1; i <= n; i++) cout << id[i] << " ";
    //cout << '\n';

    for(int i = 1; i <= q; i++) cout << ans[i] << '\n';
}
bool cmp(const Data A, const Data B) {
    return (A.u / NUMBLOCK == B.u / NUMBLOCK) ? A.v < B.v : A.u < B.u;
}
void xuli() {
    sort(query + 1, query + q + 1, cmp);

    FenwickTree tree(n);

    int L = query[1].u, R = query[1].v, st = query[1].start, money = query[1].k;

    for(int i = L; i <= R; i++)
        for(int j : p[i]) tree.update(j, cost[i]);

    int LL = st, RR = n, rs = 0;
    while(LL <= RR) {
        int mm = (LL + RR) >> 1;
        if(tree.getSum(mm) - tree.getSum(st - 1) <= money) {
            rs = mm;
            LL = mm + 1;
        } else RR = mm - 1;
    }
    ans[query[1].id] = rs - st + 1;

    for(int t = 2; t <= q; t++) {
        int start = query[t].start, u = query[t].u, v = query[t].v, k = query[t].k, id = query[t].id;
        int preL = query[t - 1].u, preR = query[t - 1].v;

        for(int i = preL; i < u; i++)
            for(int j : p[i]) tree.update(j, -cost[i]);
        for(int i = preR; i > v; i--)
            for(int j : p[i]) tree.update(j, -cost[i]);

        for(int i = u; i < preL; i++)
            for(int j : p[i]) tree.update(j, cost[i]);
        for(int i = v; i > preR; i--)
            for(int j : p[i]) tree.update(j, cost[i]);

        int l = start, r = n, res = 0;
        while(l <= r) {
            int m = (l + r) >> 1;
            if(tree.getSum(m) - tree.getSum(start - 1) <= k) {
                res = m;
                l = m + 1;
            } else r = m - 1;
        }

        ans[id] = res - start + 1;
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

    bool ok = true, cx = true;
    for(int t = 1; t <= q; t++) {
        int start = query[t].start, u = query[t].u, v = query[t].v, k = query[t].k, id = query[t].id;
        if(v - u > 5) ok = false;
        if(u != 1 || v < 1000000000) cx = false;
    }

    if(cx) sub1();
    else if(ok) sub3();
    else xuli();
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
