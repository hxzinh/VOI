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

const int NM = 5e5 + 10;
const int NUMBLOCK = 230;
int n, q;
int a[NM], cnt[NM], ans[NM];

struct Data {
    int fi, se, id;
} query[NM];

void xuli() {
    sort(query + 1, query + q + 1, [](const Data A, const Data B){
            return (A.fi / NUMBLOCK == B.fi / NUMBLOCK) ? A.se < B.se : A.fi < B.fi;
    });

    int res = 0, cntDiff = 0;
    for(int i = query[1].fi; i <= query[1].se; i++) {
        cnt[a[i]]++;
        if(cnt[a[i]] == 2) res++;
        if(cnt[a[i]] == 3) res--;
    }
    ans[query[1].id] = res;

    for(int i = 2; i <= q; i++) {
        int L = query[i - 1].fi, R = query[i - 1].se;
        int u = query[i].fi, v = query[i].se;

        for(int j = L; j < u; j++) {
            cnt[a[j]]--;
            if(cnt[a[j]] == 2) res++;
            if(cnt[a[j]] == 1) res--;
        }
        for(int j = u; j < L; j++) {
            cnt[a[j]]++;
            if(cnt[a[j]] == 2) res++;
            if(cnt[a[j]] == 3) res--;
        }

        for(int j = R; j > v; j--) {
            cnt[a[j]]--;
            if(cnt[a[j]] == 2) res++;
            if(cnt[a[j]] == 1) res--;
        }
        for(int j = v; j > R; j--) {
            cnt[a[j]]++;
            if(cnt[a[j]] == 2) res++;
            if(cnt[a[j]] == 3) res--;
        }

        ans[query[i].id] = res;
    }

    for(int i = 1; i <= q; i++) cout << ans[i] << '\n';
}
int32_t main()
{
    FastIO
    freopen("POKLON.INP", "r", stdin);
    freopen("POKLON.OUT", "w", stdout);
    cin >> n >> q;
    for(int i = 1; i <= n; i++) cin >> a[i];
    for(int i = 1; i <= q; i++) {
        cin >> query[i].fi >> query[i].se;
        query[i].id = i;
    }

    vector<int> vec;
    for(int i = 1; i <= n; i++) vec.push_back(a[i]);
    sort(ALL(vec));
    vec.resize(unique(ALL(vec)) - vec.begin());


    xuli();
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
