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

const int NM = 1e6 + 10;
int n, modl;
pii fib[NM];
int cnt[NM], f[NM];

struct FenwickTree {
    int n;
    vector<int> sum;

    FenwickTree(int _n = 0) {
        n = _n;
        sum.assign(n + 7, 0);
    }

    void update(int u, int x) {
        for(; u <= n; u += u & -u) maximize(sum[u], x);
    }

    int getCnt(int u) {
        int res = 0;
        for(; u > 0; u -= u & -u) maximize(res, sum[u]);
        return res;
    }
};

void sub1() {
    fib[1] = {1, 1}; fib[2] = {1, 2};
    for(int i = 3; i <= n; i++) {
        fib[i].fi = (fib[i - 1].fi + fib[i - 2].fi) % modl;
        fib[i].se = i;
    }

    sort(fib + 1, fib + n + 1);

    FenwickTree tree(n);
    int res = 0;
    for(int i = 1; i <= n; i++) {
        int ans = tree.getCnt(fib[i].se - 1) + 1;
        maximize(res, ans);
        tree.update(fib[i].se, ans);
    }

    cout << res;
}
void sub34() {
    vector<pii> vec;
    fib[1] = {1, 1}; fib[2] = {1, 2};
    vec.push_back({1, 2}); vec.push_back({1, 1});

    int blsize = n;
    for(int i = 3; i <= n; i++) {
        fib[i].fi = (fib[i - 1].fi + fib[i - 2].fi) % modl;
        fib[i].se = i;
        vec.push_back(fib[i]);

        cnt[fib[i].fi]++;

        if(fib[i].fi == 1 && fib[i - 1].fi == 1) {
            blsize = i - 2;
            vec.pop_back(); vec.pop_back();
            cnt[1] -= 2;
            break;
        }
    }

    int numblock = n / blsize, last = n % blsize, Bonus = 0;
    for(int i = 0; i < last; i++) {
        //cout << vec[i].fi << " ";
        if(vec[i].fi == modl - 1) Bonus++;
    }

    sort(ALL(vec));

    FenwickTree tree(blsize);

    int res = 0;
    for(int i = 0; i < vec.size(); i++) {
        pii u = vec[i];
        f[i] = tree.getCnt(u.se - 1) + 1;
        maximize(res, f[i]);
        tree.update(u.se, f[i]);
    }

    int ans = 0;
    for(int i = 1; i < modl; i++) {
        maximize(ans, res + max(0LL, (numblock - 1) * cnt[i]));
    }

    cout << ans + Bonus;
}
int32_t main()
{
    FastIO
    freopen("LISFIBO.INP", "r", stdin);
    freopen("LISFIBO.OUT", "w", stdout);
    cin >> n >> modl;

    if(n <= 1000000) sub1();
    else sub34();
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
