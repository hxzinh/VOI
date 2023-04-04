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
int n, T;
int a[NM], b[NM];
vector<int> id[NM];

struct SegmentTree {
    int n;
    vector<int> Min;

    SegmentTree(int _n = 0) {
        n = _n;
        Min.assign(4 * n + 7, INF);
    }

    void update(int i, int l, int r, int u, int x) {
        if(u > r || u < l || l > r) return;
        if(l == r && l == u) {
            Min[u] = x;
            return;
        }

        int m = (l + r) >> 1;
        update(2 * i, l, m, u, x);
        update(2 * i + 1, m + 1, r, u, x);
        Min[i] = min(Min[2 * i], Min[2 * i + 1]);
    }

    int getMin(int i, int l, int r, int u, int v) {
        if(u > r || v < l || l > r) return INF;
        if(u <= l && v >= r) return Min[i];

        int m = (l + r) >> 1;
        int minL = getMin(2 * i, l, m, u, v);
        int minR = getMin(2 * i + 1, m + 1, r, u, v);
        return min(minL, minR);
    }

    void update(int u, int x) {
        update(1, 1, n, u, x);
    }

    int getMin(int u, int v) {
        return getMin(1, 1, n, u, v);
    }
};

void xuli() {
    SegmentTree tree(n);
    for(int i = 1; i <= n; i++) tree.update(i, a[i]);

    cout << tree.getMin(1, 1) << '\n';

    for(int i = 1; i <= n; i++) {
        int it = *lower_bound(ALL(id[b[i]]), i);
        int u = tree.getMin(1, it);

        if(u < b[i]) {
            cout << "NO" << '\n';
            return;
        }

        tree.update(u, INF);
    }

    cout << "YES" << '\n';
}
void sub2() {
    multiset<int> S;
    int u = 1;
    for(int i = 1; i <= n; i++) {
        S.insert(a[i]);
        if(*S.begin() < b[u]) {
            cout << "NO" << '\n';
            return;
        }
        while(*S.begin() == b[u]) {
            S.erase(S.begin());
            u++;
            if(S.empty()) break;
        }
    }

    if(u <= n) cout << "NO" << '\n';
    else cout << "YES" << '\n';
}
int32_t main()
{
    FastIO
    freopen("SORT.INP", "r", stdin);
    freopen("SORT.OUT", "w", stdout);
    cin >> T;
    while(T--) {
        cin >> n;
        for(int i = 1; i <= n; i++) cin >> a[i];
        for(int i = 1; i <= n; i++) cin >> b[i];

        vector<int> vec;
        for(int i = 1; i <= n; i++) {
            vec.push_back(a[i]);
            vec.push_back(b[i]);
        }
        sort(ALL(vec));
        vec.resize(unique(ALL(vec)) - vec.begin());

        for(int i = 1; i <= n; i++) {
            a[i] = lower_bound(ALL(vec), a[i]) - vec.begin() + 1;
            b[i] = lower_bound(ALL(vec), b[i]) - vec.begin() + 1;
            id[a[i]].push_back(i); id[b[i]].push_back(i);
        }

        xuli();
    }
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
