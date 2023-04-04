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
ll n;
pii a[NM], lim[NM];
vector<ll> vec[NM];

struct Data {
    int l, r;

    bool inline operator < (const Data &A) const {
        return r > A.r;
    }
};

bool check(ll x) {
    for(int i = 1; i <= n; i++) vec[i].clear();

    for(int i = 1; i <= n; i++) {
        ll L = max(1LL, a[i].fi - x / a[i].se);
        ll R = min(n, a[i].fi + x / a[i].se);
        vec[L].push_back(R);
    }

    priority_queue<ll, vector<ll>, greater<ll>> pq;

    for(int i = 1; i <= n; i++) {
        for(ll u : vec[i]) pq.push(u);
        while(pq.size() && pq.top() < i) pq.pop();

        if(!pq.size()) return false;
        pq.pop();
    }
    return true;
}
void xuli() {
    ll l = 1, r = 2e14, res = -1;
    while(l <= r) {
        ll m = (l + r) >> 1;
        if(check(m)) {
            res = m;
            r = m - 1;
        }
        else l = m + 1;
    }

    cout << res;
}
int32_t main()
{
    FastIO
    freopen("A.INP", "r", stdin);
    freopen("A.OUT", "w", stdout);
    cin >> n;
    for(int i = 1; i <= n; i++) cin >> a[i].fi >> a[i].se;

    xuli();
    return 0;
}
