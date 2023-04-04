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

const int NM = 1e7 + 10;
int n, m;
int a[NM], b[NM];
set<int> A, B;
vector<pair<int, char>> ans;

void xuli() {
    while(A.size()) {
        int u = *A.begin();
        if(a[u] & 1) {
            a[u]++;
            ans.push_back(make_pair(u, 'D'));
        }
        for(int i = 2; i <= a[u]; i += 2) {
            ans.push_back(make_pair(u, 'W'));
            b[u]++;
        }
        if(b[u] & 1) {
            ans.push_back(make_pair(u, 'D'));
            ans.push_back(make_pair(u, 'D'));
            ans.push_back(make_pair(u, 'W'));
            b[u]++;
        }
        for(int i = 2; i <= b[u]; i += 2)
            ans.push_back(make_pair(u, 'L'));

        auto it = B.find(u);
        if(it != B.end()) B.erase(it);
        A.erase(A.begin());
    }

    while(B.size()) {
        int u = *B.begin();
        if(b[u] & 1) {
            ans.push_back(make_pair(u, 'D'));
            ans.push_back(make_pair(u, 'D'));
            ans.push_back(make_pair(u, 'W'));
            b[u]++;
        }
        for(int i = 2; i <= b[u]; i += 2)
            ans.push_back(make_pair(u, 'L'));

        B.erase(B.begin());
    }

    cout << ans.size() << '\n';
    for(pair<int, char> u : ans) cout << u.fi << " " << u.se << '\n';
}
int32_t main()
{
    FastIO
    freopen("VECTOR.INP", "r", stdin);
    freopen("VECTOR.OUT", "w", stdout);
    cin >> n;
    for(int i = 1; i <= n; i++) {
        int u; cin >> u;
        if(!b[u]) B.insert(u);
        b[u]++;
    }
    cin >> m;
    for(int i = 1; i <= m; i++) {
        int u; cin >> u;
        if(!a[u]) A.insert(u);
        a[u]++;
    }

    xuli();
    return 0;
}

/* Author: hxzinh */

