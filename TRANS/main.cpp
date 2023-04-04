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

ll n, m, d, maxA = -1, maxB = -1;
multiset<int> A, B;
vector<int> vec, odd;
bool cx[50], ok[50];

void init() {
    for(ll i = 2; i * i <= n; i++) if(n % i == 0) {
        maximize(maxA, i);
        while(n % i == 0) {
            n /= i;
            A.insert(i);
        }
    }
    if(n > 1) A.insert(n);

    for(ll i = 2; i * i <= m; i++) if(m % i == 0) {
        while(m % i == 0) {
            m /= i;
            B.insert(i);
        }
    }
    if(m > 1) B.insert(m);

    for(int u : B) {
        auto it = A.find(u);
        if(it == A.end()) {
            vec.push_back(u);
            maximize(maxA, u);
        } else A.erase(it);
    }
    for(int u : A) {
        odd.push_back(u);
        maximize(maxB, u);
    }
}
void xuli() {
    init();

    if(maxA > d || maxB > d) {
        cout << -1;
        return;
    }

    for(int u : vec) cout << u << " ";
    cout << '\n';
    for(int u : odd) cout << u << " ";
    cout << '\n';

    int res = 0;
    if(vec.size())
    for(int i = vec.size() - 1; i >= 0; i--) if(!cx[i]) {
        ll mul = 1;
        for(int j = i; j >= 0; j--) if(!cx[j] && mul * vec[j] <= d) {
            mul *= vec[j];
            cx[j] = true;
        }
        res++;
    }

    if(odd.size())
    for(int i = odd.size() - 1; i >= 0; i--) if(!ok[i]) {
        ll mul = 1;
        for(int j = i; j >= 0; j--) if(!ok[j] && mul * odd[j] <= d) {
            mul *= odd[j];
            ok[j] = true;
        }
        res++;
    }

    cout << res;
}
int32_t main()
{
    FastIO
    freopen("TRANS.INP", "r", stdin);
    freopen("TRANS.OUT", "w", stdout);
    cin >> n >> m >> d;

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
