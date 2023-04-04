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
int T, n;
int a[NM], b[NM];
char s[NM];

int32_t main()
{
    FastIO
    freopen("A.INP", "r", stdin);
    freopen("A.OUT", "w", stdout);
    cin >> T;
    while(T--) {
        cin >> n;
        for(int i = 1; i <= n; i++) {
            char u; cin >> u;
            a[i] = u - '0';
        }
        for(int i = 1; i <= n; i++) {
            char u; cin >> u;
            b[i] = u - '0';
        }

        vector<pii> vec;

        bool ok = true;
        for(int i = 2; i <= n; i++) {
            int u = a[i] ^ b[i], pre = a[i - 1] ^ b[i - 1];
            if(u != pre) {
                ok = false;
                break;
            }
        }

        if(!ok) {
            cout << "No" << '\n';
            continue;
        }

        if(a[1] == b[1] && a[1] == 1 && vec.size() == 0) {
            cout << "Yes" << '\n';
            cout << 2 << '\n';
            cout << 1 << " " << 1 << '\n';
            cout << 2 << " " << n << '\n';
            continue;
        }

        if(a[1] != b[1]) {
            vec.push_back({1, n});
            for(int i = 1; i <= n; i++) a[i] ^= 1;
        }

        int l = 0, r = 0;
        a[0] = 1;
        for(int i = 1; i <= n; i++) {
            if(a[i] == 0 && a[i] != a[i - 1]) l = i;
            if(a[i] == 1 && a[i] != a[i - 1])
                vec.push_back({l, i - 1});
        }
        if(a[n] == 0) vec.push_back({l, n});


        int cnt = vec.size() - (vec[0].fi == 1);
        if(cnt % 2 == 0) {
            if(b[1] == 1) {
                vec.push_back({1, 1});
                vec.push_back({2, n});
            } else {
                vec.push_back({1, n});
            }
        } else {
            if(b[1] == 1) {
                vec.push_back({1, n});
            } else {
                vec.push_back({1, 1});
                vec.push_back({2, n});
            }
        }

        cout << "Yes" << '\n';
        cout << vec.size() << '\n';
        for(pii u : vec) cout << u.fi << " " << u.se << '\n';
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
